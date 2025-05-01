#include "statistique.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QChartView>
#include <QChart>
#include <QPieSeries>
#include <QPieSlice>

Statistique::Statistique() {}

Statistique::~Statistique() {}

QMap<QString, int> Statistique::calculerEvenementsParType()
{
    QMap<QString, int> evenementsParType;

    QSqlQuery query;
    if (query.exec("SELECT TYPE, COUNT(*) FROM EVENTS GROUP BY TYPE")) {
        while (query.next()) {
            QString type = query.value(0).toString();
            int count = query.value(1).toInt();
            evenementsParType[type] = count;
        }
    } else {
        qDebug() << "Erreur lors de l'exécution de la requête SQL :" << query.lastError().text();
    }

    return evenementsParType;
}
QChart *Statistique::creerGraphiqueEvenementsParType()
{
    QPieSeries *series = new QPieSeries();
    series->append("sportif", 5);
    series->append("promotion", 10);
    series->append("musique", 15);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Statistiques par Type");

    return chart;
}

