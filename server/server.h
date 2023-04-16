#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QVector>
#include <QPixmap>
#include <QDataStream>
#include <QTime>
#include <QBuffer>
#include <QGuiApplication>
#include "users.h"

class Server : public QTcpServer
{
    Q_OBJECT

public:
    Server();
    QTcpSocket *socket;

    QByteArray img_ba;
    QBuffer img_buf;
    int img_count;
    int lastSymbolPlace;

private:
    QVector <Users> m_users;
    QVector <QTcpSocket * > sockets;
    QVector <QString> users;
    QByteArray data;
    quint16 nextBlockSize;
    void sendToClient(QString username, QString rec, QString str, QByteArray ba);

private slots:
    void incomingConnection(qintptr socketDescriptor);
    void slot_readyRead();
};

#endif // SERVER_H
