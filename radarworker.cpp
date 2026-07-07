#include "radarworker.h"
#include <cstdlib>
#include <QRandomGenerator>

RadarWorker::RadarWorker(QObject *parent) : QObject(parent)
{
    m_tcpSocket = new QTcpSocket(this);
    m_udpSocket = new QUdpSocket(this);

    // Setup Excel Headers
    m_excelDoc.write(1, 1, "Raw Encoder Steps");
    m_excelDoc.write(1, 2, "Actual Position (mm)");
    m_excelDoc.write(1, 3, "Raw Signal Value");
    m_excelDoc.write(1, 4, "Actual Amplitude (dBm)");

    // Wire up internal network listeners
    connect(m_udpSocket, &QUdpSocket::readyRead, this, &RadarWorker::onUdpReadyRead);
    connect(m_tcpSocket, &QTcpSocket::stateChanged, this, &RadarWorker::onTcpStateChanged);

    // Setup hidden pattern sequence stopwatch
    m_patternTimer = new QTimer(this);
    connect(m_patternTimer, &QTimer::timeout, this, &RadarWorker::onPatternTimerTick);

    // Setup hidden mock radar local generator
    m_mockTimer = new QTimer(this);
    connect(m_mockTimer, &QTimer::timeout, this, &RadarWorker::onMockTimerTick);
    m_mockSteps = 0;
}

// ---------------------------------------------------------
// NETWORKING SETUP & STATUS CONTROLS
// ---------------------------------------------------------
void RadarWorker::connectRtc(const QString &rtcIp, quint16 rtcPort, quint16 rtcLocalPort) {
    if (m_tcpSocket->state() != QAbstractSocket::ConnectedState) {
        emit rtcStatusChanged(false, "Connecting...");
        m_tcpSocket->bind(QHostAddress::Any, rtcLocalPort);
        m_tcpSocket->connectToHost(rtcIp, rtcPort);
        emit logMessage("RTC: Binding to local port " + QString::number(rtcLocalPort) + " and connecting to remote server...");
    }
}

void RadarWorker::onTcpStateChanged(QAbstractSocket::SocketState socketState) {
    if (socketState == QAbstractSocket::ConnectedState) {
        emit rtcStatusChanged(true, "Connected");
        emit logMessage("RTC: Network connection established successfully.");
    } else if (socketState == QAbstractSocket::UnconnectedState) {
        emit rtcStatusChanged(false, "Disconnected");
        emit logMessage("RTC: Network link dropped.");
    }
}

void RadarWorker::bindAaau(const QString &aaauIp, quint16 aaauRxPort, quint16 aaauTxPort) {
    // Graceful close before abort to prevent OS-level port locking
    if (m_udpSocket->state() == QAbstractSocket::BoundState) {
        m_udpSocket->close();
        m_udpSocket->abort();
    }
    if (m_udpSocket->bind(QHostAddress::Any, aaauRxPort, QUdpSocket::ShareAddress)) {
        m_targetAaauIp = aaauIp;
        m_targetAaauTxPort = aaauTxPort;
        emit aaauStatusChanged(true, "Bound (Listening)");
        emit logMessage("AAAU: UDP bound to local listening port: " + QString::number(aaauRxPort));
    } else {
        emit aaauStatusChanged(false, "Bind Failed");
        emit logMessage("AAAU ERROR: Failed to bind to local port.");
    }
}

// ---------------------------------------------------------
// RADAR MATH, CHECKSUM, AND PACKET ARRAYS
// ---------------------------------------------------------
uint8_t RadarWorker::calculateChecksum(const QByteArray &data) {
    uint8_t checksum = 0;
    for (char byte : data) checksum ^= static_cast<uint8_t>(byte);
    return checksum;
}

void RadarWorker::setScalingFactors(double rsScale, double tsScale) {
    m_rsScale = rsScale;
    m_tsScale = tsScale;
}

void RadarWorker::sendCalibrationData(bool isTx, int m, int n, float attenuation, int phase) {
    QByteArray calibPacket;
    calibPacket.append(static_cast<char>(0xAA)); // 1. Header byte
    calibPacket.append(static_cast<char>(isTx ? 0x01 : 0x00)); // 2. Mode byte
    calibPacket.append(static_cast<char>(m)); // 3. M byte
    calibPacket.append(static_cast<char>(n)); // 4. N byte

    // 5. Attenuation (Convert 4-byte float to raw characters)
    const char *attenBytes = reinterpret_cast<const char*>(&attenuation);
    calibPacket.append(attenBytes, sizeof(float));

    calibPacket.append(static_cast<char>(phase)); // 6. Phase byte
    calibPacket.append(static_cast<char>(calculateChecksum(calibPacket))); // 7. Checksum byte

    if (calibPacket.size() == 10) {
        m_udpSocket->writeDatagram(calibPacket, QHostAddress(m_targetAaauIp), m_targetAaauTxPort);
        emit logMessage("Sent structured 10-Byte Calibration Array over UDP.");
    }
}

// ---------------------------------------------------------
// HIDDEN BACKEND AUTOMATED PATTERN SEQUENCE
// ---------------------------------------------------------
void RadarWorker::startPatternTransmission(bool isTx, int delayMs, int maxRows) {
    m_patternIsTx = isTx;
    m_patternCurrentRow = 0;
    m_patternMaxRow = maxRows; // Save the limit from UI

    m_patternTimer->start(delayMs); // Use custom delay
    emit logMessage("Automated Pattern initialized. Running 0 to " + QString::number(maxRows) + " at " + QString::number(delayMs) + "ms intervals...");
}

void RadarWorker::onPatternTimerTick() {
    // Check against the user's limit!
    if (m_patternCurrentRow >= m_patternMaxRow) {
        m_patternTimer->stop();
        emit logMessage("Pattern tracking execution successfully processed.");
        return;
    }

    int m = m_patternCurrentRow;
    int n = m_patternCurrentRow;
    float atten = 5.5f;
    int phase = 90;

    QByteArray packet;
    packet.append(static_cast<char>(0xAA));
    packet.append(static_cast<char>(m_patternIsTx ? 0x01 : 0x00));
    packet.append(static_cast<char>(m));
    packet.append(static_cast<char>(n));

    const char *attenBytes = reinterpret_cast<const char*>(&atten);
    packet.append(attenBytes, sizeof(float));
    packet.append(static_cast<char>(phase));
    packet.append(static_cast<char>(calculateChecksum(packet)));

    if (packet.size() == 10) {
        m_udpSocket->writeDatagram(packet, QHostAddress(m_targetAaauIp), m_targetAaauTxPort);
    }
    m_patternCurrentRow++;
}

// ---------------------------------------------------------
// MOCK RADAR GENERATOR (Local Loopback Data Streaming)
// ---------------------------------------------------------
void RadarWorker::startMockRadarData() {
    if (m_udpSocket->state() != QAbstractSocket::BoundState) {
        emit logMessage("MOCK SYSTEM ERROR: You must open and bind the AAAU port first.");
        return;
    }
    m_mockSteps = 0;
    m_mockTimer->start(50); // Fires fake telemetry every 50 milliseconds
    emit logMessage("Mock loopback engine initialized. Blasting local test stream...");
}

void RadarWorker::stopMockRadarData() {
    m_mockTimer->stop();
    emit logMessage("Mock loopback pipeline halted.");
}

void RadarWorker::onMockTimerTick() {
    m_mockSteps += 5;
    quint32 fakeSignalCount = QRandomGenerator::global()->bounded(800);

    // Construct an exact 8-byte network string (Big Endian)
    QByteArray fakeData;
    QDataStream stream(&fakeData, QIODevice::WriteOnly);
    stream.setByteOrder(QDataStream::BigEndian);
    stream << m_mockSteps << fakeSignalCount;

    // Throw it locally back into our own listening ear
    m_udpSocket->writeDatagram(fakeData, QHostAddress("127.0.0.1"), m_udpSocket->localPort());
}

// ---------------------------------------------------------
// TELEMETRY PROCESSING & SAVE ENGINE
// ---------------------------------------------------------
void RadarWorker::onUdpReadyRead() {
    while (m_udpSocket->hasPendingDatagrams()) {
        QByteArray rawBytes = m_udpSocket->receiveDatagram().data();

        // SECURITY CHECK: Discard unexpected stray packets or 10-byte loopbacks
        if (rawBytes.size() != 8) {
            continue;
        }

        QDataStream stream(rawBytes);
        stream.setByteOrder(QDataStream::BigEndian);

        quint32 rawEncoderSteps, rawSignalValue;
        stream >> rawEncoderSteps >> rawSignalValue;

        // Apply dynamic scale configuration math
        double actualPositionMm = (double)rawEncoderSteps * m_tsScale;
        double actualAmplitudeDbm = (double)rawSignalValue * m_rsScale;

        // Write directly to spreadsheet columns
        m_excelDoc.write(m_currentRow, 1, rawEncoderSteps);
        m_excelDoc.write(m_currentRow, 2, actualPositionMm);
        m_excelDoc.write(m_currentRow, 3, rawSignalValue);
        m_excelDoc.write(m_currentRow, 4, actualAmplitudeDbm);
        m_currentRow++;
    }
}

void RadarWorker::finalizeAndSaveReport(const QString &fileName) {
    if(m_excelDoc.saveAs(fileName)) {
        emit logMessage("Spreadsheet transaction logged to file: " + fileName);
    } else {
        emit logMessage("Excel IO Error: Failed to write system report.");
    }
}