#include "mainwindow.h"
#include "connection.h"
#include <QApplication>
#include <QMessageBox>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);  // Utilisez QApplication pour une application avec interface graphique

    qDebug() << "Tentative de connexion à la base de données.";

    if (!createConnection()) {
        qDebug() << "Échec de la connexion.";
        QMessageBox::critical(nullptr, "Erreur de connexion", "Impossible de se connecter à la base de données.");
        return -1;
    }

    qDebug() << "Connexion réussie. Lancement de la fenêtre principale.";

    MainWindow w;
    w.show();

    return a.exec();  // Lancement de la boucle principale de l'application
}
