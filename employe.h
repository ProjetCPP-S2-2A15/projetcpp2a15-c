#ifndef EMPLOYE_H
#define EMPLOYE_H
#include <QString>

class employe
{
private:
    int id;
    QString nom;
    QString prenom;
    QString dateEmbauche;
    QString poste;
    double salaire;
    QString statut; // Actif / En congé / Démission
    QString email;
    QString adresse;
    QString motDePasse;
    QString role; // Admin / Responsable

public:
    employe();
    employe(int id, QString nom, QString prenom, QString dateEmbauche, QString poste, double salaire,
            QString statut, QString email, QString adresse, QString motDePasse, QString role);

    // Getters
    int getId() const;
    QString getNom() const;
    QString getPrenom() const;
    QString getDateEmbauche() const;
    QString getPoste() const;
    double getSalaire() const;
    QString getStatut() const;
    QString getEmail() const;
    QString getAdresse() const;
    QString getMotDePasse() const;
    QString getRole() const;

    // Setters
    void setId(int id);
    void setNom(QString nom);
    void setPrenom(QString prenom);
    void setDateEmbauche(QString date);
    void setPoste(QString poste);
    void setSalaire(double salaire);
    void setStatut(QString statut);
    void setEmail(QString email);
    void setAdresse(QString adresse);
    void setMotDePasse(QString mdp);
    void setRole(QString role);
};

#endif // EMPLOYE_H
