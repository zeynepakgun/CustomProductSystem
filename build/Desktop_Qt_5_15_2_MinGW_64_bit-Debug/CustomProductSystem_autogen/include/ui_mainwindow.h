/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLineEdit *enterNumberPlate;
    QLineEdit *enterPassword;
    QPushButton *login;
    QPushButton *signUp;
    QPushButton *eyeButton;
    QWidget *widget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(593, 441);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(180, 160, 201, 16));
        QFont font;
        font.setBold(true);
        label->setFont(font);
        label->setAutoFillBackground(false);
        enterNumberPlate = new QLineEdit(centralwidget);
        enterNumberPlate->setObjectName(QString::fromUtf8("enterNumberPlate"));
        enterNumberPlate->setGeometry(QRect(180, 200, 191, 22));
        enterNumberPlate->setMinimumSize(QSize(0, 22));
        enterNumberPlate->setMaximumSize(QSize(191, 22));
        enterNumberPlate->setStyleSheet(QString::fromUtf8("border-radius: 11px;  \n"
"background-color: rgb(255, 255, 255);\n"
"border: 1px solid #afaaa3;  \n"
"\n"
""));
        enterPassword = new QLineEdit(centralwidget);
        enterPassword->setObjectName(QString::fromUtf8("enterPassword"));
        enterPassword->setGeometry(QRect(180, 240, 191, 22));
        enterPassword->setStyleSheet(QString::fromUtf8("border-radius: 10px;  \n"
"border: 1px solid #afaaa3;  "));
        login = new QPushButton(centralwidget);
        login->setObjectName(QString::fromUtf8("login"));
        login->setGeometry(QRect(240, 290, 75, 24));
        login->setStyleSheet(QString::fromUtf8("border-radius: 10px;  \n"
"border: 1px solid #afaaa3;  "));
        signUp = new QPushButton(centralwidget);
        signUp->setObjectName(QString::fromUtf8("signUp"));
        signUp->setGeometry(QRect(300, 330, 71, 24));
        signUp->setStyleSheet(QString::fromUtf8("border-radius: 10px;  \n"
"border: 1px solid #afaaa3;  "));
        eyeButton = new QPushButton(centralwidget);
        eyeButton->setObjectName(QString::fromUtf8("eyeButton"));
        eyeButton->setGeometry(QRect(380, 240, 21, 21));
        eyeButton->setIconSize(QSize(24, 24));
        eyeButton->setCheckable(true);
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(200, 10, 161, 111));
        widget->setStyleSheet(QString::fromUtf8("image: url(:/icons/icons/logo2.jpeg);"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 593, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "M\303\274\305\237teri Giri\305\237 ve \303\234r\303\274n Se\303\247im Sistemi", nullptr));
        enterNumberPlate->setText(QString());
        enterNumberPlate->setPlaceholderText(QCoreApplication::translate("MainWindow", "Plakan\304\261z\304\261 giriniz", nullptr));
        enterPassword->setText(QString());
        enterPassword->setPlaceholderText(QCoreApplication::translate("MainWindow", "\305\236ifrenizi giriniz", nullptr));
        login->setText(QCoreApplication::translate("MainWindow", "Giri\305\237 Yap", nullptr));
        signUp->setText(QCoreApplication::translate("MainWindow", "Kay\304\261t Ol", nullptr));
        eyeButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
