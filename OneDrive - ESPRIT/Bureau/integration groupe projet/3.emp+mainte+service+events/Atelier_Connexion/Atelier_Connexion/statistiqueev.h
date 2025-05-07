#ifndef STATISTIQUEEV_H
#define STATISTIQUEEV_H

#include <QMap>
#include <QChart>

class Statistique {
public:
    Statistique();
    ~Statistique();
    QMap<QString, int> calculerEvenementsParType();
    QChart* creerGraphiqueEvenementsParType();
};

#endif // STATISTIQUEEV_H
