#include "registerwindow.h"
#include <QVBoxLayout>
#include <QFormLayout>
#include <QMessageBox>
#include <QLabel>
#include <QSqlQuery>
#include <QSqlError>
#include <QLineEdit>
#include <QPushButton>
#include <QCryptographicHash>
#include <QVariant>

RegisterWindow::RegisterWindow(QWidget *parent) : QWidget(parent) {
    setWindowTitle("Créer un compte");
    setFixedSize(400, 300);

    // Appliquer les couleurs de fond et du texte
    setStyleSheet("background-color: #800000; color: beige;");

    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    QLabel *title = new QLabel("Créer un nouveau compte");
    title->setAlignment(Qt::AlignCenter);
    title->setStyleSheet("color: beige; font-size: 18px;");  // Couleur beige pour le titre
    mainLayout->addWidget(title);

    QFormLayout *formLayout = new QFormLayout;

    emailInput = new QLineEdit;
    emailInput->setPlaceholderText("Adresse mail");
    emailInput->setStyleSheet("background-color: beige; color: #800000;");  // Fond beige, texte rouge bordeaux

    passwordInput = new QLineEdit;
    passwordInput->setPlaceholderText("Mot de passe");
    passwordInput->setEchoMode(QLineEdit::Password);
    passwordInput->setStyleSheet("background-color: beige; color: #800000;");

    confirmPasswordInput = new QLineEdit;
    confirmPasswordInput->setPlaceholderText("Confirmer le mot de passe");
    confirmPasswordInput->setEchoMode(QLineEdit::Password);
    confirmPasswordInput->setStyleSheet("background-color: beige; color: #800000;");

    formLayout->addRow("Email :", emailInput);
    formLayout->addRow("Mot de passe :", passwordInput);
    formLayout->addRow("Confirmer :", confirmPasswordInput);

    mainLayout->addLayout(formLayout);

    QPushButton *registerBtn = new QPushButton("S'inscrire");
    registerBtn->setStyleSheet("background-color: beige; color: #800000; font-weight: bold;");  // Bouton avec fond beige, texte rouge bordeaux
    mainLayout->addWidget(registerBtn);

    connect(registerBtn, &QPushButton::clicked, this, &RegisterWindow::handleRegister);  // Connexion au slot handleRegister
}


void RegisterWindow::handleRegister() {
    QString email = emailInput->text();
    QString password = passwordInput->text();
    QString confirmPassword = confirmPasswordInput->text();

    // Vérification des champs vides
    if (email.isEmpty() || password.isEmpty() || confirmPassword.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Tous les champs sont requis.");
        return;
    }

    // Vérification de la correspondance des mots de passe
    if (password != confirmPassword) {
        QMessageBox::warning(this, "Erreur", "Les mots de passe ne correspondent pas.");
        return;
    }

    // Si tout est valide, on procède à l'ajout
    createAccount(email, password);
}

void RegisterWindow::createAccount(const QString &email, const QString &password)
{
    QSqlQuery query;
    QSqlDatabase db = QSqlDatabase::database();

    // Démarrer une transaction
    if (!db.transaction()) {
        QMessageBox::critical(this, "Erreur", "Échec du début de la transaction : " + db.lastError().text());
        return;
    }

    // Étape 1 : Hasher le mot de passe
    QByteArray hash = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256);

    // Étape 2 : Insérer dans la table EMPLOYE sans spécifier ID_EMPLOYE (car il est auto-incrémenté)
    query.prepare("INSERT INTO employe (ID_EMPLOYE, NOM, PRENOM, POSTE, STATUS, EMAIL, ADRESSE, PASSWORD, ROLE) "
                  "VALUES (employe_seq.NEXTVAL, '', '', '', '', :email, '', :password, '')");
    query.bindValue(":email", email);
    query.bindValue(":password", password);

    if (query.exec()) {
        QMessageBox::information(this, "Succès", "Compte créé avec succès !");
        this->close();
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la création du compte.\n" + query.lastError().text());
    }
}
