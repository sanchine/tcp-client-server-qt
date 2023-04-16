#ifndef USERS_H
#define USERS_H

#include <QTcpSocket>
#include <QVector>

class Users
{
public:
    Users();
    QTcpSocket * socket;
    QString name;
};

#endif // USERS_H
