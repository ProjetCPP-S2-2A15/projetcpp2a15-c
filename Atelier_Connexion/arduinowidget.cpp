#include "arduinowidget.h"
#include <QDebug>

ArduinoWidget::ArduinoWidget(QWidget *parent)
    : QWidget(parent)
{
    // Création des éléments de l'interface
    output = new QTextEdit(this);
    output->setReadOnly(true);

    connectBtn = new QPushButton("🔌 Connecter à l'Arduino", this);

    // Layout vertical
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(connectBtn);
    layout->addWidget(output);
    setLayout(layout);

    // Timer pour la lecture automatique
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &ArduinoWidget::readData);

    // Bouton pour se connecter à Arduino
    connect(connectBtn, &QPushButton::clicked, this, &ArduinoWidget::connectToArduino);
}

void ArduinoWidget::connectToArduino()
{
    int result = A.connect_arduino();
    if (result == 0) {
        output->append("✅ Arduino connecté sur " + A.getarduino_port_name());
        timer->start(100); // Lecture toutes les 100ms
        connectBtn->setEnabled(false); // Désactive le bouton
    } else if (result == 1) {
        output->append("⚠️ Arduino détecté mais port non ouvert.");
    } else {
        output->append("❌ Arduino non détecté !");
    }
}

void ArduinoWidget::readData()
{
    QByteArray data = A.read_from_arduino();
    if (!data.isEmpty()) {
        QString rfid = QString(data).trimmed();
        QByteArray result = A.cherchercode(rfid);

        if (result == "1") {
            output->append("📶 UID " + rfid + " ➜ ✅ Accès autorisé");
        } else {
            output->append("📶 UID " + rfid + " ➜ ❌ UID non reconnu");
        }
    }
}
