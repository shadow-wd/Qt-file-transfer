/********************************************************************************
** Form generated from reading UI file 'client.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENT_H
#define UI_CLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Client
{
public:
    QWidget *centralwidget;
    QPushButton *selectFile;
    QTextBrowser *message;
    QTextBrowser *sourcefilepathdisplay;
    QTextBrowser *objectfilepathdisplay;
    QPushButton *objectfolder;
    QPushButton *copybutton;
    QPushButton *clearmessage;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Client)
    {
        if (Client->objectName().isEmpty())
            Client->setObjectName(QString::fromUtf8("Client"));
        Client->resize(653, 559);
        centralwidget = new QWidget(Client);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        selectFile = new QPushButton(centralwidget);
        selectFile->setObjectName(QString::fromUtf8("selectFile"));
        selectFile->setGeometry(QRect(30, 390, 75, 23));
        message = new QTextBrowser(centralwidget);
        message->setObjectName(QString::fromUtf8("message"));
        message->setGeometry(QRect(10, 40, 621, 231));
        sourcefilepathdisplay = new QTextBrowser(centralwidget);
        sourcefilepathdisplay->setObjectName(QString::fromUtf8("sourcefilepathdisplay"));
        sourcefilepathdisplay->setGeometry(QRect(10, 320, 261, 41));
        objectfilepathdisplay = new QTextBrowser(centralwidget);
        objectfilepathdisplay->setObjectName(QString::fromUtf8("objectfilepathdisplay"));
        objectfilepathdisplay->setGeometry(QRect(370, 320, 261, 41));
        objectfolder = new QPushButton(centralwidget);
        objectfolder->setObjectName(QString::fromUtf8("objectfolder"));
        objectfolder->setGeometry(QRect(470, 400, 91, 23));
        copybutton = new QPushButton(centralwidget);
        copybutton->setObjectName(QString::fromUtf8("copybutton"));
        copybutton->setGeometry(QRect(270, 460, 75, 23));
        clearmessage = new QPushButton(centralwidget);
        clearmessage->setObjectName(QString::fromUtf8("clearmessage"));
        clearmessage->setGeometry(QRect(534, 280, 91, 23));
        Client->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Client);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 653, 23));
        Client->setMenuBar(menubar);
        statusbar = new QStatusBar(Client);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Client->setStatusBar(statusbar);

        retranslateUi(Client);

        QMetaObject::connectSlotsByName(Client);
    } // setupUi

    void retranslateUi(QMainWindow *Client)
    {
        Client->setWindowTitle(QCoreApplication::translate("Client", "MainWindow", nullptr));
        selectFile->setText(QCoreApplication::translate("Client", "select file", nullptr));
        objectfolder->setText(QCoreApplication::translate("Client", "object folder", nullptr));
        copybutton->setText(QCoreApplication::translate("Client", "copy", nullptr));
        clearmessage->setText(QCoreApplication::translate("Client", "clear message", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Client: public Ui_Client {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENT_H
