#ifndef LOCAL_H
#define LOCAL_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include "connection.h"
class Local
{
private:
    long long id;
    double surface;
    QString type;
    QString disponibilite; // "Disponible" ou "Loué"
    double prix;
    QString etage;

public:
    // Constructeurs
    Local();
    Local( double, QString, QString, double, QString);
    Local(long long ,double, QString, QString, double, QString);

    // Getters & Setters
    long long getId() const { return id; }
    double getSurface() const { return surface; }
    QString getType() const { return type; }
    QString getDisponibilite() const { return disponibilite; }
    double getPrix() const { return prix; }
    QString getEtage() const { return etage; }

    void setSurface(double s) { surface = s; }
    void setType(QString t) { type = t; }
    void setDisponibilite(QString d) { disponibilite = d; }
    void setPrix(double p) { prix = p; }
    void setEtage(QString e) { etage = e; }

    // Méthodes CRUD
    bool ajouter();
    bool modifier(long long id);
    bool supprimer(long long id);
    QSqlQueryModel* afficher();
};

#endif // LOCAL_H
