#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "local.h"
#include "connection.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mettreAJourAffichage();

    // Connecter les boutons "Ajouter" et "Annuler" à leurs slots respectifs
    connect(ui->pushButton_ajouter, &QPushButton::clicked, this, &MainWindow::on_pushButton_ajouter_clicked);
    connect(ui->pushButton_annuler, &QPushButton::clicked, this, &MainWindow::on_pushButton_annuler_clicked);
    connect(ui->pushButton_supprimer, &QPushButton::clicked, this, &MainWindow::on_pushButton_supprimer_clicked);
    connect(ui->pushButton_modifier, &QPushButton::clicked, this, &MainWindow::on_pushButton_modifier_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_ajouter_clicked()
{
    // Récupérer les valeurs saisies

    double surface = ui->lineEdit_surface->text().toDouble();
    QString type = ui->comboBox_type->currentText();
    QString disponibilite = ui->comboBox_dispo->currentText();
    double prix = ui->lineEdit_prix->text().toDouble();
    QString etage = ui->comboBox_etage->currentText();

   /* // Valider les valeurs saisies
    if (id <= 0 || surface <= 0 || prix <= 0 || type.isEmpty() || disponibilite.isEmpty() || etage.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez saisir des valeurs valides.");
        return;
    }*/

    // Créer un objet Local avec les valeurs saisies
    Local local( surface, type, disponibilite, prix, etage);

    // Ajouter le local à la base de données
    if (local.ajouter()) {
        QMessageBox::information(this, "Succès", "Local commercial ajouté avec succès !");
        mettreAJourAffichage();
        on_pushButton_annuler_clicked(); // Effacer les champs de saisie
    } else {
        QMessageBox::critical(this, "Erreur", "Erreur lors de l'ajout du local commercial.");


    }
}
// Slot pour annuler (effacer les champs)
void MainWindow::on_pushButton_annuler_clicked()
{
    // Effacer tous les champs de saisie

    ui->lineEdit_surface->clear();
    ui->comboBox_type->setCurrentIndex(0); // Réinitialiser le comboBox
    ui->comboBox_dispo->setCurrentIndex(0); // Réinitialiser le comboBox
    ui->lineEdit_prix->clear();
    ui->comboBox_etage->setCurrentIndex(0); // Réinitialiser le comboBox
    ui->lineEdit_id_3->clear();
}
void MainWindow::on_pushButton_supprimer_clicked()
{
    // Récupérer l'ID saisi
    QString idText = ui->lineEdit_id_3->text();
    bool conversionOk;
    long long id = idText.toLongLong(&conversionOk);

    // Valider l'ID
    if (!conversionOk || id <= 0) {
        QMessageBox::warning(this, "Erreur", "Veuillez saisir un ID valide.");
        return;
    }

    // Supprimer le local
    Local local;
    if (local.supprimer(id)) {
        QMessageBox::information(this, "Succès", "Local commercial supprimé avec succès !");
        mettreAJourAffichage();
        ui->lineEdit_id_3->clear(); // Effacer le champ ID après suppression
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la suppression du local commercial.");
    }
}
void MainWindow::on_pushButton_modifier_clicked()
{
    // Récupérer l'ID saisi
    QString idText = ui->lineEdit_idU->text();
    bool conversionOk;
    long long id = idText.toLongLong(&conversionOk);

    // Valider l'ID
    if (!conversionOk || id <= 0) {
        QMessageBox::warning(this, "Erreur", "Veuillez saisir un ID valide.");
        return;
    }

    // Récupérer les nouvelles valeurs saisies
    double surface = ui->lineEdit_id_2->text().toDouble();
    QString type = ui->comboBox_4->currentText();
    QString disponibilite = ui->comboBox_6->currentText();
    double prix = ui->lineEdit_lieu_2->text().toDouble();
    QString etage = ui->comboBox_5->currentText();

    // Valider les valeurs saisies
    if (surface <= 0 || prix <= 0 || type.isEmpty() || disponibilite.isEmpty() || etage.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez saisir des valeurs valides.");
        return;
    }

    // Créer un objet Local avec les nouvelles valeurs
    Local local(surface, type, disponibilite, prix, etage);

    // Modifier le local dans la base de données
    if (local.modifier(id)) {
        QMessageBox::information(this, "Succès", "Local commercial modifié avec succès !");
        mettreAJourAffichage();  // ✅ Rafraîchir TableView
        on_pushButton_annuler_clicked(); // Effacer les champs de saisie
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la modification du local commercial.");
    }
}

void MainWindow::mettreAJourAffichage()
{
    Local local;
    ui->tableView->setModel(local.afficher());  // Mettre à jour le modèle de tableView
}

