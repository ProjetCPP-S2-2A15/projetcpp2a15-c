#include "NotificationPanel.h"

NotificationPanel::NotificationPanel(QWidget *parent) : QWidget(parent)
{
    layout = new QVBoxLayout(this);
    setLayout(layout);
}

void NotificationPanel::addNotification(const QString &message)
{
    QLabel *notif = new QLabel(message, this);
    notif->setStyleSheet("background-color: yellow; padding: 8px; border: 1px solid orange;");
    layout->addWidget(notif);
}

void NotificationPanel::clearNotifications()
{
    // Parcourir toutes les notifications et les supprimer
    QLayoutItem *item;
    while ((item = layout->takeAt(0)) != nullptr) {
        delete item->widget();  // Supprimer le widget
        delete item;  // Supprimer l'item du layout
    }
}
