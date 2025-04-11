#include "NotificationWidget.h"
#include <QLabel>
#include <QTimer> // Assure-toi que ce fichier est bien inclus

NotificationWidget::NotificationWidget(QWidget *parent) : QWidget(parent), layout(new QVBoxLayout(this))
{
    // Créer le label de notification
    label = new QLabel(this);
    label->setStyleSheet("background-color: lightgreen; padding: 10px; font-weight: bold;");

    // Ajouter le label au layout
    layout->addWidget(label);

    // Définir le layout pour ce widget
    setLayout(layout);
}
void NotificationWidget::addNotification(const QString &message, const QString &type)
{
    QLabel *newLabel = new QLabel(message, this);

    QString style;
    if (type == "warning")
        style = "background-color: orange; color: black;";
    else if (type == "error")
        style = "background-color: red; color: white;";
    else
        style = "background-color: lightblue; color: black;";

    newLabel->setStyleSheet(style + " padding: 10px; font-weight: bold; border-radius: 8px;");
    layout->addWidget(newLabel);

    QTimer::singleShot(4000, newLabel, &QLabel::deleteLater);
}
