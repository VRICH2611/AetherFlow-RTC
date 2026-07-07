#ifndef RUNSTAGESEQUENCER_H
#define RUNSTAGESEQUENCER_H

#include <QObject>
#include <QTimer>
#include "lancommandchannel.h"
#include "calibrationdataparser.h"

class RunStageSequencer : public QObject {
    Q_OBJECT
public:
    explicit RunStageSequencer(LanCommandChannel* lanChannel,
                               CalibrationDataParser* parser,
                               QObject *parent = nullptr);

public slots:
    // UPGRADED: Now takes the dynamic IP and the new Control Signals!
    void startCalibrationRoutine(QString targetIp, bool isTx, int priDelay, int pint, int trap);
    void stopRoutine();

signals:
    // NEW: Yells out the progress to the UI Progress Bar
    void progressUpdated(int currentRow, int totalRows);

private slots:
    void onActivityCheckPassed();
    void processNextRow();
    void onInitRunAckReceived();

private:
    LanCommandChannel* m_lanChannel;
    CalibrationDataParser* m_parser;
    int m_currentRowIndex;

    // User Inputs
    QString m_targetIp;
    bool m_isTx;
    int m_priDelay;
    int m_pint;
    int m_trap;

    QTimer* m_priTimer;
};

#endif // RUNSTAGESEQUENCER_H