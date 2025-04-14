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

    if (!QSqlDatabase::database().isOpen()) {
        QMessageBox::critical(this, "Erreur de connexion", "Impossible de se connecter à la base de données.");
        return;
    }

    qDebug() << "Connexion du bouton ajouter au slot"; // Message de débogage

    connect(ui->pushButton_ok, &QPushButton::clicked, this, &MainWindow::on_pushButton_ok_clicked);
    connect(ui->pushButton_modifier, &QPushButton::clicked, this, &MainWindow::on_pushButton_modifier_clicked);
    connect(ui->pushButton_6, &QPushButton::clicked, this, &MainWindow::on_pushButton_6_clicked);
    connect(ui->pushButton_mailing, &QPushButton::clicked, this, &MainWindow::on_pushButton_mailing_clicked);
    connect(ui->pushButton_afficherStats, &QPushButton::clicked, this, &MainWindow::on_pushButton_afficherStats_clicked);

    // === CONFIGURATION DU CHATBOT ===
    chatbot = new LocalChat(this);

    // Quand le bot envoie une réponse
    connect(chatbot, &LocalChat::responseReceived, this, [=](const QString &response) {
        ui->chatDisplay->append("🤖 Assistant: " + response);
    });

    // En cas d'erreur dans le bot
    connect(chatbot, &LocalChat::error, this, [=](const QString &errorMessage) {
        ui->chatDisplay->append("⚠️ Erreur: " + errorMessage);
    });

    // Connexion du bouton d'envoi à la fonction
    connect(ui->sendChatMessage, &QPushButton::clicked, this, &MainWindow::on_sendChatMessage_clicked);

    // Envoi du message aussi via la touche Entrée
    connect(ui->chatInput, &QLineEdit::returnPressed, ui->sendChatMessage, &QPushButton::click);

    // Interface du chat
    ui->chatDisplay->setReadOnly(true);
    chatbot->initialize(); // message d’accueil automatique

    afficherLocataires(); // Affichage des locataires
}

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
