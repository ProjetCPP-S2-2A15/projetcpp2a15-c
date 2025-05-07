#ifndef STATISTIQUE_H
#define STATISTIQUE_H

#include <QString>
#include <QMap>
#include <QPair>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QChart>
#include <QPieSeries>
#include <QPieSlice>

class Statistique
{
public:
    Statistique();
    ~Statistique();

    // Méthode pour récupérer les statistiques de salaire par poste
    QMap<QString, int> calculerEmploisParPoste();

    // Méthode pour créer le graphique en pie chart
    QChart* creerGraphiqueSalaireParPoste();
signals:
    void employeModifie(); // Signal pour informer que les employés ont changé

private slots:
    void mettreAJourStatistiques(); // Méthode pour rafraîchir le graphique

    void on_pushButton_stat_clicked();
    void on_pushButton_ajouter_clicked(); // Lorsqu'on ajoute un employé
    void on_pushButton_supprimer_clicked(); // Lorsqu'on supprime un employé
    void on_pushButton_modifier_clicked(); // Lorsqu'on modifie un employé

private:
    // Méthode pour récupérer les employés par poste et leur salaire
    QMap<QString, QPair<double, double>> salairePoste();

    // Méthode d'exécution SQL pour obtenir les données
    int obtenirNombreEmployesParPosteSalaire(const QString &poste, double minSalaire, double maxSalaire);
};

#endif // STATISTIQUE_H
