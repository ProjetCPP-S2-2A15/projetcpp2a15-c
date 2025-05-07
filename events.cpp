#include "events.h"
#include <QSqlError>
#include <QMessageBox>
#include <QDebug>
#include <QSqlQuery>

QSqlDatabase Events::db;

Events::Events()
{
    id = 0;
    nom = "";
    description = "";
    type = "";
    telephone = "";
    date_ev = QDate::currentDate();
    heure = QTime::currentTime();
    lieu = "";
}

Events::Events(int id, const QString &nom, const QString &description, const QString &type,
               const QString &telephone, const QDate &date_ev, const QTime &heure, const QString &lieu)
    : id(id), nom(nom), description(description), type(type), telephone(telephone),
    date_ev(date_ev), heure(heure), lieu(lieu) {}

bool Events::ouvrirConnexion() {
    if (!db.isValid()) {
        db = QSqlDatabase::addDatabase("QODBC", "SourceProjet_2A15");
    }

    if (db.isOpen()) {
        return true;
    }

    db.setDatabaseName("source_projet2A15"); // Nom de la source de données
    db.setUserName("SYSTEM");               // Nom d'utilisateur pour la connexion
    db.setPassword("amin123");

    if (!db.open()) {
        qCritical() << "Échec de la connexion à la base de données : " << db.lastError().text();
        return false;
    }
    return true;
}

void Events::fermerConnexion() {
    if (db.isOpen()) {
        db.close();
    }
}

bool Events::ajouter() {
    if (!ouvrirConnexion()) {
        qCritical() << "Impossible d'ouvrir la connexion à la base de données.";
        return false;
    }

    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT COUNT(*) FROM EVT WHERE Nom = :nom AND date_ev = TO_DATE(:date_ev, 'DD-MM-YYYY')");
    checkQuery.bindValue(":nom", nom);
    checkQuery.bindValue(":date_ev", date_ev.toString("dd-MM-yyyy"));

    if (!checkQuery.exec()) {
        qCritical() << "Erreur lors de la vérification de l'existence de l'événement : " << checkQuery.lastError().text();
        return false;
    }

    checkQuery.next();
    int count = checkQuery.value(0).toInt();
    if (count > 0) {
        qDebug() << "L'événement existe déjà !";
        return false;
    }

    QSqlQuery query;
    query.prepare("INSERT INTO EVT (Nom, Description, Type, Num_tel, date_ev, Heure, Lieu) "
                  "VALUES (:nom, :description, :type, :telephone, TO_DATE(:date_ev, 'DD-MM-YYYY'), TO_TIMESTAMP(:heure, 'HH24:MI:SS'), :lieu)");
    query.bindValue(":nom", nom);
    query.bindValue(":description", description);
    query.bindValue(":type", type);
    query.bindValue(":telephone", telephone);
    query.bindValue(":date_ev", date_ev.toString("dd-MM-yyyy"));
    query.bindValue(":heure", heure.toString("HH:mm:ss"));
    query.bindValue(":lieu", lieu);

    if (!query.exec()) {
        qCritical() << "Échec de l'ajout de l'événement : " << query.lastError().text();
        return false;
    }

    qDebug() << "Événement ajouté avec succès !";
    return true;
}

bool Events::modifier(int id, const QString &nom, const QString &description, const QString &type,
                      const QString &telephone, const QDate &date_ev, const QTime &heure, const QString &lieu) {
    if (!ouvrirConnexion()) {
        return false;
    }

    QSqlQuery query;
    query.prepare("UPDATE EVT SET Nom = :nom, Description = :description, Type = :type, "
                  "Num_tel = :telephone, date_ev = TO_DATE(:date_ev, 'DD-MM-YYYY'), "
                  "Heure = TO_TIMESTAMP(:heure, 'HH24:MI:SS'), Lieu = :lieu "
                  "WHERE ID_EVENEMENT = :id_evenement");

    query.bindValue(":id_evenement", id);
    query.bindValue(":nom", nom);
    query.bindValue(":description", description);
    query.bindValue(":type", type);
    query.bindValue(":telephone", telephone);
    query.bindValue(":date_ev", date_ev.toString("dd-MM-yyyy"));
    query.bindValue(":heure", heure.toString("HH:mm:ss"));
    query.bindValue(":lieu", lieu);

    if (!query.exec()) {
        qCritical() << "Échec de la modification de l'événement : " << query.lastError().text();
        return false;
    }

    qDebug() << "Événement modifié avec succès !";
    return true;
}

bool Events::supprimer(int id) {
    if (!ouvrirConnexion()) return false;

    QSqlQuery query;
    query.prepare("DELETE FROM EVT WHERE ID_EVENEMENT = :id");
    query.bindValue(":id", id);

    if (!query.exec()) {
        qCritical() << "Échec de la suppression de l'événement : " << query.lastError().text();
        return false;
    }

    qDebug() << "Événement supprimé avec succès !";
    return true;
}

QSqlQueryModel* Events::afficher() {
    QSqlQuery query;
    query.prepare("SELECT * FROM EVT");
    if (!query.exec()) {
        qCritical() << "Erreur lors de la récupération des événements : " << query.lastError().text();
        return nullptr;
    }

    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery(std::move(query));
    return model;
}

void Events::setId(int id) {
    this->id = id;
}

int Events::getId() const {
    return id;
}
