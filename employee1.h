#ifndef EMPLOYEE1_H
#define EMPLOYEE1_H

#include <QString>
#include<QDateTime>
#include <QSqlQuery>
#include <QSqlQueryModel>
class employee1
{
public:
    employee1();

    employee1(int id, QString nom, QString prenom, QString poste, double salaire, QString status, QString adresse, QString role, QDateTime dateEmbauche);
    int getId() { return id_employe; }
    QString getNom() { return Nom; }
    QString getPrenom() { return Prenom; }
    QString getPoste() { return Poste; }
    double getSalaire() { return Salaire; }
    QString getStatus() { return Status; }
    QString getAdresse() { return Adresse; }
    QString getRole() { return Role; }
    QDateTime getDateEmbauche() { return DateEmbauche; }

    // Setters
    void setId(int id) { id_employe = id; }
    void setNom(QString nom) { Nom = nom; }
    void setPrenom(QString prenom) { Prenom = prenom; }
    void setPoste(QString poste) { Poste = poste; }
    void setSalaire(double salaire) { Salaire = salaire; }
    void setStatus(QString status) { Status = status; }
    void setAdresse(QString adresse) { Adresse = adresse; }
    void setRole(QString role) { Role = role; }
    void setDateEmbauche(QDateTime dateEmbauche) { DateEmbauche = dateEmbauche; }

    // Fonctionnalités CRUD
    bool ajouter();
    QSqlQueryModel *afficher();  // Déclaration correcte
    bool supprimer(int id);
    bool modifier(int id, QString nom, QString prenom, QString poste, double salaire,
                  QString status, QString adresse, QString role, QDateTime dateEmbauche);


private:
    int id_employe;
    QString Nom;
    QString Prenom;
    QString Poste;
    double Salaire;
    QString Status;
    QString Adresse;
    QString Role;
    QDateTime DateEmbauche;



};



#endif // EMPLOYEE1_H
