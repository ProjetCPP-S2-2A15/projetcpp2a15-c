#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "services.h"
#include <QMessageBox>
#include <QPdfWriter>
#include <QPainter>
#include <QTableWidgetItem>
#include <QFile>
#include <QFileDialog>
#include "NotificationPanel.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentWidget(ui->page_3); // Affiche la page CRUD au démarrage
    ui->tab_Services->setModel(s.afficher());


    // Crée un panneau de notifications
    notificationPanel = new NotificationPanel(this);
    ui->verticalLayout_12->addWidget(notificationPanel);

    // Exemple : appel de la fonction pour vérifier les services
    checkServiceStatus();


    // 👉 Ajoute ton QDoubleValidator ici :
    QDoubleValidator *prixValidator = new QDoubleValidator(0, 999999.99, 2, this);
    prixValidator->setNotation(QDoubleValidator::StandardNotation);
    ui->le_prix->setValidator(prixValidator);
    ui->le_modif_prix->setValidator(prixValidator);

}

// Méthode pour vérifier les services et ajouter des notifications
void MainWindow::checkServiceStatus()
{
    // Effacer les notifications précédentes avant d'ajouter les nouvelles
    notificationPanel->clearNotifications();

    // Récupérer tous les services de la base de données
    Services service;
    QSqlQueryModel* model = service.afficher();  // Récupérer tous les services dans un modèle

    for (int i = 0; i < model->rowCount(); ++i) {
        // Récupérer les données du service
        QString statut = model->data(model->index(i, 4)).toString();  // Statut du service
        QString dateFinStr = model->data(model->index(i, 7)).toString();  // Date de fin
        QDate dateFin = QDate::fromString(dateFinStr, "yyyy-MM-dd");

        // Vérifier si le service n'est pas réalisé et que la date limite est dépassée
        if (statut != "réalisé" && statut != "en cours" && dateFin < QDate::currentDate()) {
            QString serviceNom = model->data(model->index(i, 1)).toString();  // Nom du service
            // Afficher la date limite (date de fin) dans le message
            QString message = QString("⚠️ Le service '%1' n'est pas encore réalisé. Date limite : %2")
                                  .arg(serviceNom).arg(dateFin.toString("dd/MM/yyyy"));

            // Ajouter la notification au panneau
            notificationPanel->addNotification(message);
        }
    }
}








MainWindow::~MainWindow()
{
    delete ui;

}





void MainWindow::on_pushButton_ajouter_clicked()
{
    int id = ui->le_id_ser->text().toInt();
    QString nom = ui->le_nom->text();
    QString prixStr = ui->le_prix->text();
    QString description = ui->le_descrip->text();
    QString statut = ui->le_statut->currentText();
    QString type = ui->le_type->currentText();
    QString dateDebut = ui->le_dated_date->date().toString("yyyy-MM-dd");
    QString dateFin = ui->le_datef_date->date().toString("yyyy-MM-dd");

    bool prixOk;
    double prix = prixStr.toDouble(&prixOk);

    // Contrôle des champs
    if (id == 0 || nom.isEmpty() || description.isEmpty() || statut.isEmpty() || type.isEmpty()) {
        QMessageBox::warning(this, "Champs manquants", "Veuillez remplir tous les champs !");
        return;
    }

    if (!prixOk || prix <= 0) {
        QMessageBox::warning(this, "Prix invalide", "Le prix doit être un nombre supérieur à 0.");
        return;
    }

    Services s(id, nom, prix, description, statut, type, dateDebut, dateFin);
    bool ajoutOK = s.ajouter();

    if (ajoutOK) {
        QMessageBox::information(this, "Ajout", "Service ajouté avec succès !");
        ui->tab_Services->setModel(s.afficher());
        ajouterHistorique("Ajout du service : " + nom);
    } else {
        QMessageBox::critical(this, "Erreur", "Erreur lors de l'ajout du service.");
    }
}



void MainWindow::on_pushButton_supprimer_clicked()
{
    int id = ui->id_supp->text().toInt();

    qDebug() << " [UI] Suppression - ID récupéré : " << id;

    if (id == 0) {
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                              QObject::tr("Veuillez entrer un ID valide !\n"), QMessageBox::Cancel);
        return;
    }

    bool test = s.supprimer(id);

    if (test) {
        qDebug() << " [SUPPRESSION] Succès! Rafraîchissement du tableau.";
        ui->tab_Services->setModel(s.afficher());
        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Suppression effectuée\nClick Cancel to exit."), QMessageBox::Cancel);
    } else {
        qDebug() << " [SUPPRESSION] Échec ! Vérifie la requête SQL.";
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                              QObject::tr("Suppression non effectuée\nClick Cancel to exit."), QMessageBox::Cancel);
    }


    if (s.supprimer(id)) {
        ui->tab_Services->setModel(s.afficher());
        ajouterHistorique("Suppression du service ID : " + QString::number(id));
    }

}


void MainWindow::on_pushButton_annuler_clicked()
{
    ui->le_id_ser->clear();
    ui->le_nom->clear();
    ui->le_prix->clear();
    ui->le_descrip->clear();
    ui->le_statut->clear();
    ui->le_type->clear();
    ui->le_dated_date->clear();
    ui->le_datef_date->clear();
}

void MainWindow::on_pushButton_annuler_2_clicked()
{
    ui->le_modif_id_ser->clear();
    ui->le_modif_nom->clear();
    ui->le_modif_prix->clear();
    ui->le_modif_descrip->clear();
    ui->le_modif_statut->clear();
    ui->le_modif_type->clear();
    ui->le_modif_dated_date->clear();
    ui->le_modif_datef_date->clear();
}

void MainWindow::on_pushButton_modifier_clicked()
{
    int id = ui->le_modif_id_ser->text().toInt();
    QString nom = ui->le_modif_nom->text();
    QString prixStr = ui->le_modif_prix->text();
    QString description = ui->le_modif_descrip->text();
    QString statut = ui->le_modif_statut->currentText();
    QString type = ui->le_modif_type->currentText();
    QString dateDebut = ui->le_modif_dated_date->date().toString("yyyy-MM-dd");
    QString dateFin = ui->le_modif_datef_date->date().toString("yyyy-MM-dd");

    bool prixOk;
    double prix = prixStr.toDouble(&prixOk);

    if (id == 0 || nom.isEmpty() || description.isEmpty() || statut.isEmpty() || type.isEmpty()) {
        QMessageBox::warning(this, "Champs manquants", "Veuillez remplir tous les champs !");
        return;
    }

    if (!prixOk || prix <= 0) {
        QMessageBox::warning(this, "Prix invalide", "Le prix doit être un nombre supérieur à 0.");
        return;
    }

    Services s(id, nom, prix, description, statut, type, dateDebut, dateFin);
    bool modifOK = s.modifier(id, nom, prix, description, statut, type, dateDebut, dateFin);

    if (modifOK) {
        QMessageBox::information(this, "Modification", "Service modifié avec succès !");
        ui->tab_Services->setModel(s.afficher());
        ajouterHistorique("Modification du service : " + nom);
        checkServiceStatus(); // Mise à jour notifications
    } else {
        QMessageBox::critical(this, "Erreur", "Erreur lors de la modification.");
    }
}



void MainWindow::on_pushButton_annuler_3_clicked()
{
    ui->id_supp->clear();
}

void MainWindow::on_pb_rechercher_clicked()
{
    QString nom = ui->le_recherche->text();  // Récupérer le texte du champ de recherche
    Services s1;

    QSqlQueryModel *model = s1.recherchernom(nom);

    if (model->rowCount() > 0) {
        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Service retrouvé \n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tab_Services->setModel(model);  // Affichage dans le tableau
    } else {
        QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                              QObject::tr("Service non retrouvé.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
    }
}



void MainWindow::on_pushButton_annuler_search_clicked()
{
    // Vider le champ de recherche
    ui->le_recherche->clear();

    // Restaurer l'affichage initial du tableau avec toutes les données
    ui->tab_Services->setModel(s.afficher());  // Cela suppose que 's' est l'objet qui gère les services et que la méthode afficher() retourne le modèle de la table complet
}


void MainWindow::exportTableToPDF(QTableView *table, const QString &filename)
{
    if (!table) return;

    QPdfWriter pdfWriter(filename);
    pdfWriter.setPageSize(QPageSize(QPageSize::A4));
    pdfWriter.setResolution(300);
    QPainter painter(&pdfWriter);
    QFont font("Arial", 10);
    painter.setFont(font);

    int leftMargin = 20;
    int topMargin = 50;
    int rowHeight = 30;
    int textPadding = 5;

    QAbstractItemModel *model = table->model();
    int columnCount = model->columnCount();
    int rowCount = model->rowCount();
    int pageWidth = pdfWriter.width() - 2 * leftMargin;
    int columnWidth = pageWidth / columnCount;

    int y = topMargin;
    painter.setPen(Qt::black);
    painter.setBrush(Qt::lightGray);
    painter.drawRect(leftMargin, y, pageWidth, rowHeight);

    for (int col = 0; col < columnCount; ++col) {
        QString headerText = model->headerData(col, Qt::Horizontal, Qt::DisplayRole).toString();
        QRect headerRect(leftMargin + col * columnWidth + textPadding, y, columnWidth - 2 * textPadding, rowHeight);
        painter.drawText(headerRect, Qt::AlignCenter, headerText);
    }

    y += rowHeight;
    painter.setBrush(Qt::NoBrush);
    for (int row = 0; row < rowCount; ++row) {
        painter.drawRect(leftMargin, y, pageWidth, rowHeight);
        for (int col = 0; col < columnCount; ++col) {
            QString cellText = model->data(model->index(row, col), Qt::DisplayRole).toString();
            QRect cellRect(leftMargin + col * columnWidth + textPadding, y, columnWidth - 2 * textPadding, rowHeight);
            painter.drawText(cellRect, Qt::AlignCenter, cellText);
        }
        y += rowHeight;
    }

    painter.end();
    QMessageBox::information(this, "Exportation réussie", "Le fichier PDF a été enregistré avec succès !");
}

void MainWindow::on_pushButton_telecharger_pdf_clicked()
{
    QString filePath = QFileDialog::getSaveFileName(this, "Enregistrer en PDF", "services.pdf", "PDF Files (*.pdf)");
    if (!filePath.isEmpty()) {
        exportTableToPDF(ui->tab_Services, filePath);
    }
}

void MainWindow::on_tab_Services_clicked(const QModelIndex &index)
{
    if (!index.isValid()) return;

    // Récupérer l'index de la ligne sélectionnée
    int row = index.row();

    // Récupérer le modèle de données
    QAbstractItemModel *model = ui->tab_Services->model();

    // Récupérer les valeurs des colonnes
    int id = model->data(model->index(row, 0)).toInt();
    QString nom = model->data(model->index(row, 1)).toString();
    double prix = model->data(model->index(row, 2)).toDouble();
    QString description = model->data(model->index(row, 3)).toString();
    QString statut = model->data(model->index(row, 4)).toString();
    QString type = model->data(model->index(row, 5)).toString();
    QString dateDebut = model->data(model->index(row, 6)).toString();
    QString dateFin = model->data(model->index(row, 7)).toString();

    // Remplir les champs de modification avec les valeurs sélectionnées
    ui->le_modif_id_ser->setText(QString::number(id));
    ui->le_modif_nom->setText(nom);
    ui->le_modif_prix->setText(QString::number(prix));
    ui->le_modif_descrip->setText(description);
    ui->le_modif_statut->setCurrentText(statut);
    ui->le_modif_type->setCurrentText(type);
    ui->le_modif_dated_date->setDate(QDate::fromString(dateDebut, "yyyy-MM-dd"));
    ui->le_modif_datef_date->setDate(QDate::fromString(dateFin, "yyyy-MM-dd"));
}



void MainWindow::on_pb_tier_clicked()
{
    QString critere = ui->le_trier->currentText().trimmed().toLower();  // on normalise tout

    Services s;
    QSqlQueryModel* model = nullptr;

    if (critere == "prix") {
        model = s.trierParPrix();
    } else if (critere == "type") {
        model = s.trierParType();
    } else {
        QMessageBox msg;
        msg.setStyleSheet("QMessageBox { background-color: white; }");
        msg.setWindowTitle("Attention");
        msg.setText("Veuillez choisir un critère de tri valide !");
        msg.setIcon(QMessageBox::Warning);
        msg.exec();
        return;
    }

    if (model && model->rowCount() > 0) {
        ui->tab_Services->setModel(model);

        QMessageBox msg;
        msg.setStyleSheet("QMessageBox { background-color: white; }");
        msg.setWindowTitle("Tri effectué");
        msg.setText("Les services ont été triés avec succès.");
        msg.setIcon(QMessageBox::Information);
        msg.exec();

    } else {
        QMessageBox msg;
        msg.setStyleSheet("QMessageBox { background-color: white; }");
        msg.setWindowTitle("Erreur");
        msg.setText("Aucun service trouvé ou erreur lors du tri.");
        msg.setIcon(QMessageBox::Critical);
        msg.exec();
    }
}


// Aller à la page Fonctionnalités
void MainWindow::on_pushButton_fonctionnalites_2_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_4);
}


void MainWindow::on_pushButton_crud_2_clicked()
{
     ui->stackedWidget->setCurrentWidget(ui->page_3);
}




void MainWindow::on_actualiser_clicked()
{
    // Effacer les notifications précédentes
    notificationPanel->clearNotifications();

    // Re-vérifier les services pour ajouter les nouvelles notifications
    checkServiceStatus();  // Appel de la fonction pour vérifier et ajouter les notifications
}

void MainWindow::ajouterHistorique(const QString &operation)
{
    QString horodatage = QDateTime::currentDateTime().toString("dd/MM/yyyy hh:mm:ss");
    QString entree = horodatage + " - " + operation;
    ui->listWidgetHistorique->addItem(entree);
    ui->listWidgetHistorique->scrollToBottom();  // Pour voir la dernière action
}

