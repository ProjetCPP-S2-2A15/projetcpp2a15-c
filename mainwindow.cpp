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
    static const QRegularExpression regexLettres("^[a-zA-Z\\s]+$");  // Pour nom, prénom, poste, rôle et status
    static const QRegularExpression regexAdresse("^[a-zA-Z0-9\\s,.-]+$"); // Pour l'adresse


    // Vérification que tous les champs obligatoires sont remplis
    if (nom.isEmpty() || prenom.isEmpty() || poste.isEmpty() || status.isEmpty() || role.isEmpty() || adresse.isEmpty() || !dateE.isValid()) {
        QMessageBox::critical(this, "Erreur", "Veuillez remplir tous les champs obligatoires !");
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
    QRegularExpression regexlettres("^[a-zA-Z\\s]+$");
    if (!regexLettres.match(nom).hasMatch()) {
        QMessageBox::critical(this, "Erreur", "Le nom ne doit contenir que des lettres et des espaces.");
        return;
    }

    // Validation du prénom : Le prénom ne doit pas contenir de chiffres
    if (!regexLettres.match(prenom).hasMatch()) {
        QMessageBox::critical(this, "Erreur", "Le prénom ne doit contenir que des lettres et des espaces.");
        return;
    }
    if (!regexLettres.match(poste).hasMatch()) {
        QMessageBox::critical(this, "Erreur de validation", "Le poste ne doit contenir que des lettres et des espaces.");
        return;
    }

    // Vérification pour le rôle
    if (!regexLettres.match(role).hasMatch()) {
        QMessageBox::critical(this, "Erreur de validation", "Le rôle ne doit contenir que des lettres et des espaces.");
        return;
    }

    // Vérification pour l'adresse
    if (!regexAdresse.match(adresse).hasMatch()) {
        QMessageBox::critical(this, "Erreur de validation", "L'adresse ne doit contenir que des lettres, chiffres, espaces, virgules, points ou tirets.");
        return;
    }
    if (!regexLettres.match(status).hasMatch()) {
        QMessageBox::critical(this, "Erreur de validation", "Le statut ne doit contenir que des lettres et des espaces.");
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



/*void MainWindow::on_pushButton_ok_clicked()
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
*/

/*
void MainWindow::on_pushButton_modifier_clicked()
{
    int id = ui->le_modif_id_emp->text().toInt();

    if (id <= 0) {
        QMessageBox::warning(this, "Erreur", "ID invalide !");
        return;
    }

    employee1 emp = employee1::chercherParId(id); // Assure-toi que cette fonction existe

    if (emp.getId() == 0) {
        QMessageBox::warning(this, "Employé introuvable", "Aucun employé trouvé avec cet ID !");
        return;
    }

    // Remplissage des champs
    ui->le_modif_nom->setText(emp.getNom());
    ui->le_modif_prenom->setText(emp.getPrenom());
    ui->le_modif_poste->setText(emp.getPoste());
    ui->le_modif_salaire->setText(QString::number(emp.getSalaire()));
    ui->le_modif_status->setText(emp.getStatus());
    ui->le_modif_adresse->setText(emp.getAdresse());
    ui->le_modif_role->setText(emp.getRole());
    ui->le_modif_dateE->setDateTime(emp.getDateEmbauche());

    // Demande de confirmation
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirmer", "Voulez-vous modifier cet employé ?", QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        // Récupérer les nouvelles valeurs
        QString nom = ui->le_modif_nom->text();
        QString prenom = ui->le_modif_prenom->text();
        QString poste = ui->le_modif_poste->text();
        double salaire = ui->le_modif_salaire->text().toDouble();
        QString status = ui->le_modif_status->text();
        QString adresse = ui->le_modif_adresse->text();
        QString role = ui->le_modif_role->text();
        QDateTime dateE = ui->le_modif_dateE->dateTime();

        // Vérifier la validité des champs
        if (nom.isEmpty() || prenom.isEmpty() || poste.isEmpty() || status.isEmpty() || role.isEmpty()) {
            QMessageBox::critical(this, "Erreur", "Veuillez remplir tous les champs !");
            return;
        }

        if (!dateE.isValid() || dateE.date().isNull()) {
            QMessageBox::critical(this, "Erreur", "Veuillez entrer une date valide !");
            return;
        }

        // Vérification de la date avec debug
        qDebug() << "Date sélectionnée :" << dateE.toString("yyyy-MM-dd HH:mm:ss");

        // Modification de l'employé
        bool test = emp.modifier(id, nom, prenom, poste, salaire, status, adresse, role, dateE);

        if (test) {
            ui->tab_employee1->setModel(emp.afficher()); // Rafraîchir la table
            QMessageBox::information(this, "Succès", "Modification effectuée !");
        } else {
            QMessageBox::critical(this, "Erreur", "Modification non effectuée !");
        }
    }
}
/*

/*void MainWindow::on_pushButton_modifier_clicked()
{
    // Récupérer l'ID de l'employé depuis le champ de texte
    int id = ui->le_modif_id_emp->text().toInt();

    if (id <= 0) {
        QMessageBox::critical(this, "Erreur de validation", "Veuillez saisir un ID valide pour l'employé.");
        return;
    }

    // Vérifier si l'ID existe dans la base de données
    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT COUNT(*) FROM EMPLOYE WHERE ID_EMPLOYE = :id");
    checkQuery.bindValue(":id", id);
    if (!checkQuery.exec()) {
        QMessageBox::critical(this, "Erreur", "Échec lors de la vérification de l'ID : " + checkQuery.lastError().text());
        return;
    }

    checkQuery.next();
    if (checkQuery.value(0).toInt() == 0) {
        QMessageBox::critical(this, "Erreur", "L'ID spécifié n'existe pas dans la base de données.");
        return;
    }

    // Créer un objet Employe pour récupérer les informations actuelles de l'employé
    employee1 emp;
    emp.chargerDonnees(id); // Appeler la méthode chargerDonnees pour charger les informations

    // Remplir les champs de modification avec les données actuelles de l'employé
    ui->le_modif_nom->setText(emp.getNom());
    ui->le_modif_prenom->setText(emp.getPrenom());
    ui->le_modif_poste->setText(emp.getPoste());
    ui->le_modif_salaire->setText(QString::number(emp.getSalaire()));
    ui->le_modif_status->setText(emp.getStatus());
    ui->le_modif_adresse->setText(emp.getAdresse());
    ui->le_modif_role->setText(emp.getRole());
    ui->le_modif_dateE->setDateTime(emp.getDateEmbauche());  // Utiliser setDate au lieu de setDateTime pour une date simple

    // Récupérer les valeurs des champs pour les valider
    QString name = ui->le_modif_nom->text();
    QString prenom = ui->le_modif_prenom->text();
    QString poste = ui->le_modif_poste->text();
    QString salaireStr = ui->le_modif_salaire->text();
    QString status = ui->le_modif_status->text();
    QString adresse = ui->le_modif_adresse->text();
    QString role = ui->le_modif_role->text();
    QDate dateEmbauche = ui->le_modif_dateE->date();

    // Validation des champs
    QRegularExpression regexName("^[a-zA-Z\\s]+$");
    if (!regexName.match(name).hasMatch()) {
        QMessageBox::critical(this, "Erreur de validation", "Le nom doit contenir uniquement des lettres et des espaces.");
        return;
    }

    QRegularExpression regexPoste("^[a-zA-Z\\s]+$");
    if (!regexPoste.match(poste).hasMatch()) {
        QMessageBox::critical(this, "Erreur de validation", "Le poste doit contenir uniquement des lettres et des espaces.");
        return;
    }

    QRegularExpression regexNumber("^[0-9]+(\\.[0-9]+)?$");
    if (!regexNumber.match(salaireStr).hasMatch()) {
        QMessageBox::critical(this, "Erreur de validation", "Le salaire doit être un nombre valide.");
        return;
    }

    double salaire = salaireStr.toDouble();
    if (salaire <= 0) {
        QMessageBox::critical(this, "Erreur de validation", "Le salaire doit être un nombre supérieur à zéro.");
        return;
    }

    // Mise à jour des informations de l'employé dans la base de données
    QSqlQuery query;
    query.prepare("UPDATE EMPLOYE SET NOM = :NOM, PRENOM = :PRENOM, POSTE = :POSTE, "
                  "SALAIRE = :SALAIRE, STATUS = :STATUS, ADRESSE = :ADRESSE, ROLE = :ROLE, "
                  "DATE_E = :DATE_E WHERE ID_EMPLOYE = :ID_EMPLOYE");

    // Lier les valeurs aux paramètres dans la requête
    query.bindValue(":NOM", name);
    query.bindValue(":PRENOM", prenom);
    query.bindValue(":POSTE", poste);
    query.bindValue(":SALAIRE", salaire);
    query.bindValue(":STATUS", status);
    query.bindValue(":ADRESSE", adresse);
    query.bindValue(":ROLE", role);
    query.bindValue(":DATE_E", dateEmbauche.toString("yyyy-MM-dd")); // Date formatée au format 'YYYY-MM-DD'
    query.bindValue(":ID_EMPLOYE", id);

    // Exécuter la requête et vérifier si elle a réussi
    if (query.exec()) {
        QMessageBox::information(this, "Succès", "L'employé a été mis à jour avec succès!");
        ui->tab_employee1->setModel(employee1().afficher()); // Mettre à jour la vue
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la mise à jour : " + query.lastError().text());

    }
}

*/
void MainWindow::on_pushButton_modifier_clicked()
{
    int id = ui->le_modif_id_emp->text().toInt();

    if (id <= 0) {
        QMessageBox::warning(this, "Erreur", "ID invalide !");
        return;
    }

    // Chercher l'employé avec l'ID
    employee1 emp = employee1::chercherParId(id);

    if (emp.getId() == 0) {
        QMessageBox::warning(this, "Employé introuvable", "Aucun employé trouvé avec cet ID !");
        return;
    }

    // Remplir les champs avec les données existantes
    ui->le_modif_nom->setText(emp.getNom());
    ui->le_modif_prenom->setText(emp.getPrenom());
    ui->le_modif_poste->setText(emp.getPoste());
    ui->le_modif_salaire->setText(QString::number(emp.getSalaire()));
    ui->le_modif_status->setText(emp.getStatus());
    ui->le_modif_adresse->setText(emp.getAdresse());
    ui->le_modif_role->setText(emp.getRole());
    ui->le_modif_dateE->setDateTime(emp.getDateEmbauche());

    // Demande de confirmation pour modifier l'employé
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirmer", "Voulez-vous modifier cet employé ?", QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        // Récupérer les nouvelles valeurs
        QString nom = ui->le_modif_nom->text();
        QString prenom = ui->le_modif_prenom->text();
        QString poste = ui->le_modif_poste->text();
        double salaire = ui->le_modif_salaire->text().toDouble();
        QString status = ui->le_modif_status->text();
        QString adresse = ui->le_modif_adresse->text();
        QString role = ui->le_modif_role->text();
        QDateTime dateE = ui->le_modif_dateE->dateTime();

        // Vérifier que tous les champs sont remplis
        if (nom.isEmpty() || prenom.isEmpty() || poste.isEmpty() || status.isEmpty() || role.isEmpty()) {
            QMessageBox::critical(this, "Erreur", "Veuillez remplir tous les champs !");
            return;
        }

        if (!dateE.isValid() || dateE.date().isNull()) {
            QMessageBox::critical(this, "Erreur", "Veuillez entrer une date valide !");
            return;
        }

        // Vérification de la date avec debug
        qDebug() << "Date sélectionnée :" << dateE.toString("yyyy-MM-dd HH:mm:ss");

        // Modifier l'employé avec les nouvelles valeurs
        bool test = emp.modifier(id, nom, prenom, poste, salaire, status, adresse, role, dateE);

        if (test) {
            // Rafraîchir l'affichage de la table avec les nouvelles données
            ui->tab_employee1->setModel(emp.afficher()); // Rafraîchir la table
            QMessageBox::information(this, "Succès", "Modification effectuée !");
        } else {
            QMessageBox::critical(this, "Erreur", "La modification a échoué !");
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
    if (id <= 0) {
        QMessageBox::critical(this, "Erreur", "L'ID doit être un nombre positif.");
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

void MainWindow::on_pushButton_rechercher_clicked()
{
    connect(ui->pushButton_rechercher, SIGNAL(clicked()), this, SLOT(on_pushButton_rechercher_clicked()));
            ui->pushButton_rechercher->setEnabled(true);
            ui->pushButton_rechercher->setFocus();
    QString nomRecherche = ui->le_recherche->text().trimmed();

    if (nomRecherche.isEmpty()) {
        QMessageBox::warning(this, "Recherche", "Veuillez entrer un nom à rechercher !");
        return;
    }

    qDebug() << "Recherche en cours pour :" << nomRecherche;

    QSqlQueryModel* model = emp.rechercherParNom(nomRecherche);

    if (model && model->rowCount() > 0) {
        ui->tab_employee1->setModel(model);
        qDebug() << "Résultats trouvés :" << model->rowCount();
    } else {
        QMessageBox::information(this, "Résultat", "Aucun employé trouvé avec ce nom.");
        qDebug() << "Aucun résultat trouvé.";
    }
}

