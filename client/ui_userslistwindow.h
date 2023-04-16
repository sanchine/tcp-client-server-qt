/********************************************************************************
** Form generated from reading UI file 'userslistwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERSLISTWINDOW_H
#define UI_USERSLISTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UsersListWindow
{
public:
    QMenuBar *menubar;
    QWidget *centralwidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *UsersListWindow)
    {
        if (UsersListWindow->objectName().isEmpty())
            UsersListWindow->setObjectName(QString::fromUtf8("UsersListWindow"));
        UsersListWindow->resize(800, 600);
        menubar = new QMenuBar(UsersListWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        UsersListWindow->setMenuBar(menubar);
        centralwidget = new QWidget(UsersListWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        UsersListWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(UsersListWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        UsersListWindow->setStatusBar(statusbar);

        retranslateUi(UsersListWindow);

        QMetaObject::connectSlotsByName(UsersListWindow);
    } // setupUi

    void retranslateUi(QMainWindow *UsersListWindow)
    {
        UsersListWindow->setWindowTitle(QApplication::translate("UsersListWindow", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UsersListWindow: public Ui_UsersListWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERSLISTWINDOW_H
