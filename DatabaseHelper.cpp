#include "DatabaseHelper.h"

DatabaseHelper* DatabaseHelper::instance = nullptr;

DatabaseHelper* DatabaseHelper::getInstance() {
    if (instance == nullptr) {
        instance = new DatabaseHelper();
    }
    return instance;
}

DatabaseHelper::DatabaseHelper() {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/mthnd/Desktop/Qt.Case/CustomProductSystem/database.db");
}

bool DatabaseHelper::openDatabase() {
    if (db.open()) {
        qDebug() << " DatabaseHelper tarafından Veritabanına bağlanıldı!";
        return true;
    } else {
        qDebug() << "DatabaseHelper tarafından Veritabanına bağlanılamadı:" << db.lastError().text();
        return false;
    }
}

void DatabaseHelper::closeDatabase() {
    if (db.isOpen()) {
        db.close();
        qDebug() << "Veritabanı kapatıldı!";
    }
}

void DatabaseHelper::createTable() {
    QSqlQuery query;
   //customer tablosu
    bool success = query.exec("CREATE TABLE IF NOT EXISTS Customer ("
                              "ID INTEGER PRIMARY KEY AUTOINCREMENT, "
                              "Plaka TEXT, "
                              "Sifre TEXT)");
    if (success) {
        qDebug() << "Customer Tablo başarıyla oluşturuldu.";
    } else {
        qDebug() << "Customer Tablo oluşturulamadı:" << query.lastError().text();
    }

}
void DatabaseHelper::createSignUpTable() {
    QSqlQuery query;
    bool success = query.exec("CREATE TABLE IF NOT EXISTS SignUp ("
                              "ID INTEGER PRIMARY KEY AUTOINCREMENT, "
                              "Name TEXT, "
                              "Surname TEXT, "
                              "Plate TEXT, "
                              "PhoneNumber TEXT, "
                              "Balance TEXT, "
                              "Password BLOB)");
    if (success) {
        qDebug() << "SignUp tablosu başarıyla oluşturuldu.";
    } else {
        qDebug() << "SignUp tablosu oluşturulamadı:" << query.lastError().text();
    }
}

void DatabaseHelper::createProductTable() {
    QSqlQuery query;
    bool success = query.exec("CREATE TABLE IF NOT EXISTS definitions.Product ("
                              "ProductName TEXT, "
                              "Price TEXT)");
    if (success) {
        qDebug() << "Product tablosu başarıyla oluşturuldu.";
    } else {
        qDebug() << "Product tablosu oluşturulamadı:" << query.lastError().text();
    }
}


