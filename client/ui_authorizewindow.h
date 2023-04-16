/********************************************************************************
** Form generated from reading UI file 'authorizewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTHORIZEWINDOW_H
#define UI_AUTHORIZEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_authorizeWindow
{
public:
    QWidget *centralwidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *nameLabel;
    QLabel *presentLabel;
    QPushButton *enterButton;
    QLineEdit *nameLineEdit;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *authorizeWindow)
    {
        if (authorizeWindow->objectName().isEmpty())
            authorizeWindow->setObjectName(QStringLiteral("authorizeWindow"));
        authorizeWindow->resize(380, 113);
        centralwidget = new QWidget(authorizeWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 10, 361, 72));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        nameLabel = new QLabel(gridLayoutWidget);
        nameLabel->setObjectName(QStringLiteral("nameLabel"));

        gridLayout->addWidget(nameLabel, 1, 0, 1, 1);

        presentLabel = new QLabel(gridLayoutWidget);
        presentLabel->setObjectName(QStringLiteral("presentLabel"));
        presentLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(presentLabel, 0, 1, 1, 1);

        enterButton = new QPushButton(gridLayoutWidget);
        enterButton->setObjectName(QStringLiteral("enterButton"));
        enterButton->setStyleSheet(QStringLiteral(""));

        gridLayout->addWidget(enterButton, 2, 1, 1, 1);

        nameLineEdit = new QLineEdit(gridLayoutWidget);
        nameLineEdit->setObjectName(QStringLiteral("nameLineEdit"));

        gridLayout->addWidget(nameLineEdit, 1, 1, 1, 1);

        authorizeWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(authorizeWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        authorizeWindow->setStatusBar(statusbar);

        retranslateUi(authorizeWindow);

        QMetaObject::connectSlotsByName(authorizeWindow);
    } // setupUi

    void retranslateUi(QMainWindow *authorizeWindow)
    {
        authorizeWindow->setWindowTitle(QApplication::translate("authorizeWindow", "MainWindow", nullptr));
        nameLabel->setText(QApplication::translate("authorizeWindow", "Enter your name:", nullptr));
        presentLabel->setText(QApplication::translate("authorizeWindow", "KV CHAT", nullptr));
        enterButton->setText(QApplication::translate("authorizeWindow", "Join", nullptr));
    } // retranslateUi

};

namespace Ui {
    class authorizeWindow: public Ui_authorizeWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTHORIZEWINDOW_H
