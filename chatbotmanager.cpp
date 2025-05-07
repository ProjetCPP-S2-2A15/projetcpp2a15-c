#include "chatbotmanager.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>

ChatbotManager::ChatbotManager(QObject *parent) : QObject(parent)
{
    networkManager = new QNetworkAccessManager(this);
    connect(networkManager, &QNetworkAccessManager::finished, this, &ChatbotManager::onReplyFinished);
}

void ChatbotManager::sendMessage(const QString &message)
{
    QUrl url("https://dialogflow.googleapis.com/v2/projects/mallassistant-vbyf/agent/sessions/123456:detectIntent");
    QNetworkRequest request(url);

    request.setRawHeader("Authorization", "Bearer YOUR_ACCESS_TOKEN");
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QJsonObject json;
    json["queryInput"] = QJsonObject{
        {"text", QJsonObject{
                     {"text", message},
                     {"languageCode", "fr"}
                 }}
    };

    QJsonDocument doc(json);
    networkManager->post(request, doc.toJson());
}

void ChatbotManager::onReplyFinished(QNetworkReply *reply)
{
    if (reply->error() == QNetworkReply::NoError) {
        QJsonDocument doc = QJsonDocument::fromJson(reply->readAll());
        QJsonObject root = doc.object();
        QJsonObject queryResult = root["queryResult"].toObject();
        QString responseText = queryResult["fulfillmentText"].toString();
        emit responseReceived(responseText);
    } else {
        qDebug() << "Error: " << reply->errorString();
    }
    reply->deleteLater();
}
