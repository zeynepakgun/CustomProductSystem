#ifndef SELECTPRODUCTFORM_H
#define SELECTPRODUCTFORM_H



#include <QWidget>
#include <QtSql/QSqlQuery>
#include <QMessageBox>
#include <QTimer>  // Geri sayımı başlatmak için
#include <QIntValidator>   // Sayısal doğrulama için
#include <QDoubleValidator> // Ondalıklı sayılar için

namespace Ui {
class SelectProductForm;
}

class SelectProductForm : public QWidget
{
    Q_OBJECT

public:
    explicit SelectProductForm(QWidget *parent = nullptr);
    ~SelectProductForm();
    void setCustomerPlaka(const QString &plaka);  // Plaka almak için fonksiyon tanımla
    void loadBalanceFromDatabase();  // Veritabanından bakiye yüklemek için fonksiyon
    void updateBalanceInDatabase();  // Bakiye güncelleme fonksiyonu


private slots:
    void on_productComboBox_currentIndexChanged(int index);
    void on_startProductButton_clicked();
    void updateCountdown();
    void on_loadBalanceButton_clicked();  // Bakiye yükleme butonuna tıklanması

private:
    Ui::SelectProductForm *ui;
    int selectedProductPrice;

    QTimer *countdownTimer;
    int countdownTime;
    QString customerPlaka;  // Plakayı tutacak değişken
    double customerBalance;  // Bakiyeyi tutacak değişken



    void loadProducts();  // Ürünleri yükleme fonksiyonu
    void startProductProcess();  // Ürün başlatma işlemi
    void updateProductPrice();  // Fiyatı güncelleme

};

#endif // SELECTPRODUCTFORM_H
