#include "employe.h"


employe::employe(){}
employe::employe(int id, QString nom, QString prenom, QString dateEmbauche, QString poste, double salaire,
                 QString statut, QString email, QString adresse, QString motDePasse, QString role) {
    this->id = id;
    this->nom = nom;
    this->prenom = prenom;
    this->dateEmbauche = dateEmbauche;
    this->poste = poste;
    this->salaire = salaire;
    this->statut = statut;
    this->email = email;
    this->adresse = adresse;
    this->motDePasse = motDePasse;
    this->role = role;
}

// Getters
int employe::getId() const { return id; }
QString employe::getNom() const { return nom; }
QString employe::getPrenom() const { return prenom; }
QString employe::getDateEmbauche() const { return dateEmbauche; }
QString employe::getPoste() const { return poste; }
double employe::getSalaire() const { return salaire; }
QString employe::getStatut() const { return statut; }
QString employe::getEmail() const { return email; }
QString employe::getAdresse() const { return adresse; }
QString employe::getMotDePasse() const { return motDePasse; }
QString employe::getRole() const { return role; }

// Setters
void employe::setId(int id) { this->id = id; }
void employe::setNom(QString nom) { this->nom = nom; }
void employe::setPrenom(QString prenom) { this->prenom = prenom; }
void employe::setDateEmbauche(QString date) { this->dateEmbauche = date; }
void employe::setPoste(QString poste) { this->poste = poste; }
void employe::setSalaire(double salaire) { this->salaire = salaire; }
void employe::setStatut(QString statut) { this->statut = statut; }
void employe::setEmail(QString email) { this->email = email; }
void employe::setAdresse(QString adresse) { this->adresse = adresse; }
void employe::setMotDePasse(QString mdp) { this->motDePasse = mdp; }
void employe::setRole(QString role) { this->role = role; }
