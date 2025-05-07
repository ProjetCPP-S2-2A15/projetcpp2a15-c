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

Arduino::~Arduino()
{
    if (Serial->isOpen()) {
        Serial->close();
    }
    delete Serial;
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
    foreach (const QSerialPortInfo &serial_port_info, QSerialPortInfo::availablePorts()) {
        if (serial_port_info.hasVendorIdentifier() && serial_port_info.hasProductIdentifier()) {
            if (serial_port_info.vendorIdentifier() == arduino_uno_vendor_id &&
                serial_port_info.productIdentifier() == arduino_uno_product_id) {
                arduino_is_available = true;
                arduino_port_name = serial_port_info.portName();
            }
        }
    }

    qDebug() << "Arduino port name is:" << arduino_port_name;

    if (arduino_is_available) {
        Serial->setPortName(arduino_port_name);
        if (Serial->open(QSerialPort::ReadWrite)) {
            qDebug() << "Port opened successfully:" << arduino_port_name;
            Serial->setBaudRate(QSerialPort::Baud9600);
            Serial->setDataBits(QSerialPort::Data8);
            Serial->setParity(QSerialPort::NoParity);
            Serial->setStopBits(QSerialPort::OneStop);
            Serial->setFlowControl(QSerialPort::NoFlowControl);
            return 0; // Success
        } else {
            qDebug() << "Error opening port:" << Serial->errorString();
            return 1; // Error opening port
        }
    } else {
        qDebug() << "Arduino not detected on available ports.";
        return -1; // Arduino not available
    }
}

int Arduino::close_arduino()
{
    if (Serial->isOpen()) {
        Serial->close();
        return 0;
    }
    return 1;
}

QByteArray Arduino::read_from_arduino()
{
    if (Serial->isReadable()) {
        data = Serial->readAll();
        QString readableData = QString(data).trimmed();
        qDebug() << "📡 UID received from Arduino:" << readableData;
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
        qDebug() << "⚠️ Couldn't write to Arduino!";
        return 1;
    }
}

QByteArray Arduino::cherchercode(QString rfid)
{
    QSqlQuery query;
    query.prepare("SELECT NOM, PRENOM FROM EMPLOYE WHERE RFID = :rfid");
    query.bindValue(":rfid", rfid);

    if (query.exec()) {
        if (query.next()) {
            QString nom = query.value("NOM").toString();
            QString prenom = query.value("PRENOM").toString();
            qDebug() << "✅ Access authorized for:" << nom << prenom;
            return "1"; // Access authorized
        } else {
            qDebug() << "❌ Access denied: Unknown UID in database";
            return "0"; // UID not found
        }
    } else {
        qDebug() << "❌ SQL Error:" << query.lastError().text();
        return "0"; // Query failed
    }
}
