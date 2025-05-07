#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QProcess>

class loginwindow : public QWidget {
    Q_OBJECT

public:
    explicit loginwindow(QWidget *parent = nullptr);

private:
    QLineEdit *emailInput;
    QLineEdit *passwordInput;
    QPushButton *forgotButton;

    int loginAttempts; // compteur d'essais

private slots:
    void checkLogin();             // Vérification normale
    void handleFaceRecognition();  // En cas d'échec
};

#endif // LOGINWINDOW_H
