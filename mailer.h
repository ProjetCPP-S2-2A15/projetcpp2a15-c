#ifndef MAILER_H
#define MAILER_H

#include <QObject>
#include <QString>
#include <QSslSocket>  // Add this include

class mailer : public QObject
{
    Q_OBJECT
public:
    explicit mailer(QObject *parent = nullptr);
    int sendEmail(const QString &to, const QString &subject, const QString &body);

private:
    const QString SMTP_SERVER = "smtp.gmail.com";
    const int SMTP_PORT = 465;
    const QString USERNAME = "autogenius.team@gmail.com";
    const QString PASSWORD = "zouc cyei qfnh lmof";
};

#endif // MAILER_H
