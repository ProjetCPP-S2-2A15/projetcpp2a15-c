#include "connection.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>

Connection::Connection() {}

bool Connection::createconnect()
{
    bool test = false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Source_Projet2A"); // Nom de la source de données ODBC
    db.setUserName("fethi");          // Nom d'utilisateur
    db.setPassword("pojet2a15");          // Mot de passe

    if (db.open()) {
        qDebug() << "Connected successfully!";
        test = true;
    } else {
        qDebug() << "Connection failed:" << db.lastError().text();
    }

    return test;
}
