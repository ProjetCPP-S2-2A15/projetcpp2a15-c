#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employee1.h"
#include "statistique.h"
#include <QMessageBox>
#include <QDebug>
#include <QTimer>
#include <QFileDialog>
#include <QPdfWriter>
#include <QPainter>
#include <QPageSize>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QGraphicsScene>




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
stat(new Statistique())

{

    ui->setupUi(this);
    ui->tab_employee1->setModel(emp.afficher());
    QDateTime today = QDateTime::currentDateTime();  // Récupère la date actuelle
    ui->le_dateE_2->setDate(today.date()); // 'dateEmbauche' est le nom de votre QDateEdit
    connect(ui->le_recherche, &QLineEdit::textChanged, this, &MainWindow::on_le_recherche_textChanged);
    connect(ui->pushButton_rechercher, &QPushButton::clicked, this, &MainWindow::on_pushButton_rechercher_clicked);
    connect(ui->pushButton_stat, &QPushButton::clicked, this, &MainWindow::on_pushButton_stat_clicked);
    connect(A.getserial(), SIGNAL(readyRead()), this, SLOT(handleSerialData()));



}


MainWindow::~MainWindow()
{
    delete ui;
    delete stat;
}

void MainWindow::on_pushButton_ajouter_clicked()
{
    // Récupération des données depuis l'interface
    //int id = ui->le_id->text().toInt();
    QString nom = ui->le_nom->text();
    QString prenom = ui->le_prenom->text();
    QString poste = ui->le_poste->currentText();
    double salaire = ui->le_salaire->text().toDouble();
    QString status = ui->le_status->currentText();
    QString adresse = ui->le_adresse->text();
    QString role = ui->le_role->currentText();
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

    // Vérification pour l'adresse
    // Vérification de la longueur de l'adresse (entre 10 et 20 caractères)
    if (adresse.length() < 10 || adresse.length() > 20) {
        QMessageBox::critical(this, "Erreur de validation", "L'adresse doit contenir entre 10 et 20 caractères.");
        return;
    }

    // Vérification du format de l'adresse (lettres, chiffres, espaces, virgules, points ou tirets)
    if (!regexAdresse.match(adresse).hasMatch()) {
        QMessageBox::critical(this, "Erreur de validation", "L'adresse ne doit contenir que des lettres, chiffres, espaces, virgules, points ou tirets.");
        return;
    }

    // Vérification que le salaire est un chiffre et qu'il respecte la plage du poste
    if (salaire <= 0) {
        QMessageBox::critical(this, "Erreur", "Le salaire doit être un nombre valide et supérieur à zéro.");
        return;
    }

    // Exemple de contrôle de saisie basé sur le poste et des intervalles de salaire
    // Vérification du salaire en fonction du poste
    QMap<QString, QPair<double, double>> salairePoste = {
        {"Responsable Maintenance", {2500, 5000}},
        {"Responsable Evenements", {2800, 5500}},
        {"Responsable Services", {2700, 5200}},
        {"Responsable Locataires", {2600, 5100}},
        {"Responsable locaux comerciaux", {3000, 6000}},
        {"Responsable Employees", {2200, 4500}},
        {"Technicien", {1500, 3500}},
        {"Agent de Sécurité", {1200, 3000}}
    };

    // Normalisation du poste
    QString posteNormalise = poste.toLower().trimmed();
    QString posteExact;
    bool posteTrouve = false;

    qDebug() << "Comparaison du poste saisi avec la liste des postes disponibles:";
    for (const QString &key : salairePoste.keys()) {
        qDebug() << "Comparaison avec :" << key << " -> " << key.toLower().trimmed();
        if (key.toLower().trimmed() == posteNormalise) {
            posteExact = key; // Récupération du nom exact du poste
            posteTrouve = true;
            qDebug() << "Poste trouvé et validé :" << posteExact;
            break;
        }
    }

    if (!posteTrouve) {
        QMessageBox::critical(this, "Erreur", QString("Poste inconnu : '%1'. Veuillez choisir un poste valide.").arg(poste));
        return;
    }

    // Vérification du salaire dans l'intervalle
    QPair<double, double> intervalle = salairePoste.value(posteExact);
    if (salaire < intervalle.first || salaire > intervalle.second) {
        QMessageBox::critical(this, "Erreur", QString("Le salaire pour %1 doit être compris entre %2 et %3.")
                                                  .arg(posteExact).arg(intervalle.first).arg(intervalle.second));
        return;
    }
    QStringList responsables = {"Responsable Maintenance", "Responsable Evenements", "Responsable Services",
                                "Responsable Locataires", "Responsable locaux comerciaux", "Responsable Employees"};
    QStringList rolesResponsables = { "Responsable" };

    // Ajout des postes de technicien et agent de sécurité à la condition
    QStringList postesRestreints = {"Technicien", "Agent de Sécurité"};

    if (responsables.contains(posteExact)) {
        // Si le poste est un poste responsable, le rôle ne peut pas être "Employé"
        if (role == "Employee") {
            QMessageBox::critical(this, "Erreur", "Le rôle 'Employé' n'est pas valide pour un poste de responsable.");
            return;
        }
    } else if (postesRestreints.contains(posteExact)) {
        // Si le poste est Technicien ou Agent de Sécurité, le rôle ne peut pas être "Responsable"
        if (rolesResponsables.contains(role)) {
            QMessageBox::critical(this, "Erreur", "Le rôle 'Responsable' n'est pas valide pour ce poste.");
            return;
        }
    } else {
        // Si le poste n'est pas un poste responsable, le rôle ne peut pas être "Responsable"
        if (rolesResponsables.contains(role)) {
            QMessageBox::critical(this, "Erreur", "Le rôle 'Responsable' n'est pas valide pour ce poste.");
            return;
        }

        // Vérification si le rôle est "Employé" pour un poste de Responsable
        if (role == "Employee" && responsables.contains(posteExact)) {
            QMessageBox::critical(this, "Erreur", "Le rôle 'Employé' ne peut pas être associé à un poste de Responsable.");
            return;
        }
    }


    int id =0;
    // Création de l'objet employé
    employee1 emp(id,nom, prenom, poste, salaire, status, adresse, role, dateE);

    // Ajout de l'employé
    bool test = emp.ajouter();

    // Affichage des résultats
    if (test) {
        ui->tab_employee1->setModel(emp.afficher());
        QMessageBox::information(this, "Succès", "Employé ajouté avec succès !");
    } else {
        QMessageBox::critical(this, "Erreur", "L'ajout de l'employé a échoué.");
    }
     // Met à jour les statistiques
}


void MainWindow::onAjouterEmploye()
{
    QDateTime dateE = ui->le_dateE_2->dateTime();  // Récupère la date d'embauche

    // Vérification que la date d'embauche n'est pas dans le futur
    if (dateE > QDateTime::currentDateTime()) {
        QMessageBox::critical(this, "Erreur", "La date d'embauche ne peut pas être dans le futur.");
        return;
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
QString initialPoste = "Responsable Employees";
QString initialStatus = "Actif";
QString initialRole = "Responsable";
void MainWindow::on_pushButton_annuler_clicked(){


    ui->le_nom->clear();
    ui->le_prenom->clear();
      ui->le_poste->setCurrentText(initialPoste);
    ui->le_salaire->clear();
    ui->le_status->setCurrentText(initialStatus);
    ui->le_adresse->clear();
    ui->le_role->setCurrentText(initialRole);
    ui->le_dateE_2->setDate(QDate::currentDate());
}
void MainWindow::on_pushButton_annuler_3_clicked()
{
    ui->id_supp->clear();
}
void MainWindow::on_pushButton_annuler_2_clicked()
{
    ui->le_modif_id_emp->clear();
    ui->le_modif_nom->clear();
    ui->le_modif_prenom->clear();
    ui->le_poste->setCurrentText(initialPoste);
    ui->le_modif_salaire->clear();
    ui->le_poste->setCurrentText(initialPoste);
    ui->le_modif_adresse->clear();
    ui->le_role->setCurrentText(initialRole);
    ui->le_dateE_2->setDate(QDate::currentDate());
}
void MainWindow::on_pushButton_ok_clicked()
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
    ui->le_modif_poste->setCurrentText(emp.getPoste());
    ui->le_modif_salaire->setText(QString::number(emp.getSalaire()));
    ui->le_modif_status->setCurrentText(emp.getStatus());
    ui->le_modif_adresse->setText(emp.getAdresse());
    ui->le_modif_role->setCurrentText(emp.getRole());
    QDateTime dateUTC = emp.getDateEmbauche().toUTC();
    ui->le_modif_dateE->setDateTime(dateUTC);

}
void MainWindow::on_pushButton_modifier_clicked()
{
    // Récupérer l'ID de l'employé depuis le champ de texte
    int id = ui->le_modif_id_emp->text().toInt();
    qDebug() << "Employee ID: " << id;

    // Demander confirmation
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirmer", "Voulez-vous modifier cet employé ?", QMessageBox::Yes | QMessageBox::No);

    // Récupérer les nouvelles valeurs
    QString nom = ui->le_modif_nom->text();
    QString prenom = ui->le_modif_prenom->text();
    QString poste = ui->le_modif_poste->currentText();
    double salaire = ui->le_modif_salaire->text().toDouble();
    QString status = ui->le_modif_status->currentText();
    QString adresse = ui->le_modif_adresse->text();
    QString role = ui->le_modif_role->currentText();
    QDateTime dateE = ui->le_modif_dateE->dateTime();

    // Contrôles de saisie
    QRegularExpression regexLettres("^[a-zA-Z\\s]+$");
    QRegularExpression regexAdresse("^[a-zA-Z0-9\\s,.-]+$");

    if (!regexLettres.match(nom).hasMatch()) {
        QMessageBox::critical(this, "Erreur", "Le nom ne doit contenir que des lettres et des espaces.");
        return;
    }
    if (!regexLettres.match(prenom).hasMatch()) {
        QMessageBox::critical(this, "Erreur", "Le prénom ne doit contenir que des lettres et des espaces.");
        return;
    }
    if (adresse.length() < 10 || adresse.length() > 20) {
        QMessageBox::critical(this, "Erreur", "L'adresse doit contenir entre 10 et 20 caractères.");
        return;
    }
    if (!regexAdresse.match(adresse).hasMatch()) {
        QMessageBox::critical(this, "Erreur", "L'adresse ne doit contenir que des lettres, chiffres, espaces, virgules, points ou tirets.");
        return;
    }
    if (!dateE.isValid() || dateE.date().isNull()) {
        QMessageBox::critical(this, "Erreur", "Veuillez entrer une date valide !");
        return;
    }

    // Vérification du salaire en fonction du poste
    QMap<QString, QPair<double, double>> salairePoste = {
        {"Responsable Maintenance", {2500, 5000}},
        {"Responsable Evenements", {2800, 5500}},
        {"Responsable Services", {2700, 5200}},
        {"Responsable Locataires", {2600, 5100}},
        {"Responsable locaux comerciaux", {3000, 6000}},
        {"Responsable Employees", {2200, 4500}},
        {"Technicien", {1500, 3500}},
        {"Agent de Sécurité", {1200, 3000}}
    };

    if (salaire < salairePoste[poste].first || salaire > salairePoste[poste].second) {
        QMessageBox::critical(this, "Erreur", QString("Le salaire pour %1 doit être entre %2 et %3.")
                                                  .arg(poste).arg(salairePoste[poste].first).arg(salairePoste[poste].second));
        return;
    }

    // Vérification du rôle
    QStringList responsables = {"Responsable Maintenance", "Responsable Evenements", "Responsable Services",
                                "Responsable Locataires", "Responsable locaux comerciaux", "Responsable Employees"};
    QStringList rolesResponsables = { "Responsable" };
    QStringList postesRestreints = {"Technicien", "Agent de Sécurité"};

    if (responsables.contains(poste) && role == "Employee") {
        QMessageBox::critical(this, "Erreur", "Le rôle 'Employé' n'est pas valide pour un poste de responsable.");
        return;
    }
    if (postesRestreints.contains(poste) && rolesResponsables.contains(role)) {
        QMessageBox::critical(this, "Erreur", "Le rôle 'Responsable' n'est pas valide pour ce poste.");
        return;
    }

    if (reply == QMessageBox::Yes) {
        bool test = emp.modifier(id, nom, prenom, poste, salaire, status, adresse, role, dateE);
        if (test) {
            ui->tab_employee1->setModel(emp.afficher());
            QMessageBox::information(this, "Succès", "Modification effectuée !");
        } else {
            QMessageBox::critical(this, "Erreur", "Modification non effectuée !");
        }
    }
}



void MainWindow::on_le_recherche_textChanged(const QString &text)
{
    if (text.trimmed().isEmpty()) {
        // Si le champ de recherche est vide, afficher tous les employés
        ui->tab_employee1->setModel(emp.afficher());
    }
}

void MainWindow::on_pushButton_rechercher_clicked()
{
    QString nomRecherche = ui->le_recherche->text().trimmed();

    if (nomRecherche.isEmpty()) {
        ui->tab_employee1->setModel(emp.afficher());
        return;
    }

    QSqlQueryModel* model = emp.rechercherParNom(nomRecherche);

    if (model && model->rowCount() > 0) {
        ui->tab_employee1->setModel(model);

        // Masquer les colonnes Email et Password
        ui->tab_employee1->setColumnHidden(3, true);  // Ajuste l'index si nécessaire
        ui->tab_employee1->setColumnHidden(4, true);  // Ajuste l'index si nécessaire

        qDebug() << "Résultats trouvés :" << model->rowCount();
    } else {
        QMessageBox::information(this, "Résultat", "Aucun employé trouvé avec ce nom.");
        qDebug() << "Aucun résultat trouvé.";
    }
}
void MainWindow::on_pushButton_tri_clicked() {
    static bool asc = true;  // Variable pour alterner entre ASC et DESC
    QString ordre = asc ? "ASC" : "DESC";
    asc = !asc;  // Inverser l'ordre pour le prochain clic

    employee1 emp;
    QSqlQueryModel* model = emp.trier("DATE_E", ordre);
    ui->tab_employee1->setModel(model);

    // Mettre à jour le texte du bouton pour indiquer le sens du tri
    ui->pushButton_tri->setText(ordre == "ASC" ? "Trier par Date (↑)" : "Trier par Date (↓)");
}
void MainWindow::on_pushButton_telecharger_2_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Enregistrer le PDF", "", "*.pdf");
    if (fileName.isEmpty())
        return;

    QPdfWriter pdfWriter(fileName);
    pdfWriter.setPageSize(QPageSize(QPageSize::A3));
    pdfWriter.setResolution(300);

    QPainter painter(&pdfWriter);
    int pageWidth = pdfWriter.width();
    int xStart;
    int yStart = 200;
    int rowHeight = 100;

    int colWidthNom = 350;
    int colWidthPrenom = 350;
    int colWidthPoste = 600;  // Élargi
    int colWidthSalaire = 300;
    int colWidthDate = 400;
    int colWidthAdresse = 500;  // Élargi
    int colWidthID = 250;
    int colWidthRole = 400;

    int tableWidth = colWidthNom + colWidthPrenom + colWidthPoste + colWidthSalaire +
                     colWidthDate + colWidthAdresse + colWidthID + colWidthRole;

    xStart = (pageWidth - tableWidth) / 2;

    // Titre
    QFont titleFont = painter.font();
    titleFont.setPointSize(16);
    titleFont.setBold(true);
    painter.setFont(titleFont);
    painter.setPen(Qt::green);
    QString title = "Liste des Employés";
    int titleWidth = painter.fontMetrics().horizontalAdvance(title);
    int titleX = (pageWidth - titleWidth) / 2;
    painter.drawText(titleX, 100, title);

    // Police pour le tableau
    QFont font = painter.font();
    font.setPointSize(10);
    painter.setFont(font);
    painter.setPen(Qt::black);

    // Dessiner l'en-tête avec les lignes
    painter.drawRect(xStart, yStart, tableWidth, rowHeight);
    QStringList headers = {"Nom", "Prénom", "Poste", "Salaire", "Date d'Embauche", "Adresse", "ID", "Rôle"};
    QVector<int> colWidths = {colWidthNom, colWidthPrenom, colWidthPoste, colWidthSalaire,
                              colWidthDate, colWidthAdresse, colWidthID, colWidthRole};

    int colPosition = xStart;
    for (int i = 0; i < headers.size(); i++) {
        painter.drawText(colPosition + 50, yStart + rowHeight / 2, headers[i]);
        painter.drawLine(colPosition, yStart, colPosition, yStart + rowHeight);
        colPosition += colWidths[i];
    }
    painter.drawLine(xStart + tableWidth, yStart, xStart + tableWidth, yStart + rowHeight);

    yStart += rowHeight;

    // Récupération des employés
    QSqlQuery query("SELECT ID_EMPLOYE, NOM, PRENOM, POSTE, SALAIRE, STATUS, ADRESSE, ROLE, DATE_E FROM Employe");

    while (query.next()) {
        employee1 emp;
        emp.setNom(query.value("NOM").toString());
        emp.setPrenom(query.value("PRENOM").toString());
        emp.setPoste(query.value("POSTE").toString());
        emp.setSalaire(query.value("SALAIRE").toDouble());
        emp.setStatus(query.value("STATUS").toString());
        emp.setAdresse(query.value("ADRESSE").toString());
        emp.setRole(query.value("ROLE").toString());
        emp.setDateEmbauche(query.value("DATE_E").toDateTime());
        emp.setId(query.value("ID_EMPLOYE").toInt());

        // Dessiner une ligne pour chaque employé
        painter.drawRect(xStart, yStart, tableWidth, rowHeight);
        QStringList values = {
            emp.getNom(), emp.getPrenom(), emp.getPoste(),
            QString::number(emp.getSalaire()), emp.getDateEmbauche().toString("dd/MM/yyyy"),
            emp.getAdresse(), QString::number(emp.getId()), emp.getRole()
        };

        colPosition = xStart;
        for (int i = 0; i < values.size(); i++) {
            painter.drawText(colPosition + 50, yStart + rowHeight / 2, values[i]);
            painter.drawLine(colPosition, yStart, colPosition, yStart + rowHeight);
            colPosition += colWidths[i];
        }
        painter.drawLine(xStart + tableWidth, yStart, xStart + tableWidth, yStart + rowHeight);

        yStart += rowHeight;

        // Vérifier si on doit ajouter une nouvelle page
        if (yStart > pdfWriter.height() - 200) {
            pdfWriter.newPage();
            yStart = 200;
        }
    }

    QMessageBox::information(this, "Succès", "Le fichier PDF a été généré avec succès !");
}

void MainWindow::on_pushButton_stat_clicked()
{
    // Créer une instance de la classe Statistique
    Statistique statistique;

    // Créer le graphique basé sur les statistiques
    QChart *chart = statistique.creerGraphiqueSalaireParPoste();

    // Créer un QChartView pour afficher le graphique
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setBackgroundBrush(Qt::transparent); // Supprimer le fond blanc du QChartView

    // Définir une taille plus large (ajouter de l'espace sur les côtés)
    int largeur = ui->graphicsView->width() * 1.4; // 40% plus large
    int hauteur = ui->graphicsView->height();
    chartView->setMinimumSize(largeur, hauteur);

    // Nettoyer l'ancienne scène s'il y en a une
    if (ui->graphicsView->scene()) {
        delete ui->graphicsView->scene();
    }

    // Ajouter le graphique dans le QGraphicsView
    QGraphicsScene *scene = new QGraphicsScene(this);
    scene->addWidget(chartView);

    // Ajuster la scène pour qu'elle soit plus large sur les côtés
    scene->setSceneRect(-largeur / 4, 0, largeur * 1.2, hauteur);

    ui->graphicsView->setScene(scene);
    ui->graphicsView->fitInView(scene->itemsBoundingRect(), Qt::KeepAspectRatio);
}

void MainWindow::handleSerialData()
{
    QByteArray data = A.read_from_arduino(); // A = ton objet de classe Arduino
    QString rfid = QString(data).trimmed();  // Nettoyer les retours à la ligne

    qDebug() << "RFID reçu :" << rfid;

    QByteArray result = A.cherchercode(rfid); // interro Oracle
    A.write_to_arduino(result + "\n"); // envoyer "1\n" ou "0\n"
}


