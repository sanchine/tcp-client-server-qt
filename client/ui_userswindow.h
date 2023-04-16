/********************************************************************************
** Form generated from reading UI file 'userswindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERSWINDOW_H
#define UI_USERSWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_userswindow
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *userswindow)
    {
        if (userswindow->objectName().isEmpty())
            userswindow->setObjectName(QString::fromUtf8("userswindow"));
        userswindow->resize(401, 774);
        centralwidget = new QWidget(userswindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(20, 20, 361, 711));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(170, 0, 61, 16));
        userswindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(userswindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 401, 20));
        userswindow->setMenuBar(menubar);
        statusbar = new QStatusBar(userswindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        userswindow->setStatusBar(statusbar);

        retranslateUi(userswindow);

        QMetaObject::connectSlotsByName(userswindow);
    } // setupUi

    void retranslateUi(QMainWindow *userswindow)
    {
        userswindow->setWindowTitle(QApplication::translate("userswindow", "MainWindow", nullptr));
        label->setText(QApplication::translate("userswindow", "UsersOnline", nullptr));
    } // retranslateUi

};

namespace Ui {
    class userswindow: public Ui_userswindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERSWINDOW_H
