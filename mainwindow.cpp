#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employee1.h"
#include <QMessageBox>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tab_employee1->setModel(emp.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*void MainWindow::on_pushButton_ajouter_clicked()
{
    int id = ui->le_id->text().toInt();
    QString nom = ui->le_nom->text();
    QString prenom = ui->le_prenom->text();
    QString poste = ui->le_poste->text();
    double salaire = ui->le_salaire->text().toDouble();
    QString status = ui->le_status->text();
    QString adresse = ui->le_adresse->text();
    QString role = ui->le_role->text();
    QDateTime dateE = ui->le_dateE_2->dateTime();







    if (nom.isEmpty() || prenom.isEmpty()  || poste.isEmpty() || status.isEmpty() || role.isEmpty() || !dateE.isValid()) {
        QMessageBox::critical(this, "Erreur", "Veuillez remplir tous les champs obligatoires !");
        return;
    }

    employee1 emp(id, nom, prenom, poste, salaire,  status,adresse, role , dateE);
    bool test = emp.ajouter();

    if (test) {
        ui->tab_employee1->setModel(emp.afficher());
        QMessageBox::information(this, "Succès", "Employé ajouté avec succès !");
    } else {
        QMessageBox::critical(this, "Erreur", "L'ajout de l'employé a échoué.");
    }
}
*/
void MainWindow::on_pushButton_ajouter_clicked()
{
    // Récupération des données depuis l'interface
    int id = ui->le_id->text().toInt();
    QString nom = ui->le_nom->text();
    QString prenom = ui->le_prenom->text();
    QString poste = ui->le_poste->text();
    double salaire = ui->le_salaire->text().toDouble();
    QString status = ui->le_status->text();
    QString adresse = ui->le_adresse->text();
    QString role = ui->le_role->text();
    QDateTime dateE = ui->le_dateE_2->dateTime();

    // Vérification que tous les champs obligatoires sont remplis
    if (nom.isEmpty() || prenom.isEmpty() || poste.isEmpty() || status.isEmpty() || role.isEmpty() || adresse.isEmpty() || !dateE.isValid()) {
        QMessageBox::critical(this, "Erreur", "Veuillez remplir tous les champs obligatoires !");
        return;
    }

    // Validation de l'ID : Il doit être un entier positif
    if (id <= 0) {
        QMessageBox::critical(this, "Erreur", "L'ID doit être un nombre positif.");
        return;
    }

    // Validation du salaire : Il doit être un nombre supérieur à zéro
    if (salaire <= 0) {
        QMessageBox::critical(this, "Erreur", "Le salaire doit être un nombre valide et supérieur à zéro.");
        return;
    }

    // Validation de la date d'embauche : La date ne doit pas être dans le futur
    if (dateE > QDateTime::currentDateTime()) {
        QMessageBox::critical(this, "Erreur", "La date d'embauche ne peut pas être dans le futur.");
        return;
    }

    // Validation du nom : Le nom ne doit pas contenir de chiffres
    QRegularExpression regex("^[a-zA-Z\\s]+$");
    if (!regex.match(nom).hasMatch()) {
        QMessageBox::critical(this, "Erreur", "Le nom ne doit contenir que des lettres et des espaces.");
        return;
    }

    // Validation du prénom : Le prénom ne doit pas contenir de chiffres
    if (!regex.match(prenom).hasMatch()) {
        QMessageBox::critical(this, "Erreur", "Le prénom ne doit contenir que des lettres et des espaces.");
        return;
    }

    // Création de l'objet employé
    employee1 emp(id, nom, prenom, poste, salaire, status, adresse, role, dateE);

    // Ajout de l'employé
    bool test = emp.ajouter();

    // Affichage des résultats
    if (test) {
        ui->tab_employee1->setModel(emp.afficher());
        QMessageBox::information(this, "Succès", "Employé ajouté avec succès !");
    } else {
        QMessageBox::critical(this, "Erreur", "L'ajout de l'employé a échoué.");
    }
}

void MainWindow::on_pushButton_ok_clicked()
{
    int id = ui->le_modif_id_emp->text().toInt();

    if (id == 0) {
        QMessageBox::warning(this, "ID manquant", "Veuillez entrer un ID valide !");
        return;
    }



    if (emp.getId() == 0) { // Vérifier si l'employé existe
        QMessageBox::warning(this, "Employé introuvable", "Aucun employé trouvé avec cet ID!");
        return;
    }

    // Remplir les champs de l'UI
    ui->le_modif_nom->setText(emp.getNom());
    ui->le_modif_prenom->setText(emp.getPrenom());
    ui->le_modif_poste->setText(emp.getPoste());
    ui->le_modif_salaire->setText(QString::number(emp.getSalaire()));
    ui->le_modif_status->setText(emp.getStatus());
    ui->le_modif_adresse->setText(emp.getAdresse());
    ui->le_modif_role->setText(emp.getRole());
    ui->le_modif_dateE->setDateTime(emp.getDateEmbauche());

    QMessageBox::information(this, "Succès", "Données de l'employé chargées !");
}


void MainWindow::on_pushButton_modifier_clicked()
{
    int id = ui->le_modif_id_emp->text().toInt();


    if (emp.getId() == 0) {
        QMessageBox::warning(this, "Employé introuvable", "Aucun employé trouvé avec cet ID !");
        return;
    }


    // Fill UI fields with existing employee data
    ui->le_modif_nom->setText(emp.getNom());
    ui->le_modif_prenom->setText(emp.getPrenom());
    ui->le_modif_poste->setText(emp.getPoste());
    ui->le_modif_salaire->setText(QString::number(emp.getSalaire()));
    ui->le_modif_status->setText(emp.getStatus());
    ui->le_modif_adresse->setText(emp.getAdresse());
    ui->le_modif_role->setText(emp.getRole());
    ui->le_modif_dateE->setDateTime(emp.getDateEmbauche());

    // Ask for confirmation before update
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirmer", "Voulez-vous modifier cet employé ?",
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        // Retrieve updated values from UI
        QString nom = ui->le_modif_nom->text();
        QString prenom = ui->le_modif_prenom->text();
        QString poste = ui->le_modif_poste->text();
        double salaire = ui->le_modif_salaire->text().toDouble();
        QString status = ui->le_modif_status->text();
        QString adresse = ui->le_modif_adresse->text();
        QString role = ui->le_modif_role->text();
        QDateTime dateE = ui->le_modif_dateE->dateTime();

        if (nom.isEmpty() || prenom.isEmpty() || poste.isEmpty() || status.isEmpty() || role.isEmpty() || !dateE.isValid()) {
            QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                                  QObject::tr("Veuillez remplir tous les champs et entrer une date valide !"), QMessageBox::Cancel);
            return;
        }

        // Update employee
        bool test = emp.modifier(id, nom, prenom, poste, salaire, status, adresse, role, dateE);

        if (test) {
            ui->tab_employee1->setModel(emp.afficher()); // Refresh table
            QMessageBox::information(nullptr, QObject::tr("OK"),
                                     QObject::tr("Modification effectuée"), QMessageBox::Ok);
        } else {
            QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                                  QObject::tr("Modification non effectuée"), QMessageBox::Cancel);
        }
    }
}


void MainWindow::on_pushButton_supprimer_clicked()
{
    int id = ui->id_supp->text().toInt(); // Get the ID entered by the user

    qDebug() << " [UI] Suppression - ID récupéré : " << id;

    if (id == 0) {
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                              QObject::tr("Veuillez entrer un ID valide !\n"), QMessageBox::Cancel);
        return;
    }

    // Assuming s is an instance of employee1
    bool test = emp.supprimer(id); // Call the supprimer method of employee1

    if (test) {
        qDebug() << " [SUPPRESSION] Succès! Rafraîchissement du tableau.";
        ui->tab_employee1->setModel(emp.afficher()); // Refresh the table
        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Suppression effectuée\nClick Cancel to exit."), QMessageBox::Cancel);
    } else {
        qDebug() << " [SUPPRESSION] Échec ! Vérifie la requête SQL.";
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                              QObject::tr("Suppression non effectuée\nClick Cancel to exit."), QMessageBox::Cancel);
    }
}
void MainWindow::on_pushButton_annuler_2_clicked()
{
    ui->le_modif_id_emp->clear();
    ui->le_modif_nom->clear();
    ui->le_modif_prenom->clear();
    ui->le_modif_poste->clear();
    ui->le_modif_salaire->clear();
    ui->le_modif_status->clear();
    ui->le_modif_adresse->clear();
    ui->le_modif_role->clear();
    ui->le_modif_dateE->setDate(QDate(2000, 1, 1));
}
void MainWindow::on_pushButton_annuler_3_clicked()
{
    ui->id_supp->clear();
}
void MainWindow::on_pushButton_annuler_clicked(){

    ui->le_id->clear();
    ui->le_nom->clear();
    ui->le_prenom->clear();
    ui->le_poste->clear();
    ui->le_salaire->clear();
    ui->le_status->clear();
    ui->le_adresse->clear();
    ui->le_role->clear();
    ui->le_dateE_2->setDate(QDate(2000, 1, 1));
}


void MainWindow::on_btn_modifier_clicked()
{
    int id = ui->le_modif_id_emp->text().toInt();
    QString nom = ui->le_modif_nom->text().trimmed();
    QString prenom = ui->le_modif_prenom->text().trimmed();
    QString poste = ui->le_modif_poste->text().trimmed();
    double salaire = ui->le_modif_salaire->text().toDouble();
    QString status = ui->le_modif_status->text().trimmed();
    QString adresse = ui->le_modif_adresse->text().trimmed();
    QString role = ui->le_modif_role->text().trimmed();
    QDateTime dateE = ui->le_modif_dateE->dateTime();

    // Vérifier si un champ est vide
    if (id <= 0 || nom.isEmpty() || prenom.isEmpty() || poste.isEmpty() ||
        status.isEmpty() || adresse.isEmpty() || role.isEmpty() || salaire <= 0) {
        QMessageBox::warning(this, "Erreur", "Veuillez remplir tous les champs correctement !");
        return;
    }

    // Vérifier si la date est valide
    if (!dateE.isValid()) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer une date valide !");
        return;
    }

    // Appel de la fonction de modification
    employee1 emp;
    if (emp.modifier(id, nom, prenom, poste, salaire, status, adresse, role, dateE)) {
        QMessageBox::information(this, "Succès", "Employé modifié avec succès !");
    } else {
        QMessageBox::critical(this, "Échec", "La modification a échoué. Vérifiez les logs.");
    }
}
