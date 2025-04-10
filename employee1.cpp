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

    query.prepare("INSERT INTO EMPLOYE (ID_EMPLOYE,NOM, PRENOM, POSTE, SALAIRE, STATUS, ADRESSE, ROLE, DATE_E) "
                  "VALUES (EMPLOYÉ_SEQ.NEXTVAL, :NOM, :PRENOM, :POSTE, :SALAIRE, :STATUS, :ADRESSE, :ROLE, TO_DATE(:DATE_E, 'YYYY-MM-DD'))");
    query.bindValue(":ID_EMPLOYE", id_employe);
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

bool employee1::modifier(int id, QString nom, QString prenom, QString poste, double salaire, QString status, QString adresse, QString role, QDateTime dateE)
{
    QSqlQuery query;

    // Prepare the query with TO_DATE to handle the date format correctly for Oracle
    query.prepare("UPDATE EMPLOYE SET NOM=:nom, PRENOM=:prenom, POSTE=:poste, SALAIRE=:salaire, STATUS=:status, ADRESSE=:adresse, ROLE=:role, DATE_E=TO_DATE(:dateE, 'YYYY-MM-DD') WHERE ID_EMPLOYE=:id");

    query.bindValue(":id", id);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":poste", poste);
    query.bindValue(":salaire", salaire);
    query.bindValue(":status", status);
    query.bindValue(":adresse", adresse);
    query.bindValue(":role", role);
    query.bindValue(":dateE", dateE.toString("yyyy-MM-dd")); // Ensure the date is in 'YYYY-MM-DD' format

    if (!query.exec()) {

        qDebug() << "Erreur SQL lors de la modification :" << query.lastError().text();
        return false;
    }

    qDebug() << "Employé modifié avec succès!";
    return true;
}

employee1 employee1::chercherParId(int id)
{
    employee1 emp; // Employé vide par défaut

    QSqlQuery query;
    query.prepare("SELECT * FROM EMPLOYE WHERE ID_EMPLOYE = :ID");
    query.bindValue(":ID", id);

    if (query.exec()) {
        if (query.next()) { // Si un employé est trouvé
            emp.setNom(query.value("NOM").toString());
            emp.setPrenom(query.value("PRENOM").toString());
            emp.setPoste(query.value("POSTE").toString());
            emp.setSalaire(query.value("SALAIRE").toDouble());
            emp.setStatus(query.value("STATUS").toString());
            emp.setAdresse(query.value("ADRESSE").toString());
            emp.setRole(query.value("ROLE").toString());
            emp.setDateEmbauche(QDateTime(query.value("DATE_E").toDate(), QTime(12, 0, 0)));
        }
    } else {
        qDebug() << "Erreur SQL lors de la recherche par ID :" << query.lastError().text();
    }

    return emp; // Retourne l'employé trouvé ou un objet vide si aucun résultat
}

QSqlQueryModel* employee1::rechercherParNom(QString nomRecherche)
{
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query;

    query.prepare("SELECT ID_EMPLOYE, NOM, PRENOM, POSTE, SALAIRE, STATUS, ADRESSE, ROLE, DATE_E FROM Employe WHERE LOWER(nom) LIKE LOWER(:nom)");
    query.bindValue(":nom", "%" + nomRecherche.toLower() + "%");

    if (!query.exec()) {
        qDebug() << "Erreur lors de la recherche : " << query.lastError().text();
        return nullptr;
    }

    model->setQuery(query);
    return model;
}

QSqlQueryModel* employee1::trier(QString critere, QString ordre)
{
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query;

    // Préparer la requête avec le critère et l'ordre de tri
    query.prepare("SELECT ID_EMPLOYE, NOM, PRENOM, POSTE, SALAIRE, STATUS, ADRESSE, ROLE, DATE_E FROM EMPLOYE ORDER BY " + critere + " " + ordre);

    // Vérification de l'exécution de la requête
    if (!query.exec()) {
        qDebug() << "Erreur lors de l'exécution de la requête de tri:" << query.lastError().text();
        return nullptr;
    }

    // Définir le modèle de requête
    model->setQuery(query);

    // Définir les en-têtes des colonnes
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

employee1::employee1(int id, const QString& name, double salary)
    : id(id), name(name), salary(salary) {}

int employee1::getId() const {
    return id;
}

QString employee1::getName() const {
    return name;
}

double employee1::getSalary() const {
    return salary;
}
