#ifndef EVENTS_H
#define EVENTS_H

#include <QString>
#include <QDate>
#include <QTime>
#include <QSqlDatabase>
#include <QSqlQueryModel>

class Events
{
public:
    Events(); // Constructeur par défaut
    Events(int id, const QString &nom, const QString &description, const QString &type,
           const QString &telephone, const QDate &date_ev, const QTime &heure, const QString &lieu);

    bool ajouter();
    bool modifier(int id, const QString &nom, const QString &description, const QString &type,
                  const QString &telephone, const QDate &date_ev, const QTime &heure, const QString &lieu);
    bool supprimer(int id);
    QSqlQueryModel* afficher();

    static bool ouvrirConnexion();
    static void fermerConnexion();

    // Getters / Setters
    void setId(int id);
    int getId() const;

private:
    int id;
    QString nom;
    QString description;
    QString type;
    QString telephone;
    QDate date_ev;
    QTime heure;
    QString lieu;

    static QSqlDatabase db;
};

#endif // EVENTS_H
