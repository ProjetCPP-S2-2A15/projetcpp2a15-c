#include "arduino.h"

Arduino::Arduino(QObject *parent) : QObject(parent)
{
    serial = new QSerialPort(this);
    arduino_is_available = false;
    arduino_port_name = "";

    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
        if (info.hasVendorIdentifier() && info.hasProductIdentifier()) {
            arduino_port_name = info.portName();
            arduino_is_available = true;
            break;
        }
    }
}

Arduino::~Arduino()
{
    close_arduino();
}

int Arduino::connect_arduino()
{
    if (arduino_is_available) {
        serial->setPortName(arduino_port_name);
        serial->setBaudRate(QSerialPort::Baud9600);
        serial->setDataBits(QSerialPort::Data8);
        serial->setParity(QSerialPort::NoParity);
        serial->setStopBits(QSerialPort::OneStop);
        serial->setFlowControl(QSerialPort::NoFlowControl);

        if (serial->open(QIODevice::ReadWrite))
            return 0;
        else
            return -1;
    }
    return -1;
}

int Arduino::close_arduino()
{
    if (serial->isOpen()) {
        serial->close();
        return 0;
    }
    return -1;
}

QByteArray Arduino::read_from_arduino()
{
    if (serial->isReadable())
        return serial->readAll();
    return QByteArray();
}

bool Arduino::write_to_arduino(QByteArray data)
{
    if (serial->isWritable()) {
        serial->write(data);
        return true;
    }
    return false;
}

QString Arduino::get_port_name()
{
    return arduino_port_name;
}

bool Arduino::is_connected()
{
    return serial->isOpen();
}
