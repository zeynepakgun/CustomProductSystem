#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
 #include <QMessageBox>        // QMessageBox kullanabilmek için
 #include <QtSql/QSqlQuery>     // QSqlQuery kullanabilmek için
#include <QCryptographicHash>
#include <QByteArray>
#include <QIcon>
#include <QPixmap>
#include "DatabaseHelper.h"  // DatabaseHelper sınıfını dahil et
#include "signupform.h"      // SignUpForm'u dahil et
#include <QtSql/QSqlDatabase>  // QSqlDatabase için
#include <QLineEdit>



QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

// private slots:
//     void onLoginClicked();  // Giriş yapma fonksiyonu
//     void onSignUpClicked(); // Yeni kullanıcı kaydı fonksiyonu
private slots:
    void onLoginClicked(); // Giriş butonu için slot
    void onSignUpClicked(); // Kayıt ol butonuna basıldığında sinupForma git
    void openSelectProductForm();

    void togglePasswordVisibility();
      QString hashPassword(const QString &password);  // Hash fonksiyonunu buraya ekledim


private:
    Ui::MainWindow *ui;
    int customerBalance;  // Kullanıcının bakiyesi

};
#endif // MAINWINDOW_H
