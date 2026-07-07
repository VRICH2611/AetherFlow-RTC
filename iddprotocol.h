#ifndef IDDPROTOCOL_H
#define IDDPROTOCOL_H

#include <QByteArray>
#include <QDataStream>

class IddProtocol {
public:
    // RTC (Master) to AC (Slave) Commands
    enum RtcCommand {
        CMD_RTC_AC_CHECK_ACTIVITY = 10,
        CMD_RTC_AC_INIT_RUN = 11,
        CMD_RTC_AC_END_OF_RAY = 12,
        CMD_RTC_AC_NACK = 13,
        CMD_RTC_AC_STOP = 14
    };

    // AC (Slave) to RTC (Master) Answers
    enum AcAnswer {
        ANS_AC_RTC_CHECK_ACTIVITY_OK = 20,
        ANS_AC_RTC_CHECK_ACTIVITY_FAILED = 21,
        ANS_AC_RTC_INIT_RUN_OK = 22,
        ANS_AC_RTC_INIT_RUN_FAILED = 23,
        ANS_AC_RTC_END_OF_RAY_OK = 24,
        ANS_AC_RTC_END_OF_RAY_FAILED = 25,
        ANS_AC_RTC_STOP_OK = 26,
        ANS_AC_RTC_NACK = 27
    };
};

class IddMessage {
public:
    // Wraps any payload in the strict 14-byte IDD TCP frame
    static QByteArray pack(quint8 opCode, const QByteArray& payload = QByteArray());
private:
    static quint32 messageCounter;
};

class InitRunPayload {
public:
    // Builds the specific data block for the INIT_RUN command
    static QByteArray build(qint32 subRays, qint32 mode, qint32 subMode, qint32 acType, qint32 elementI, qint32 elementJ);
};

#endif // IDDPROTOCOL_H