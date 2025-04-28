#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "events.h"
#include <QMessageBox>
#include <QSqlError>
#include <QDebug>
#include <QRegularExpression>
#include <QCloseEvent>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Set icons for buttons
    ui->pushButton_8->setIcon(QIcon(":/icons/icons/align-left.svg"));
    ui->pushButton_8->setIconSize(QSize(32, 32));

    ui->pushButton_6->setIcon(QIcon(":/icons/icons/search.svg"));
    ui->pushButton_6->setIconSize(QSize(32, 32));

    ui->pushButton_4->setIcon(QIcon(":/icons/icons/bell.svg"));
    ui->pushButton_4->setIconSize(QSize(32, 32));

    ui->pushButton_5->setIcon(QIcon(":/icons/icons/user.svg"));
    ui->pushButton_5->setIconSize(QSize(32, 32));

    ui->pushButton->setIcon(QIcon(":/icons/icons/maximize-2.svg"));
    ui->pushButton->setIconSize(QSize(32, 32));

    ui->pushButton_2->setIcon(QIcon(":/icons/icons/arrow-down-left.svg"));
    ui->pushButton_2->setIconSize(QSize(32, 32));

    ui->pushButton_3->setIcon(QIcon(":/icons/icons/x.svg"));
    ui->pushButton_3->setIconSize(QSize(32, 32));

    ui->pushButton_7->setIcon(QIcon(":/icons/icons/box.svg"));
    ui->pushButton_7->setIconSize(QSize(32, 32));

    ui->pushButton_9->setIcon(QIcon(":/icons/icons/external-link.svg"));
    ui->pushButton_9->setIconSize(QSize(32, 32));

    QPixmap pixmap(":/icons/images/Capture_2025.png");
    ui->label_3->setPixmap(pixmap);
    ui->label_3->setScaledContents(true);

    // Connect to the database
    if (!connectToDatabase()) {
        QMessageBox::critical(this, "Erreur", "La connexion à la base de données a échoué.");
        return;
    }

    // Connect buttons to slots
    connect(ui->button_ajouter, &QPushButton::clicked, this, &MainWindow::on_button_ajouter_clicked);
    connect(ui->button_modifier, &QPushButton::clicked, this, &MainWindow::on_button_modifier_clicked);
    connect(ui->button_supprimer, &QPushButton::clicked, this, &MainWindow::on_button_supprimer_clicked);

    // Refresh the table view
    updateTableView();
}

MainWindow::~MainWindow() {
    delete ui;
}

// Connect to the database
bool MainWindow::connectToDatabase() {
    if (!Events::ouvrirConnexion()) {
        QMessageBox::critical(this, "Erreur", "La connexion à la base de données a échoué.");
        return false;
    }
    return true;
}

// Add an event
void MainWindow::on_button_ajouter_clicked() {
    int id = ui->lineEdit_id->text().toInt();
    QString nom = ui->lineEdit_nom->text();
    QString description = ui->lineEdit_description->text();
    QString type = ui->lineEdit_type->currentText();
    QString telephone = ui->lineEdit_telephone->text();
    QDate date_ev = ui->dateEdit_date_ev->date();
    QTime heure = ui->timeEdit_heure->time();
    QString lieu = ui->lineEdit_lieu->text();

    // Validate user inputs
    if (!validateInputs(nom, description, type, telephone, lieu)) return;

    // Debug: Print values before adding
    qDebug() << "Nom:" << nom;
    qDebug() << "Description:" << description;
    qDebug() << "Type:" << type;
    qDebug() << "Telephone:" << telephone;
    qDebug() << "Date Event:" << date_ev.toString();
    qDebug() << "Heure:" << heure.toString();
    qDebug() << "Lieu:" << lieu;

    // Create an event and attempt to add it
    Events e(id, nom, description, type, telephone, date_ev, heure, lieu);
    if (e.ajouter()) {
        QMessageBox::information(this, "Succès", "Événement ajouté avec succès.");
        updateTableView();
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de l'ajout de l'événement.");
    }
}
// Modify an event
void MainWindow::on_button_modifier_clicked() {
    int id = ui->lineEdit_id_2->text().toInt();
    QString nom = ui->lineEdit_nom_2->text();
    QString description = ui->lineEdit_description_2->text();
    QString type = ui->lineEdit_type_2->currentText();
    QString telephone = ui->lineEdit_telephone_2->text();
    QDate date_ev = ui->dateEdit_date_ev_2->date();
    QTime heure = ui->timeEdit_heure_2->time();
    QString lieu = ui->lineEdit_lieu_2->text();

    // Validate user inputs
    if (!validateInputs(nom, description, type, telephone, lieu)) return;

    // Create an event and attempt to modify it
    Events e;
    if (e.modifier(id, nom, description, type, telephone, date_ev, heure, lieu)) {
        QMessageBox::information(this, "Succès", "Événement modifié avec succès.");
        updateTableView();
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la modification de l'événement.");
    }
}

// Delete an event
void MainWindow::on_button_supprimer_clicked() {
    int id = ui->lineEdit_id_3->text().toInt();

    Events e;
    if (e.supprimer(id)) {
        QMessageBox::information(this, "Succès", "Événement supprimé avec succès.");
        updateTableView();
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la suppression de l'événement.");
    }
}


// Refresh the table view
void MainWindow::updateTableView() {
    Events event;  // Create an instance of the Events class
    QSqlQueryModel *model = event.afficher();

    if (model) {
        ui->tableView_2->setModel(model);
    } else {
        QMessageBox::critical(this, "Erreur", "Impossible d'afficher les événements.");
    }
}

// Validate user inputs
bool MainWindow::validateInputs(const QString &nom, const QString &description, const QString &type,
                                const QString &telephone, const QString &lieu) {
    if (nom.isEmpty() || description.isEmpty() || type.isEmpty() || telephone.isEmpty() || lieu.isEmpty()) {
        QMessageBox::warning(this, "Validation", "Tous les champs doivent être remplis.");
        return false;
    }

    if (!telephone.contains(QRegularExpression("^[0-9]{8}$"))) {
        QMessageBox::warning(this, "Validation", "Le numéro de téléphone doit contenir 8 chiffres.");
        return false;
    }

    return true;
}
void MainWindow::closeEvent(QCloseEvent *event) {
    // Your custom closing logic here, such as saving data or asking for confirmation
    event->accept();  // Proceed with the close event
}
