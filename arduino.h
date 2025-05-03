#ifndef ARDUINO_H
#define ARDUINO_H

#include <QObject>
#include <QSerialPort>
#include <QSerialPortInfo>

class Arduino : public QObject
{
    Q_OBJECT

public:
    Arduino(QObject *parent = nullptr);
    ~Arduino();

    int connect_arduino();      // retourne 0 si ok, -1 sinon
    int close_arduino();        // fermeture
    QByteArray read_from_arduino();
    bool write_to_arduino(QByteArray data);
    QString get_port_name();
    bool is_connected();

private:
    QSerialPort *serial;
    QString arduino_port_name;
    bool arduino_is_available;
};

#endif // ARDUINO_H
