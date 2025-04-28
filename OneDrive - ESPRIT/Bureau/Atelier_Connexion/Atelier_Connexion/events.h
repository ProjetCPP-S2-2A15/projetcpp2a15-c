#ifndef EVENTS_H
#define EVENTS_H

#include <QString>
#include <QDate>
#include <QTime>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDebug>

class Events {
public:
    // Constructor with default values for flexibility
    Events(int id = 0, const QString &nom = "", const QString &description = "", const QString &type = "",
           const QString &telephone = "", const QDate &date_ev = QDate(), const QTime &heure = QTime(),
           const QString &lieu = "");

    // Method to add a new event
    bool ajouter();

    // Method to modify an existing event
    bool modifier(int id, const QString &nom, const QString &description, const QString &type,
                  const QString &telephone, const QDate &date_ev, const QTime &heure, const QString &lieu);

    bool supprimer(int id);


    // Method to display all events in a QSqlQueryModel
    QSqlQueryModel* afficher();

    // Getter and Setter for the ID
    void setId(int id);
    int getId() const;

    // Static methods for managing the database connection
    static bool ouvrirConnexion();
    static void fermerConnexion();

private:
    // Event details
    int id;
    QString nom;
    QString description;
    QString type;
    QString telephone;
    QDate date_ev;
    QTime heure;
    QString lieu;

    // Static database connection object (shared across all instances)
    static QSqlDatabase db;
};

#endif // EVENTS_H
