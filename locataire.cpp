#include "locataire.h"
#include <QSqlError>
#include <QDebug>

Locataire::Locataire(int id, QString nom, QString adresse, QString email, QString telephone, QDate debut_de_contrat, QDate fin_de_contrat)
{
    this->id = id;
    this->nom = nom;
    this->adresse = adresse;
    this->email = email;
    this->telephone = telephone;
    this->debut_de_contrat = debut_de_contrat;
    this->fin_de_contrat = fin_de_contrat;
}

bool Locataire::ajouter()
{
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.transaction()) {
        qDebug() << "Erreur lors du démarrage de la transaction:" << db.lastError().text();
        return false;
    }

    QSqlQuery query;
    query.prepare("INSERT INTO Locataires (NOM, ADRESSE, EMAIL, TELEPHONE, DEBUT_CONTRAT, FIN_CONTRAT) "
                  "VALUES (:nom, :adresse, :email, :telephone, :debut_de_contrat, :fin_de_contrat)");
    query.bindValue(":nom", nom);
    query.bindValue(":adresse", adresse);
    query.bindValue(":email", email);
    query.bindValue(":telephone", telephone);
    query.bindValue(":debut_de_contrat", debut_de_contrat.toString("yyyy-MM-dd"));
    query.bindValue(":fin_de_contrat", fin_de_contrat.toString("yyyy-MM-dd"));

    if (!query.exec()) {
        qDebug() << "Erreur lors de l'ajout:" << query.lastError().text();
        db.rollback();
        return false;
    }

    if (!db.commit()) {
        qDebug() << "Erreur lors de la validation de la transaction:" << db.lastError().text();
        return false;
    }

    return true;
}

bool Locataire::modifier(int id, QString nom, QString adresse, QString email, QString telephone, QDate debut_de_contrat, QDate fin_de_contrat)
{
    QSqlQuery query;
    query.prepare("UPDATE Locataires SET NOM = :nom, ADRESSE = :adresse, EMAIL = :email, TELEPHONE = :telephone, DEBUT_CONTRAT = :debut_de_contrat, FIN_CONTRAT = :fin_de_contrat WHERE ID_LOCATAIRE = :id");
    query.bindValue(":nom", nom);
    query.bindValue(":adresse", adresse);
    query.bindValue(":email", email);
    query.bindValue(":telephone", telephone);
    query.bindValue(":debut_de_contrat", debut_de_contrat.toString("yyyy-MM-dd"));
    query.bindValue(":fin_de_contrat", fin_de_contrat.toString("yyyy-MM-dd"));
    query.bindValue(":id", id);

    if (!query.exec()) {
        qDebug() << "Erreur lors de la mise à jour:" << query.lastError().text();
        return false;
    }

    return true;
}

QSqlQueryModel* Locataire::afficher()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM Locataires");
    return model;
}

bool Locataire::supprimer(int id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM Locataires WHERE ID_LOCATAIRE = :id");
    query.bindValue(":id", id);

    return query.exec();
}
QSqlQueryModel* Locataire::afficherTrieParDate()
{
    QSqlQueryModel* model = new QSqlQueryModel();

    // Tri par DEBUT_CONTRAT de manière croissante (ASC)
    model->setQuery("SELECT * FROM Locataires ORDER BY DEBUT_CONTRAT ASC");

    return model;
}

QSqlQueryModel* Locataire::afficherTrieParId()
{
    QSqlQueryModel* model = new QSqlQueryModel();

    // Tri par ID_LOCATAIRE de manière croissante
    model->setQuery("SELECT * FROM Locataires ORDER BY ID_LOCATAIRE ASC");

    return model;
}
QSqlQueryModel* Locataire::statistiquesContratsParMois() {
    QSqlQueryModel* model = new QSqlQueryModel();

    // Exécuter une requête SQL compatible avec Oracle
    model->setQuery("SELECT TO_CHAR(TO_DATE(DEBUT_CONTRAT, 'YYYY-MM-DD'), 'MM/YYYY') AS mois, COUNT(*) AS total "
                    "FROM LOCATAIRES "
                    "GROUP BY TO_CHAR(TO_DATE(DEBUT_CONTRAT, 'YYYY-MM-DD'), 'MM/YYYY') "
                    "ORDER BY TO_DATE(TO_CHAR(TO_DATE(DEBUT_CONTRAT, 'YYYY-MM-DD'), 'MM/YYYY'), 'MM/YYYY')");

    // Débogage si une erreur SQL est détectée
    if (model->lastError().isValid()) {
        qDebug() << "Erreur SQL détectée :" << model->lastError().text();
    }

    return model;
}



