#ifndef SIGNUPFORM_H
#define SIGNUPFORM_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include <QCryptographicHash>  // Şifreleme için
#include <QByteArray>  // ByteArray kullanımı için
#include <QtSql/QSqlDatabase>  // QSqlDatabase sınıfını dahil et
#include <QRegExp>
#include "DatabaseHelper.h"  // DatabaseHelper'ı dahil ettik

namespace Ui {
class SignUpForm;
}

class SignUpForm : public QWidget
{
    Q_OBJECT

public:
    explicit SignUpForm(QWidget *parent = nullptr);
    ~SignUpForm();
     void setSqlDatabase(QSqlDatabase db);


private slots:
    void onPasswordTextChanged();  // Şifre kontrolü ve renk değiştirme
    void onPlateChanged();  // Plaka kontrolü
    void onShowHidePasswordClicked();  // Şifreyi göster/gizle
    void onSignUpButtonClicked();  // Kayıt ol butonu tıklanırsa veritabanına veri ekleme
    void  goToMainWindow();

private:
    Ui::SignUpForm *ui;
    QString hashPassword(const QString &password);  // Şifreyi hash'leme fonksiyonu

};

#endif // SIGNUPFORM_H
