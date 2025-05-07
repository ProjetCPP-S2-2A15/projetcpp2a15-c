#ifndef REGISTERWINDOW_H
#define REGISTERWINDOW_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>

class RegisterWindow : public QWidget
{
    Q_OBJECT

public:
    explicit RegisterWindow(QWidget *parent = nullptr);

private slots:
    void handleRegister();  // Déclaration de la méthode
    void createAccount(const QString& email, const QString& password);

private:
    QLineEdit *emailInput;
    QLineEdit *passwordInput;
    QLineEdit *confirmPasswordInput;
};

#endif // REGISTERWINDOW_H
