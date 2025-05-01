#ifndef ARDUINO_H
#define ARDUINO_H

#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>

class Arduino
{
public:
    Arduino();
    int connect_arduino();  // Connecte le PC à Arduino
    int close_arduino();    // Ferme la connexion
    int write_to_arduino(QByteArray data);  // Envoie des données vers Arduino
    QByteArray read_from_arduino();  // Reçoit des données de la carte Arduino
    QSerialPort* getserial();  // Accesseur pour obtenir l'objet QSerialPort
    QString getarduino_port_name();  // Retourne le nom du port série

private:
    QSerialPort* serial;  // Objet représentant la connexion série avec Arduino
    static const quint16 arduino_uno_vendor_id = 9025;  // Identifiant du vendeur Arduino Uno
    static const quint16 arduino_uno_product_id = 67;   // Identifiant du produit Arduino Uno
    QString arduino_port_name;  // Nom du port série
    bool arduino_is_available;  // Indique si Arduino est disponible
    QByteArray data;  // Contient les données lues à partir d'Arduino
};

#endif // ARDUINO_H
