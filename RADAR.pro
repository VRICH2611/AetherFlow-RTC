QT += core gui network
QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    calibrationdataparser.cpp \
    iddprotocol.cpp \
    lancommandchannel.cpp \
    main.cpp \
    mainwindow.cpp \
    radarworker.cpp \
    runstagesequencer.cpp

HEADERS += \
    calibrationdataparser.h \
    iddprotocol.h \
    lancommandchannel.h \
    mainwindow.h \
    radarworker.h \
    runstagesequencer.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
include(QXlsx/QXlsx.pri)
