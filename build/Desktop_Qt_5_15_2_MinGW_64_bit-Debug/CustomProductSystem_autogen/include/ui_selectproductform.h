/********************************************************************************
** Form generated from reading UI file 'selectproductform.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECTPRODUCTFORM_H
#define UI_SELECTPRODUCTFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SelectProductForm
{
public:
    QComboBox *productComboBox;
    QLabel *productNameLabel;
    QPushButton *startProductButton;
    QProgressBar *progressBar;
    QLineEdit *lineEdit;
    QLabel *loadBalanceStatusLabel;
    QPushButton *loadBalanceButton;
    QWidget *widget;

    void setupUi(QWidget *SelectProductForm)
    {
        if (SelectProductForm->objectName().isEmpty())
            SelectProductForm->setObjectName(QString::fromUtf8("SelectProductForm"));
        SelectProductForm->resize(593, 441);
        SelectProductForm->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(255, 255, 255);\n"
""));
        productComboBox = new QComboBox(SelectProductForm);
        productComboBox->setObjectName(QString::fromUtf8("productComboBox"));
        productComboBox->setGeometry(QRect(210, 70, 141, 22));
        productComboBox->setStyleSheet(QString::fromUtf8("border-radius: 10px;  \n"
"border: 1px solid #afaaa3;  \n"
"background-color: rgb(252, 252, 252);"));
        productComboBox->setPlaceholderText(QString::fromUtf8("\303\234r\303\274n Se\303\247iniz"));
        productNameLabel = new QLabel(SelectProductForm);
        productNameLabel->setObjectName(QString::fromUtf8("productNameLabel"));
        productNameLabel->setGeometry(QRect(220, 100, 131, 31));
        productNameLabel->setStyleSheet(QString::fromUtf8("border-radius: 11px;  \n"
"background-color: rgb(255, 255, 255);\n"
"border: 1px solid #afaaa3;  "));
        productNameLabel->setFrameShape(QFrame::Box);
        productNameLabel->setFrameShadow(QFrame::Plain);
        startProductButton = new QPushButton(SelectProductForm);
        startProductButton->setObjectName(QString::fromUtf8("startProductButton"));
        startProductButton->setGeometry(QRect(250, 150, 61, 24));
        startProductButton->setStyleSheet(QString::fromUtf8("border-radius: 10px;  \n"
"border: 1px solid #afaaa3;  \n"
"background-color: rgb(252, 252, 252);"));
        progressBar = new QProgressBar(SelectProductForm);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(190, 190, 191, 21));
        progressBar->setStyleSheet(QString::fromUtf8("border-radius: 10px;  \n"
"border: 1px solid #afaaa3;  \n"
"background-color: rgb(252, 252, 252);"));
        progressBar->setValue(24);
        lineEdit = new QLineEdit(SelectProductForm);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(410, 300, 113, 22));
        lineEdit->setStyleSheet(QString::fromUtf8("border-radius: 10px;  \n"
"border: 1px solid #afaaa3;  \n"
"background-color: rgb(252, 252, 252);"));
        loadBalanceStatusLabel = new QLabel(SelectProductForm);
        loadBalanceStatusLabel->setObjectName(QString::fromUtf8("loadBalanceStatusLabel"));
        loadBalanceStatusLabel->setGeometry(QRect(370, 360, 191, 21));
        loadBalanceStatusLabel->setStyleSheet(QString::fromUtf8("border-radius: 10px;  \n"
"border: 1px solid #afaaa3;  \n"
"background-color: rgb(252, 252, 252);"));
        loadBalanceStatusLabel->setFrameShape(QFrame::Box);
        loadBalanceButton = new QPushButton(SelectProductForm);
        loadBalanceButton->setObjectName(QString::fromUtf8("loadBalanceButton"));
        loadBalanceButton->setGeometry(QRect(450, 330, 41, 24));
        loadBalanceButton->setStyleSheet(QString::fromUtf8("border-radius: 10px;  \n"
"border: 1px solid #afaaa3;  \n"
"background-color: rgb(252, 252, 252);"));
        widget = new QWidget(SelectProductForm);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(459, 10, 121, 81));
        widget->setStyleSheet(QString::fromUtf8("image: url(:/icons/icons/logo2.jpeg);"));

        retranslateUi(SelectProductForm);

        QMetaObject::connectSlotsByName(SelectProductForm);
    } // setupUi

    void retranslateUi(QWidget *SelectProductForm)
    {
        SelectProductForm->setWindowTitle(QCoreApplication::translate("SelectProductForm", "Form", nullptr));
        productNameLabel->setText(QString());
        startProductButton->setText(QCoreApplication::translate("SelectProductForm", "SE\303\207", nullptr));
        lineEdit->setPlaceholderText(QCoreApplication::translate("SelectProductForm", "Bakiye Y\303\274kleyiniz!", nullptr));
        loadBalanceStatusLabel->setText(QString());
        loadBalanceButton->setText(QCoreApplication::translate("SelectProductForm", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SelectProductForm: public Ui_SelectProductForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECTPRODUCTFORM_H
