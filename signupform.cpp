#include "signupform.h"
#include "ui_signupform.h"
#include <QMessageBox>
#include <QtSql/QSqlQuery>
#include <QCryptographicHash>
#include <QtSql/QSqlError>
#include <QtSql/QSqlDatabase>
#include <QDebug>
#include <QSqlError>
#include <QTimer>  // kayıt başarılı ifadesinden sonra 2 saniye bekleyip anasayfaya yönlendirecek
#include "DatabaseHelper.h"  // DatabaseHelper sınıfını dahil et
#include "mainwindow.h"

SignUpForm::SignUpForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SignUpForm)
{

    ui->setupUi(this);
    ui->eyeButtonSignUp->setIconSize(QSize(24, 24));  // Simge boyutunu ayarla
    ui->eyeButtonSignUp->setIcon(QIcon("C:/Users/mthnd/Desktop/Qt.Case/CustomProductSystem/icons/eye.png"));
    ui->backButton->setIcon(QIcon("C:/Users/mthnd/Desktop/Qt.Case/CustomProductSystem/icons/back.jpg"));

    // Veritabanı bağlantısını başlatıyoruz
    DatabaseHelper* db = DatabaseHelper::getInstance();
    if (db->openDatabase()) {
        qDebug() << "Veritabanına SignUpForm'da bağlanıldı!";
        // db->createTable();  // Tabloyu oluştur
        db->createSignUpTable();  // Sadece SignUp tablosunu oluşturuyoruz

    } else {
        qDebug() << "Veritabanı bağlantısı başarısız!";
    }

    // Şifre kontrolü sadece confirm şifreye yazıldığında yapılacak
    connect(ui->enterPasswordConfirm, &QLineEdit::textChanged, this, &SignUpForm::onPasswordTextChanged);
    connect(ui->enterNumberPlate, &QLineEdit::textChanged, this, &SignUpForm::onPlateChanged);
    // SignUpForm constructor'ında, göz butonuna tıklanmasıyla şifreyi göster/gizle
    connect(ui->eyeButtonSignUp, &QPushButton::clicked, this, &SignUpForm::onShowHidePasswordClicked);
    //Kayıt ol butonunun bağlanması
    connect(ui->signUpButton, &QPushButton::clicked, this, &SignUpForm::onSignUpButtonClicked);
    //Anasayfaya geri gönder
    connect(ui->backButton, &QPushButton::clicked, this, &SignUpForm::goToMainWindow);

}

SignUpForm::~SignUpForm()
{
    delete ui;
    // Veritabanı bağlantısını kapatıyoruz
    DatabaseHelper::getInstance()->closeDatabase();

}

void SignUpForm::onPasswordTextChanged() { //şifre dogrulama için
    QString password = ui->enterPasswordSignUp->text();  // Şifreyi al
    QString confirmPassword = ui->enterPasswordConfirm->text();  // Confirm password al

    // Şifreler eşleşiyorsa, renklendirme normale döner
    if (password == confirmPassword) {
        ui->enterPasswordConfirm->setStyleSheet("border: 2px solid green;");  // Yeşil renk
    } else {
        // Şifreler eşleşmiyorsa, kırmızıya döner
        ui->enterPasswordConfirm->setStyleSheet("border: 2px solid red;");  // Kırmızı renk
    }
}

void SignUpForm::onPlateChanged() {
    QString plate = ui->enterNumberPlate->text();

    // Plakayı büyük harfe dönüştür
    plate = plate.toUpper();

    // Sadece harf ve rakamlara izin ver, diğer karakterleri temizle
    QRegExp rx("^[A-Za-z0-9]*$");  // Yalnızca harf ve rakam
    if (!rx.exactMatch(plate)) {
        plate = plate.left(plate.length() - 1);  // Geçersiz karakteri kaldır
    }

    // QLineEdit'i güncelle
    ui->enterNumberPlate->setText(plate);
}

void SignUpForm::onShowHidePasswordClicked() {
    // Şifreyi ve doğrulama şifresini kontrol et
    if (ui->enterPasswordSignUp->echoMode() == QLineEdit::Password) {
        // Eğer şifre gizliyse, şifreyi ve doğrulama şifresini göster
        ui->enterPasswordSignUp->setEchoMode(QLineEdit::Normal);
        ui->enterPasswordConfirm->setEchoMode(QLineEdit::Normal);
        ui->eyeButtonSignUp->setIcon(QIcon("C:/Users/mthnd/Desktop/Qt.Case/CustomProductSystem/icons/eye_open.png"));  // Göz açık simgesi
    } else {
        // Eğer şifre görünüyorsa, şifreyi ve doğrulama şifresini gizle
        ui->enterPasswordSignUp->setEchoMode(QLineEdit::Password);
        ui->enterPasswordConfirm->setEchoMode(QLineEdit::Password);
        ui->eyeButtonSignUp->setIcon(QIcon("C:/Users/mthnd/Desktop/Qt.Case/CustomProductSystem/icons/eye.png"));  // Göz kapalı simgesi
    }
}

QString SignUpForm::hashPassword(const QString &password) {
    QByteArray hash = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256);
    return hash.toHex();
}

void SignUpForm::onSignUpButtonClicked() {
    QString password = ui->enterPasswordSignUp->text();
    QString confirmPassword = ui->enterPasswordConfirm->text();

    // Şifrelerin eşleşip eşleşmediğini kontrol et
    if (password != confirmPassword) {
        ui->enterPasswordConfirm->setStyleSheet("border: 2px solid red;");  // Kırmızı renk
        QMessageBox::warning(this, "Şifre Hatası", "Şifreler eşleşmiyor. Lütfen tekrar deneyin.");
        return;
    } else {
        ui->enterPasswordConfirm->setStyleSheet("border: 2px solid green;");  // Yeşil renk
    }

    // Telefon numarasını kontrol et
    QString phoneNumber = ui->enterPhoneNumber->text();
    if (phoneNumber.startsWith("0") || phoneNumber.length() != 10 || !phoneNumber.toLongLong()) {
        ui->enterPhoneNumber->setStyleSheet("border: 2px solid red;");
        QMessageBox::warning(this, "Hata", "Telefon numarası 10 haneli olmalı ve başında sıfır olmamalı.");
        return;
    } else {
        ui->enterPhoneNumber->setStyleSheet("border: 2px solid green;");
    }

    QString name = ui->enterName->text();
    QString surname = ui->enterSurname->text();
    QString plate = ui->enterNumberPlate->text();
    QString balance= ui->enterBalance->text();

    // Şifreyi hash'le
    QString hashedPassword = hashPassword(password);

    // Singleton kullanarak veritabanı bağlantısını alıyoruz
    DatabaseHelper* db = DatabaseHelper::getInstance();
    if (db->openDatabase()) {
        qDebug() << "Veritabanına SignUpForm'da bağlanıldı!";

        // Plakayı kontrol et
        QSqlQuery checkQuery;
        checkQuery.prepare("SELECT * FROM SignUp WHERE Plate = :plate");
        checkQuery.bindValue(":plate", plate);

        if (checkQuery.exec() && checkQuery.next()) {
            // Eğer plaka zaten kayıtlıysa uyarı ver ve işlemi durdur
            QMessageBox::warning(this, "Hata", "Bu plaka daha önce kayıt edilmiştir.");
            return;
        }

        // Eğer plaka unique ise yeni kullanıcı kaydı yap

        QSqlQuery query;
        query.prepare("INSERT INTO SignUp (Name, Surname, Plate, PhoneNumber, Balance, Password) "
                      "VALUES (:name, :surname, :plate, :phoneNumber, :balance, :password)");
        query.bindValue(":name", name);
        query.bindValue(":surname", surname);
        query.bindValue(":plate", plate);
        query.bindValue(":phoneNumber", phoneNumber);
        query.bindValue(":balance", balance);  // balance burada null veya boş olabilir
        query.bindValue(":password", QByteArray::fromHex(hashedPassword.toUtf8()));

        if (query.exec()) {
            qDebug() << "Veri SignUp tablosuna kaydedildi.";

            // Aynı veriyi Customer tablosuna kaydetti
            QSqlQuery insertQuery;
            insertQuery.prepare("INSERT INTO Customer (Plaka, Sifre) VALUES (:plaka, :sifre)");
            insertQuery.bindValue(":plaka", plate);
            insertQuery.bindValue(":sifre", QByteArray::fromHex(hashedPassword.toUtf8()));

            if (insertQuery.exec()) {
                QMessageBox::information(this, "Başarılı", "Kayıt başarıyla yapıldı ve giriş tablosuna veriler kaydedildi.");
                // Kayıt başarılı olduktan sonra, anasayfaya yönlendirmek için işlemi gerçekleştirebiliriz
                // 2 saniye sonra MainWindow'a yönlendirme
                QTimer::singleShot(2000, this, &SignUpForm::goToMainWindow);

            } else {
                QMessageBox::critical(this, "Hata", "Veri Customer tablosuna kaydedilemedi: " + insertQuery.lastError().text());
            }
        } else {
            QMessageBox::critical(this, "Hata", "Veri SignUp tablosuna kaydedilemedi: " + query.lastError().text());
        }
    } else {
        qDebug() << "Veritabanına bağlanılamadı!";
    }

     }


// 2 saniye sonra ana sayfaya yönlendirme
void SignUpForm::goToMainWindow() {
    this->close();  // SignUpForm'u kapatıyoruz
    MainWindow* mainWindow = new MainWindow();  // MainWindow'u oluşturuyoruz
    mainWindow->show();  // MainWindow'u gösteriyoruz
}
