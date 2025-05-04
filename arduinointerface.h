#ifndef ARDUINOINTERFACE_H
#define ARDUINOINTERFACE_H

#include <QWidget>
#include <QTextEdit>
#include <QPushButton>
#include <QTimer>
#include <QSerialPort>
#include <QSqlDatabase>
#include <QLineEdit>

class ArduinoInterface : public QWidget
{
    Q_OBJECT

public:
    explicit ArduinoInterface(QWidget *parent = nullptr);
    ~ArduinoInterface();

private:
    QTextEdit *output;
    QPushButton *connectBtn;
    QTimer *timer;
    QSerialPort *serial;
    QLineEdit *event1;

    void connectToArduino();
    void readData();
    void incrementParticipantsInDatabase();  // Declare the function here
    void on_pushButton_rechercher_clicked();

    int connect_arduino();
    int close_arduino();
    QByteArray read_from_arduino();
};

#endif // ARDUINOINTERFACE_H
