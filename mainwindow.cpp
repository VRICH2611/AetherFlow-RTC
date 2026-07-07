#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "radarworker.h"
#include <QMessageBox>
#include <QStandardPaths>
#include <QDateTime>
#include <QDebug>
#include <QFile>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    radarEngine = new RadarWorker(this);
    radarEngine->setScalingFactors(1.2, 0.5);

    // TELEMETRY
    connect(radarEngine, &RadarWorker::logMessage, this, [this](const QString &text) {
        ui->consoleTextEdit->append(text);
    });
    connect(radarEngine, &RadarWorker::rtcStatusChanged, this, [this](bool connected, const QString &status) {
        ui->labelStatusRtc->setText(status);
        ui->labelStatusRtc->setStyleSheet(connected ? "color: green; font-weight: bold;" : "color: red; font-weight: bold;");
    });
    connect(radarEngine, &RadarWorker::aaauStatusChanged, this, [this](bool bound, const QString &status) {
        ui->labelStatusAaau->setText(status);
        ui->labelStatusAaau->setStyleSheet(bound ? "color: green; font-weight: bold;" : "color: red; font-weight: bold;");
    });

    // NETWORK BINDINGS
    connect(ui->btnBindRtc, &QPushButton::clicked, this, [this]() {
        radarEngine->connectRtc(ui->editRtcIp->text(), ui->editRtcPort->text().toUShort(), ui->editRtcLocalPort->text().toUShort());
    });
    connect(ui->btnBindAaau, &QPushButton::clicked, this, [this]() {
        radarEngine->bindAaau(ui->editAaauIp->text(), ui->editAaauRxPort->text().toUShort(), ui->editAaauTxPort->text().toUShort());
    });

    // =========================================================
    // RESTORED: TAB 2 - SEARCH BY INDEX
    // =========================================================
    connect(ui->btnSearchRow, &QPushButton::clicked, this, [this]() {
        int targetRow = ui->spinSearchIndex->value();
        if (m_calParser->getRowCount() == 0) {
            QMessageBox::warning(this, "Data Error", "Calibration matrix is empty. Ensure calibration_matrix.txt is in the build folder.");
            return;
        }
        if (targetRow >= m_calParser->getRowCount() || targetRow < 0) {
            QMessageBox::warning(this, "Index Error", "Row index out of bounds!");
            return;
        }
        CalibrationRow rowData = m_calParser->getRow(targetRow);
        ui->spinM->setValue(rowData.m);
        ui->spinN->setValue(rowData.n);
        ui->spinAtten->setValue(rowData.attn);
        ui->spinPhase->setValue(rowData.phase);
        ui->consoleTextEdit->append("Loaded row " + QString::number(targetRow) + " into UI.");
    });

    connect(ui->btnSendCalib, &QPushButton::clicked, this, [this]() {
        if (!ui->radioTx->isChecked() && !ui->radioRx->isChecked()) return;
        radarEngine->sendCalibrationData(ui->radioTx->isChecked(), ui->spinM->value(), ui->spinN->value(), ui->spinAtten->value(), ui->spinPhase->value());
    });

    // =========================================================
    // RESTORED: TAB 3 - DYNAMIC PATTERN DELAY & MAX ROWS
    // =========================================================
    connect(ui->btnSendPattern, &QPushButton::clicked, this, [this]() {
        if (!ui->radioPattTx->isChecked() && !ui->radioPattRx->isChecked()) return;
        int delay = ui->spinPatternDelay->value();
        int max = ui->spinPatternMaxRow->value();
        radarEngine->startPatternTransmission(ui->radioPattTx->isChecked(), delay, max);
    });

    // MOCK PIPELINES
    connect(ui->btnStartMock, &QPushButton::clicked, this, [this]() { radarEngine->startMockRadarData(); });
    connect(ui->btnStopMock, &QPushButton::clicked, this, [this]() { radarEngine->stopMockRadarData(); });
    connect(ui->btnStopAndSave, &QPushButton::clicked, this, [this]() {
        QString path = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "/Final_Radar_Scan_" + QDateTime::currentDateTime().toString("hhmmss") + ".xlsx";
        radarEngine->finalizeAndSaveReport(path);
    });

    // =========================================================
    // RESTORED: PHASE 2 INITIALIZATION & STOP BUTTON
    // =========================================================
    m_calParser = new CalibrationDataParser(this);
    m_lanChannel = new LanCommandChannel(this);
    m_sequencer = new RunStageSequencer(m_lanChannel, m_calParser, this);
    // PHASE 2 LIVE PROGRESS BAR
    connect(m_sequencer, &RunStageSequencer::progressUpdated, this, [this](int current, int total) {
        ui->progressBarPhase2->setMaximum(total);
        ui->progressBarPhase2->setValue(current);
        ui->lblProgressPhase2->setText(QString("Row: %1 / %2").arg(current).arg(total));
    });
    // ---------------------------------------------------------
    // AUTO-GENERATE DUMMY FILE IF MISSING
    // ---------------------------------------------------------
    QFile calibFile("calibration_matrix.txt");
    if (!calibFile.exists()) {
        if (calibFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&calibFile);
            out << "i,j,m,n,atten,phase\n"; // Header row
            out << "0,0,1,1,5.5,90\n";      // Row 0
            out << "0,1,1,2,5.6,91\n";      // Row 1
            out << "1,0,2,1,5.7,92\n";      // Row 2
            out << "1,1,2,2,5.8,93\n";      // Row 3
            calibFile.close();
            ui->consoleTextEdit->append("SYSTEM NOTICE: Auto-generated a missing calibration_matrix.txt file in the build folder.");
        }
    }

    // (Your existing code continues here...)
    if (m_calParser->loadFromFile("calibration_matrix.txt")) {
        ui->consoleTextEdit->append("SUCCESS: Phase 2 Calibration Matrix Loaded.");
    } // ...

    if (m_calParser->loadFromFile("calibration_matrix.txt")) {
        ui->consoleTextEdit->append("SUCCESS: Phase 2 Calibration Matrix Loaded.");
    } else {
        ui->consoleTextEdit->append("WARNING: Phase 2 calibration_matrix.txt not found in build directory.");
    }

    connect(ui->btnStartCalibration, &QPushButton::clicked, this, &MainWindow::onStartCalibrationClicked);

    // EMERGENCY STOP
    connect(ui->btnStopPhase2, &QPushButton::clicked, this, [this]() {
        ui->consoleTextEdit->append("HALTING PHASE 2 SEQUENCE (OpCode 14)...");
        m_sequencer->stopRoutine();
        ui->btnStartCalibration->setEnabled(true);
    });
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::onStartCalibrationClicked() {
    if (!ui->radioPhase2Tx->isChecked() && !ui->radioPhase2Rx->isChecked()) return;

    ui->btnStartCalibration->setEnabled(false);
    ui->consoleTextEdit->append("INITIATING PHASE 2 TCP SEQUENCE...");

    // Grab the Target IP from Tab 1 (System Setup)
    QString targetIp = ui->editRtcIp->text();

    // Grab all parameters
    bool isTx = ui->radioPhase2Tx->isChecked();
    int pri = ui->spinPhase2Pri->value();
    int pint = ui->spinPint->value();
    int trap = ui->spinTrap->value();

    // Fire the engine with ALL data
    m_sequencer->startCalibrationRoutine(targetIp, isTx, pri, pint, trap);
}