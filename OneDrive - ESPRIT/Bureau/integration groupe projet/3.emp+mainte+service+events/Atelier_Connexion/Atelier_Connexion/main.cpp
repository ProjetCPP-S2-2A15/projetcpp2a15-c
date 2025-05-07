#include "mainwindow.h"
#include "loginwindow.h"
#include "arduinointerface.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include <QSerialPort>
#include "arduinowidget.h" // Inclure ArduinoWidget pour l'interface Arduino


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Connexion à la base de données
    Connection c;
    bool test = c.createconnect();

    if (test) {
        // Affichage d'une fenêtre d'information si la connexion est réussie
        QMessageBox::information(nullptr, QObject::tr("Database Open"),
                                 QObject::tr("Connection successful.\nClick OK to continue."),
                                 QMessageBox::Ok);

        // Lancement de la fenêtre de connexion
        loginwindow login;
        login.show();

        // Création de la fenêtre ArduinoWidget
        ArduinoWidget w;
        w.setWindowTitle("📡 Interface Arduino RFID");
        w.resize(400, 300);
        w.show();  // Affichage de la fenêtre Arduino
        ////////////////////////////////////////////////////////////////////////////////////////////////////
        // Création de la fenêtre ArduinoInterface et affichage
        ArduinoInterface arduinoInterface;  // Création de l'interface Arduino
        arduinoInterface.setWindowTitle("📡 Interface Arduino");
        arduinoInterface.resize(400, 300);
        arduinoInterface.show();  // Affiche la fenêtre ArduinoInterface

        return a.exec(); // Exécution de l'application principale
    } else {
        // Message d'erreur en cas d'échec de la connexion
        QMessageBox::critical(nullptr, QObject::tr("Database Not Open"),
                              QObject::tr("Connection failed.\nClick Cancel to exit."),
                              QMessageBox::Cancel);

        return 0; // Retour propre en cas d'échec de la connexion
    }
}
