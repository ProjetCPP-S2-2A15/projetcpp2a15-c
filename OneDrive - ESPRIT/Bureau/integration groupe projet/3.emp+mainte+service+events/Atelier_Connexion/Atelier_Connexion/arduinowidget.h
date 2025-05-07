#ifndef ARDUINOWIDGET_H
#define ARDUINOWIDGET_H

#include <QWidget>
#include <QTextEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QTimer>
#include "arduino.h"

class ArduinoWidget : public QWidget
{
    Q_OBJECT

public:
    ArduinoWidget(QWidget *parent = nullptr);

private slots:
    void connectToArduino();
    void readData();

private:
    QTextEdit *output;
    QPushButton *connectBtn;
    QTimer *timer;
    Arduino A;
};

#endif // ARDUINOWIDGET_H
