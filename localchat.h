#ifndef LOCALCHAT_H
#define LOCALCHAT_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

class LocalChat : public QObject
{
    Q_OBJECT
public:
    explicit LocalChat(QObject *parent = nullptr);
    void processMessage(const QString &message);
    void setCurrentState(const QString &state) { currentState = state; }
    void initialize();

signals:
    void responseReceived(const QString &response);
    void error(const QString &errorMessage);

private:
    QString currentState;
    void handleInitialState(const QString &message);
    void handleAwaitingLocataireId(const QString &message);
    void handleAwaitingContratId(const QString &message);
    QString getLocationDates(const QString &locataireId);
    QString generateContract(const QString &locataireId);
    QString getStatistics();
    bool isValidLocataireId(const QString &id);
};

#endif // LOCALCHAT_H
