#include "maintenance.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QSqlDatabase>

Maintenance::Maintenance() :
    id_maintenance(0), id_technicien(0),
    numero_telephone(0), id_service(0)
{
}

Maintenance::Maintenance(int id, const QString &desc, const QString &type,
                         const QString &cat, const QDate &date, const QString &stat,
                         int id_tech, const QString &email, int tel, int id_serv) :
    id_maintenance(id), description(desc), type_maintenance(type), categorie(cat),
    date_maintenance(date), statut(stat), id_technicien(id_tech),
    email_technicien(email), numero_telephone(tel), id_service(id_serv)
{
}

// Getters implementation
int Maintenance::getIdMaintenance() const { return id_maintenance; }
QString Maintenance::getDescription() const { return description; }
QString Maintenance::getTypeMaintenance() const { return type_maintenance; }
QString Maintenance::getCategorie() const { return categorie; }
QDate Maintenance::getDateMaintenance() const { return date_maintenance; }
QString Maintenance::getStatut() const { return statut; }
int Maintenance::getIdTechnicien() const { return id_technicien; }
QString Maintenance::getEmailTechnicien() const { return email_technicien; }
int Maintenance::getNumeroTelephone() const { return numero_telephone; }
int Maintenance::getIdService() const { return id_service; }

// Setters implementation
void Maintenance::setIdMaintenance(int id) { id_maintenance = id; }
void Maintenance::setDescription(const QString &desc) { description = desc; }
void Maintenance::setTypeMaintenance(const QString &type) { type_maintenance = type; }
void Maintenance::setCategorie(const QString &cat) { categorie = cat; }
void Maintenance::setDateMaintenance(const QDate &date) { date_maintenance = date; }
void Maintenance::setStatut(const QString &stat) { statut = stat; }
void Maintenance::setIdTechnicien(int id) { id_technicien = id; }
void Maintenance::setEmailTechnicien(const QString &email) { email_technicien = email; }
void Maintenance::setNumeroTelephone(int tel) { numero_telephone = tel; }
void Maintenance::setIdService(int id) { id_service = id; }

// CRUD Operations implementation
bool Maintenance::addMaintenance() const
{
    // Vérifier si la connexion est ouverte
    if (!QSqlDatabase::database().isOpen()) {
        qDebug() << "La base de données n'est pas ouverte lors de l'ajout";
        return false;
    }

    QSqlQuery query;
    query.prepare("INSERT INTO MAINTENANCE (ID_MAINTENANCE, DESCRIPTION, TYPE_MAINTENANCE, "
                  "CATEGORIE, DATE_MAINTENANCE, STATUT, ID_TECHNICIEN, EMAIL_TECHNICIEN, "
                  "NUMERO_TELEPHONE, ID_SERVICE) "
                  "VALUES (:id, :desc, :type, :cat, :date, :stat, :id_tech, :email, :tel, :id_serv)");

    query.bindValue(":id", id_maintenance);
    query.bindValue(":desc", description);
    query.bindValue(":type", type_maintenance);
    query.bindValue(":cat", categorie);
    query.bindValue(":date", date_maintenance);
    query.bindValue(":stat", statut);
    query.bindValue(":id_tech", id_technicien);
    query.bindValue(":email", email_technicien);
    query.bindValue(":tel", numero_telephone);
    query.bindValue(":id_serv", id_service);

    if(!query.exec()) {
        qDebug() << "Error adding maintenance:" << query.lastError().text();
        return false;
    }
    return true;
}

QList<Maintenance> Maintenance::getAllMaintenance()
{
    QList<Maintenance> maintenances;

    // Vérifier si la connexion est ouverte
    if (!QSqlDatabase::database().isOpen()) {
        qDebug() << "La base de données n'est pas ouverte lors de la récupération";
        return maintenances; // Retourner une liste vide
    }

    QSqlQuery query;
    if (!query.exec("SELECT * FROM MAINTENANCE")) {
        qDebug() << "Erreur lors de l'exécution de la requête SELECT:" << query.lastError().text();
        return maintenances; // Retourner une liste vide
    }

    while(query.next()) {
        Maintenance m;
        m.setIdMaintenance(query.value("ID_MAINTENANCE").toInt());
        m.setDescription(query.value("DESCRIPTION").toString());
        m.setTypeMaintenance(query.value("TYPE_MAINTENANCE").toString());
        m.setCategorie(query.value("CATEGORIE").toString());
        m.setDateMaintenance(query.value("DATE_MAINTENANCE").toDate());
        m.setStatut(query.value("STATUT").toString());
        m.setIdTechnicien(query.value("ID_TECHNICIEN").toInt());
        m.setEmailTechnicien(query.value("EMAIL_TECHNICIEN").toString());
        m.setNumeroTelephone(query.value("NUMERO_TELEPHONE").toInt());
        m.setIdService(query.value("ID_SERVICE").toInt());

        maintenances.append(m);
    }

    qDebug() << "Nombre de maintenances récupérées de la base:" << maintenances.size();
    return maintenances;
}

bool Maintenance::updateMaintenance() const
{
    // Vérifier si la connexion est ouverte
    if (!QSqlDatabase::database().isOpen()) {
        qDebug() << "La base de données n'est pas ouverte lors de la mise à jour";
        return false;
    }

    QSqlQuery query;
    query.prepare("UPDATE MAINTENANCE SET DESCRIPTION = :desc, TYPE_MAINTENANCE = :type, "
                  "CATEGORIE = :cat, DATE_MAINTENANCE = :date, STATUT = :stat, "
                  "ID_TECHNICIEN = :id_tech, EMAIL_TECHNICIEN = :email, "
                  "NUMERO_TELEPHONE = :tel, ID_SERVICE = :id_serv "
                  "WHERE ID_MAINTENANCE = :id");

    query.bindValue(":id", id_maintenance);
    query.bindValue(":desc", description);
    query.bindValue(":type", type_maintenance);
    query.bindValue(":cat", categorie);
    query.bindValue(":date", date_maintenance);
    query.bindValue(":stat", statut);
    query.bindValue(":id_tech", id_technicien);
    query.bindValue(":email", email_technicien);
    query.bindValue(":tel", numero_telephone);
    query.bindValue(":id_serv", id_service);

    if(!query.exec()) {
        qDebug() << "Error updating maintenance:" << query.lastError().text();
        return false;
    }
    return true;
}

bool Maintenance::deleteMaintenance(int id)
{
    // Vérifier si la connexion est ouverte
    if (!QSqlDatabase::database().isOpen()) {
        qDebug() << "La base de données n'est pas ouverte lors de la suppression";
        return false;
    }

    QSqlQuery query;
    query.prepare("DELETE FROM MAINTENANCE WHERE ID_MAINTENANCE = :id");
    query.bindValue(":id", id);

    if(!query.exec()) {
        qDebug() << "Error deleting maintenance:" << query.lastError().text();
        return false;
    }
    return true;
}
// Dans le fichier maintenance.cpp
Maintenance Maintenance::getMaintenance(int id)
{
    Maintenance maintenance;
    QSqlQuery query;
    query.prepare("SELECT * FROM maintenance WHERE id_maintenance = :id");
    query.bindValue(":id", id);

    if (query.exec() && query.next()) {
        maintenance.setIdMaintenance(query.value("id_maintenance").toInt());
        maintenance.setDescription(query.value("description").toString());
        maintenance.setTypeMaintenance(query.value("type_maintenance").toString());
        maintenance.setCategorie(query.value("categorie").toString());
        maintenance.setDateMaintenance(query.value("date_maintenance").toDate());
        maintenance.setStatut(query.value("statut").toString());
        maintenance.setIdTechnicien(query.value("id_technicien").toInt());
        maintenance.setEmailTechnicien(query.value("email_technicien").toString());
        maintenance.setNumeroTelephone(query.value("numero_telephone").toInt());
        maintenance.setIdService(query.value("id_service").toInt());
    }

    return maintenance;
}
