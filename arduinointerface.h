#ifndef ARDUINOINTERFACE_H
#define ARDUINOINTERFACE_H

#include <QWidget>
#include <QTextEdit>
#include <QPushButton>
#include <QTimer>
#include <QSerialPort>
#include <QSqlDatabase>

class ArduinoInterface : public QWidget
{
    Q_OBJECT

public:
    explicit ArduinoInterface(QWidget *parent = nullptr);
    ~ArduinoInterface();

private slots:
    void connectToArduino();
    void readData();

private:
    int connect_arduino();
    int close_arduino();
    QByteArray read_from_arduino();
    double getDistanceSeuil();
    void insertDistanceInDatabase(double distance);





    QTextEdit *output;
    QPushButton *connectBtn;
    QSerialPort *serial;
    QTimer *timer;
};

#endif // ARDUINOINTERFACE_H
