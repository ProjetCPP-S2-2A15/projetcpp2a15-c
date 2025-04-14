#ifndef CHATBOTMANAGER_H
#define CHATBOTMANAGER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>

class ChatbotManager : public QObject
{
    Q_OBJECT
public:
    explicit ChatbotManager(QObject *parent = nullptr);
    void sendMessage(const QString &message);

signals:
    void responseReceived(const QString &response);

private slots:
    void onReplyFinished(QNetworkReply *reply);

private:
    QNetworkAccessManager *networkManager;
};

#endif // CHATBOTMANAGER_H
