#ifndef LOCATAIRE_H
#define LOCATAIRE_H

#include <QString>
#include <QDate>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Locataire
{
private:
    int id;
    QString nom;
    QString adresse;
    QString email;
    QString telephone;
    QDate debut_de_contrat;
    QDate fin_de_contrat;

public:
    // Constructeurs
    Locataire() {}
    Locataire(int, QString, QString, QString, QString, QDate, QDate);

    // Getters
    int getId() { return id; }
    QString getNom() { return nom; }
    QString getAdresse() { return adresse; }
    QString getEmail() { return email; }
    QString getTelephone() { return telephone; }
    QDate getDebutDeContrat() { return debut_de_contrat; }
    QDate getFinDeContrat() { return fin_de_contrat; }

    // Setters
    void setId(int i) { id = i; }
    void setNom(QString n) { nom = n; }
    void setAdresse(QString a) { adresse = a; }
    void setEmail(QString e) { email = e; }
    void setTelephone(QString t) { telephone = t; }
    void setDebutDeContrat(QDate d) { debut_de_contrat = d; }
    void setFinDeContrat(QDate f) { fin_de_contrat = f; }

    // Fonctionnalités CRUD
    bool ajouter();
    bool modifier(int, QString, QString, QString, QString, QDate, QDate); // Ajout de cette ligne
    QSqlQueryModel *afficher();
    bool supprimer(int);
    QSqlQueryModel *afficherTrieParDate();
    QSqlQueryModel *afficherTrieParId();
    QSqlQueryModel* statistiquesContratsParMois();
};

#endif // LOCATAIRE_H
