#include "selectproductform.h"
#include "ui_selectproductform.h"
#include "DatabaseHelper.h"
#include "mainwindow.h"
#include "signupform.h"
#include <QDebug>
SelectProductForm::SelectProductForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SelectProductForm)
{
    ui->setupUi(this);
    ui->lineEdit->setValidator(new QDoubleValidator(0, 100000, 2, this));


    // veritabanı bağlantısını başlatıyoruz buu sadece bir kez yapılmalı
    DatabaseHelper* db = DatabaseHelper::getInstance();
    if (db->openDatabase()) {
        qDebug() << "selectproductform da  Veritabanına bağlanıldı!";
        db->createSignUpTable();
        db->createTable();
        db->createProductTable(); // tabloları sadece bir kez oluşturuyoruz.
    } else {
        qDebug() << "SelectProductForm Veritabanı bağlantısı başarısız!";
    }
    // Ürünleri yükle
    loadProducts();

    connect(ui->loadBalanceButton, &QPushButton::clicked, this, &SelectProductForm::on_loadBalanceButton_clicked);

    // Buton tıklama olayını bağla
    connect(ui->startProductButton, &QPushButton::clicked, this, &SelectProductForm::on_startProductButton_clicked);

    // Geri sayım için timer başlatıyoruz
    countdownTimer = new QTimer(this);
    connect(countdownTimer, &QTimer::timeout, this, &SelectProductForm::updateCountdown);

    // Başlangıçta bakiye sorgulaması
    customerBalance = 100;  // Test için statik bir bakiye, bunu veritabanından almanız gerekebilir.

}

SelectProductForm::~SelectProductForm()
{
    delete ui;
}

void SelectProductForm::loadProducts() //Veritabanındaki ürünleri comboBox a ekler
{
    QSqlQuery query;
    query.exec("SELECT ProductName, Price FROM Product");

    while (query.next()) {
        ui->productComboBox->addItem(query.value(0).toString());  // Ürün adı
    }
}

//Bu fonksiyon ürün seçildiğinde tetkilenecek ve fiyatı labelda gösterecek
void SelectProductForm::on_productComboBox_currentIndexChanged(int index)
{    qDebug() << "on_productComboBox_currentIndexChanged tetiklendi";
    QSqlQuery query;
    query.prepare("SELECT Price FROM Product WHERE ProductName = :productName");
    query.bindValue(":productName", ui->productComboBox->currentText());
    query.exec();

    if (query.next()) {
        selectedProductPrice = query.value(0).toInt();
        updateProductPrice();
    }
}

//ComboBox da seçilen ürünün fiyatını gösterir.
void SelectProductForm::updateProductPrice()
{
    ui->productNameLabel->setText("Fiyat: " + QString::number(selectedProductPrice) + " TL");
    //Label de fiyat bilgisi veriyoruz.
}

//satın almak için önce bakiye kontrolü daha sonra işlem
void SelectProductForm::on_startProductButton_clicked()
{
    static bool isProcessing = false; // İşlemin başlatılıp başlatılmadığını kontrol etmek için, gerekliydi yoksa fonksiyonun 2 kere çalışmasına sebep oluyordu.

    // Eğer işlem zaten başlatılmışsa fonksiyonu sonlandır
    if (isProcessing) {
        return;
    }

    if (customerBalance >= selectedProductPrice) {
        // Yeterli bakiye varsa işlemi başlat
        startProductProcess();
    } else {
        QMessageBox::warning(this, "Hata", "Yetersiz bakiye!");
        return;
    }
}

//startProductButtonundan sonra hesaptan para düşülmesi görevini yapar.
void SelectProductForm::startProductProcess()
{
    static bool isProcessing = false; // İşlemin başlatılıp başlatılmadığını kontrol etmek için

    // Eğer işlem zaten başlatılmışsa, fonksiyonu sonlandır
    if (isProcessing) {
        return;
    }

    qDebug() << "startProductProcess tetiklendi";

    // Bakiye düşme işlemi
    customerBalance -= selectedProductPrice;

    // Geri sayımı başlat
    countdownTime = 5;  // 5 saniye geri sayım
    ui->progressBar->setMaximum(countdownTime); // Progress bar ayarlanır
    ui->progressBar->setValue(countdownTime); // Başlangıç değerini ayarlanır

    // Zamanlayıcı daha önce başlatılmamışsa başlat
    if (!countdownTimer->isActive()) {
        countdownTimer->start(1000);  // Her saniye geri sayımı güncelle
    }

    // Ürünü başlat (Geri sayım başladığında kullanıcı başka işlem yapamasın)
    ui->startProductButton->setDisabled(true);  // Start button devre dışı
    ui->loadBalanceButton->setDisabled(true);  // Bakiye yükleme butonunu devre dışı bırak
    ui->productComboBox->setDisabled(true);    // Ürün seçim kutusunu devre dışı bırak

    // Veritabanında Balance güncelle
    updateBalanceInDatabase();

    // İşlemi başlat
    isProcessing = true;  // İşlemi başlattık

    // Geri sayım tamamlandığında işlemi bitir
    QTimer::singleShot(5000, this, [this]() {
        ui->startProductButton->setEnabled(true);  // 5 saniye sonra buton tekrar aktif
        ui->loadBalanceButton->setEnabled(true);
        ui->productComboBox->setEnabled(true);  // Ürün kutusunu da tekrar aktif et
        QMessageBox::information(this, "İşlem Tamamlandı", "Ürün başarıyla başlatıldı!");
        isProcessing = false; // İşlem tamamlandığında durumu sıfırla
    });
}

// Veritabanında bakiyeyi güncellemek için sorgu yapılır
void SelectProductForm::updateBalanceInDatabase()
{   qDebug() <<"updateBalanceInDatabase tetiklendi";

    QSqlQuery query;
    query.prepare("UPDATE SignUp SET Balance = :balance WHERE Plate = :plate");
    query.bindValue(":balance", customerBalance);  // Güncellenmiş bakiyeyi kullanıyoruz
    query.bindValue(":plate", customerPlaka);  // Plaka numarasını alıyoruz

    if (query.exec()) {
        qDebug() << "Balance başarıyla güncellendi!";
    } else {
        qDebug() << "Balance güncellenemedi: " << query.lastError().text();
    }

}
void SelectProductForm::updateCountdown()

{  /*qDebug() <<"updateCountdown tetiklendi";*/
    countdownTime--;
    ui->progressBar->setValue(countdownTime);

    if (countdownTime <= 0) {
        countdownTimer->stop();
    }
}

void SelectProductForm::setCustomerPlaka(const QString &plaka) {
    qDebug() <<"setCustomerPlaka tetiklendi";
    this->customerPlaka = plaka;
    qDebug() << "Giriş yapan plaka: " << customerPlaka;

    // Veritabanından plakaya ait bakiyeyi alıyoruz
    loadBalanceFromDatabase();
}

//Veritabanından müşteri bilgisini çeker
void SelectProductForm::loadBalanceFromDatabase() {
    qDebug() <<"loadBalanceFromDatabase tetiklendi";

    QSqlQuery query;
    query.prepare("SELECT Balance FROM SignUp WHERE Plate = :plate");
    query.bindValue(":plate", customerPlaka);
    query.exec();

    if (query.next()) {
        customerBalance = query.value("Balance").toDouble();  // Bakiyeyi alıyoruz
        qDebug() << "Müşterinin bakiyesi: " << customerBalance;
        // UI güncelleme veya bakiye ile işlem yapma burada yapılabilir
    } else {
        QMessageBox::warning(this, "Hata", "Plaka bulunamadı veya bakiye yüklenemedi.");
    }
}

//Bakiye yükleme işlemi yapılırken çaağrılır
void SelectProductForm::on_loadBalanceButton_clicked()
{
    qDebug() <<"on_loadBalanceButton_clicked tetiklendi";

    bool ok;
    double amount = ui->lineEdit->text().toDouble(&ok);  // Kullanıcının girdiği bakiye miktarını alıyoruz
    qDebug() << "Girilen değer:" << ui->lineEdit->text();
    qDebug() << "Dönüştürülen amount:" << amount << ", ok:" << ok;

    if (!ok || amount <= 0) {
        QMessageBox::information(this, "Bilgi", "Ürün yüklendi");
        return;
    }

    QString inputText = ui->lineEdit->text().trimmed();  // Kullanıcının girdiği metni alıyoruz

    if (inputText.isEmpty()) {
        QMessageBox::warning(this, "Hata", "Lütfen bakiye miktarını girin!"); // Eğer giriş boşsa uyarı veriyoruz
        return;
    }

    // Yeni bakiyeyi hesapla
    customerBalance += amount;  // Eski bakiyeye yeni yüklemeyi ekliyoruz

    // Veritabanında bakiyeyi güncelle
    updateBalanceInDatabase();

    // İşlem tamamlandığında kullanıcıyı bilgilendir
    ui->loadBalanceStatusLabel->setText("Bakiye başarıyla yüklendi: " + QString::number(amount) + " TL");
    ui->lineEdit->clear();  // Hatalı girişte LineEdit temizlenebilir

}
