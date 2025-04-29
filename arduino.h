#ifndef ARDUINO_H
#define ARDUINO_H

#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>

class Arduino
{
public:
    Arduino();

    // Méthodes pour la gestion de la connexion avec Arduino
    int connect_arduino();         // Se connecter à Arduino
    int close_arduino();           // Fermer la connexion Arduino
    int write_to_arduino(QByteArray);  // Écrire dans Arduino
    QByteArray read_from_arduino();   // Lire depuis Arduino

    // Méthodes pour récupérer des informations
    QSerialPort* getserial();           // Retourne le port série
    QString getarduino_port_name();     // Retourne le nom du port Arduino

    // Recherche de code RFID dans la base de données Oracle
    QByteArray cherchercode(QString rfid);

private:
    QSerialPort *Serial;           // Objet de communication série
    static const quint16 arduino_uno_vendor_id = 9025;  // Identifiant du vendeur Arduino
    static const quint16 arduino_uno_product_id = 67;   // Identifiant du produit Arduino
    QString arduino_port_name;     // Nom du port série
    bool arduino_is_available;     // Vérification de la disponibilité d'Arduino

    QByteArray data;              // Stocke les données lues depuis Arduino
};

#endif // ARDUINO_H

