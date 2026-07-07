#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "radarworker.h"
#include "calibrationdataparser.h"
#include "lancommandchannel.h"
#include "runstagesequencer.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onStartCalibrationClicked();

private:
    Ui::MainWindow *ui;

    // Phase 1 Engine
    RadarWorker *radarEngine;

    // Phase 2 Hardware Engines
    CalibrationDataParser *m_calParser;
    LanCommandChannel *m_lanChannel;
    RunStageSequencer *m_sequencer;
};

#endif // MAINWINDOW_H