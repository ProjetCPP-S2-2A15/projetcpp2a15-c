#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "locataire.h"
#include <QMessageBox>
#include <QSqlError>
#include <QRegularExpression>
#include <QDebug>
#include <QPdfWriter>
#include <QPainter>
#include <QFileDialog>
#include "smtpclient.h"
#include "mimemessage.h"
#include "mimeattachment.h"
#include "mimepart.h"
#include "mimetext.h"
#include "emailaddress.h"
#include <QSqlRecord>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QtCharts/QChart>
#include <QCoreApplication>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDir>
#include <QJsonDocument>
#include <QJsonObject>
#include <QFile>
#include <QDebug>

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
#include <QDesktopServices>
#include <QUrl>
// Fonctions de validation avec QRegularExpression statique
bool validerNom(const QString &nom) {
    static const QRegularExpression regex("^[A-Za-z]+( [A-Za-z]+)?$");
    return regex.match(nom).hasMatch();
}

bool validerAdresse(const QString &adresse) {
    static const QRegularExpression regex("^[A-Za-z ]+$");
    return regex.match(adresse).hasMatch();
}

bool validerEmail(const QString &email) {
    static const QRegularExpression regex("^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.(com|fr)$");
    return regex.match(email).hasMatch() && (email.endsWith("@gmail.com") || email.endsWith("@yahoo.fr") || email.endsWith("@outlook.com"));
}

bool validerTelephone(const QString &telephone) {
    static const QRegularExpression regex("^\\d{8}$");
    return regex.match(telephone).hasMatch();
}

bool validerDates(const QDate &debut, const QDate &fin) {
    QDate currentDate = QDate::currentDate();

    // Vérifier que la date de début n'est pas dans le passé
    if (debut < currentDate) {
        return false;
    }

    // Vérifier que la date de fin est au moins un an après la date de début
    if (fin < debut.addYears(1)) {
        return false;
    }

    return true;
}


// Définition des méthodes de MainWindow
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , ajoutEnCours(false) // Initialisation du drapeau
{
    ui->setupUi(this);

    // Vérification de la connexion à la base de données
    if (!QSqlDatabase::database().isOpen()) {
        QMessageBox::critical(this, "Erreur de connexion", "Impossible de se connecter à la base de données.");
        return;
    }
//fatma
    ui->quickWidget->setSource(QUrl(QStringLiteral("qrc:/map.qml")));
    ui->quickWidget->show();
    auto obj = ui->quickWidget->rootObject();
    connect(this, SIGNAL(setCenter(QVariant, QVariant)), obj, SLOT(setCenter(QVariant, QVariant)));
    connect(this, SIGNAL(addMarker(QVariant, QVariant)), obj, SLOT(addMarker(QVariant, QVariant)));

    emit setCenter(36.8065, 10.1815);
    emit addMarker(36.8065, 10.1815);
mettreAJourAffichage();




    // Connecter les boutons "Ajouter" et "Annuler" à leurs slots respectifs
    connect(ui->pushButton_ajouter_2, &QPushButton::clicked, this, &MainWindow::on_pushButton_Ajouter_clicked);
     connect(ui->pushButton_annuler, &QPushButton::clicked, this, &MainWindow::on_pushButton_Annuler_clicked);
    connect(ui->pushButton_supprimer_2, &QPushButton::clicked, this, &MainWindow::on_pushButton_Supprimer_clicked);
     connect(ui->pushButton_modifier_2, &QPushButton::clicked, this, &MainWindow::on_pushButton_Modifier_clicked);
    // Dans le constructeur MainWindow
    connect(ui->pushButton_6, &QPushButton::clicked, this, &MainWindow::rechercherLocaux);
    connect(ui->pushButton_telecharger, &QPushButton::clicked, this, &MainWindow::on_pushButton_telecharger_clicked);

    connect(ui->pushButton_25, &QPushButton::clicked, this, &MainWindow::on_pushButton_statistique_clicked);
    connect(ui->pushButton_27, &QPushButton::clicked, this, &MainWindow::on_pushButton_18_clicked);
    connect(ui->pushButton_clear, &QPushButton::clicked, this, &MainWindow::on_pushButton_clear_clicked);
    connect(ui->pushButton_26, &QPushButton::clicked, this, &MainWindow::pushButton_26_clicked);
    connect(this, SIGNAL(setCenterWithZoom(QVariant, QVariant, QVariant)),
            obj, SLOT(setCenter(QVariant, QVariant, QVariant)));
//////
    qDebug() << "Connexion du bouton ajouter au slot";

    // Connexions des boutons aux slots
    connect(ui->pushButton_ok, &QPushButton::clicked, this, &MainWindow::on_pushButton_ok_clicked);
    connect(ui->pushButton_modifier, &QPushButton::clicked, this, &MainWindow::on_pushButton_modifier_clicked);
    connect(ui->pushButton_6, &QPushButton::clicked, this, &MainWindow::on_pushButton_6_clicked);
    connect(ui->pushButton_mailing, &QPushButton::clicked, this, &MainWindow::on_pushButton_mailing_clicked);
    connect(ui->pushButton_afficherStats, &QPushButton::clicked, this, &MainWindow::on_pushButton_afficherStats_clicked);
    connect(ui->pushButton_111, &QPushButton::clicked, this, &MainWindow::on_pushButton_11_clicked);
    //connect(ui->pushButton_13, &QPushButton::clicked, this, &MainWindow::on_pushButton_13_clicked);


    // === CONFIGURATION DU CHATBOT ===
    chatbot = new LocalChat(this);

    // Réponse du chatbot
    connect(chatbot, &LocalChat::responseReceived, this, [=](const QString &response) {
        ui->chatDisplay->append("🤖 Assistant: " + response);
    });

    // Erreur du chatbot
    connect(chatbot, &LocalChat::error, this, [=](const QString &errorMessage) {
        ui->chatDisplay->append("⚠️ Erreur: " + errorMessage);
    });

    // Envoi d'un message par bouton ou par touche Entrée
    connect(ui->sendChatMessage, &QPushButton::clicked, this, &MainWindow::on_sendChatMessage_clicked);
    connect(ui->chatInput, &QLineEdit::returnPressed, ui->sendChatMessage, &QPushButton::click);

    // Configuration de l'affichage du chat
    ui->chatDisplay->setReadOnly(true);
    chatbot->initialize(); // message d’accueil automatique

    afficherLocataires(); // Affichage initial des locataires

    // === CONFIGURATION PORT SÉRIE ARDUINO ===


    arduino = new QSerialPort(this);
    portname = "COM15"; // ⚠️ Change ce port si nécessaire

    arduino->setPortName(portname);
    arduino->setBaudRate(QSerialPort::Baud9600);
    arduino->setDataBits(QSerialPort::Data8);
    arduino->setParity(QSerialPort::NoParity);
    arduino->setStopBits(QSerialPort::OneStop);
    arduino->setFlowControl(QSerialPort::NoFlowControl);

    // Ouverture du port série
    if (arduino->open(QIODevice::ReadOnly)) {
        connect(arduino, &QSerialPort::readyRead, this, &MainWindow::on_readyRead);
        qDebug() << "✅ Port série connecté sur " << portname;
    } else {
        QMessageBox::critical(this, "Erreur Port Série", "❌ Impossible d'ouvrir le port " + portname);
    }
}
/*void MainWindow::readSerialData()
{
    QByteArray data = arduino->readAll();
    qDebug() << "🔵 Données reçues : " << data;

    // Exemple : déclenche une alerte si température > 28
    QString dataStr = QString::fromUtf8(data).trimmed();

    // suppose que les données sont du style "Temp=29"
    if (dataStr.startsWith("Temp=")) {
        QString tempValue = dataStr.mid(5); // après "Temp="
        bool ok;
        double temperature = tempValue.toDouble(&ok);
        if (ok && temperature > 28.0) {
            QMessageBox::warning(this, "Température élevée",
                                 "⚠️ Température détectée : " + QString::number(temperature) + "°C");
        }
    }
}*/



void MainWindow::on_pushButton_ok_clicked()
{
    // C'est ici que tu colles le code donné précédemment
    int id = ui->lineEdit_idU->text().toInt();  // récupérer l'ID saisi

    if (id <= 0) {
        QMessageBox::warning(this, "ID invalide", "Veuillez entrer un ID valide.");
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT * FROM LOCATAIRES WHERE ID_LOCATAIRE = :id");
    query.bindValue(":id", id);

    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur SQL", "Impossible de récupérer les informations du locataire.");
        return;
    }

    if (query.next()) {
        ui->lineEdit_nom2->setText(query.value("NOM").toString());
        ui->lineEdit_adresse2->setText(query.value("ADRESSE").toString());
        ui->lineEdit_Email2->setText(query.value("EMAIL").toString());
        ui->lineEdit_telephone2->setText(query.value("TELEPHONE").toString());

        QDate debutContrat = QDate::fromString(query.value("DEBUT_CONTRAT").toString(), "yyyy-MM-dd");
        QDate finContrat = QDate::fromString(query.value("FIN_CONTRAT").toString(), "yyyy-MM-dd");

        ui->dateEdit_debutcontrat2->setDate(debutContrat);
        ui->dateEdit_fincontrat2->setDate(finContrat);
    } else {
        QMessageBox::warning(this, "Aucun locataire", "Aucun locataire trouvé avec cet ID.");
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pushButton_ajouter_clicked()
{
    qDebug() << "Bouton ajouter cliqué"; // Message de débogage

    if (ajoutEnCours) {
        qDebug() << "Ajout déjà en cours"; // Message de débogage
        return; // Si une opération est déjà en cours, ne rien faire
    }

    ajoutEnCours = true; // Marquer le début de l'opération

    QString nom = ui->lineEdit_nom->text();
    QString adresse = ui->lineEdit_adresse->text();
    QString email = ui->lineEdit_email->text();
    QString telephone = ui->lineEdit_telephone->text();
    QDate debut_de_contrat = ui->dateEdit_C_2->date();
    QDate fin_de_contrat = ui->dateEdit_C_3->date();

    if (!validerNom(nom)) {
        QMessageBox::warning(this, "Nom invalide", "Le nom doit contenir uniquement des lettres et un seul espace.");
        ajoutEnCours = false; // Réinitialiser le drapeau
        return;
    }

    if (!validerAdresse(adresse)) {
        QMessageBox::warning(this, "Adresse invalide", "L'adresse doit contenir uniquement des lettres.");
        ajoutEnCours = false; // Réinitialiser le drapeau
        return;
    }

    if (!validerEmail(email)) {
        QMessageBox::warning(this, "Email invalide", "L'email doit se terminer par '@gmail.com', '@yahoo.fr', ou '@outlook.com' et contenir un seul '@' et un seul '.'.");
        ajoutEnCours = false; // Réinitialiser le drapeau
        return;
    }

    if (!validerTelephone(telephone)) {
        QMessageBox::warning(this, "Téléphone invalide", "Le téléphone doit être composé de 8 chiffres.");
        ajoutEnCours = false; // Réinitialiser le drapeau
        return;
    }

    if (!validerDates(debut_de_contrat, fin_de_contrat)) {
        QMessageBox::warning(this, "Dates invalides", "La date doit être valide et le contrat doit être d'une durée minimum d'une année.");
        ajoutEnCours = false; // Réinitialiser le drapeau
        return;
    }

    Locataire locataire(0, nom, adresse, email, telephone, debut_de_contrat, fin_de_contrat); // 0 pour l'ID car il est auto-incrémenté

    if (locataire.ajouter()) {
        QMessageBox::information(this, "Ajout réussi", "Le locataire a été ajouté avec succès.");
        afficherLocataires();
    } else {
        QMessageBox::critical(this, "Erreur", "L'ajout du locataire a échoué.");
    }

    ajoutEnCours = false; // Réinitialiser le drapeau à la fin de l'opération
}
void MainWindow::afficherLocataires()
{
    QSqlQuery query("SELECT * FROM LOCATAIRES");
    if (!query.exec()) {
        qDebug() << "Erreur SQL:" << query.lastError().text();
    } else if (!query.next()) {
        qDebug() << "Aucun locataire trouvé dans la base.";
    } else {
        do {
            qDebug() << "ID:" << query.value("ID_LOCATAIRE").toString()
            << "Nom:" << query.value("NOM").toString()
            << "Adresse:" << query.value("ADRESSE").toString()
            << "Email:" << query.value("EMAIL").toString()
            << "Téléphone:" << query.value("TELEPHONE").toString()
            << "Début contrat:" << query.value("DEBUT_CONTRAT").toString()
            << "Fin contrat:" << query.value("FIN_CONTRAT").toString();
        } while (query.next());
    }

    // Création du modèle pour QTableView
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM LOCATAIRES");  // Récupérer les locataires

    // Ajouter des en-têtes personnalisés
    model->setHeaderData(0, Qt::Horizontal, "ID");
    model->setHeaderData(1, Qt::Horizontal, "Nom");
    model->setHeaderData(2, Qt::Horizontal, "Adresse");
    model->setHeaderData(3, Qt::Horizontal, "Email");
    model->setHeaderData(4, Qt::Horizontal, "Téléphone");
    model->setHeaderData(5, Qt::Horizontal, "Début contrat");
    model->setHeaderData(6, Qt::Horizontal, "Fin contrat");

    // Afficher les données dans le QTableView
    ui->tableView->setModel(model);  // Utiliser QTableView au lieu de QTableWidget

    // Optionnel: Ajuster les colonnes à leur contenu
    ui->tableView->resizeColumnsToContents();
}
void MainWindow::on_pushButton_modifier_clicked()
{
    int id = ui->lineEdit_idU->text().toInt();
    QString nom = ui->lineEdit_nom2->text();
    QString adresse = ui->lineEdit_adresse2->text();
    QString email = ui->lineEdit_Email2->text();
    QString telephone = ui->lineEdit_telephone2->text();
    QDate debut_de_contrat = ui->dateEdit_debutcontrat2->date();
    QDate fin_de_contrat = ui->dateEdit_fincontrat2->date();

    if (!validerNom(nom)) {
        QMessageBox::warning(this, "Nom invalide", "Le nom doit contenir uniquement des lettres et un seul espace.");
        return;
    }

    if (!validerAdresse(adresse)) {
        QMessageBox::warning(this, "Adresse invalide", "L'adresse doit contenir uniquement des lettres.");
        return;
    }

    if (!validerEmail(email)) {
        QMessageBox::warning(this, "Email invalide", "L'email doit se terminer par '@gmail.com', '@yahoo.fr', ou '@outlook.com' et contenir un seul '@' et un seul '.'");
        return;
    }

    if (!validerTelephone(telephone)) {
        QMessageBox::warning(this, "Téléphone invalide", "Le téléphone doit être composé de 8 chiffres.");
        return;
    }

    if (!validerDates(debut_de_contrat, fin_de_contrat)) {
        QMessageBox::warning(this, "Dates invalides", "La date de fin de contrat doit être au moins un mois après la date de début de contrat.");
        return;
    }

    QSqlQuery query;
    query.prepare("UPDATE LOCATAIRES SET NOM = :nom, ADRESSE = :adresse, EMAIL = :email, TELEPHONE = :telephone, DEBUT_CONTRAT = :debut_de_contrat, FIN_CONTRAT = :fin_de_contrat WHERE ID_LOCATAIRE = :id");
    query.bindValue(":nom", nom);
    query.bindValue(":adresse", adresse);
    query.bindValue(":email", email);
    query.bindValue(":telephone", telephone);
    query.bindValue(":debut_de_contrat", debut_de_contrat.toString("yyyy-MM-dd"));
    query.bindValue(":fin_de_contrat", fin_de_contrat.toString("yyyy-MM-dd"));
    query.bindValue(":id", id);

    if (query.exec()) {
        QMessageBox::information(this, "Mise à jour réussie", "Le locataire a été mis à jour avec succès.");
        afficherLocataires();
    } else {
        QMessageBox::critical(this, "Erreur", "La mise à jour du locataire a échoué.");
    }
}
void MainWindow::on_pushButton_supprimer_clicked()
{
    // Récupérer l'ID saisi
    int id = ui->lineEdit_id3->text().toInt();

    if (id <= 0) {
        QMessageBox::warning(this, "ID invalide", "Veuillez entrer un ID valide.");
        return;
    }

    // Vérifier si le locataire existe
    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT COUNT(*) FROM LOCATAIRES WHERE ID_LOCATAIRE = :id");
    checkQuery.bindValue(":id", id);
    checkQuery.exec();

    if (checkQuery.next() && checkQuery.value(0).toInt() == 0) {
        QMessageBox::warning(this, "Erreur", "Aucun locataire trouvé avec cet ID.");
        return;
    }

    // Supprimer le locataire
    QSqlQuery deleteQuery;
    deleteQuery.prepare("DELETE FROM LOCATAIRES WHERE ID_LOCATAIRE = :id");
    deleteQuery.bindValue(":id", id);

    if (deleteQuery.exec()) {
        QMessageBox::information(this, "Succès", "Le locataire a été supprimé avec succès.");
        ui->lineEdit_id3->clear();  // Vider le champ ID après la suppression
    } else {
        QMessageBox::critical(this, "Erreur", "Impossible de supprimer le locataire.");
    }
}
void MainWindow::on_pushButton_triedate_clicked()
{
    // Créer un modèle pour afficher les locataires triés par DEBUT_CONTRAT
    QSqlQueryModel* model = locataire.afficherTrieParDate();  // Utiliser la méthode de tri de la classe Locataire

    // Afficher le modèle dans le QTableView
    ui->tableView->setModel(model);

    // Ajuster la taille des colonnes pour mieux les adapter
    ui->tableView->resizeColumnsToContents();
}

void MainWindow::on_pushButton_trieid_clicked()
{
    // Crée un modèle pour afficher les locataires triés par ID_LOCATAIRE
    QSqlQueryModel* model = locataire.afficherTrieParId();  // Utiliser la méthode de tri de la classe Locataire

    // Afficher le modèle dans un QTableView
    ui->tableView->setModel(model);

    // Ajuster la taille des colonnes pour mieux les adapter
    ui->tableView->resizeColumnsToContents();
}
// Dans mainwindow.cpp (dans le constructeur de MainWindow)

// Dans mainwindow.cpp
void MainWindow::on_pushButton_6_clicked()
{
    QString nomRecherche = ui->lineEdit->text();
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query;

    // Rechercher le locataire par nom (insensible à la casse)
    query.prepare("SELECT * FROM Locataires WHERE LOWER(nom) LIKE LOWER(:nom)");
    query.bindValue(":nom", "%" + nomRecherche.toLower() + "%");
    query.exec();

    model->setQuery(std::move(query));
    ui->tableView->setModel(model);
}
void MainWindow::on_pushButton_telecharger_2_clicked()
{
    QString idRecherche = ui->lineEdit_id4->text().trimmed();
    if (idRecherche.isEmpty()) {
        QMessageBox::warning(this, "Champ vide", "Veuillez saisir l'ID du locataire.");
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT NOM, TELEPHONE, EMAIL, DEBUT_CONTRAT, FIN_CONTRAT FROM Locataires WHERE ID_LOCATAIRE = :id");
    query.bindValue(":id", idRecherche);

    if (!query.exec() || !query.next()) {
        QMessageBox::critical(this, "Erreur", "Impossible de récupérer les informations du locataire.");
        return;
    }

    QString nomComplet = query.value(0).toString();
    QString telephone = query.value(1).toString();
    QString email = query.value(2).toString();
    QString debutContrat = query.value(3).toString();
    QString finContrat = query.value(4).toString();

    QString fileName = QFileDialog::getSaveFileName(this, tr("Enregistrer le contrat"), "", tr("PDF Files (*.pdf)"));
    if (fileName.isEmpty()) return;

    QPdfWriter writer(fileName);
    writer.setPageSize(QPageSize(QPageSize::A4));
    QPainter painter(&writer);



        // Configuration des styles avec des espacements ajustés
        QFont titleFont("Arial", 16, QFont::Bold);
        QFont normalFont("Arial", 11);
        QFont boldFont("Arial", 11, QFont::Bold);

        // Ajuster les espacements
        int y = 800;  // Commencer plus haut
        int lineHeight = 200;  // Réduire l'espacement entre les lignes
        int paragraphSpace = 400;  // Espace entre les paragraphes

        // Titre
        painter.setFont(titleFont);
        painter.drawText(QRect(0, y, writer.width(), 50), Qt::AlignHCenter, "Contrat de location");
        y += lineHeight * 2;

        // En-tête avec mise en page améliorée
        painter.setFont(normalFont);
        painter.drawText(500, y, "Entre les soussignés :");
        y += lineHeight;

        QString entete = nomComplet ;
        painter.drawText(500, y, entete);
        y += lineHeight;
        painter.drawText(500, y, "D'une part");
        y += lineHeight;

        painter.drawText(500, y, "Et");
        y += lineHeight;
        painter.drawText(500, y, "LUXBRAND CENTER");
        y += lineHeight;
        painter.drawText(500, y, "D'autre part");
        y += paragraphSpace;

        // Articles avec espacement amélioré
        // Article 1
        painter.setFont(boldFont);
        painter.drawText(500, y, "Article 1 :");
        y += lineHeight;
        painter.setFont(normalFont);
        painter.drawText(500, y, "LUXBRAND CENTER a loué à " + nomComplet + " qui accepte son local commercial");
        y += paragraphSpace;

        // Article 2
        painter.setFont(boldFont);
        painter.drawText(500, y, "Article 2 :");
        y += lineHeight;
        painter.setFont(normalFont);
        QString article2 = "La présente location est consentie et acceptée pour la durée de " +
                           calculerDuree(debutContrat, finContrat) +
                           " commençant le " + debutContrat + " et finissant le " + finContrat +
                           ", faute de congé donné par lettre recommandée trois mois avant son expiration, " +
                           "le présent contrat sera prolongé pour une nouvelle période d'un an aux mêmes clauses " +
                           "et conditions, et ainsi de suite jusqu'à dénonciation par lettre recommandée. Les loyers " +
                           "continuent à courir tant qu'il n'a pas été mis fin à la présente location par la remise " +
                           "des clés et une vérification contradictoire de l'état des lieux.";
        QRectF article2Rect(500, y, writer.width() - 1000, 800);
        painter.drawText(article2Rect, Qt::TextWordWrap, article2);
        y += paragraphSpace * 2.5;

        // Article 3
        painter.setFont(boldFont);
        painter.drawText(500, y, "Article 3 :");
        y += lineHeight;
        painter.setFont(normalFont);
        painter.drawText(500, y, "Le loyer est fixé d'un commun accord entre les parties à mille deux cent dinar (1200 d) par mois");
        y += lineHeight * 1.5;  // Plus d'espace entre les lignes
        painter.drawText(500, y, "et d'avance au domicile du bailleur, toutes taxes à la charge du locataire.");
        y += paragraphSpace * 2;  // Plus d'espace entre les articles

        // Article 4
        painter.setFont(boldFont);
        painter.drawText(500, y, "Article 4 :");
        y += lineHeight;
        painter.setFont(normalFont);
        painter.drawText(500, y, "Le présent local ne pourra être utilisé que d'habitation.");
        y += paragraphSpace * 1.5;  // Plus d'espace après l'article

        // Article 5
        painter.setFont(boldFont);
        painter.drawText(500, y, "Article 5 :");
        y += lineHeight;
        painter.setFont(normalFont);
        QString article5 = "Le locataire reconnaît avoir visité et agréé le local objet de ce contrat, "
                           "il reconnaît avoir reçu les lieux dans un état neuf, et en parfait et complet état d'utilisation. "
                           "Les frais d'enregistrement du présent contrat sont à la charge du locataire qui s'y oblige.";
        QRectF article5Rect(500, y, writer.width() - 1000, 800);  // Augmenté la hauteur du rectangle
        painter.drawText(article5Rect, Qt::TextWordWrap, article5);
        y += paragraphSpace * 1.5;  // Plus d'espace après l'article long
        y += lineHeight;

        // Article 6
        painter.setFont(boldFont);
        painter.drawText(500, y, "Article 6 :");
        y += lineHeight;
        painter.setFont(normalFont);
        painter.drawText(500, y, "Les frais de consommation d'électricité et d'eau sont à la charge du locataire");
        y += lineHeight * 1.5;  // Plus d'espace entre les lignes
        painter.drawText(500, y, "payable à la STEG et SONEDE suivant factures.");
        y += paragraphSpace * 1.5;  // Plus d'espace entre les articles

        // Article 7
        painter.setFont(boldFont);
        painter.drawText(500, y, "Article 7 :");
        y += lineHeight;
        painter.setFont(normalFont);
        painter.drawText(500, y, "Les deux parties sont convenues à ce que le locataire paie les taxes locatives.");
        y += paragraphSpace * 1.5;  // Plus d'espace entre les articles

        // Article 8
        painter.setFont(boldFont);
        painter.drawText(500, y, "Article 8 :");
        y += lineHeight;
        painter.setFont(normalFont);
        painter.drawText(500, y, "Les frais d'enregistrement du présent contrat sont à la charge du locataire qui s'y oblige.");
        y += paragraphSpace * 2;  // Encore plus d'espace avant la section des signatures

        // Date et signatures
        painter.drawText(500, y, "Fait à Tunis le : " + debutContrat);
        y += paragraphSpace;

        // Signatures avec meilleur alignement
        painter.drawText(500, y, "LE PROPRIETAIRE");
        painter.drawText(writer.width() - 2000, y, "LE LOCATAIRE");
        y += lineHeight;
        painter.drawText(writer.width() - 2000, y, nomComplet);  // Nom du locataire sous sa signature

        painter.end();
        QMessageBox::information(this, "Succès", "Le contrat a été généré avec succès !");
    }

// Fonction auxiliaire pour calculer la durée entre deux dates
QString MainWindow::calculerDuree(const QString& debut, const QString& fin) {
    // Conversion des dates au format YYYY-MM-DD
    QDate dateDebut = QDate::fromString(debut, "yyyy-MM-dd");
    QDate dateFin = QDate::fromString(fin, "yyyy-MM-dd");

    if (!dateDebut.isValid() || !dateFin.isValid()) {
        return "durée indéterminée";
    }

    // Calculer la différence en jours
    int jours = dateDebut.daysTo(dateFin);
    int mois = jours / 30;  // approximation
    int annees = mois / 12;
    mois = mois % 12;

    QString duree;
    if (annees > 0) {
        duree += QString::number(annees) + " an" + (annees > 1 ? "s" : "");
        if (mois > 0) {
            duree += " et ";
        }
    }
    if (mois > 0) {
        duree += QString::number(mois) + " mois";
    }
    return duree;
}
#include "smtpclient.h"
#include "mimemessage.h"
#include "mimetext.h"
#include "emailaddress.h"

void MainWindow::envoyerEmail(QString destinataire, QString idLocataire) {
    // Configuration du serveur SMTP
    SmtpClient smtp("smtp.gmail.com", 465, SmtpClient::SslConnection);

    // Connexion au serveur SMTP
    smtp.connectToHost();
    if (!smtp.waitForReadyConnected()) {
        qDebug() << "Erreur : Impossible de se connecter au serveur SMTP.";
        return;
    }

    // Authentification
    smtp.login("mejriftouuh@gmail.com", "wdnq ovkj cqtz cers", SmtpClient::AuthLogin);
    if (!smtp.waitForAuthenticated()) {
        qDebug() << "Erreur : Authentification échouée.";
        return;
    }

    // Récupérer les informations du locataire
    QSqlQuery query;
    query.prepare("SELECT NOM, EMAIL, DEBUT_CONTRAT, FIN_CONTRAT FROM Locataires WHERE ID_LOCATAIRE = :id");
    query.bindValue(":id", idLocataire);

    if (!query.exec() || !query.next()) {
        qDebug() << "Erreur : Impossible de récupérer les informations du locataire.";
        return;
    }

    QString nom = query.value(0).toString();
    QString email = query.value(1).toString();
    QString debutContrat = query.value(2).toString();
    QString finContrat = query.value(3).toString();

    // Création du message
    MimeMessage message;
    EmailAddress sender("mejriftouuh@gmail.com", "LUXBRAND CENTER");
    EmailAddress recipient(destinataire, nom);

    message.setSender(sender);
    message.addRecipient(recipient);
    message.setSubject("Contrat de Location - LUXBRAND CENTER");

    // Corps du message
    MimeText text;
    QString emailContent =
        "Cher(e) " + nom + ",\n\n"
                           "Nous vous remercions d'avoir choisi LUXBRAND CENTER pour votre location commerciale.\n\n"
                           "Vous trouverez ci-joint votre contrat de location pour la période du " + debutContrat + " au " + finContrat + ".\n\n"
                                               "Informations importantes :\n"
                                               "- ID Locataire : " + idLocataire + "\n"
                        "- Début du contrat : " + debutContrat + "\n"
                         "- Fin du contrat : " + finContrat + "\n"
                       "- Montant du loyer mensuel : 1200 dinars\n\n"
                       "Pour toute question concernant votre contrat, n'hésitez pas à nous contacter.\n\n"
                       "Cordialement,\n"
                       "L'équipe LUXBRAND CENTER";

    text.setText(emailContent);
    message.addPart(&text);

    // Envoi du mail
    smtp.sendMail(message);
    if (!smtp.waitForMailSent()) {
        qDebug() << "Erreur : L'e-mail n'a pas pu être envoyé.";
        return;
    }

    smtp.quit();
    qDebug() << "E-mail envoyé avec succès à " << destinataire;
}

void MainWindow::on_pushButton_mailing_clicked()
{
    QString idLocataire = ui->lineEdit_id4->text();  // Récupère l'ID du locataire
    QString destinataire;

    // Chercher l'email du locataire dans la base de données
    QSqlQuery query;
    query.prepare("SELECT EMAIL FROM Locataires WHERE ID_LOCATAIRE = :id");
    query.bindValue(":id", idLocataire);

    if (query.exec() && query.next()) {
        destinataire = query.value(0).toString();  // Récupère l'email du locataire
    } else {
        qDebug() << "Erreur : Locataire introuvable.";
        QMessageBox::warning(this, "Erreur", "Aucun locataire trouvé avec cet ID.");
        return;
    }

    // Appeler la fonction pour envoyer l'email
    envoyerEmail(destinataire, idLocataire);
}
void MainWindow::on_pushButton_afficherStats_clicked() {

    // Récupération des statistiques via Locataire
    QSqlQueryModel* model = Locataire().statistiquesContratsParMois();

    if (model->rowCount() == 0) {
        qDebug() << "Aucune donnée récupérée pour les statistiques.";
        return;
    }

    // Création des séries pour les données
    QBarSet* setContrats = new QBarSet("Contrats commencés");
    QStringList categories;
    int maxValue = 0;

    for (int i = 0; i < model->rowCount(); ++i) {
        QString mois = model->record(i).value("mois").toString();
        int total = model->record(i).value("total").toInt();

        *setContrats << total;
        categories << mois;

        if (total > maxValue) {
            maxValue = total;
        }
    }

    // Vérification des données
    if (categories.isEmpty()) {
        qDebug() << "Aucune donnée récupérée. Impossible de générer la charte.";
        return;
    }

    // Création des séries de barres
    QBarSeries* series = new QBarSeries();
    series->append(setContrats);

    // Création du graphique
    QChart* chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Nombre de contrats commencés par mois");
    chart->setAnimationOptions(QChart::SeriesAnimations);
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    // Définition des axes
    QBarCategoryAxis* axisX = new QBarCategoryAxis();
    axisX->append(categories);
    axisX->setTitleText("Mois");
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis* axisY = new QValueAxis();
    axisY->setTitleText("Nombre de contrats");
    axisY->setRange(0, maxValue + 1); // Étendre l'axe Y pour un meilleur affichage
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    // Configuration de la vue du graphique
    QChartView* chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // Affichage dans une nouvelle fenêtre
    QMainWindow* statsWindow = new QMainWindow(this);
    statsWindow->setCentralWidget(chartView);
    statsWindow->resize(800, 600);
    statsWindow->show();

    qDebug() << "Graphique généré et affiché avec succès.";
    // Vérifier les données récupérées par le modèle
    qDebug() << "Nombre de lignes récupérées :" << model->rowCount();
    for (int i = 0; i < model->rowCount(); ++i) {
        qDebug() << "Mois :" << model->record(i).value("mois").toString()
        << "Total contrats :" << model->record(i).value("total").toInt();
    }

}
void MainWindow::on_sendChatMessage_clicked()
{
    QString userMessage = ui->chatInput->text().trimmed();
    if (!userMessage.isEmpty()) {
        ui->chatDisplay->append("👤 Vous: " + userMessage);
        chatbot->processMessage(userMessage);
        ui->chatInput->clear();
    }
}
void MainWindow::handleChatResponse(const QString &response)
{
    ui->chatDisplay->append("Assistant: " + response);
}
void MainWindow::handleChatError(const QString &error)
{
    ui->chatDisplay->append("Erreur du chatbot : " + error);
}
void MainWindow::on_readyRead() {
    // Utilise l'objet arduino pour lire les données
    static QString bufferSerie; // ou mets QString bufferSerie; dans le header (section private:)
    QByteArray data = arduino->readAll();
    QString dataStr = QString::fromUtf8(data);
    qDebug() << "📥 Données reçues : " << dataStr;

    bufferSerie.append(dataStr);
    qDebug() << "=== Buffer après append ===" << bufferSerie;

    // Normalisation : remplace \r\n, \r, \n par un unique séparateur
    bufferSerie.replace("\r\n", "\n");
    bufferSerie.replace("\r", "\n");
    qDebug() << "=== Buffer après normalisation ===" << bufferSerie;

    while (bufferSerie.contains('\n')) {
        int endIndex = bufferSerie.indexOf('\n');
        QString line = bufferSerie.left(endIndex);
        bufferSerie.remove(0, endIndex + 1);

        line = line.trimmed();
        qDebug() << "🔎 Chaîne extraite et nettoyée:" << line;

        if (!line.isEmpty()) {
            detecterIncendie(line); // Appelle ta fonction de traitement
        } else {
            qDebug() << "⚠️ Ligne vide reçue, ignorée.";
        }
    }
}



void MainWindow::detecterIncendie(QString idLocal) {
    qDebug() << "🔥 Appel de detecterIncendie() avec:" << idLocal;

    idLocal = idLocal.trimmed().remove(QChar(0));
    int idLocalInt = idLocal.toInt();
    qDebug() << "🧼 ID nettoyé et converti en entier:" << idLocalInt;

    QSqlQuery query;
    query.prepare("SELECT L.ID_LOCATAIRE, L.NOM, L.EMAIL "
                  "FROM LOCAUX LC "
                  "JOIN LOCATAIRES L ON LC.ID_LOCATAIRE = L.ID_LOCATAIRE "
                  "WHERE LC.ID_LOCAL = :idLocal");
    query.bindValue(":idLocal", idLocalInt);

    if (!query.exec()) {
        qDebug() << "🚨 Erreur SQL lors de l'exécution de la requête:" << query.lastError().text();
        qDebug() << "❓ Requête préparée:" << query.lastQuery();
        return;
    }

    if (!query.next()) {
        qDebug() << "❌ Aucun locataire trouvé pour le local" << idLocalInt;
        return;
    }

    QString idLocataire = query.value(0).toString();
    QString nom         = query.value(1).toString();
    QString email       = query.value(2).toString();

    qDebug() << "✅ Données extraites - ID Locataire:" << idLocataire
             << ", Nom:" << nom << ", Email:" << email;

    if (email.isEmpty()) {
        qDebug() << "⚠️ Aucun e-mail trouvé pour ce locataire. Fin du traitement.";
        return;
    }

    qDebug() << "🚀 Appel de la fonction incendieEmail() avec l'email:" << email;
    incendieEmail(email, idLocataire);
}



void MainWindow::incendieEmail(QString destinataire, QString idLocataire) {
    qDebug() << "=== DEBUT incendieEmail === destinataire:" << destinataire << "idLocataire:" << idLocataire;

    // Connexion au serveur SMTP Gmail
    SmtpClient smtp("smtp.gmail.com", 465, SmtpClient::SslConnection);

    smtp.connectToHost();
    if (!smtp.waitForReadyConnected()) {
        qDebug() << "🚨 Erreur : Impossible de se connecter au serveur SMTP.";
        return;
    }
    qDebug() << "✅ Connexion au serveur SMTP réussie.";

    // Authentification avec un mot de passe d'application
    smtp.login("mejriftouuh@gmail.com", "wdnq ovkj cqtz cers");
    if (!smtp.waitForAuthenticated()) {
        qDebug() << "🚨 Erreur : Authentification échouée.";
        return;
    }
    qDebug() << "✅ Authentification réussie.";

    // Création du message
    MimeMessage message;
    EmailAddress sender("mejriftouuh@gmail.com", "LUXBRAND CENTER");
    EmailAddress recipient(destinataire, "Locataire");

    message.setSender(sender);
    message.addRecipient(recipient);
    message.setSubject("🚨 Alerte Incendie - LUXBRAND CENTER");

    // Corps de l'email
    MimeText text;
    QString emailContent =
        "Cher(e) Locataire,\n\n"
        "Un incendie a été détecté dans votre local commercial.\n\n"
        "Merci de vérifier immédiatement et de contacter les secours si nécessaire.\n\n"
        "ID Locataire : " + idLocataire + "\n\n"
                        "Cordialement,\nL'équipe de sécurité\nLUXBRAND CENTER";

    text.setText(emailContent);
    message.addPart(&text);

    // Envoi du message
    smtp.sendMail(message);
    if (!smtp.waitForMailSent()) {
        qDebug() << "🚨 Erreur : L'e-mail n'a pas pu être envoyé.";
        return;
    }
    qDebug() << "✅ E-mail envoyé avec succès à " << destinataire;

    smtp.quit();
}

/*void MainWindow::On_pushButton_111_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_3); // Aller directement à la page_3
}*/
void MainWindow::on_pushButton_13_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_4); // Affiche la page 4
}



//fatma



void MainWindow::on_pushButton_Ajouter_clicked()
{
    // Récupérer les valeurs saisies
    bool ok;
    double surface = ui->lineEdit_surface->text().toDouble(&ok);
    if (!ok || surface <= 0) {
        QMessageBox::warning(this, "Erreur", "Veuillez saisir une surface valide (nombre positif).");
        return;
    }

    QString type = ui->comboBox_type->currentText();
    if (type.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner un type.");
        return;
    }

    QString disponibilite = ui->comboBox_dispo->currentText();
    if (disponibilite.isEmpty() || (disponibilite != "dispo" && disponibilite != "non")) {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner une disponibilité valide ('dispo' ou 'non').");
        return;
    }

    double prix = ui->lineEdit_prix->text().toDouble(&ok);
    if (!ok || prix <= 0) {
        QMessageBox::warning(this, "Erreur", "Veuillez saisir un prix valide (nombre positif).");
        return;
    }

    QString etage = ui->comboBox_etage->currentText();
    if (etage.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner un étage.");
        return;
    }

    // Créer un objet Local avec les valeurs saisies
    Local local(surface, type, disponibilite, prix, etage);

    // Ajouter le local à la base de données
    if (local.ajouter()) {
        QMessageBox::information(this, "Succès", "Local commercial ajouté avec succès !");
        mettreAJourAffichage();
        on_pushButton_Annuler_clicked(); // Effacer les champs de saisie
    } else {
        QMessageBox::critical(this, "Erreur", "Erreur lors de l'ajout du local commercial.");
    }
}
// Slot pour annuler (effacer les champs)
void MainWindow::on_pushButton_Annuler_clicked()
{
    // Effacer tous les champs de saisie

    ui->lineEdit_surface->clear();
    ui->comboBox_type->setCurrentIndex(0); // Réinitialiser le comboBox
    ui->comboBox_dispo->setCurrentIndex(0); // Réinitialiser le comboBox
    ui->lineEdit_prix->clear();
    ui->comboBox_etage->setCurrentIndex(0); // Réinitialiser le comboBox
    ui->lineEdit_id_3->clear();
}
void MainWindow::on_pushButton_Supprimer_clicked()
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
        on_pushButton_Annuler_clicked();
        ui->lineEdit_id_3->clear(); // Effacer le champ ID après suppression
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la suppression du local commercial.");
    }
}
void MainWindow::on_pushButton_Modifier_clicked()
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
        on_pushButton_Annuler_clicked(); // Effacer les champs de saisie
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la modification du local commercial.");
    }
}

void MainWindow::mettreAJourAffichage()
{
    Local local;
    ui->tableView_4->setModel(local.afficher());
}
void MainWindow::on_pushButton_18_clicked()
{
    QSqlQueryModel* model = local.trier();
    if (model != nullptr) {
        ui->tableView_4->setModel(model);
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
            ui->tableView_4->setModel(model);
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
    pdfWriter.setTitle("locaux List");

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
    if (!query.prepare("SELECT ID_LOCAL, SURFACE, TYPE, DISPONIBILITE, PRIX, ETAGE FROM FETHI.local_commerciale")) {
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
    if (query.exec("SELECT DISPONIBILITE, COUNT(*) FROM FETHI.local_commerciale GROUP BY DISPONIBILITE")) {
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
        QSqlQuery query("SELECT ID_LOCAL FROM FETHI.local_commerciale WHERE LOWER(DISPONIBILITE) = 'dispo'");
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
        QSqlQuery query("SELECT ID_LOCAL, PRIX FROM FETHI.local_commerciale WHERE LOWER(DISPONIBILITE) = 'dispo'");
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
        QSqlQuery query("SELECT ID_LOCAL, ETAGE FROM FETHI.local_commerciale WHERE LOWER(DISPONIBILITE) = 'dispo'");
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
        QSqlQuery query("SELECT ID_LOCAL, TYPE FROM FETHI.local_commerciale WHERE LOWER(DISPONIBILITE) = 'dispo'");
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
    ui->stackedWidget->setCurrentWidget(ui->page_3); // Aller directement à la page_3
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

void MainWindow::pushButton_26_clicked()
{
    // Coordonnées exactes de Tunisia Mall
    double lat = 36.8117;
    double lng = 10.1631;

    emit setCenter(lat, lng);
    emit addMarker(lat, lng);

    // Si vous avez ajouté setCenterWithZoom :
    emit setCenterWithZoom(lat, lng, 16);
}
// [Le reste du fichier reste inchangé jusqu'à on_connecter_clicked]

/*void MainWindow::on_connecter_clicked()
{
    QString rfid = ui->textEdit_uid->text().trimmed(); // Récupérer l'UID saisi

    if (rfid.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un UID.");
        return;
    }

    // Traiter l'UID saisi
    handleSerialData(rfid);
}

void MainWindow::handleSerialData(QString rfid)
{
    qDebug() << "RFID à traiter :" << rfid;

    if (rfid.isEmpty()) {
        qDebug() << "Données vides ignorées.";
        if (A.getserial()->isOpen()) {
            A.write_to_arduino("0|Erreur|Erreur\n");
            qDebug() << "Envoi à l'Arduino : 0|Erreur|Erreur";
        }
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT NOM, PRENOM FROM FETHI.EMPLOYE WHERE RFID = :rfid");
    query.bindValue(":rfid", rfid);

    if (!query.exec()) {
        qDebug() << "Erreur SQL :" << query.lastError().text();
        if (A.getserial()->isOpen()) {
            A.write_to_arduino("0|Erreur|SQL\n");
            qDebug() << "Envoi à l'Arduino : 0|Erreur|SQL";
        }
        return;
    }

    if (query.next()) {
        QString nom = query.value("NOM").toString();
        QString prenom = query.value("PRENOM").toString();

        if (rfid == "A3478F28" || rfid == "E941054B") {
            if (A.getserial()->isOpen()) {
                A.write_to_arduino(("1|" + nom + "|" + prenom + "\n").toUtf8());
                qDebug() << "Envoi à l'Arduino : 1|" << nom << "|" << prenom;
            } else {
                qDebug() << "Erreur : Port série non ouvert, impossible d'envoyer à l'Arduino.";
            }
        } else if (rfid == "718AA97B") {
            if (A.getserial()->isOpen()) {
                A.write_to_arduino(("0|" + nom + "|" + prenom + "\n").toUtf8());
                qDebug() << "Envoi à l'Arduino : 0|" << nom << "|" << prenom;
            } else {
                qDebug() << "Erreur : Port série non ouvert, impossible d'envoyer à l'Arduino.";
            }
        } else {
            if (A.getserial()->isOpen()) {
                A.write_to_arduino(("0|" + nom + "|" + prenom + "\n").toUtf8());
                qDebug() << "Envoi à l'Arduino : 0|" << nom << "|" << prenom;
            } else {
                qDebug() << "Erreur : Port série non ouvert, impossible d'envoyer à l'Arduino.";
            }
        }

    } else {
        if (A.getserial()->isOpen()) {
            A.write_to_arduino("0|Inconnu|Inconnu\n");
            qDebug() << "Envoi à l'Arduino : 0|Inconnu|Inconnu";
        } else {
            qDebug() << "Erreur : Port série non ouvert, impossible d'envoyer à l'Arduino.";
        }
    }
}*/



