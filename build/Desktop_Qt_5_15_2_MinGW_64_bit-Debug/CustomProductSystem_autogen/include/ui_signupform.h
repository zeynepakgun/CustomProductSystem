/********************************************************************************
** Form generated from reading UI file 'signupform.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNUPFORM_H
#define UI_SIGNUPFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SignUpForm
{
public:
    QLineEdit *enterName;
    QLineEdit *enterSurname;
    QLineEdit *enterNumberPlate;
    QLineEdit *enterPhoneNumber;
    QLineEdit *enterPasswordSignUp;
    QLineEdit *enterPasswordConfirm;
    QPushButton *signUpButton;
    QPushButton *eyeButtonSignUp;
    QLineEdit *enterBalance;
    QPushButton *backButton;
    QWidget *widget;

    void setupUi(QWidget *SignUpForm)
    {
        if (SignUpForm->objectName().isEmpty())
            SignUpForm->setObjectName(QString::fromUtf8("SignUpForm"));
        SignUpForm->resize(593, 441);
        SignUpForm->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        enterName = new QLineEdit(SignUpForm);
        enterName->setObjectName(QString::fromUtf8("enterName"));
        enterName->setGeometry(QRect(230, 80, 131, 31));
        enterName->setStyleSheet(QString::fromUtf8("border-radius: 10px;  \n"
"border: 1px solid #afaaa3;  \n"
"background-color: rgb(255, 255, 255);\n"
""));
        enterSurname = new QLineEdit(SignUpForm);
        enterSurname->setObjectName(QString::fromUtf8("enterSurname"));
        enterSurname->setGeometry(QRect(230, 120, 131, 31));
        enterSurname->setStyleSheet(QString::fromUtf8("border-radius: 10px;  \n"
"border: 1px solid #afaaa3;  \n"
"background-color: rgb(255, 255, 255);"));
        enterNumberPlate = new QLineEdit(SignUpForm);
        enterNumberPlate->setObjectName(QString::fromUtf8("enterNumberPlate"));
        enterNumberPlate->setGeometry(QRect(230, 160, 131, 31));
        enterNumberPlate->setStyleSheet(QString::fromUtf8("border-radius: 10px;  \n"
"border: 1px solid #afaaa3;  \n"
"background-color: rgb(255, 255, 255);"));
        enterPhoneNumber = new QLineEdit(SignUpForm);
        enterPhoneNumber->setObjectName(QString::fromUtf8("enterPhoneNumber"));
        enterPhoneNumber->setGeometry(QRect(230, 200, 131, 31));
        enterPhoneNumber->setStyleSheet(QString::fromUtf8("border-radius: 10px;  \n"
"border: 1px solid #afaaa3;  \n"
"background-color: rgb(255, 255, 255);"));
        enterPasswordSignUp = new QLineEdit(SignUpForm);
        enterPasswordSignUp->setObjectName(QString::fromUtf8("enterPasswordSignUp"));
        enterPasswordSignUp->setGeometry(QRect(230, 240, 131, 31));
        enterPasswordSignUp->setStyleSheet(QString::fromUtf8("border-radius: 10px;  \n"
"border: 1px solid #afaaa3;  \n"
"background-color: rgb(255, 255, 255);"));
        enterPasswordConfirm = new QLineEdit(SignUpForm);
        enterPasswordConfirm->setObjectName(QString::fromUtf8("enterPasswordConfirm"));
        enterPasswordConfirm->setGeometry(QRect(230, 280, 131, 31));
        enterPasswordConfirm->setStyleSheet(QString::fromUtf8("border-radius: 10px;  \n"
"border: 1px solid #afaaa3;  \n"
"background-color: rgb(255, 255, 255);\n"
""));
        signUpButton = new QPushButton(SignUpForm);
        signUpButton->setObjectName(QString::fromUtf8("signUpButton"));
        signUpButton->setGeometry(QRect(250, 330, 75, 24));
        signUpButton->setStyleSheet(QString::fromUtf8("border-radius: 10px;  \n"
"border: 1px solid #afaaa3;  \n"
"background-color: rgb(252, 252, 252);\n"
""));
        eyeButtonSignUp = new QPushButton(SignUpForm);
        eyeButtonSignUp->setObjectName(QString::fromUtf8("eyeButtonSignUp"));
        eyeButtonSignUp->setGeometry(QRect(370, 280, 21, 24));
        eyeButtonSignUp->setIconSize(QSize(24, 24));
        enterBalance = new QLineEdit(SignUpForm);
        enterBalance->setObjectName(QString::fromUtf8("enterBalance"));
        enterBalance->setGeometry(QRect(230, 40, 131, 31));
        enterBalance->setStyleSheet(QString::fromUtf8("border-radius: 10px;  \n"
"border: 1px solid #afaaa3;  \n"
"background-color: rgb(255, 255, 255);"));
        backButton = new QPushButton(SignUpForm);
        backButton->setObjectName(QString::fromUtf8("backButton"));
        backButton->setGeometry(QRect(30, 20, 21, 21));
        widget = new QWidget(SignUpForm);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(460, 10, 121, 81));
        widget->setStyleSheet(QString::fromUtf8("image: url(:/icons/icons/logo2.jpeg);"));

        retranslateUi(SignUpForm);

        QMetaObject::connectSlotsByName(SignUpForm);
    } // setupUi

    void retranslateUi(QWidget *SignUpForm)
    {
        SignUpForm->setWindowTitle(QCoreApplication::translate("SignUpForm", "Form", nullptr));
        enterName->setPlaceholderText(QCoreApplication::translate("SignUpForm", "\304\260sminizi giriniz", nullptr));
        enterSurname->setText(QString());
        enterSurname->setPlaceholderText(QCoreApplication::translate("SignUpForm", "Soyad\304\261n\304\261z\304\261 giriniz", nullptr));
        enterNumberPlate->setPlaceholderText(QCoreApplication::translate("SignUpForm", "Plakan\304\261z\304\261 giriniz", nullptr));
        enterPhoneNumber->setPlaceholderText(QCoreApplication::translate("SignUpForm", "Telefonunuzu giriniz ", nullptr));
        enterPasswordSignUp->setText(QString());
        enterPasswordSignUp->setPlaceholderText(QCoreApplication::translate("SignUpForm", "\305\236ifrenizi giriniz", nullptr));
        enterPasswordConfirm->setText(QString());
        enterPasswordConfirm->setPlaceholderText(QCoreApplication::translate("SignUpForm", "\305\236ifrenizi do\304\237rulay\304\261n\304\261z", nullptr));
        signUpButton->setText(QCoreApplication::translate("SignUpForm", "Kay\304\261t ol!", nullptr));
        eyeButtonSignUp->setText(QString());
        enterBalance->setPlaceholderText(QCoreApplication::translate("SignUpForm", "Bakiyenizi Giriniz", nullptr));
        backButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SignUpForm: public Ui_SignUpForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNUPFORM_H
