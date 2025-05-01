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

class Statistique : public QObject
{
    Q_OBJECT

public:
    Statistique();
    ~Statistique();

    QMap<QString, int> calculerEvenementsParType();
    QChart* creerGraphiqueEvenementsParType();

};

#endif // STATISTIQUE_H
