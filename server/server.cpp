#include "server.h"

#include <QDir>

Server::Server()
{
    if (this->listen(QHostAddress::Any, 3000)) {
        qDebug() << " * Server has started * ";
    } else {
        qDebug() << " ** Server error ** ";
    }
    nextBlockSize = 0;
    img_count = 0;
    lastSymbolPlace = 0;
}

void Server::incomingConnection(qintptr socketDescriptor) {
    socket = new QTcpSocket;
    socket->setSocketDescriptor(socketDescriptor);
    connect(socket, &QTcpSocket::readyRead, this, &Server::slot_readyRead);
    connect(socket, &QTcpSocket::disconnected, this, &Server::deleteLater);

    sockets.append(socket);
    qDebug() << " * Client has connected * " << socketDescriptor;
}

void Server::slot_readyRead() {
    socket = (QTcpSocket*)sender();
    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_5_11);

    if (in.status() == QDataStream::Ok) {
        qDebug() << " * Reading... * ";
        while (true) {
            if (nextBlockSize == 0) {
                qDebug() << " * nextBlockSize = 0 * ";
                if (socket->bytesAvailable() < 2) {
                    qDebug() << " * Data < 2 * ";
                    break;
                }
                in >> nextBlockSize;
                qDebug() << " * nextBlockSize = " << nextBlockSize << " * ";
            }

            if (socket->bytesAvailable() < nextBlockSize) {
                qDebug() << " * data is not full, break.. * ";
                break;
            }

            QString str;
            QString msg;
            QTime time;
            QByteArray ba;
            QString username;
            QString recipient;
            QString newStr;
            in >> username >> ba; // was str
            QImage newImg;
            QBuffer buf(&ba);
            QImage img;

            QByteArray pData;


            int factor = 2;
            int usersCount = sockets.size();

            if (username[0] == '@') {

                img_buf.setBuffer(&img_ba);
                int i = 0;
                for (i = lastSymbolPlace; i < ba.size() / usersCount; ++i) {
                    img_ba += ba;
                }
                lastSymbolPlace = i;
                ++img_count;

                qDebug() << username << " : " << img_count << " | " << usersCount;

                if (img_count == usersCount) {


                    if (img.loadFromData(ba)) {
                        qDebug() << "* Image has loaded from buffer of byte array! *";
                    } else {
                        qDebug() << "** Image has not loaded! **";
                    }

                    int w = img.width();
                    int h = img.height();
                    newImg = QImage(w / factor, h / factor, QImage::Format_RGB32);

                    for (int x = 0, _x = 0; x < w; x += factor, ++_x) {
                        for (int y = 0, _y = 0; y < h; y += factor, ++_y) {
                            QRgb pixel = img.pixel(x, y);
                            newImg.setPixel(_x, _y, pixel);
                        }
                    }

                    QBuffer pBuffer(&pData);
                    pBuffer.open(QIODevice::WriteOnly);
                    newImg.save("E:/nubostyle/server/newImg.JPEG", "JPEG");
                }
            }

            bool whoTo = false;
            bool isMsg = false;
            int j = 0;
            for (int i = 0; i < str.length(); ++i) {
                if (str[i] == "<" || str[i] == ">") {
                    whoTo = !whoTo;
                    if (!whoTo) {
                        isMsg = true;
                        j = 0;
                    }
                    continue;
                }
                if (whoTo) {
                    recipient[j++] = str[i];
                }

                if (isMsg) {
                    msg[j++] = str[i];
                }
            }

            bool userExist = false;
            for (int i = 0; i < users.size(); ++i) {
                if (users[i] == username) {
                    userExist = true;
                }
            }

            if (!userExist) {
                users.append(username);
            }

            nextBlockSize = 0;

            if (recipient != "") {
                qDebug() << " * From: " << username << " [" << time.currentTime().toString()
                         << "] : " << msg << " | To : " << recipient << " *\n" << newStr;
                sendToClient(username, recipient, msg, pData);
            } else {
                qDebug() << " * From: " << username << " [" << time.currentTime().toString()
                         << "] : " << "" << " * ";
                sendToClient(username, "", str, "");
            }

            break;
        }
    } else {
        qDebug() << " ** DataStream error ** ";
    }
}

void Server::sendToClient(QString username, QString rec, QString str, QByteArray ba) {
    data.clear();
    QDataStream out(&data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_11);
    out << quint16(0) << username << QTime::currentTime().toString() << str << ba;
    out.device()->seek(0);
    out << quint16(data.size() - sizeof(quint16));

    if (rec != "") {
        int counter = 0;
        for (int i = 0; i < users.size(); ++i) {
            if (users[i] == username || users[i] == rec) {
                sockets[i]->write(data);
                ++counter;
            }
            if (counter == 2) break;
        }
    } else {
        for (int i = 0; i < sockets.size(); ++i) {
            sockets[i]->write(data);
        }
    }
}
