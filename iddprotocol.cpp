#include "iddprotocol.h"
#include <QtEndian>
#include <QIODevice>

quint32 IddMessage::messageCounter = 1;

QByteArray IddMessage::pack(quint8 opCode, const QByteArray& payload) {
    QByteArray packet;
    QDataStream stream(&packet, QIODevice::WriteOnly);
    stream.setByteOrder(QDataStream::LittleEndian); // STRICT IDD REQUIREMENT

    // 1. SYNCS (3 bytes)
    stream << (quint8)0xAA << (quint8)0xAA << (quint8)0xAA;

    // 2. OPCODE (1 byte)
    stream << opCode;

    // 3. LENGTH (2 bytes) - Total size = 14 wrapper bytes + payload size
    quint16 totalLength = 14 + payload.size();
    stream << totalLength;

    // 4. MSG_NUM & 5. NUM_MSGS (1 byte each)
    stream << (quint8)0x01 << (quint8)0x01;

    // 6. COUNTER (4 bytes)
    stream << messageCounter++;

    // 7. DATA (n bytes)
    if (!payload.isEmpty()) {
        stream.writeRawData(payload.constData(), payload.size());
    }

    // 8. CHECKSUM (2 bytes padding)
    stream << (quint16)0x0000;

    return packet;
}

QByteArray InitRunPayload::build(qint32 subRays, qint32 mode, qint32 subMode, qint32 acType, qint32 elementI, qint32 elementJ) {
    QByteArray payload;
    QDataStream stream(&payload, QIODevice::WriteOnly);
    stream.setByteOrder(QDataStream::LittleEndian);

    // Pack the integers exactly as defined in the IDD Table 3
    stream << subRays;
    stream << mode;
    stream << subMode;
    stream << acType;
    stream << (qint32)0; // Spare 1
    stream << (qint32)0; // Spare 2
    stream << (qint32)1000; // PRI (microseconds)
    stream << (qint32)50;   // Pulse Width (microseconds)
    stream << elementJ;
    stream << elementI;
    stream << (qint32)1; // Number of nested loops
    stream << (qint32)1; // Number of iterations

    // Example of adding the raw string loop description as requested by IDD
    QString loopDesc = "@Freqs,2000000000@";
    stream.writeRawData(loopDesc.toUtf8().constData(), loopDesc.toUtf8().size());

    return payload;
}