#ifndef AUTHORIZEWINDOW_H
#define AUTHORIZEWINDOW_H

#include <QMainWindow>

namespace Ui {
class authorizeWindow;
}

class authorizeWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit authorizeWindow(QWidget *parent = nullptr);
    ~authorizeWindow();
    QString getUsername();

signals:
    void join_button_clicked();

private slots:
    void on_enterButton_clicked();
    void on_nameLineEdit_textEdited(const QString &arg1);

private:
    Ui::authorizeWindow *ui;
    QString m_username;
};

#endif // AUTHORIZEWINDOW_H
