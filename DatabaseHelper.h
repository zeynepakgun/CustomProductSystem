#ifndef DATABASEHELPER_H
#define DATABASEHELPER_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

class DatabaseHelper {
public:
    static DatabaseHelper* getInstance();
    bool openDatabase();
    void closeDatabase();
    void createTable();  // Tabloyu oluşturacak fonksiyon
    void createSignUpTable();
    void createProductTable();

private:
    DatabaseHelper();
    static DatabaseHelper* instance;
    QSqlDatabase db;
};

#endif // DATABASEHELPER_H
