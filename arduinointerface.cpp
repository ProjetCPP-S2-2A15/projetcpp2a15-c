#include "arduinointerface.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QVBoxLayout>
#include <QSerialPort>

ArduinoInterface::ArduinoInterface(QWidget *parent)
    : QWidget(parent), serial(nullptr)
{
    output = new QTextEdit(this);
    output->setReadOnly(true);
    connectBtn = new QPushButton("🔌 Connecter à l'Arduino", this);

    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(connectBtn);
    layout->addWidget(output);
    setLayout(layout);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &ArduinoInterface::readData);
    connect(connectBtn, &QPushButton::clicked, this, &ArduinoInterface::connectToArduino);

    if (!QSqlDatabase::database().isOpen()) {
        output->append("❗ Erreur : Impossible de se connecter à la base de données.");
    }
}

ArduinoInterface::~ArduinoInterface()
{
    close_arduino();
}

void ArduinoInterface::connectToArduino()
{
    int result = connect_arduino();
    if (result == 0) {
        output->append("✅ Arduino connecté");
        timer->start(100);
        connectBtn->setEnabled(false);
    } else if (result == 1) {
        output->append("⚠️ Arduino détecté mais port non ouvert.");
    } else {
        output->append("❌ Arduino non détecté !");
    }
}

void ArduinoInterface::readData()
{
    QByteArray data = read_from_arduino();
    if (!data.isEmpty()) {
        QString rfid = QString(data).trimmed();

        double distanceSeuil = getDistanceSeuil();
        if (distanceSeuil == -1) {
            output->append("❗ Erreur : Impossible de récupérer la distance seuil.");
            return;
        }

        bool ok;
        double distance = rfid.toDouble(&ok);

        if (ok) {
            if (distance <= distanceSeuil) {
                output->append("✅ Accès autorisé, distance : " + QString::number(distance) + " cm");
                insertDistanceInDatabase(distance);
            } else {
                output->append("❌ Accès refusé, distance : " + QString::number(distance) + " cm");
                // Aucun enregistrement en base pour Accès refusé
            }
        } else {
            output->append("❗ Erreur : Données invalides.");
        }
    }
}

double ArduinoInterface::getDistanceSeuil()
{
    if (!QSqlDatabase::database().isOpen()) {
        output->append("❗ Erreur : Base de données non ouverte.");
        return -1.0;
    }

    QSqlQuery query;
    query.prepare("SELECT distance FROM Services WHERE ID_SERVICE = 15");

    if (query.exec() && query.next()) {
        return query.value(0).toDouble();
    } else {
        output->append("❗ Erreur SQL : " + query.lastError().text());
        return -1.0;
    }
}

void ArduinoInterface::insertDistanceInDatabase(double distance)
{
    if (!QSqlDatabase::database().isOpen()) {
        output->append("❗ Erreur : Base de données non ouverte.");
        return;
    }

    QSqlQuery query;
    query.prepare("INSERT INTO SERVICES (ID_SERVICE, NOM, PRIX, DESCRIPTION, STATUT, TYPE, DATEDEBUT, DATEFIN, DISTANCE) "
                  "VALUES (SERVICES_SEQ.NEXTVAL, 'samar', 600, 'eef', 'Accès autorisé', 'interne', "
                  "TO_DATE('2000-01-01 00:00:00', 'YYYY-MM-DD HH24:MI:SS'), "
                  "TO_DATE('2000-01-01 00:00:00', 'YYYY-MM-DD HH24:MI:SS'), :distance)");

    query.bindValue(":distance", distance);

    if (!query.exec()) {
        output->append("❗ Erreur insertion : " + query.lastError().text());
    } else {
        output->append("✅ Distance insérée : " + QString::number(distance) + " cm");
    }
}

int ArduinoInterface::connect_arduino()
{
    if (!serial) {
        serial = new QSerialPort(this);
    }
    serial->setPortName("COM4"); // Mets ici ton port correct
    if (serial->open(QIODevice::ReadWrite)) {
        return 0;
    }
    return 1;
}

int ArduinoInterface::close_arduino()
{
    if (serial && serial->isOpen()) {
        serial->close();
        return 0;
    }
    return 1;
}

QByteArray ArduinoInterface::read_from_arduino()
{
    if (serial && serial->canReadLine()) {
        return serial->readLine();
    }
    return QByteArray();
}


