#ifndef LANCOMMANDCHANNEL_H
#define LANCOMMANDCHANNEL_H

#include <QObject>
#include <QTcpSocket>
#include <QByteArray>
#include "iddprotocol.h" // Your existing Phase 2 protocol class

class LanCommandChannel : public QObject {
    Q_OBJECT
public:
    explicit LanCommandChannel(QObject *parent = nullptr);
    void connectToRdc(const QString& ipAddress, quint16 port = 5001);
    void sendInitRun(const QByteArray& payload);
    void sendStop();

signals:
    void connectionEstablished();
    void activityCheckPassed();   // Emitted when we get OPCODE 20
    void initRunAckReceived();    // Emitted when we get OPCODE 22
    void errorOccurred(QString errorMsg);

private slots:
    void onConnected();
    void onReadyRead();
    void onSocketError(QAbstractSocket::SocketError socketError);

private:
    QTcpSocket* m_tcpSocket;
    void sendCheckActivity();
};

#endif // LANCOMMANDCHANNEL_H