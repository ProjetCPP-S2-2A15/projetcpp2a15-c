#include "mainwindow.h"
#include "loginwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Connection c;
    bool test = c.createconnect();

    if (test) {
        QMessageBox::information(nullptr, QObject::tr("Database Open"),
                                 QObject::tr("Connection successful.\nClick OK to continue."),
                                 QMessageBox::Ok);

        loginwindow login;
        login.show();

        return a.exec();
    } else {
        QMessageBox::critical(nullptr, QObject::tr("Database Not Open"),
                              QObject::tr("Connection failed.\nClick Cancel to exit."),
                              QMessageBox::Cancel);
        return -1;
    }
}
