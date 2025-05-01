#include "arduino.h"

Arduino::Arduino() {
    serial = new QSerialPort();
    arduino_is_available = false;
}

int Arduino::connect_arduino() {
    // Recherche d'un port série compatible avec Arduino
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
        if (info.vendorIdentifier() == arduino_uno_vendor_id &&
            info.productIdentifier() == arduino_uno_product_id) {
            arduino_port_name = info.portName();
            serial->setPort(info);
            serial->setBaudRate(QSerialPort::Baud9600);
            serial->setDataBits(QSerialPort::Data8);
            serial->setParity(QSerialPort::NoParity);
            serial->setStopBits(QSerialPort::OneStop);
            serial->setFlowControl(QSerialPort::NoFlowControl);
            if (serial->open(QIODevice::ReadWrite)) {
                arduino_is_available = true;
                return 0;  // Succès
            }
        }
    }
    return -1;
}

int Arduino::close_arduino() {
    if (serial->isOpen()) {
        serial->close();
        arduino_is_available = false;
        return 0;
    }
    return -1;
}

int Arduino::write_to_arduino(QByteArray data) {
    if (arduino_is_available && serial->isOpen()) {
        serial->write(data);
        return 0;
    }
    return -1;
}

QByteArray Arduino::read_from_arduino() {
    data.clear();
    if (arduino_is_available && serial->isOpen()) {
        // Lecture des données
        data = serial->readAll();
        while (serial->waitForReadyRead(10)) {
            data.append(serial->readAll());
        }
    }
    return data;
}

QSerialPort* Arduino::getserial() {
    return serial;
}

QString Arduino::getarduino_port_name() {
    return arduino_port_name;
}
