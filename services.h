#ifndef SERVICES_H
#define SERVICES_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Services
{
public:
    // Constructeurs
    Services();
    Services(int id, QString nom, double prix, QString description, QString statut, QString type, QString dateDebut, QString dateFin);

    // Getters
    int getIdService() { return id_service; }
    QString getNom() { return Nom; }
    double getPrix() { return Prix; }
    QString getDescription() { return Description; }
    QString getStatut() { return Statut; }
    QString getType() { return Type; }
    QString getDateDebut() { return DateDebut; }
    QString getDateFin() { return DateFin; }

    // Setters
    void setIdService(int id) { id_service = id; }
    void setNom(QString nom) { Nom = nom; }
    void setPrix(double prix) { Prix = prix; }
    void setDescription(QString description) { Description = description; }
    void setStatut(QString statut) { Statut = statut; }
    void setType(QString type) { Type = type; }
    void setDateDebut(QString dateDebut) { DateDebut = dateDebut; }
    void setDateFin(QString dateFin) { DateFin = dateFin; }

    // Fonctionnalités CRUD
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int id);
    bool modifier(int id, QString nom, double prix, QString description, QString statut, QString type, QString dateDebut, QString dateFin);

private:
    int id_service;
    QString Nom;
    double Prix;
    QString Description;
    QString Statut;
    QString Type;
    QString DateDebut;
    QString DateFin;
};

#endif // SERVICES_H
