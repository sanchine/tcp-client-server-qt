#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "authorizewindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    socket = new QTcpSocket(this);
    connect(socket, &QTcpSocket::readyRead, this, &MainWindow::slot_readyRead);
    connect(socket, &QTcpSocket::disconnected, this, &MainWindow::deleteLater);
    connect(&ui_auth, SIGNAL(join_button_clicked()), this, SLOT(authorizeUser()));
    nextBlockSize = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::display() {
    ui_auth.show();
}

void MainWindow::authorizeUser() {
    m_username = ui_auth.getUsername();
    ui_auth.close();
    socket->connectToHost("127.0.0.1", 3000);
    this->show();
    ui->usernameLabel->setText("Your name: " + m_username);
}

void MainWindow::sendToServer(QString str)
{
    data.clear();
    QDataStream out(&data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_11);
    if (!imageFilePath.isEmpty()) {
        QPixmap p(imageFilePath);
        QByteArray pData = QByteArray();
        QBuffer pBuffer(&pData);
        pBuffer.open(QIODevice::WriteOnly);
        p.save(&pBuffer, "PNG", 0);
        out << quint16(0) << m_username << pData;
    } else {
        out << quint16(0) << m_username << str;
    }
    out.device()->seek(0);
    out << quint16(data.size() - sizeof(quint16));
    socket->write(data);
    ui->lineEdit->clear();
}

void MainWindow::slot_readyRead() {
    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_5_11);

    if (in.status() == QDataStream::Ok) {
        while (true) {
            if (nextBlockSize == 0) {
                if (socket->bytesAvailable() < 2) {
                    break;
                }
                in >> nextBlockSize;
            }

            if (socket->bytesAvailable() < nextBlockSize) {
                break;
            }
            QString str;
            QString time;
            QString username;
            QByteArray ba;
            QBuffer buf(&ba);
            buf.open(QIODevice::WriteOnly);
            in >> username >> time >> str >> ba;

            nextBlockSize = 0;
            ui->textBrowser->append(username + " [" + time + "] : " + str);
            QPixmap mpixmap;
            mpixmap.loadFromData("../server/newImg.JPEG");
            mpixmap.loadFromData(ba);
            mpixmap.save("11.JPEG", "JPEG");
            //ui->imageLabel->setPixmap(mpixmap);
            //ui->imageLabel->setScaledContents(true);
        }
    } else {
        ui->textBrowser->append("read error");
    }
}


void MainWindow::on_sendButton_clicked()
{
    sendToServer(ui->lineEdit->text());
}


void MainWindow::on_lineEdit_returnPressed()
{
    sendToServer(ui->lineEdit->text());
}


void MainWindow::on_pushButton_clicked()
{
    imageFilePath = QFileDialog::getOpenFileName(this, "Open a file", "../server/", "PNG Image (*.PNG);;jpg Image (*.jpg);");
    qDebug() << imageFilePath;
}

