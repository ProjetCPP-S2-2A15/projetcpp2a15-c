#include "mailer.h"
#include <QSslSocket>
#include <QDebug>
#include <QByteArray>

mailer::mailer(QObject *parent) : QObject(parent)
{
    // Verify SSL support at construction
    qDebug() << "SSL Support Status:";
    qDebug() << "Supports SSL:" << QSslSocket::supportsSsl();
    qDebug() << "SSL Library Build Version:" << QSslSocket::sslLibraryBuildVersionString();
    qDebug() << "SSL Library Runtime Version:" << QSslSocket::sslLibraryVersionString();
}

int mailer::sendEmail(const QString &to, const QString &subject, const QString &body)
{
    // 1. Verify SSL support
    if (!QSslSocket::supportsSsl()) {
        qDebug() << "Error: SSL not supported!";
        return -2;
    }

    // 2. Create and configure socket
    QSslSocket socket;
    socket.setProtocol(QSsl::TlsV1_2OrLater);

    // 3. Connect to SMTP server
    qDebug() << "Connecting to SMTP server...";
    socket.connectToHostEncrypted(SMTP_SERVER, SMTP_PORT);

    if (!socket.waitForConnected(5000)) {
        qDebug() << "Connection error:" << socket.errorString();
        return -1;
    }

    if (!socket.waitForEncrypted(5000)) {
        qDebug() << "Encryption error:" << socket.errorString();
        return -3;
    }

    // 4. SMTP Protocol Sequence
    QStringList commands = {
        "EHLO localhost",
        "AUTH LOGIN",
        QByteArray().append(USERNAME.toUtf8()).toBase64(),
        QByteArray().append(PASSWORD.toUtf8()).toBase64(),
        QString("MAIL FROM:<%1>").arg(USERNAME),
        QString("RCPT TO:<%1>").arg(to),
        "DATA",
        QString("From: %1\r\nTo: %2\r\nSubject: %3\r\n\r\n%4\r\n.")
            .arg(USERNAME, to, subject, body),
        "QUIT"
    };

    // 5. Execute commands
    for (const QString &cmd : commands) {
        socket.write(cmd.toUtf8() + "\r\n");
        socket.waitForBytesWritten(3000);

        if (!socket.waitForReadyRead(3000)) {
            qDebug() << "Timeout waiting for response to:" << cmd;
            return -4;
        }

        QString response = socket.readAll();
        qDebug() << "Server response to" << cmd.left(20) << ":" << response.trimmed();

        if (response.startsWith("5")) { // SMTP error code
            qDebug() << "SMTP Error:" << response;
            return -5;
        }
    }

    // 6. Cleanup
    socket.disconnectFromHost();
    if (socket.state() != QAbstractSocket::UnconnectedState) {
        socket.waitForDisconnected(3000);
    }

    qDebug() << "Email sent successfully to" << to;
    return 1;
}

