#include "arduino.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>
#include <QVariant>
#include <QDebug>

Arduino::Arduino()
{
    data = "";
    arduino_port_name = "";
    arduino_is_available = false;
    Serial = new QSerialPort;
}

QString Arduino::getarduino_port_name()
{
    return arduino_port_name;
}

QSerialPort* Arduino::getserial()
{
    return Serial;
}

int Arduino::connect_arduino()
{
    foreach (const QSerialPortInfo &serial_port_info, QSerialPortInfo::availablePorts())
    {
        if (serial_port_info.hasVendorIdentifier() && serial_port_info.hasProductIdentifier())
        {
            if (serial_port_info.vendorIdentifier() == arduino_uno_vendor_id &&
                serial_port_info.productIdentifier() == arduino_uno_product_id)
            {
                arduino_is_available = true;
                arduino_port_name = serial_port_info.portName();
            }
        }
    }

    qDebug() << "arduino_port_name is: " << arduino_port_name;

    if (arduino_is_available)
    {
        Serial->setPortName(arduino_port_name);

        // Essayer d'ouvrir le port série
        if (Serial->open(QSerialPort::ReadWrite))
        {
            qDebug() << "Port ouvert avec succès : " << arduino_port_name;
            Serial->setBaudRate(QSerialPort::Baud9600);
            Serial->setDataBits(QSerialPort::Data8);
            Serial->setParity(QSerialPort::NoParity);
            Serial->setStopBits(QSerialPort::OneStop);
            Serial->setFlowControl(QSerialPort::NoFlowControl);
            return 0;
        }
        else
        {
            qDebug() << "Erreur d'ouverture du port : " << Serial->errorString();
            return 1;  // Retourner une erreur avec le code d'erreur
        }
    }
    else
    {
        qDebug() << "Arduino non détecté sur les ports disponibles.";
        return -1;
    }
}

int Arduino::close_arduino()
{
    if (Serial->isOpen())
    {
        Serial->close();
        return 0;
    }
    return 1;
}

QByteArray Arduino::read_from_arduino()
{
    if (Serial->isReadable())
    {
        data = Serial->readAll();
        QString readableData = QString(data).trimmed();
        qDebug() << "📡 UID reçu depuis Arduino:" << readableData;
        return data;
    }
    return "";
}
int Arduino::write_to_arduino(QByteArray d)
{
    if (Serial->isWritable()) {
        Serial->write(d);
        return 0;
    } else {
        qDebug() << "⚠️ Impossible d'écrire sur le port série Arduino !";
        return 1;
    }
}

QByteArray Arduino::cherchercode(QString rfid)
{
    QSqlQuery query;
    query.prepare("SELECT NOM, PRENOM FROM EMPLOYE WHERE RFID = :rfid");
    query.bindValue(":rfid", rfid);

    if (query.exec())
    {
        if (query.next())
        {
            QString nom = query.value("NOM").toString();
            QString prenom = query.value("PRENOM").toString();
            qDebug() << "✅ Accès autorisé pour :" << nom << prenom;
            return "1"; // Accès autorisé
        }
        else
        {
            qDebug() << "❌ Accès refusé : UID inconnu dans la base";
            return "0"; // UID non trouvé
        }
    }
    else
    {
        qDebug() << "❌ Erreur SQL :" << query.lastError().text();
        return "0"; // Échec de la requête
    }
}
