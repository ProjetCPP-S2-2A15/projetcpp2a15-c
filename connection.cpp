#include "connection.h"
#include <QSqlError>
#include <QDebug>

Connection::Connection()
{
    // Constructeur de la classe Connection
}

bool Connection::createconnect()
{
    bool test = false;

    // Ajout de la base de données avec le driver ODBC
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");

    // Définition du nom de la source de données
    db.setDatabaseName("source_projet2A"); // Nom de la source de données
    db.setUserName("samar");               // Nom d'utilisateur pour la connexion
    db.setPassword("samar");               // Mot de passe de l'utilisateur

    // Tentative d'ouverture de la connexion
    if (db.open()) {
        test = true; // La connexion a réussi
    } else {
        // Si la connexion échoue, afficher l'erreur
        qDebug() << "Échec de la connexion à la base de données : " << db.lastError().text();
    }

    // Retourne vrai si la connexion est réussie, sinon faux
    return test;
}
