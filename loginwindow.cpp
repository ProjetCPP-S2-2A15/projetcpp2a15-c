#include "loginwindow.h"
#include "mainwindow.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QLabel>
#include <QPixmap>
#include <QPalette>
#include <QPushButton>
#include <QMessageBox>

loginwindow::loginwindow(QWidget *parent) : QWidget(parent) {
    setWindowTitle("Login");
    setFixedSize(1000, 600);

    QPalette palette;
    palette.setColor(QPalette::Window, QColor("#FDF6CC"));
    setAutoFillBackground(true);
    setPalette(palette);

    QHBoxLayout *mainLayout = new QHBoxLayout(this);

    // Colonne gauche
    // === Colonne gauche : logo ===
    QLabel *logo = new QLabel;
    QPixmap pix(":/logo.png");
    logo->setPixmap(pix.scaled(300, 300, Qt::KeepAspectRatio));
    logo->setAlignment(Qt::AlignCenter);

    QVBoxLayout *leftLayout = new QVBoxLayout;
    leftLayout->addStretch(); // Espace en haut
    leftLayout->addWidget(logo, 0, Qt::AlignCenter); // Centre le logo
    leftLayout->addStretch(); // Espace en bas

    QWidget *leftWidget = new QWidget;
    leftWidget->setLayout(leftLayout);
    leftWidget->setFixedWidth(500);


    // Colonne droite
    QWidget *rightWidget = new QWidget;
    rightWidget->setStyleSheet("background-color: #5C0A0A; border-top-left-radius: 60px;");

    QVBoxLayout *rightLayout = new QVBoxLayout(rightWidget);

    QLabel *welcomeLabel = new QLabel("Welcome");
    welcomeLabel->setStyleSheet("color: white; font-size: 28px; font-weight: bold;");
    welcomeLabel->setAlignment(Qt::AlignCenter);
    rightLayout->addWidget(welcomeLabel);

    QFormLayout *formLayout = new QFormLayout;

    emailInput = new QLineEdit;
    emailInput->setPlaceholderText("Adresse mail");
    emailInput->setStyleSheet("background-color: #D8C5C5; padding: 8px; border-radius: 10px;");
    formLayout->addRow("", emailInput);

    passwordInput = new QLineEdit;
    passwordInput->setPlaceholderText("Mot de passe");
    passwordInput->setEchoMode(QLineEdit::Password);
    passwordInput->setStyleSheet("background-color: #D8C5C5; padding: 8px; border-radius: 10px;");
    formLayout->addRow("", passwordInput);

    rightLayout->addLayout(formLayout);

    QPushButton *forgotButton = new QPushButton("Mot de passe oublié?");
    forgotButton->setFlat(true);
    forgotButton->setStyleSheet("color: white; text-align: left;");
    rightLayout->addWidget(forgotButton);

    QPushButton *loginButton = new QPushButton("Login");
    loginButton->setStyleSheet("background-color: #D8C5C5; padding: 10px; border-radius: 10px;");
    rightLayout->addWidget(loginButton);
    rightLayout->setSpacing(15);

    connect(loginButton, &QPushButton::clicked, this, &loginwindow::checkLogin);

    mainLayout->addWidget(leftWidget);
    mainLayout->addWidget(rightWidget);
}

// === Méthode de vérification ===
void loginwindow::checkLogin()
{
    QString email = emailInput->text();
    QString password = passwordInput->text();

    if (email == "admin@gmail.com" && password == "admin123") {
        MainWindow *mainWin = new MainWindow();
        mainWin->show();
        this->close();
    } else {
        QMessageBox::warning(this, "Erreur de connexion", "Email ou mot de passe incorrect.");
    }
}
