#include "authorizewindow.h"
#include "ui_authorizewindow.h"

authorizeWindow::authorizeWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::authorizeWindow)
{
    ui->setupUi(this);
}

authorizeWindow::~authorizeWindow()
{
    delete ui;
}

QString authorizeWindow::getUsername()
{
    return m_username;
}

void authorizeWindow::on_enterButton_clicked()
{
    emit join_button_clicked();
}

void authorizeWindow::on_nameLineEdit_textEdited(const QString &arg1)
{
    m_username = arg1;
}

