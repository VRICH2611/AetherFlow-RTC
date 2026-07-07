#ifndef RADARWORKER_H
#define RADARWORKER_H

#include <QObject>
#include <QTcpSocket>
#include <QUdpSocket>
#include <QNetworkDatagram>
#include <QDataStream>
#include <QTimer>
#include "xlsxdocument.h"

class RadarWorker : public QObject
{
    Q_OBJECT
public:
    explicit RadarWorker(QObject *parent = nullptr);

    void connectRtc(const QString &rtcIp, quint16 rtcPort, quint16 rtcLocalPort);
    void bindAaau(const QString &aaauIp, quint16 aaauRxPort, quint16 aaauTxPort);
    void setScalingFactors(double rsScale, double tsScale);
    void finalizeAndSaveReport(const QString &fileName);
    void sendCalibrationData(bool isTx, int m, int n, float attenuation, int phase);

    // RESTORED: Dynamic Pattern arguments
    void startPatternTransmission(bool isTx, int delayMs, int maxRows);

    void startMockRadarData();
    void stopMockRadarData();

signals:
    void logMessage(const QString &msg);
    void rtcStatusChanged(bool connected, const QString &statusText);
    void aaauStatusChanged(bool bound, const QString &statusText);

private slots:
    void onUdpReadyRead();
    void onTcpStateChanged(QAbstractSocket::SocketState socketState);
    void onPatternTimerTick();
    void onMockTimerTick();

private:
    uint8_t calculateChecksum(const QByteArray &data);

    QTcpSocket *m_tcpSocket;
    QUdpSocket *m_udpSocket;
    QXlsx::Document m_excelDoc;

    int m_currentRow = 2;
    double m_rsScale = 1.0;
    double m_tsScale = 1.0;
    QString m_targetAaauIp;
    quint16 m_targetAaauTxPort;

    QTimer *m_patternTimer;
    int m_patternCurrentRow;
    int m_patternMaxRow; // RESTORED
    bool m_patternIsTx;

    QTimer *m_mockTimer;
    quint32 m_mockSteps;
};

#endif // RADARWORKER_H