#include "runstagesequencer.h"
#include "iddprotocol.h"
#include <QDebug>

RunStageSequencer::RunStageSequencer(LanCommandChannel* lanChannel,
                                     CalibrationDataParser* parser,
                                     QObject *parent)
    : QObject(parent), m_lanChannel(lanChannel), m_parser(parser), m_currentRowIndex(0) {

    m_priTimer = new QTimer(this);
    m_priTimer->setSingleShot(true);

    connect(m_lanChannel, &LanCommandChannel::activityCheckPassed, this, &RunStageSequencer::onActivityCheckPassed);
    connect(m_lanChannel, &LanCommandChannel::initRunAckReceived, this, &RunStageSequencer::onInitRunAckReceived);
    connect(m_priTimer, &QTimer::timeout, this, &RunStageSequencer::processNextRow);
}

void RunStageSequencer::startCalibrationRoutine(QString targetIp, bool isTx, int priDelay, int pint, int trap) {
    m_currentRowIndex = 0;
    m_targetIp = targetIp;
    m_isTx = isTx;
    m_priDelay = priDelay;
    m_pint = pint; // Saved for 32-byte UDP payload later!
    m_trap = trap; // Saved for 32-byte UDP payload later!

    int totalRows = m_parser->getRowCount();
    if (totalRows == 0) {
        qWarning() << "No data loaded!";
        return;
    }

    // Tell the UI we are starting at 0
    emit progressUpdated(0, totalRows);

    // FIXED: Use the dynamic IP instead of the hardcoded one!
    m_lanChannel->connectToRdc(m_targetIp, 5001);
}

void RunStageSequencer::onActivityCheckPassed() {
    processNextRow();
}

void RunStageSequencer::processNextRow() {
    int totalRows = m_parser->getRowCount();

    // Update the progress bar!
    emit progressUpdated(m_currentRowIndex, totalRows);

    if (m_currentRowIndex >= totalRows) {
        qDebug() << "Calibration Complete!";
        return;
    }

    CalibrationRow row = m_parser->getRow(m_currentRowIndex);
    int subMode = m_isTx ? 1 : 2;

    QByteArray payload = InitRunPayload::build(1, 2, subMode, 9, row.i, row.j);
    m_lanChannel->sendInitRun(payload);
}

void RunStageSequencer::onInitRunAckReceived() {
    m_priTimer->start(m_priDelay);
    m_currentRowIndex++;
}

void RunStageSequencer::stopRoutine() {
    m_priTimer->stop();
    m_lanChannel->sendStop();
}