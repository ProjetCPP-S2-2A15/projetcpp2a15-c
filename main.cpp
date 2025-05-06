#include "mainwindow.h"
#include "mainwindow.h"
#include "connection.h"
#include <QApplication>
#include <QDebug>
#include <QSerialPort>
#include "local.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Connection c;
    Locataire l;
    Local lo;

    if (c.createconnect()) {
        qDebug() << "Database connection established!";
    } else {
        qDebug() << "Failed to connect to database.";
    }

    MainWindow w;
    w.show();
    return a.exec();
    //qputenv("GOOGLE_APPLICATION_CREDENTIALS", QFile::encodeName(QCoreApplication::applicationDirPath() + "/mallassistant-vbyf-3683b3913d9d.json"));
}
