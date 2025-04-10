#include "statistique.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QtCharts/QChart>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>

Statistique::Statistique()
{
}

Statistique::~Statistique()
{
}

QMap<QString, QPair<double, double>> Statistique::salairePoste()
{
    QMap<QString, QPair<double, double>> salairePoste = {
        {"Responsable Maintenance", {2500, 5000}},
        {"Responsable Evenements", {2800, 5500}},
        {"Responsable Services", {2700, 5200}},
        {"Responsable Locataires", {2600, 5100}},
        {"Responsable locaux comerciaux", {3000, 6000}},
        {"Responsable Employees", {2200, 4500}},
        {"Technicien", {1500, 3500}},
        {"Agent de Sécurité", {1200, 3000}}
    };

    return salairePoste;
}

int Statistique::obtenirNombreEmployesParPosteSalaire(const QString &poste, double minSalaire, double maxSalaire)
{
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM EMPLOYE WHERE POSTE = :poste AND SALAIRE BETWEEN :minSalaire AND :maxSalaire");
    query.bindValue(":poste", poste);
    query.bindValue(":minSalaire", minSalaire);
    query.bindValue(":maxSalaire", maxSalaire);

    if (query.exec() && query.next()) {
        return query.value(0).toInt();
    } else {
        qDebug() << "Erreur lors de l'exécution de la requête SQL :" << query.lastError().text();
        return 0;
    }
}

QMap<QString, int> Statistique::calculerEmploisParPoste()
{
    QMap<QString, int> employesParPoste;
    QMap<QString, QPair<double, double>> salairePoste = this->salairePoste();

    // Calcul du nombre d'employés pour chaque poste et salaire
    for (auto it = salairePoste.begin(); it != salairePoste.end(); ++it) {
        QString poste = it.key();
        double minSalaire = it.value().first;
        double maxSalaire = it.value().second;

        int nombreEmployes = this->obtenirNombreEmployesParPosteSalaire(poste, minSalaire, maxSalaire);
        employesParPoste[poste] = nombreEmployes;
    }

    return employesParPoste;
}

QChart* Statistique::creerGraphiqueSalaireParPoste()
{
    QMap<QString, int> employesParPoste = this->calculerEmploisParPoste();

    // Création du graphique en secteur
    QPieSeries *series = new QPieSeries();
    for (auto it = employesParPoste.begin(); it != employesParPoste.end(); ++it) {
        if (it.value() > 0) {
            QPieSlice *slice = series->append(it.key() + ": " + QString::number(it.value()), it.value());
            slice->setLabelVisible(true);  // Afficher les labels sur le graphique
        }
    }

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Répartition des employés selon le poste et le salaire");
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);
    chart->setBackgroundVisible(false);  // Supprimer le fond blanc du QChart

    return chart;
}
