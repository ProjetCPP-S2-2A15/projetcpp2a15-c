#include "mainwindow.h"
#include "loginwindow.h"
#include "arduinointerface.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include <QSerialPort>
#include "arduinowidget.h"
#include "mainevent.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Connexion à la base de données
    Connection c;
    bool test = c.createconnect();

    if (!test) {
        // Message d'erreur en cas d'échec de la connexion
        QMessageBox::critical(nullptr, QObject::tr("Database Not Open"),
                              QObject::tr("Connection failed.\nClick Cancel to exit."),
                              QMessageBox::Cancel);
        return 0; // Retour propre en cas d'échec de la connexion
    }

    // Affichage d'une fenêtre d'information si la connexion est réussie
    QMessageBox::information(nullptr, QObject::tr("Database Open"),
                             QObject::tr("Connection successful.\nClick OK to continue."),
                             QMessageBox::Ok);

    // Création des fenêtres
    loginwindow login;
    MainEvent mainEvent;
    ArduinoWidget arduinoWidget;
    ArduinoInterface arduinoInterface;

    // Configuration des fenêtres Arduino
    arduinoWidget.setWindowTitle("📡 Interface Arduino RFID");
    arduinoWidget.resize(400, 300);
    arduinoInterface.setWindowTitle("📡 Interface Arduino");
    arduinoInterface.resize(400, 300);

    // Connecter le signal de login réussi pour afficher MainEvent et les fenêtres Arduino
    QObject::connect(&login, &loginwindow::loginSuccessful, [&]() {
        login.hide(); // Cacher la fenêtre de login
        mainEvent.show(); // Afficher MainEvent
        arduinoWidget.show(); // Afficher ArduinoWidget
        arduinoInterface.show(); // Afficher ArduinoInterface
    });

    // Connecter la fermeture de MainEvent pour quitter l'application
    QObject::connect(&mainEvent, &MainEvent::destroyed, &a, &QApplication::quit);

    // Afficher la fenêtre de login
    login.show();

    return a.exec(); // Exécution de l'application principale
}
