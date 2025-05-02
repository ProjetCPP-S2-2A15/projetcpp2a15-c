#include "mainwindow.h"
#include "arduinointerface.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Création de l'objet de connexion à la base de données
    Connection c;
    bool test = c.createconnect();

    // Création de la fenêtre principale de l'application
    MainWindow w;

    // Création de la fenêtre ArduinoInterface et affichage
    ArduinoInterface arduinoInterface;  // Création de l'interface Arduino
    arduinoInterface.setWindowTitle("📡 Interface Arduino");
    arduinoInterface.resize(400, 300);
    arduinoInterface.show();  // Affiche la fenêtre ArduinoInterface

    // Vérification de la connexion à la base de données
    if (test) {
        w.show();  // Affiche la fenêtre principale si la connexion est réussie
        QMessageBox::information(nullptr, QObject::tr("Database is open"),
                                 QObject::tr("Connection successful.\nClick Cancel to exit."),
                                 QMessageBox::Cancel);
    } else {
        QMessageBox::critical(nullptr, QObject::tr("Database is not open"),
                              QObject::tr("Connection failed.\nClick Cancel to exit."),
                              QMessageBox::Cancel);
    }

    // Exécution de l'application
    return a.exec();
}
