#include "services.h"
#include <QSqlQuery>
#include <QSqlError>  // Ajout pour afficher les erreurs SQL
#include <QtDebug>
#include <QObject>

Services::Services()
{
    this->id_service = 0;
    this->Prix = 0.0;
    this->Nom = "";
    this->Description = "";
    this->Statut = "";
    this->Type = "";
    this->DateDebut = "";
    this->DateFin = "";
}

Services::Services(int id, QString nom, double prix, QString description, QString statut, QString type, QString dateDebut, QString dateFin)
{
    this->id_service = id;
    this->Nom = nom;
    this->Prix = prix;
    this->Description = description;
    this->Statut = statut;
    this->Type = type;
    this->DateDebut = dateDebut;
    this->DateFin = dateFin;
}

bool Services::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO SERVICES(ID_SERVICE, NOM, PRIX, DESCRIPTION, STATUT, TYPE, DATEDEBUT, DATEFIN) "
                  "VALUES (:ID_SERVICE, :NOM, :PRIX, :DESCRIPTION, :STATUT, :TYPE, TO_DATE(:DATEDEBUT, 'YYYY-MM-DD'), TO_DATE(:DATEFIN, 'YYYY-MM-DD'))");

    query.bindValue(":ID_SERVICE", id_service);
    query.bindValue(":NOM", Nom);
    query.bindValue(":PRIX", Prix);
    query.bindValue(":DESCRIPTION", Description);
    query.bindValue(":STATUT", Statut);
    query.bindValue(":TYPE", Type);
    query.bindValue(":DATEDEBUT", DateDebut);
    query.bindValue(":DATEFIN", DateFin);

    qDebug() << "Requête SQL : " << query.lastQuery();
    qDebug() << "Valeurs : " << id_service << Nom << Prix << Description << Statut << Type << DateDebut << DateFin;

    if (!query.exec()) {
        qDebug() << " Erreur lors de l'ajout du service:" << query.lastError().text();
        return false;
    }

    qDebug() << " Service ajouté avec succès!";
    return true;
}

QSqlQueryModel * Services::afficher()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM SERVICES");

    if (model->lastError().isValid()) {
        qDebug() << "Erreur lors de l'affichage des services:" << model->lastError().text();
    }

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_SERVICE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRIX"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DESCRIPTION"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("STATUT"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("TYPE"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("DATEDEBUT"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("DATEFIN"));

    return model;
}

bool Services::supprimer(int id_service)
{
    QSqlQuery query;
    query.prepare("DELETE FROM SERVICES WHERE ID_SERVICE = :ID_SERVICE");
    query.bindValue(":ID_SERVICE", id_service);

    qDebug() << "[SUPPRESSION] ID : " << id_service;

    if (!query.exec()) {
        qDebug() << " [SUPPRESSION] Erreur SQL :" << query.lastError().text();
        return false;
    }

    qDebug() << " [SUPPRESSION] Succès!";
    return true;
}

bool Services::modifier(int id, QString nom, double prix, QString description, QString statut, QString type, QString dateDebut, QString dateFin)
{
    QSqlQuery query;
    query.prepare("UPDATE SERVICES SET NOM = :NOM, PRIX = :PRIX, DESCRIPTION = :DESCRIPTION, STATUT = :STATUT, "
                  "TYPE = :TYPE, DATEDEBUT = TO_DATE(:DATEDEBUT, 'YYYY-MM-DD'), DATEFIN = TO_DATE(:DATEFIN, 'YYYY-MM-DD') WHERE ID_SERVICE = :ID_SERVICE");

    query.bindValue(":ID_SERVICE", id);
    query.bindValue(":NOM", nom);
    query.bindValue(":PRIX", prix);
    query.bindValue(":DESCRIPTION", description);
    query.bindValue(":STATUT", statut);
    query.bindValue(":TYPE", type);
    query.bindValue(":DATEDEBUT", dateDebut);
    query.bindValue(":DATEFIN", dateFin);

    qDebug() << " [MODIFICATION] Requête SQL : " << query.lastQuery();
    qDebug() << " [MODIFICATION] Valeurs : " << id << nom << prix << description << statut << type << dateDebut << dateFin;

    if (!query.exec()) {
        qDebug() << "[MODIFICATION] Erreur SQL :" << query.lastError().text();
        return false;
    }

    qDebug() << " [MODIFICATION] Succès!";
    return true;
}
