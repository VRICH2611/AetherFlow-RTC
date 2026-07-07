QT       += core gui network widgets

TARGET = AetherFlow-RTC
TEMPLATE = app
CONFIG += c++17

# Source Files
SOURCES += \
    calibrationdataparser.cpp \
    iddprotocol.cpp \
    lancommandchannel.cpp \
    main.cpp \
    mainwindow.cpp \
    radarworker.cpp \
    runstagesequencer.cpp

# Header Files
HEADERS += \
    calibrationdataparser.h \
    iddprotocol.h \
    lancommandchannel.h \
    mainwindow.h \
    radarworker.h \
    runstagesequencer.h

# UI Files
FORMS += \
    mainwindow.ui
