#include "statistiqueev.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QChartView>
#include <QChart>
#include <QPieSeries>
#include <QPieSlice>

QMap<QString, int> Statistique::calculerEvenementsParType()
{
    QMap<QString, int> evenementsParType;

    QSqlQuery query;
    if (query.exec("SELECT TYPE, COUNT(*) FROM EVT GROUP BY TYPE")) {
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

QChart* Statistique::creerGraphiqueEvenementsParType()
{
    QMap<QString, int> evenements = calculerEvenementsParType();
    QPieSeries* series = new QPieSeries();

    for (auto it = evenements.constBegin(); it != evenements.constEnd(); ++it) {
        series->append(it.key(), it.value());
    }

    QChart* chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Statistiques par Type");
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignRight);

    return chart;
}
