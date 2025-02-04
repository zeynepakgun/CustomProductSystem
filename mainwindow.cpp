#include "mainwindow.h"
#include "./ui_mainwindow.h"
// #include "ui_mainwindow.h"
#include <QtSql/QSqlQuery>  // QSqlQuery sınıfı için
#include <QMessageBox>
#include <QtSql/QSqlError>
#include <QtSql/QSqlDatabase>
#include <QDebug>
#include <QSqlError>
#include <QCryptographicHash>
#include <QByteArray>
#include <QIcon>
#include <QPixmap>
#include <QTimer>
#include "DatabaseHelper.h"  // DatabaseHelper sınıfını dahil et

#include "signupform.h"  // SignUpForm'u dahil ediyoruz
#include "selectproductform.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    // Veritabanı bağlantısını başlatıyoruz (Bu sadece bir kez yapılmalı)
    DatabaseHelper* db = DatabaseHelper::getInstance();
    if (db->openDatabase()) {
        qDebug() << "MainWindowda Veritabanına bağlanıldı!";
        db->createTable(); // Tabloları sadece bir kez oluşturuyoruz.
    } else {
        qDebug() << "MainWindowda Veritabanı bağlantısı başarısız!";
    }


    ui->eyeButton->setIcon(QIcon("C:/Users/mthnd/Desktop/Qt.Case/CustomProductSystem/icons/eye.png"));  // başta gözü kapalı olmalı
    ui->eyeButton->setIconSize(QSize(24, 24));  // Simge boyutunu ayarla

    // Şifreyi başlangıçta maskeli (noktalı) göster
    ui->enterPassword->setEchoMode(QLineEdit::Password);

    // Göz butonuna tıklama olayını bağla
    connect(ui->eyeButton, &QPushButton::clicked, this, &MainWindow::togglePasswordVisibility);
    connect(ui->login, &QPushButton::clicked, this, &MainWindow::onLoginClicked);
  //login butonuna tıklandığında signali pushbutton clicked temsil eder ve tıklandığında çalışacak olan fonksiyon onLoginClicked temsil edilir.
    connect(ui->signUp, &QPushButton::clicked, this, &MainWindow::onSignUpClicked);
  //signUp butonuna tıklandığında sinyal olayı clicked ile temsil edilir ve çalışacak olan fonksiyon onsignUp olur.

}

MainWindow::~MainWindow() {
    delete ui;
    // Veritabanı bağlantısını kapatıyoruz
    DatabaseHelper::getInstance()->closeDatabase();
}

void MainWindow::togglePasswordVisibility() {
    // Eğer şifre gizleniyorsa, şifreyi göster.Şifreyi gizlemek ve göstermek için kullanılıcak.
    if (ui->enterPassword->echoMode() == QLineEdit::Password) {
        ui->enterPassword->setEchoMode(QLineEdit::Normal);  // Şifreyi normal göster
        ui->eyeButton->setIcon(QIcon("C:/Users/mthnd/Desktop/Qt.Case/CustomProductSystem/icons/eye_open.png"));  // Göz açık simgesi
    } else {
        ui->enterPassword->setEchoMode(QLineEdit::Password);  // Şifreyi gizle
        ui->eyeButton->setIcon(QIcon("C:/Users/mthnd/Desktop/Qt.Case/CustomProductSystem/icons/eye.png"));  // Göz kapalı simgesi
    }
    ui->eyeButton->setIconSize(QSize(24, 24));  // Simge boyutunu ayarla
}


void MainWindow::onLoginClicked() {
    QString plaka = ui->enterNumberPlate->text();  // Kullanıcı plakasını al
    QString sifre = ui->enterPassword->text();    // Kullanıcı şifresini al

    // Şifreyi SHA-256 ile hash'le
    QString hashedPassword = hashPassword(sifre);

    // DatabaseHelper'dan veritabanını alıyoruz
    DatabaseHelper* db = DatabaseHelper::getInstance();

    // Veritabanında plaka ve şifreyi kontrol et
    QSqlQuery query;
    query.prepare("SELECT * FROM Customer WHERE Plaka = :plaka");
    query.bindValue(":plaka", plaka);

    if (query.exec()) {
        if (query.next()) {
            // Veritabanındaki şifreyi al
            QByteArray storedHashedPassword = query.value("Sifre").toByteArray();
            qDebug() << "Veritabanındaki Şifre (Hash): " << storedHashedPassword;

            // Şifreleri karşılaştır
            if (storedHashedPassword == QByteArray::fromHex(hashedPassword.toUtf8())) {
                // Başarılı giriş, kullanıcı bakiyesini alıyoruz

                // Başarılı işlemi kullanıcıya bildirme
                QLabel* successLabel = new QLabel("Giriş başarılı!", this); // QLabel ile mesaj gösterebiliriz.
                successLabel->setAlignment(Qt::AlignCenter);  // Merkezi hizalama
                successLabel->setStyleSheet("color: green; font-size: 14px; font-weight: bold;");

                successLabel->setGeometry(10, this->height() - 40, 300, 30); // Sol alt köşeye yerleştir

                successLabel->show();

                // 2 saniye sonra mesajı kaldırma
                QTimer::singleShot(2000, successLabel, &QLabel::hide);  // 2 saniye sonra hide fonksiyonunu çağırır.


                QTimer::singleShot(2000, this, &MainWindow::openSelectProductForm);
            } else {
                QMessageBox::warning(this, "Hata", "Yanlış plaka veya şifre");
            }
        } else {
            QMessageBox::warning(this, "Hata", "Yanlış plaka veya şifre");
        }
    } else {
        QMessageBox::critical(this, "Veritabanı Hatası", query.lastError().text());
    }
}


void MainWindow::openSelectProductForm() {
    // Giriş başarılı olduktan sonra SelectProductForm'u açıyoruz
    SelectProductForm *selectProductForm = new SelectProductForm();

    // Plakayı SelectProductForm'a gönderiyoruz
    selectProductForm->setCustomerPlaka(ui->enterNumberPlate->text());

    // SelectProductForm'u gösteriyoruz
    selectProductForm->show();
    this->close();  // MainWindow'u kapatıyoruz
}
QString MainWindow::hashPassword(const QString &password) {
    QByteArray hash = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256);
    return hash.toHex();
}

void MainWindow::onSignUpClicked() {
    SignUpForm *signUpForm = new SignUpForm();
    signUpForm->show();  // SignUpForm'u açıyoruz
    this->close();  // MainWindow'u kapatıyoruz
}

