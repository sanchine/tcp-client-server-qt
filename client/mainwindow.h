#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QTime>
#include <QPixmap>
#include <QBuffer>
#include <QFileDialog>

#include "authorizewindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void display();

//private slots:
//    void on_connectButton_clicked();

private:
    Ui::MainWindow * ui;
    authorizeWindow ui_auth;

    QString m_username;

    QTcpSocket * socket;
    QByteArray data;
    QString imageFilePath;
    quint16 nextBlockSize;

    void sendToServer(QString str);
    void sendToServer(QBuffer buf);

private slots:
    void authorizeUser();

    void slot_readyRead();
    void on_sendButton_clicked();
    void on_lineEdit_returnPressed();
    void on_pushButton_clicked();
};
#endif // MAINWINDOW_H
