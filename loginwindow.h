#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>

class loginwindow : public QWidget
{
    Q_OBJECT

public:
    explicit loginwindow(QWidget *parent = nullptr);

signals:
    void loginSuccessful(); // Signal emitted on successful login

private slots:
    void checkLogin();
    void handleFaceRecognition();

private:
    QLineEdit *emailInput;
    QLineEdit *passwordInput;
    QPushButton *forgotButton;
    int loginAttempts;
};

#endif // LOGINWINDOW_H
