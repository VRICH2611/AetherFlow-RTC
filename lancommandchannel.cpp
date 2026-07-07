#include "lancommandchannel.h"
#include <QDataStream>
#include <QDebug>
#include <QAbstractSocket>
#include <QRandomGenerator>

LanCommandChannel::LanCommandChannel(QObject *parent) : QObject(parent) {
    m_tcpSocket = new QTcpSocket(this);
    connect(m_tcpSocket, &QTcpSocket::connected, this, &LanCommandChannel::onConnected);
    connect(m_tcpSocket, &QTcpSocket::readyRead, this, &LanCommandChannel::onReadyRead);
    connect(m_tcpSocket, &QTcpSocket::errorOccurred, this, &LanCommandChannel::onSocketError);
}

void LanCommandChannel::connectToRdc(const QString& ipAddress, quint16 port) {
    qDebug() << "Connecting to RDC at" << ipAddress << ":" << port;
    m_tcpSocket->connectToHost(ipAddress, port);
}

void LanCommandChannel::onConnected() {
    emit connectionEstablished();
    sendCheckActivity(); // Immediately send OpCode 10 as per mentor sketch
}

void LanCommandChannel::sendCheckActivity() {
    // Uses the IddProtocol class you already wrote!
    QByteArray packet = IddMessage::pack(IddProtocol::CMD_RTC_AC_CHECK_ACTIVITY);
    m_tcpSocket->write(packet);
    m_tcpSocket->flush();
}

void LanCommandChannel::sendInitRun(const QByteArray& payload) {
    QByteArray packet = IddMessage::pack(IddProtocol::CMD_RTC_AC_INIT_RUN, payload);
    m_tcpSocket->write(packet);
    m_tcpSocket->flush();
}

void LanCommandChannel::onReadyRead() {
    QByteArray data = m_tcpSocket->readAll();

    // Minimal parser to extract the 1-byte OpCode (assuming 3 bytes sync prior)
    // In production, ensure you check the length and sync bytes thoroughly.
    if (data.size() >= 14) {
        quint8 opCode = data.at(3);

        if (opCode == IddProtocol::ANS_AC_RTC_CHECK_ACTIVITY_OK) { // OPCODE 20
            qDebug() << "Activity Check OK received!";
            emit activityCheckPassed();
        }
        else if (opCode == IddProtocol::ANS_AC_RTC_INIT_RUN_OK) { // OPCODE 22
            qDebug() << "Init Run ACK received!";
            emit initRunAckReceived();
        }
    }
}

void LanCommandChannel::onSocketError(QAbstractSocket::SocketError socketError) {
    Q_UNUSED(socketError);
    emit errorOccurred(m_tcpSocket->errorString());
}

void LanCommandChannel::sendStop() {
    // Sends OpCode 14 exactly as your mentor sketched
    QByteArray packet = IddMessage::pack(IddProtocol::CMD_RTC_AC_STOP);
    m_tcpSocket->write(packet);
    m_tcpSocket->flush();
    qDebug() << "EMERGENCY STOP (OpCode 14) Sent!";
}