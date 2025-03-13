#include "employee1.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QtDebug>
#include <QObject>

employee1::employee1() {
    // id_employe = 0;
    Nom = "";
    Prenom = "";
    Poste = "";
    Salaire = 0.0;
    Status = "";
    Adresse = "";
    Role = "";
    DateEmbauche = QDateTime();
}

employee1::employee1(int id, QString nom, QString prenom, QString poste, double salaire, QString status, QString adresse, QString role, QDateTime dateEmbauche)
{
    this->id_employe = id;
    this->Nom = nom;
    this->Prenom = prenom;
    this->Poste = poste;
    this->Salaire = salaire;
    this->Status = status;
    this->Adresse = adresse;
    this->Role = role;
    this->DateEmbauche = dateEmbauche;
}

bool employee1::ajouter()
{
    QSqlQuery query;

    query.prepare("INSERT INTO EMPLOYE (ID_EMPLOYE, NOM, PRENOM, POSTE, SALAIRE, STATUS, ADRESSE, ROLE, DATE_E) "
                  "VALUES (EMPLOYÉ_SEQ.NEXTVAL, :NOM, :PRENOM, :POSTE, :SALAIRE, :STATUS, :ADRESSE, :ROLE, TO_DATE(:DATE_E, 'YYYY-MM-DD'))");

    query.bindValue(":NOM", Nom);
    query.bindValue(":PRENOM", Prenom);
    query.bindValue(":POSTE", Poste);
    query.bindValue(":SALAIRE", Salaire);
    query.bindValue(":STATUS", Status);
    query.bindValue(":ADRESSE", Adresse);
    query.bindValue(":ROLE", Role);
    query.bindValue(":DATE_E", DateEmbauche.toString("yyyy-MM-dd"));

    if (!query.exec()) {
        qDebug() << "Erreur SQL lors de l'ajout de l'employé :" << query.lastError().text();
        return false;
    }

    qDebug() << "Employé ajouté avec succès!";
    return true;
}

QSqlQueryModel *employee1::afficher()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT ID_EMPLOYE, NOM, PRENOM, POSTE, SALAIRE, STATUS, ADRESSE, ROLE, DATE_E FROM EMPLOYE");

    if (model->lastError().isValid()) {
        qDebug() << "Erreur lors de l'affichage des employés:" << model->lastError().text();
    }

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_EMPLOYE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("POSTE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("SALAIRE"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("STATUS"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("ADRESSE"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("ROLE"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("DATE_E"));

    return model;
}

bool employee1::supprimer(int id_employe)
{
    QSqlQuery query;
    query.prepare("DELETE FROM EMPLOYE WHERE ID_EMPLOYE = :ID_EMPLOYE");
    query.bindValue(":ID_EMPLOYE", id_employe);

    if (!query.exec()) {
        qDebug() << "Erreur SQL lors de la suppression :" << query.lastError().text();
        return false;
    }

    qDebug() << "Employé supprimé avec succès!";
    return true;
}

bool employee1::modifier(int id, QString nom, QString prenom, QString poste, double salaire, QString status, QString adresse, QString role, QDateTime dateEmbauche)
{
    if (id <= 0) {
        qDebug() << "Erreur : ID invalide (" << id << ")";
        return false;
    }

    // Vérifier si l'ID existe avant modification
    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT COUNT(*) FROM EMPLOYE WHERE ID_EMPLOYE = :ID");
    checkQuery.bindValue(":ID", id);
    if (!checkQuery.exec() || !checkQuery.next()) {
        qDebug() << "Erreur SQL lors de la vérification de l'ID :" << checkQuery.lastError().text();
        return false;
    }

    if (checkQuery.value(0).toInt() == 0) {
        qDebug() << "Erreur : Aucun employé trouvé avec l'ID" << id;
        return false;
    }

    // Préparer la requête de mise à jour
    QSqlQuery query;
    query.prepare("UPDATE EMPLOYE SET NOM = :NOM, PRENOM = :PRENOM, POSTE = :POSTE, SALAIRE = :SALAIRE, "
                  "STATUS = :STATUS, ADRESSE = :ADRESSE, ROLE = :ROLE, DATE_E = :DATE_E WHERE ID_EMPLOYE = :ID");

    query.bindValue(":ID", id);
    query.bindValue(":NOM", nom);
    query.bindValue(":PRENOM", prenom);
    query.bindValue(":POSTE", poste);
    query.bindValue(":SALAIRE", salaire);
    query.bindValue(":STATUS", status);
    query.bindValue(":ADRESSE", adresse);
    query.bindValue(":ROLE", role);
    query.bindValue(":DATE_E", dateEmbauche.toString("yyyy-MM-dd")); // Format pour colonne DATE

    // Débogage : Afficher les valeurs
    qDebug() << "Valeurs bindées -> ID:" << id << ", Nom:" << nom << ", Prénom:" << prenom
             << ", Poste:" << poste << ", Salaire:" << salaire << ", Status:" << status
             << ", Adresse:" << adresse << ", Rôle:" << role << ", Date Embauche:" << dateEmbauche.toString("yyyy-MM-dd");

    // Exécuter la requête
    if (!query.exec()) {
        qDebug() << "Erreur SQL lors de la modification :" << query.lastError().text();
        return false;
    }

    // Vérifier si la modification a bien eu lieu
    if (query.numRowsAffected() == 0) {
        qDebug() << "Aucune modification effectuée. Vérifie si les nouvelles valeurs sont identiques aux anciennes.";
        return false;
    }

    qDebug() << "Employé modifié avec succès!";
    return true;
}
