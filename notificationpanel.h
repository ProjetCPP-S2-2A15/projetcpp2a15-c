#ifndef NOTIFICATIONPANEL_H
#define NOTIFICATIONPANEL_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>

class NotificationPanel : public QWidget
{
    Q_OBJECT

public:
    explicit NotificationPanel(QWidget *parent = nullptr);

    void addNotification(const QString &message);
    void clearNotifications();  // Déclaration de la méthode

private:
    QVBoxLayout *layout;
};

#endif // NOTIFICATIONPANEL_H
