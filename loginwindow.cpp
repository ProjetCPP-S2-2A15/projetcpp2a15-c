#include "loginwindow.h"
#include "mainwindow.h"
#include "registerwindow.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QLabel>
#include <QPixmap>
#include <QPalette>
#include <QPushButton>
#include <QMessageBox>
#include <QSqlQuery>
#include <QDebug>
#include <QProcess>

loginwindow::loginwindow(QWidget *parent) : QWidget(parent), loginAttempts(0) {
    setWindowTitle("Login");
    setFixedSize(1000, 600);

    QPalette palette;
    palette.setColor(QPalette::Window, QColor("#FDF6CC"));
    setAutoFillBackground(true);
    setPalette(palette);

    QHBoxLayout *mainLayout = new QHBoxLayout(this);

    // === Colonne gauche : logo ===
    QLabel *logo = new QLabel;
    QPixmap pix(":/logo.png");
    logo->setPixmap(pix.scaled(300, 300, Qt::KeepAspectRatio));
    logo->setAlignment(Qt::AlignCenter);

    QVBoxLayout *leftLayout = new QVBoxLayout;
    leftLayout->addStretch();
    leftLayout->addWidget(logo, 0, Qt::AlignCenter);
    leftLayout->addStretch();

    QWidget *leftWidget = new QWidget;
    leftWidget->setLayout(leftLayout);
    leftWidget->setFixedWidth(500);

    // === Colonne droite ===
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

    forgotButton = new QPushButton("Mot de passe oublié?");
    forgotButton->setFlat(true);
    forgotButton->setStyleSheet("color: white; text-align: left;");
    forgotButton->setEnabled(false); // désactivé au début
    rightLayout->addWidget(forgotButton);

    connect(forgotButton, &QPushButton::clicked, this, &loginwindow::handleFaceRecognition);

    QPushButton *loginButton = new QPushButton("Login");
    loginButton->setStyleSheet("background-color: #D8C5C5; padding: 10px; border-radius: 10px;");
    rightLayout->addWidget(loginButton);
    rightLayout->setSpacing(15);

    connect(loginButton, &QPushButton::clicked, this, &loginwindow::checkLogin);

    QPushButton *registerButton = new QPushButton("Créer un compte");
    registerButton->setFlat(true);
    registerButton->setStyleSheet("color: white; text-align: center; font-size: 14px;");
    rightLayout->addWidget(registerButton, 0, Qt::AlignCenter);

    connect(registerButton, &QPushButton::clicked, this, [=]() {
        RegisterWindow *regWin = new RegisterWindow();
        regWin->show();
    });

    mainLayout->addWidget(leftWidget);
    mainLayout->addWidget(rightWidget);
}

// === Méthode de vérification ===
void loginwindow::checkLogin() {
    QString email = emailInput->text();
    QString password = passwordInput->text();

    QSqlQuery query;
    query.prepare("SELECT * FROM employe WHERE email = :email AND password = :password");
    query.bindValue(":email", email);
    query.bindValue(":password", password);

    if (query.exec() && query.next()) {
        MainWindow *mainWin = new MainWindow();
        mainWin->show();
        this->close();
    } else {
        loginAttempts++;
        QMessageBox::warning(this, "Erreur de connexion", "Email ou mot de passe incorrect.");

        if (loginAttempts >= 3) {
            forgotButton->setEnabled(true);
            QMessageBox::information(this, "Info", "Vous avez dépassé 3 tentatives. Essayez avec la reconnaissance faciale.");
        }
    }
}

void loginwindow::handleFaceRecognition() {
    // Chemin vers python.exe (modifié)
    QString pythonPath = "C:\\Program Files\\Python313\\python.exe";  // Met à jour ce chemin si nécessaire

    // Chemin vers ton script Python (modifié)
    QString scriptPath = "C:\\Users\\siwar\\Downloads\\reconnaisanceFaciale\\face\\detect.py";  // Met à jour ce chemin si nécessaire

    // Création d'un processus QProcess pour exécuter le script Python
    QProcess *process = new QProcess(this);

    // Configuration de l'environnement du processus
    QProcessEnvironment env = QProcessEnvironment::systemEnvironment();
    env.insert("PATH", "C:\\Program Files\\Python313\\Scripts");  // Met à jour ce chemin si nécessaire
    env.insert("PYTHONPATH", "C:\\Program Files\\Python313");  // Met à jour ce chemin si nécessaire
    process->setProcessEnvironment(env);

    // Connexion à la sortie standard du processus pour afficher le résultat
    connect(process, &QProcess::readyReadStandardOutput, this, [=]() {
        QByteArray output = process->readAllStandardOutput();
        qDebug() << "Output: " << output;

        if (output.contains("Access denied")) {
            QMessageBox::critical(this, "Erreur", "Reconnaissance faciale échouée.");
        } else {
            QMessageBox::information(this, "Succès", "Accès autorisé par reconnaissance faciale.");
            MainWindow *mainWin = new MainWindow();
            mainWin->show();
            this->close();
        }
    });

    // Connexion à la sortie d'erreur du processus pour afficher les erreurs
    connect(process, &QProcess::readyReadStandardError, this, [=]() {
        QByteArray errorOutput = process->readAllStandardError();
        qDebug() << "Erreur Python: " << errorOutput;
    });

    // Démarrer le processus pour exécuter le script Python
    process->start(pythonPath, QStringList() << scriptPath);

    // Vérifier si le processus a démarré correctement
    if (!process->waitForStarted()) {
        QMessageBox::critical(this, "Erreur", "Impossible de démarrer le script Python.");
    }
}
