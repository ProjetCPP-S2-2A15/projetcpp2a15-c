#include "connection.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QMessageBox>
#include <QDebug>

bool createConnection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("SourceProjet_2A15"); // Nom de la source de données ODBC
    db.setUserName("system"); // Nom d'utilisateur
    db.setPassword("amin123"); // Mot de passe

    if (!db.open()) {
        qDebug() << "Échec de la connexion à la base de données :" << db.lastError().text();
        QMessageBox::critical(nullptr, "Erreur", "Échec de la connexion à la base de données : " + db.lastError().text());
        return false;
    }

    qDebug() << "Connexion à la base de données réussie !";
    return true;
}
