#include "connection.h"
#include <QMessageBox>
Connection::Connection() {
    db = QSqlDatabase::addDatabase("QODBC");
}

bool Connection::createconnect()
{
    bool test = false;

    db.setDatabaseName("source_projet2A"); // Nom de la source de données
    db.setUserName("fatma"); // Nom de l'utilisateur
    db.setPassword("123456"); // Mot de passe

    if (db.open()) {
        test = true;
    } else {
        qDebug() << "Erreur de connexion: " << db.lastError().text();
    }

    return test;
}
