#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "local.h"
#include "connection.h"
#include<QPdfWriter>
#include <QPrinter>
#include <QPrintPreviewDialog>
#include <QPainter>
#include <QTableView>
#include <QSqlQueryModel>
#include <QFileDialog>
#include <QTextDocument>
#include <QPageSize>  // Inclure ce header pour utiliser QPageSize::A4
#include<QtCharts>
#include <QChartView>
#include <QDialog>
#include <QCheckBox>
#include <QPushButton>
#include <QVBoxLayout>
#include <QInputDialog>
#include <QRandomGenerator>
#include <QQuickItem>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->quickWidget->setSource(QUrl(QStringLiteral("qrc:/map.qml")));
    ui->quickWidget->show();
    auto obj = ui->quickWidget->rootObject();
    connect(this, SIGNAL(setCenter(QVariant, QVariant)), obj, SLOT(setCenter(QVariant, QVariant)));
    connect(this, SIGNAL(addMarker(QVariant, QVariant)), obj, SLOT(addMarker(QVariant, QVariant)));

    emit setCenter(36.8401, 10.2654);
    emit addMarker(36.8401, 10.2654);

    mettreAJourAffichage();


    // Connecter les boutons "Ajouter" et "Annuler" à leurs slots respectifs
    //connect(ui->pushButton_ajouter, &QPushButton::clicked, this, &MainWindow::on_pushButton_ajouter_clicked);
    //  connect(ui->pushButton_annuler, &QPushButton::clicked, this, &MainWindow::on_pushButton_annuler_clicked);
    //connect(ui->pushButton_supprimer, &QPushButton::clicked, this, &MainWindow::on_pushButton_supprimer_clicked);
    // connect(ui->pushButton_modifier, &QPushButton::clicked, this, &MainWindow::on_pushButton_modifier_clicked);
    // Dans le constructeur MainWindow
    connect(ui->pushButton_6, &QPushButton::clicked, this, &MainWindow::rechercherLocaux);
    connect(ui->pushButton_telecharger, &QPushButton::clicked, this, &MainWindow::on_pushButton_telecharger_clicked);

    connect(ui->pushButton_19, &QPushButton::clicked, this, &MainWindow::on_pushButton_statistique_clicked);
    connect(ui->pushButton_clear, &QPushButton::clicked, this, &MainWindow::on_pushButton_clear_clicked);
    //connect(ui->pushButton_20, &QPushButton::clicked, this, &MainWindow::afficherLocalisationMall);
    QString filePath = QUrl::fromLocalFile(QCoreApplication::applicationDirPath() + "/map.html").toString();
    ui->webEngineView->load(QUrl(filePath));


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

    // Valider les valeurs saisies
    if ( surface <= 0 || prix <= 0 || type.isEmpty() || disponibilite.isEmpty() || etage.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez saisir des valeurs valides.");
        return;
    }

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
        on_pushButton_annuler_clicked();
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
void MainWindow::on_pushButton_18_clicked()
{
    QSqlQueryModel* model = local.trier();
    if (model != nullptr) {
        ui->tableView->setModel(model);
    } else {
        QMessageBox::critical(this, "Erreur", "Erreur lors du tri des locaux.");
    }
}
void MainWindow::rechercherLocaux()
{
    // Récupérer la valeur entrée dans le QLineEdit
    QString disponibilite = ui->lineEdit->text().trimmed();

    // Vérifier si la disponibilité est "dispo" ou "non"
    if (disponibilite == "dispo" || disponibilite == "non") {
        Local local;  // Créer un objet Local pour accéder à la méthode de recherche
        QSqlQueryModel* model = local.rechercherParDisponibilite(disponibilite);

        if (model != nullptr) {
            // Afficher les résultats dans le QTableView
            ui->tableView->setModel(model);
        } else {
            QMessageBox::warning(this, "Erreur", "Aucun local trouvé pour cette disponibilité.");
        }
    } else {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer 'dispo' ou 'non' pour rechercher.");
    }
}
void MainWindow::on_pushButton_telecharger_clicked()
{
    QString filePath = QFileDialog::getSaveFileName(this, tr("Save PDF"), "", tr("PDF Files (*.pdf)"));
    if (filePath.isEmpty()) {
        return;
    }

    QPdfWriter pdfWriter(filePath);
    pdfWriter.setPageSize(QPageSize::A4);
    pdfWriter.setTitle("Fournisseurs List");

    QPainter painter(&pdfWriter);
    int yPos = 1000;  // Initial vertical position
    int rowHeight = 1000;  // Row height

    QFont titleFont("Helvetica", 18, QFont::Bold);
    QFont headerFont("Helvetica", 12, QFont::Bold);
    QFont contentFont("Helvetica", 12);

    // Title
    painter.setFont(titleFont);
    painter.drawText(500, 500, "LOCAUX List");

    // Header
    painter.setFont(headerFont);
    painter.drawText(400, yPos, "ID_LOCAL");
    painter.drawText(1500, yPos, "SURFACE");
    painter.drawText(2800, yPos, "TYPE");
    painter.drawText(4500, yPos, "DISPONIBILITE");
    painter.drawText(6300, yPos, "PRIX");
    painter.drawText(7200, yPos, "ETAGE");


    yPos += rowHeight;

    QSqlQuery query;
    if (!query.prepare("SELECT ID_LOCAL, SURFACE, TYPE, DISPONIBILITE, PRIX, ETAGE FROM fatma.local_commerciale")) {
        qDebug() << "SQL Error: " << query.lastError().text();
        QMessageBox::critical(this, "Database Error", "Failed to retrieve fournisseur data:\n" + query.lastError().text());
        return;
    }

    if (query.exec()) {
        painter.setFont(contentFont);
        while (query.next()) {
            painter.drawText(400, yPos, query.value("ID_LOCAL").toString());
            painter.drawText(1500, yPos, query.value("SURFACE").toString());
            painter.drawText(2800, yPos, query.value("TYPE").toString());
            painter.drawText(4500, yPos, query.value("DISPONIBILITE").toString());
            painter.drawText(6000, yPos, QString::number(query.value("PRIX").toInt()));
            painter.drawText(7800, yPos, query.value("ETAGE").toString());

            yPos += rowHeight;

            if (yPos > pdfWriter.height() - 100) {
                pdfWriter.newPage();
                yPos = 100;
            }
        }
    } else {
        qDebug() << "SQL Error: " << query.lastError().text();
        QMessageBox::critical(this, "Database Error", "Failed to retrieve LOCAUX data:\n" + query.lastError().text());
    }

    painter.end();
    QMessageBox::information(nullptr, tr("PDF file created successfully!"), tr("PDF Export"));
}

void MainWindow::on_pushButton_statistique_clicked()
{
    QSqlQuery query;
    QMap<QString, int> counts;

    // On récupère le nombre de locaux par type
    if (query.exec("SELECT DISPONIBILITE, COUNT(*) FROM fatma.local_commerciale GROUP BY DISPONIBILITE")) {
        while (query.next()) {
            QString disponibilite = query.value(0).toString();
            int count = query.value(1).toInt();
            counts[disponibilite] = count;
        }
    } else {
        QMessageBox::critical(this, "Erreur SQL", "Échec de récupération des statistiques :\n" + query.lastError().text());
        return;
    }

    // Création de la série de données
    QPieSeries *series = new QPieSeries();
    for (auto it = counts.begin(); it != counts.end(); ++it) {
        series->append(it.key(), it.value());
    }

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Répartition des locaux par disponibilite");

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // Affichage dans une nouvelle fenêtre
    QMainWindow *statsWindow = new QMainWindow(this);
    statsWindow->setWindowTitle("Statistiques des Locaux");
    statsWindow->resize(600, 400);
    statsWindow->setCentralWidget(chartView);
    statsWindow->show();
}
void MainWindow::on_pushButton_envoyer_clicked()
{
    QString question = ui->lineEdit_question->text();
    ui->textBrowser_chat->append("Vous : " + question);

    // Vérification des mots-clés dans la question
    if (question.contains("dispo", Qt::CaseInsensitive)) {
        // Requête pour récupérer les IDs des locaux disponibles
        QSqlQuery query("SELECT ID_LOCAL FROM fatma.local_commerciale WHERE LOWER(DISPONIBILITE) = 'dispo'");
        QStringList ids;
        while (query.next()) {
            ids << query.value(0).toString();
        }
        if (ids.isEmpty()) {
            ui->textBrowser_chat->append("Assistant : Aucun local disponible.");
        } else {
            ui->textBrowser_chat->append("Assistant : Locaux disponibles : " + ids.join(", "));
        }
    }
    else if (question.contains("prix", Qt::CaseInsensitive)) {
        // Requête pour récupérer l'ID et le prix des locaux disponibles
        QSqlQuery query("SELECT ID_LOCAL, PRIX FROM fatma.local_commerciale WHERE LOWER(DISPONIBILITE) = 'dispo'");
        bool localFound = false;
        while (query.next()) {
            localFound = true;
            ui->textBrowser_chat->append("Assistant : Local " + query.value(0).toString() + " → " + query.value(1).toString() + " DT");
        }
        if (!localFound) {
            ui->textBrowser_chat->append("Assistant : Aucun prix disponible pour les locaux.");
        }
    }
    else if (question.contains("étage", Qt::CaseInsensitive)) {
        // Requête pour récupérer l'ID et l'étage des locaux disponibles
        QSqlQuery query("SELECT ID_LOCAL, ETAGE FROM fatma.local_commerciale WHERE LOWER(DISPONIBILITE) = 'dispo'");
        bool localFound = false;
        while (query.next()) {
            localFound = true;
            ui->textBrowser_chat->append("Assistant : Local " + query.value(0).toString() + " est à l'" + query.value(1).toString());
        }
        if (!localFound) {
            ui->textBrowser_chat->append("Assistant : Aucun étage disponible pour les locaux.");
        }
    }
    else if (question.contains("type", Qt::CaseInsensitive)) {
        // Requête pour récupérer l'ID et le type des locaux disponibles
        QSqlQuery query("SELECT ID_LOCAL, TYPE FROM fatma.local_commerciale WHERE LOWER(DISPONIBILITE) = 'dispo'");
        bool localFound = false;
        while (query.next()) {
            localFound = true;
            ui->textBrowser_chat->append("Assistant : Local " + query.value(0).toString() + " est un(e) " + query.value(1).toString());
        }
        if (!localFound) {
            ui->textBrowser_chat->append("Assistant : Aucun type de local trouvé.");
        }
    }
    else {
        ui->textBrowser_chat->append("Assistant : Je ne comprends pas encore cette question.");
    }

    // Réinitialiser le champ de texte après l'envoi de la question
    ui->lineEdit_question->clear();
}

// Fonction pour réinitialiser les champs lorsque le bouton Clear est cliqué
void MainWindow::on_pushButton_clear_clicked()
{
    ui->lineEdit_question->clear();          // Efface la zone de saisie de la question
    ui->textBrowser_chat->clear();           // Efface le chat (zone de texte de réponse)
}

void MainWindow::jeuDevineNombre() {
    int nombreSecret = QRandomGenerator::global()->bounded(1, 11); // entre 1 et 10
    int essaisRestants = 3;
    bool ok;

    while (essaisRestants > 0) {
        int tentative = QInputDialog::getInt(this, "Jeu : Devine le Nombre",
                                             QString("Il te reste %1 essai(s).\nDevine un nombre entre 1 et 10 :").arg(essaisRestants),
                                             1, 1, 10, 1, &ok);

        if (!ok) break;  // L'utilisateur a annulé

        if (tentative == nombreSecret) {
            QMessageBox::information(this, "Bravo !", "Tu as deviné le bon nombre 🎉");
            return;
        } else if (tentative < nombreSecret) {
            QMessageBox::information(this, "Trop bas", "Essaie un nombre plus grand !");
        } else {
            QMessageBox::information(this, "Trop haut", "Essaie un nombre plus petit !");
        }

        essaisRestants--;
    }

    QMessageBox::warning(this, "Perdu 😢", QString("Désolé, le bon nombre était %1").arg(nombreSecret));
    QApplication::quit();
}

void MainWindow::on_pushButton_11_clicked() {
    verifierCaptchaEtLancerJeu();
}

void MainWindow::verifierCaptchaEtLancerJeu() {
    QMessageBox::StandardButton reponse;
    reponse = QMessageBox::question(this, "Vérification", "🧠 Je ne suis pas un robot", QMessageBox::Yes | QMessageBox::No);

    if (reponse == QMessageBox::Yes) {
        // Si l'utilisateur coche "Oui", lancer le jeu
        jeuDevineNombre();
    } else {
        QMessageBox::information(this, "Accès refusé", "Veuillez confirmer que vous n’êtes pas un robot.");
        QApplication::quit();
    }
}



