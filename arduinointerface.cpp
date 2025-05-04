#include "arduinointerface.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QVBoxLayout>
#include <QSerialPort>
#include <QMessageBox>
#include <QLineEdit>

ArduinoInterface::ArduinoInterface(QWidget *parent)
    : QWidget(parent), serial(nullptr)
{
    output = new QTextEdit(this);
    output->setReadOnly(true);

    connectBtn = new QPushButton("🔌 Connecter à l'Arduino", this);
    event1 = new QLineEdit(this);  // Champ de recherche
    QPushButton *searchButton = new QPushButton("🔍 Rechercher", this);

    QVBoxLayout *layout = new QVBoxLayout();
   // layout->addWidget(event);         // Champ texte pour le nom de l'événement
    layout->addWidget(searchButton);       // Bouton de recherche
    layout->addWidget(connectBtn);         // Bouton de connexion Arduino
    layout->addWidget(output);             // Zone de sortie

    setLayout(layout);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &ArduinoInterface::readData);
    connect(connectBtn, &QPushButton::clicked, this, &ArduinoInterface::connectToArduino);
    connect(searchButton, &QPushButton::clicked, this, &ArduinoInterface::on_pushButton_rechercher_clicked);

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

        bool ok;
        double distance = rfid.toDouble(&ok);

        if (ok) {
            if (distance <= 10) {
                output->append("✅ Accès autorisé, distance : " + QString::number(distance) + " cm");
                incrementParticipantsInDatabase();
            } else {
                output->append("❌ Accès refusé, distance : " + QString::number(distance) + " cm");
            }
        } else {
            output->append("❗ Erreur : Données invalides.");
        }
    }
}

void ArduinoInterface::incrementParticipantsInDatabase()
{
    if (!QSqlDatabase::database().isOpen()) {
        output->append("❗ Erreur : Base de données non ouverte.");
        return;
    }

    QSqlQuery query;

    query.prepare("SELECT NB_P FROM EVT WHERE ID_EVENEMENT = 1");
    if (!query.exec()) {
        output->append("❗ Erreur SQL (SELECT NB_P): " + query.lastError().text());
        return;
    }

    if (query.next()) {
        int nbParticipants = query.value(0).toInt();
        nbParticipants++;

        query.prepare("UPDATE EVT SET NB_P = :nb_p WHERE ID_EVENEMENT = 1");
        query.bindValue(":nb_p", nbParticipants);

        if (query.exec()) {
            output->append("✅ Nombre de participants mis à jour : " + QString::number(nbParticipants));
        } else {
            output->append("❗ Erreur SQL (UPDATE NB_P): " + query.lastError().text());
        }
    } else {
        output->append("❗ Erreur : Événement non trouvé.");
    }
}

int ArduinoInterface::connect_arduino()
{
    if (!serial) {
        serial = new QSerialPort(this);
    }
    serial->setPortName("COM4"); // Change si besoin
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

void ArduinoInterface::on_pushButton_rechercher_clicked()
{
    QString NOM = event1->text().trimmed();

    if (NOM.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer le nom de l'événement.");
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT NB_P FROM EVT WHERE NOM = :nom");
    query.bindValue(":nom", NOM);

    if (query.exec()) {
        if (query.next()) {
            int nb_p = query.value(0).toInt();
            output->append("🔍 NB_P pour '" + NOM + "' = " + QString::number(nb_p));

            if (serial && serial->isOpen()) {
                QString message = "NB_P=" + QString::number(nb_p) + "\n";
                serial->write(message.toUtf8());
            } else {
                output->append("❗ Erreur : Arduino non connecté.");
            }

        } else {
            QMessageBox::information(this, "Info", "Aucun événement trouvé avec ce nom.");
        }
    } else {
        QMessageBox::critical(this, "Erreur SQL", query.lastError().text());
    }
}
