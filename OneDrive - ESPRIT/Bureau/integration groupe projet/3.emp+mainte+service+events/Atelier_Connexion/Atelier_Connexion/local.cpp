#include "local.h"
#include <QMessageBox>
#include <QDebug>
#include <QSqlError>
#include <QString>
#include "connection.h"

// Constructeurs
Local::Local() : id(0), surface(0.0), type(""), disponibilite("Disponible"), prix(0.0), etage("") {}

Local::Local( double surface, QString type, QString disponibilite, double prix, QString etage)
    :  surface(surface), type(type), disponibilite(disponibilite), prix(prix), etage(etage) {}
Local::Local(long long id, double surface, QString type, QString disponibilite, double prix, QString etage)
    : id(id), surface(surface), type(type), disponibilite(disponibilite), prix(prix), etage(etage) {}

bool Local::ajouter()
{
    QSqlQuery query;

    query.prepare("INSERT INTO fatma.local_commerciale ( SURFACE, TYPE, DISPONIBILITE, PRIX, ETAGE) "
                  "VALUES ( :SURFACE, :TYPE, :DISPONIBILITE, :PRIX, :ETAGE)");


    query.bindValue(":SURFACE", surface);
    query.bindValue(":TYPE", type);
    query.bindValue(":DISPONIBILITE", disponibilite);
    query.bindValue(":PRIX", prix);
    query.bindValue(":ETAGE", etage);

    if (!query.exec()) {
        qDebug() << "❌ Erreur SQL lors de l'ajout du local :" << query.lastError().text();
        return false;
    }

    qDebug() << "✅ Local commercial ajouté avec succès!";
    return true;
}
bool Local::supprimer(long long id) {
    QSqlQuery query;
    QString res = QString::number(id); // Convertir l'ID en QString

    // Préparer la requête SQL pour supprimer le local
    query.prepare("DELETE FROM fatma.local_commerciale WHERE ID_LOCAL = :ID_LOCAL");
    query.bindValue(":ID_LOCAL", res);

    // Exécuter la requête
    if (!query.exec()) {
        qDebug() << "❌ Erreur SQL lors de la suppression :" << query.lastError().text();
        return false;
    }

    // Vérifier si des lignes ont été affectées
    if (query.numRowsAffected() == 0) {
        qDebug() << "⚠️ Aucune suppression n'a été effectuée. L'ID" << id << "n'existe pas dans la base de données.";
        return false;
    }

    qDebug() << "✅ Local commercial supprimé avec succès !";
    return true;
}
bool Local::modifier(long long id) {
    QSqlQuery query;

    // Convertir l'ID en QString (si nécessaire)
    QString res = QString::number(id);

    // Préparer la requête SQL pour mettre à jour le local
    query.prepare("UPDATE fatma.local_commerciale SET "
                  "SURFACE = :SURFACE, "
                  "TYPE = :TYPE, "
                  "DISPONIBILITE = :DISPONIBILITE, "
                  "PRIX = :PRIX, "
                  "ETAGE = :ETAGE "
                  "WHERE ID_LOCAL = :ID_LOCAL");

    // Lier les valeurs aux paramètres de la requête
    query.bindValue(":ID_LOCAL", res); // ID du local à modifier
    query.bindValue(":SURFACE", this->surface);  // Utiliser les valeurs de l'objet `Local`
    query.bindValue(":TYPE", this->type);
    query.bindValue(":DISPONIBILITE", this->disponibilite);
    query.bindValue(":PRIX", this->prix);
    query.bindValue(":ETAGE", this->etage);

    // Exécuter la requête
    if (query.exec()) {
        // Vérifier si des lignes ont été affectées
        if (query.numRowsAffected() > 0) {
            qDebug() << "✅ Local commercial modifié avec succès !";
            return true;
        } else {
            qDebug() << "⚠️ Aucun local trouvé avec l'ID spécifié :" << id;
            return false;
        }
    } else {
        qDebug() << "❌ Erreur SQL lors de la modification :" << query.lastError().text();
        return false;
    }
}

QSqlQueryModel* Local::afficher()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query;

    query.prepare("SELECT ID_LOCAL, SURFACE, TYPE, DISPONIBILITE, PRIX, ETAGE FROM fatma.local_commerciale");

    if (query.exec()) {
        model->setQuery(query);
        qDebug() << "✅ Données chargées avec succès dans TableView !";
    } else {
        qDebug() << "❌ Erreur SQL lors de l'affichage :" << query.lastError().text();
    }

    return model;
}

