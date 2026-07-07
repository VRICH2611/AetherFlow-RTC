/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *Ethernet;
    QLineEdit *editRtcIp;
    QLineEdit *editRtcPort;
    QLineEdit *editRtcLocalPort;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QFrame *line;
    QFrame *line_2;
    QFrame *line_3;
    QFrame *line_4;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *editAaauRxPort;
    QLineEdit *editAaauTxPort;
    QLineEdit *editAaauIp;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QFrame *line_5;
    QFrame *line_6;
    QFrame *line_7;
    QFrame *line_8;
    QPushButton *btnBindRtc;
    QPushButton *btnBindAaau;
    QLabel *labelStatusRtc;
    QLabel *labelStatusAaau;
    QPushButton *btnStartMock;
    QPushButton *btnStopMock;
    QWidget *Calibration;
    QRadioButton *radioTx;
    QRadioButton *radioRx;
    QSpinBox *spinM;
    QSpinBox *spinN;
    QDoubleSpinBox *spinAtten;
    QSpinBox *spinPhase;
    QPushButton *btnSendCalib;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QFrame *line_9;
    QSpinBox *spinSearchIndex;
    QPushButton *btnSearchRow;
    QWidget *PatternMode;
    QRadioButton *radioPattTx;
    QRadioButton *radioPattRx;
    QPushButton *btnSendPattern;
    QSpinBox *spinPatternDelay;
    QSpinBox *spinPatternMaxRow;
    QWidget *tab;
    QPushButton *btnStartCalibration;
    QRadioButton *radioPhase2Tx;
    QRadioButton *radioPhase2Rx;
    QSpinBox *spinPhase2Pri;
    QLabel *label_13;
    QPushButton *btnStopPhase2;
    QProgressBar *progressBarPhase2;
    QLabel *lblProgressPhase2;
    QSpinBox *spinPint;
    QSpinBox *spinTrap;
    QLabel *label_14;
    QLabel *label_15;
    QPushButton *btnStopAndSave;
    QTextEdit *consoleTextEdit;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(0, 0, 681, 361));
        Ethernet = new QWidget();
        Ethernet->setObjectName("Ethernet");
        editRtcIp = new QLineEdit(Ethernet);
        editRtcIp->setObjectName("editRtcIp");
        editRtcIp->setGeometry(QRect(160, 140, 113, 28));
        editRtcPort = new QLineEdit(Ethernet);
        editRtcPort->setObjectName("editRtcPort");
        editRtcPort->setGeometry(QRect(160, 170, 113, 28));
        editRtcLocalPort = new QLineEdit(Ethernet);
        editRtcLocalPort->setObjectName("editRtcLocalPort");
        editRtcLocalPort->setGeometry(QRect(160, 200, 113, 28));
        label = new QLabel(Ethernet);
        label->setObjectName("label");
        label->setGeometry(QRect(60, 140, 71, 20));
        label_2 = new QLabel(Ethernet);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(60, 170, 71, 20));
        label_3 = new QLabel(Ethernet);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(60, 200, 91, 20));
        line = new QFrame(Ethernet);
        line->setObjectName("line");
        line->setGeometry(QRect(280, 20, 20, 271));
        line->setFrameShape(QFrame::Shape::VLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);
        line_2 = new QFrame(Ethernet);
        line_2->setObjectName("line_2");
        line_2->setGeometry(QRect(30, 280, 261, 20));
        line_2->setFrameShape(QFrame::Shape::HLine);
        line_2->setFrameShadow(QFrame::Shadow::Sunken);
        line_3 = new QFrame(Ethernet);
        line_3->setObjectName("line_3");
        line_3->setGeometry(QRect(30, 20, 20, 271));
        line_3->setFrameShape(QFrame::Shape::VLine);
        line_3->setFrameShadow(QFrame::Shadow::Sunken);
        line_4 = new QFrame(Ethernet);
        line_4->setObjectName("line_4");
        line_4->setGeometry(QRect(40, 20, 251, 16));
        line_4->setFrameShape(QFrame::Shape::HLine);
        line_4->setFrameShadow(QFrame::Shadow::Sunken);
        label_4 = new QLabel(Ethernet);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(140, 50, 111, 41));
        QFont font;
        font.setFamilies({QString::fromUtf8("Segoe UI Symbol")});
        label_4->setFont(font);
        label_5 = new QLabel(Ethernet);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(480, 60, 63, 20));
        editAaauRxPort = new QLineEdit(Ethernet);
        editAaauRxPort->setObjectName("editAaauRxPort");
        editAaauRxPort->setGeometry(QRect(500, 160, 113, 28));
        editAaauTxPort = new QLineEdit(Ethernet);
        editAaauTxPort->setObjectName("editAaauTxPort");
        editAaauTxPort->setGeometry(QRect(500, 210, 113, 28));
        editAaauIp = new QLineEdit(Ethernet);
        editAaauIp->setObjectName("editAaauIp");
        editAaauIp->setGeometry(QRect(498, 100, 111, 28));
        editAaauIp->setDragEnabled(false);
        label_6 = new QLabel(Ethernet);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(420, 110, 63, 20));
        label_7 = new QLabel(Ethernet);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(420, 160, 63, 20));
        label_8 = new QLabel(Ethernet);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(420, 210, 63, 20));
        line_5 = new QFrame(Ethernet);
        line_5->setObjectName("line_5");
        line_5->setGeometry(QRect(363, 50, 20, 241));
        line_5->setFrameShape(QFrame::Shape::VLine);
        line_5->setFrameShadow(QFrame::Shadow::Sunken);
        line_6 = new QFrame(Ethernet);
        line_6->setObjectName("line_6");
        line_6->setGeometry(QRect(613, 50, 20, 241));
        line_6->setFrameShape(QFrame::Shape::VLine);
        line_6->setFrameShadow(QFrame::Shadow::Sunken);
        line_7 = new QFrame(Ethernet);
        line_7->setObjectName("line_7");
        line_7->setGeometry(QRect(370, 40, 251, 16));
        line_7->setFrameShape(QFrame::Shape::HLine);
        line_7->setFrameShadow(QFrame::Shadow::Sunken);
        line_8 = new QFrame(Ethernet);
        line_8->setObjectName("line_8");
        line_8->setGeometry(QRect(370, 280, 251, 16));
        line_8->setFrameShape(QFrame::Shape::HLine);
        line_8->setFrameShadow(QFrame::Shadow::Sunken);
        btnBindRtc = new QPushButton(Ethernet);
        btnBindRtc->setObjectName("btnBindRtc");
        btnBindRtc->setGeometry(QRect(60, 250, 90, 29));
        btnBindAaau = new QPushButton(Ethernet);
        btnBindAaau->setObjectName("btnBindAaau");
        btnBindAaau->setGeometry(QRect(400, 250, 90, 29));
        labelStatusRtc = new QLabel(Ethernet);
        labelStatusRtc->setObjectName("labelStatusRtc");
        labelStatusRtc->setGeometry(QRect(170, 250, 91, 20));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::BrushStyle::SolidPattern);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::WindowText, brush);
        QBrush brush1(QColor(240, 0, 0, 255));
        brush1.setStyle(Qt::BrushStyle::SolidPattern);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Button, brush1);
        QBrush brush2(QColor(255, 105, 105, 255));
        brush2.setStyle(Qt::BrushStyle::SolidPattern);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Light, brush2);
        QBrush brush3(QColor(247, 52, 52, 255));
        brush3.setStyle(Qt::BrushStyle::SolidPattern);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Midlight, brush3);
        QBrush brush4(QColor(120, 0, 0, 255));
        brush4.setStyle(Qt::BrushStyle::SolidPattern);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Dark, brush4);
        QBrush brush5(QColor(160, 0, 0, 255));
        brush5.setStyle(Qt::BrushStyle::SolidPattern);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Mid, brush5);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Text, brush);
        QBrush brush6(QColor(255, 255, 255, 255));
        brush6.setStyle(Qt::BrushStyle::SolidPattern);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::BrightText, brush6);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::ButtonText, brush);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Base, brush6);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Window, brush1);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Shadow, brush);
        QBrush brush7(QColor(247, 127, 127, 255));
        brush7.setStyle(Qt::BrushStyle::SolidPattern);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::AlternateBase, brush7);
        QBrush brush8(QColor(255, 255, 220, 255));
        brush8.setStyle(Qt::BrushStyle::SolidPattern);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::ToolTipBase, brush8);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::ToolTipText, brush);
        QBrush brush9(QColor(0, 0, 0, 127));
        brush9.setStyle(Qt::BrushStyle::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::PlaceholderText, brush9);
#endif
#if QT_VERSION >= QT_VERSION_CHECK(6, 6, 0)
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Accent, brush6);
#endif
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::WindowText, brush);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Button, brush1);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Light, brush2);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Midlight, brush3);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Dark, brush4);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Mid, brush5);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Text, brush);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::BrightText, brush6);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::ButtonText, brush);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Base, brush6);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Window, brush1);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Shadow, brush);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::AlternateBase, brush7);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::ToolTipBase, brush8);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::PlaceholderText, brush9);
#endif
#if QT_VERSION >= QT_VERSION_CHECK(6, 6, 0)
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Accent, brush6);
#endif
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::WindowText, brush4);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Button, brush1);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Light, brush2);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Midlight, brush3);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Dark, brush4);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Mid, brush5);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Text, brush4);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::BrightText, brush6);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::ButtonText, brush4);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Base, brush1);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Window, brush1);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Shadow, brush);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::AlternateBase, brush1);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::ToolTipBase, brush8);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::ToolTipText, brush);
        QBrush brush10(QColor(120, 0, 0, 127));
        brush10.setStyle(Qt::BrushStyle::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::PlaceholderText, brush10);
#endif
        QBrush brush11(QColor(255, 57, 57, 255));
        brush11.setStyle(Qt::BrushStyle::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(6, 6, 0)
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Accent, brush11);
#endif
        labelStatusRtc->setPalette(palette);
        labelStatusRtc->setAutoFillBackground(false);
        labelStatusAaau = new QLabel(Ethernet);
        labelStatusAaau->setObjectName("labelStatusAaau");
        labelStatusAaau->setGeometry(QRect(510, 250, 101, 20));
        btnStartMock = new QPushButton(Ethernet);
        btnStartMock->setObjectName("btnStartMock");
        btnStartMock->setGeometry(QRect(310, 10, 151, 29));
        btnStopMock = new QPushButton(Ethernet);
        btnStopMock->setObjectName("btnStopMock");
        btnStopMock->setGeometry(QRect(470, 10, 191, 29));
        tabWidget->addTab(Ethernet, QString());
        Calibration = new QWidget();
        Calibration->setObjectName("Calibration");
        radioTx = new QRadioButton(Calibration);
        radioTx->setObjectName("radioTx");
        radioTx->setGeometry(QRect(10, 10, 111, 25));
        radioTx->setChecked(false);
        radioTx->setAutoExclusive(true);
        radioRx = new QRadioButton(Calibration);
        radioRx->setObjectName("radioRx");
        radioRx->setGeometry(QRect(190, 10, 111, 25));
        radioRx->setChecked(false);
        radioRx->setAutoExclusive(true);
        spinM = new QSpinBox(Calibration);
        spinM->setObjectName("spinM");
        spinM->setGeometry(QRect(130, 70, 101, 29));
        spinN = new QSpinBox(Calibration);
        spinN->setObjectName("spinN");
        spinN->setGeometry(QRect(130, 130, 101, 29));
        spinAtten = new QDoubleSpinBox(Calibration);
        spinAtten->setObjectName("spinAtten");
        spinAtten->setGeometry(QRect(420, 60, 121, 29));
        spinPhase = new QSpinBox(Calibration);
        spinPhase->setObjectName("spinPhase");
        spinPhase->setGeometry(QRect(440, 120, 101, 29));
        btnSendCalib = new QPushButton(Calibration);
        btnSendCalib->setObjectName("btnSendCalib");
        btnSendCalib->setGeometry(QRect(250, 290, 151, 29));
        label_9 = new QLabel(Calibration);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(50, 80, 63, 20));
        label_10 = new QLabel(Calibration);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(50, 130, 63, 20));
        label_11 = new QLabel(Calibration);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(312, 70, 81, 20));
        label_12 = new QLabel(Calibration);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(310, 130, 63, 20));
        line_9 = new QFrame(Calibration);
        line_9->setObjectName("line_9");
        line_9->setGeometry(QRect(0, 50, 661, 16));
        line_9->setFrameShape(QFrame::Shape::HLine);
        line_9->setFrameShadow(QFrame::Shadow::Sunken);
        spinSearchIndex = new QSpinBox(Calibration);
        spinSearchIndex->setObjectName("spinSearchIndex");
        spinSearchIndex->setGeometry(QRect(73, 200, 91, 29));
        btnSearchRow = new QPushButton(Calibration);
        btnSearchRow->setObjectName("btnSearchRow");
        btnSearchRow->setGeometry(QRect(230, 200, 171, 29));
        tabWidget->addTab(Calibration, QString());
        PatternMode = new QWidget();
        PatternMode->setObjectName("PatternMode");
        radioPattTx = new QRadioButton(PatternMode);
        radioPattTx->setObjectName("radioPattTx");
        radioPattTx->setGeometry(QRect(30, 20, 111, 25));
        radioPattTx->setChecked(false);
        radioPattTx->setAutoExclusive(true);
        radioPattRx = new QRadioButton(PatternMode);
        radioPattRx->setObjectName("radioPattRx");
        radioPattRx->setGeometry(QRect(200, 20, 111, 25));
        radioPattRx->setCheckable(true);
        radioPattRx->setChecked(false);
        radioPattRx->setAutoExclusive(true);
        btnSendPattern = new QPushButton(PatternMode);
        btnSendPattern->setObjectName("btnSendPattern");
        btnSendPattern->setGeometry(QRect(30, 80, 271, 29));
        spinPatternDelay = new QSpinBox(PatternMode);
        spinPatternDelay->setObjectName("spinPatternDelay");
        spinPatternDelay->setGeometry(QRect(350, 80, 91, 29));
        spinPatternDelay->setMaximum(5000);
        spinPatternDelay->setValue(100);
        spinPatternMaxRow = new QSpinBox(PatternMode);
        spinPatternMaxRow->setObjectName("spinPatternMaxRow");
        spinPatternMaxRow->setGeometry(QRect(460, 80, 101, 29));
        spinPatternMaxRow->setMaximum(10000);
        spinPatternMaxRow->setValue(52);
        tabWidget->addTab(PatternMode, QString());
        tab = new QWidget();
        tab->setObjectName("tab");
        btnStartCalibration = new QPushButton(tab);
        btnStartCalibration->setObjectName("btnStartCalibration");
        btnStartCalibration->setGeometry(QRect(260, 90, 201, 29));
        radioPhase2Tx = new QRadioButton(tab);
        radioPhase2Tx->setObjectName("radioPhase2Tx");
        radioPhase2Tx->setGeometry(QRect(50, 10, 121, 25));
        radioPhase2Rx = new QRadioButton(tab);
        radioPhase2Rx->setObjectName("radioPhase2Rx");
        radioPhase2Rx->setGeometry(QRect(190, 10, 121, 25));
        spinPhase2Pri = new QSpinBox(tab);
        spinPhase2Pri->setObjectName("spinPhase2Pri");
        spinPhase2Pri->setGeometry(QRect(130, 90, 111, 29));
        spinPhase2Pri->setMaximum(5000);
        spinPhase2Pri->setValue(50);
        label_13 = new QLabel(tab);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(30, 90, 101, 21));
        btnStopPhase2 = new QPushButton(tab);
        btnStopPhase2->setObjectName("btnStopPhase2");
        btnStopPhase2->setGeometry(QRect(470, 90, 191, 29));
        progressBarPhase2 = new QProgressBar(tab);
        progressBarPhase2->setObjectName("progressBarPhase2");
        progressBarPhase2->setGeometry(QRect(250, 160, 181, 23));
        progressBarPhase2->setValue(0);
        lblProgressPhase2 = new QLabel(tab);
        lblProgressPhase2->setObjectName("lblProgressPhase2");
        lblProgressPhase2->setGeometry(QRect(130, 160, 101, 20));
        spinPint = new QSpinBox(tab);
        spinPint->setObjectName("spinPint");
        spinPint->setGeometry(QRect(220, 230, 44, 29));
        spinPint->setMaximum(5000);
        spinTrap = new QSpinBox(tab);
        spinTrap->setObjectName("spinTrap");
        spinTrap->setGeometry(QRect(410, 230, 44, 29));
        spinTrap->setMaximum(5000);
        label_14 = new QLabel(tab);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(150, 230, 63, 20));
        label_15 = new QLabel(tab);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(360, 230, 41, 20));
        tabWidget->addTab(tab, QString());
        btnStopAndSave = new QPushButton(centralwidget);
        btnStopAndSave->setObjectName("btnStopAndSave");
        btnStopAndSave->setGeometry(QRect(30, 390, 161, 29));
        consoleTextEdit = new QTextEdit(centralwidget);
        consoleTextEdit->setObjectName("consoleTextEdit");
        consoleTextEdit->setGeometry(QRect(210, 360, 471, 211));
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        editRtcIp->setText(QCoreApplication::translate("MainWindow", "192.168.1.10", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "RTC IP", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "RTC PORT", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "LOCAL PORT", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "RTC", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "AAAU", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "AAAU IP", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "AAAU Rx", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "AAAU Tx", nullptr));
        btnBindRtc->setText(QCoreApplication::translate("MainWindow", "Connect RTC", nullptr));
        btnBindAaau->setText(QCoreApplication::translate("MainWindow", "Bind AAAU", nullptr));
        labelStatusRtc->setText(QCoreApplication::translate("MainWindow", "Disconnected", nullptr));
        labelStatusAaau->setText(QCoreApplication::translate("MainWindow", "Disconnected", nullptr));
        btnStartMock->setText(QCoreApplication::translate("MainWindow", "Start Mock Stream", nullptr));
        btnStopMock->setText(QCoreApplication::translate("MainWindow", "Stop Mock Stream", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Ethernet), QCoreApplication::translate("MainWindow", "Network Configuration", nullptr));
        radioTx->setText(QCoreApplication::translate("MainWindow", "Tx Mode", nullptr));
        radioRx->setText(QCoreApplication::translate("MainWindow", "Rx Mode", nullptr));
        btnSendCalib->setText(QCoreApplication::translate("MainWindow", "Send Calibration", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "m", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "n", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Attenuation", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Phase", nullptr));
        btnSearchRow->setText(QCoreApplication::translate("MainWindow", "Search and Auto-Fill", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Calibration), QCoreApplication::translate("MainWindow", "UDP Calibration", nullptr));
        radioPattTx->setText(QCoreApplication::translate("MainWindow", "Tx Pattern", nullptr));
        radioPattRx->setText(QCoreApplication::translate("MainWindow", "Rx Pattern", nullptr));
        btnSendPattern->setText(QCoreApplication::translate("MainWindow", "Send Pattern Sequence", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(PatternMode), QCoreApplication::translate("MainWindow", "UDP Pattern Sequencer", nullptr));
        btnStartCalibration->setText(QCoreApplication::translate("MainWindow", "Start Calibration Sequence", nullptr));
        radioPhase2Tx->setText(QCoreApplication::translate("MainWindow", "Tx Calibration", nullptr));
        radioPhase2Rx->setText(QCoreApplication::translate("MainWindow", "Rx Calibration", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "PRI/Delay(ms):", nullptr));
        btnStopPhase2->setText(QCoreApplication::translate("MainWindow", "Stop Sequence", nullptr));
        lblProgressPhase2->setText(QCoreApplication::translate("MainWindow", "ROW:0/0", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Pint", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "Trap", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "TCP", nullptr));
        btnStopAndSave->setText(QCoreApplication::translate("MainWindow", "Stop and Save to Excel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
