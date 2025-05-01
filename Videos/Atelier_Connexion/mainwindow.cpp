#include "mainwindow.h"
#include "arduino.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QSqlQueryModel>
#include <QPixmap>  // Nécessaire pour QPixmap
#include <QSqlDatabase>
#include <QSqlError>
#include <QStandardItemModel>
#include "statistique.h"
#include <QtCharts/QChartView>
#include <QPdfWriter>
#include <QPainter>
#include <QFileDialog>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrlQuery>
#include <QRandomGenerator>
#include "arduino.h"







MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Définir les icônes des boutons
    ui->pushButton_8->setIcon(QIcon(":/icons/icons/align-left.svg"));
    ui->pushButton_8->setIconSize(QSize(32, 32));
    ui->searchButton->setIcon(QIcon(":/icons/icons/search.svg"));
    ui->searchButton->setIconSize(QSize(32, 32));
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
    if (!createConnection()) {
        QMessageBox::critical(this, "Erreur", "La connexion à la base de données a échoué.");
        return;
    }

    // Connect buttons to slots
    connect(ui->button_ajouter, &QPushButton::clicked, this, &MainWindow::on_pushButton_Ajouter_clicked);
    connect(ui->button_modifier, &QPushButton::clicked, this, &MainWindow::on_pushButton_Modifier_clicked);
    connect(ui->button_supprimer, &QPushButton::clicked, this, &MainWindow::on_pushButton_Supprimer_clicked);
    connect(ui->pushButton_annuler, &QPushButton::clicked, this, &MainWindow::on_pushButton_Afficher_clicked);
    connect(ui->comboBox_tri_2, SIGNAL(currentTextChanged(const QString &)), this, SLOT(afficherStatistiques()));
    connect(ui->button_afficherstatistique, &QPushButton::clicked, this, &MainWindow::on_pushButton_afficherstatistiques_clicked);
    connect(ui->pushButton_telecharger, &QPushButton::clicked, this, &MainWindow::exporterStatistiquesEnPDF);
    connect(ui->searchButton, &QPushButton::clicked, this, &MainWindow::rechercherEvenements);
    connect(ui->pushButton_trier_id, &QPushButton::clicked, this, &MainWindow::trierEvenementsParID);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &MainWindow::revenirAffichageNormal);
    connect(ui->pushButton_3, &QPushButton::clicked, this, &MainWindow::close);
    connect(ui->calendarWidget_events, &QCalendarWidget::clicked, this, &MainWindow::onDateClicked);
    connect(ui->pushButton_afficher2, &QPushButton::clicked, this, &MainWindow::on_pushButton_Afficher_2_clicked);
    connect(ui->pushButton_7, &QPushButton::clicked, this, &::MainWindow::on_pushButton_Ajouter_clicked);


}
MainWindow::~MainWindow()
{
    delete ui;
}


bool MainWindow::createConnection() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("SourceProjet_2A15"); // Nom de la source de données ODBC
    db.setUserName("system"); // Nom d'utilisateur
    db.setPassword("amin123"); // Mot de passe

    if (!db.open()) {
        qDebug() << "Échec de la connexion à la base de données : " << db.lastError().text();
        QMessageBox::critical(nullptr, "Erreur", "Échec de la connexion à la base de données : " + db.lastError().text());
        return false;
    }

    qDebug() << "Connexion à la base de données réussie !";
    return true;
}


void MainWindow::on_pushButton_Ajouter_clicked()
{
    e = Events(
        0, // ID généré automatiquement
        ui->lineEdit_nom->text(),
        ui->lineEdit_description->text(),
        ui->lineEdit_type->currentText(),
        ui->lineEdit_telephone->text(),
        ui->dateEdit_date_ev->date(),
        ui->timeEdit_heure->time(),
        ui->lineEdit_lieu->text()
        );

    if (e.ajouter()) {
        QMessageBox::information(this, "Succès", "Événement ajouté avec succès !");
        on_pushButton_Afficher_clicked();  // Rafraîchir l'affichage

        QString numero = ui->lineEdit_telephone->text();
        QString message = "Bonjour, l' événement \"" + ui->lineEdit_nom->text() + "\" a été ajouté avec succès. Merci !";
        envoyerSMS(numero, message);
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de l'ajout de l'événement.");
    }
}


void MainWindow::on_pushButton_Supprimer_clicked()
{
    int id = ui->lineEdit_id->text().toInt();
    if (e.supprimer(id)) {
        QMessageBox::information(this, "Succès", "Événement supprimé avec succès !");
        on_pushButton_Afficher_clicked();  // Rafraîchir l'affichage
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la suppression.");
    }
}

void MainWindow::on_pushButton_Modifier_clicked()
{
    int id = ui->lineEdit_id->text().toInt();
    if (e.modifier(
            id,
            ui->lineEdit_nom_2->text(),
            ui->lineEdit_description_2->text(),
            ui->lineEdit_type_2->currentText(),
            ui->lineEdit_telephone_2->text(),
            ui->dateEdit_date_ev_2->date(),
            ui->timeEdit_heure_2->time(),
            ui->lineEdit_lieu_2->text()
            )) {
        QMessageBox::information(this, "Succès", "Événement modifié !");
        on_pushButton_Afficher_clicked();  // Rafraîchir l'affichage
    } else {
        QMessageBox::critical(this, "Erreur", "Modification échouée !");
    }
}


void MainWindow::on_pushButton_Afficher_clicked()
{
    QSqlQueryModel* model = e.afficher();
    if (model) {
        ui->tableView_2->setModel(model);  // Assurez-vous que 'tableView_2' est un QTableView dans le fichier .ui
    } else {
        QMessageBox::critical(this, "Erreur", "Impossible d'afficher les événements.");
    }
}
void MainWindow::afficherStatistiques()
{
    Statistique stat;

    QChart *chart = stat.creerGraphiqueEvenementsParType();

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    if (ui->tableWidget_statistique->layout() == nullptr) {
        ui->tableWidget_statistique->setLayout(new QVBoxLayout());
    }

    QLayoutItem *item;
    while ((item = ui->tableWidget_statistique->layout()->takeAt(0)) != nullptr) {
        delete item->widget();
        delete item;
    }

    ui->tableWidget_statistique->layout()->addWidget(chartView);
}

    void MainWindow::on_pushButton_afficherstatistiques_clicked()
    {
        afficherStatistiques();
    }

    void MainWindow::exporterStatistiquesEnPDF()
    {
        QString filePath = QFileDialog::getSaveFileName(this, "Exporter en PDF", "", "*.pdf");
        if (filePath.isEmpty())
            return;

        if (QFileInfo(filePath).suffix().isEmpty())
            filePath.append(".pdf");

        QPdfWriter pdfWriter(filePath);
        pdfWriter.setPageSize(QPageSize(QPageSize::A4));

        QPainter painter(&pdfWriter);

        if (ui->tableWidget_statistique) {
            QPixmap pixmap = ui->tableWidget_statistique->grab();  // Capture du widget
            QRect rect = painter.viewport();
            QSize size = pixmap.size();
            size.scale(rect.size(), Qt::KeepAspectRatio);
            painter.setViewport(rect.x(), rect.y(), size.width(), size.height());
            painter.setWindow(pixmap.rect());
            painter.drawPixmap(0, 0, pixmap);
        }

        painter.end();

        QMessageBox::information(this, "Succès", "Statistiques exportées en PDF avec succès !");
    }
    void MainWindow::rechercherEvenements()
    {
        QString recherche = ui->lineEdit->text();

        if (recherche.isEmpty()) {
            QMessageBox::warning(this, "Attention", "Veuillez saisir un nom pour rechercher.");
            return;
        }

        QSqlQueryModel *model = new QSqlQueryModel();
        QSqlQuery query;

        query.prepare("SELECT * FROM EVT WHERE NOM LIKE :recherche");
        query.bindValue(":recherche", "%" + recherche + "%");

        if (!query.exec()) {
            QMessageBox::critical(this, "Erreur", "Erreur lors de l'exécution de la recherche !");
            return;
        }

        model->setQuery(std::move(query));  // Correction moderne pour Qt 6.7

        ui->tableView_2->setModel(model);

        if (model->rowCount() == 0) {
            QMessageBox::information(this, "Résultat", "Aucun événement trouvé avec ce nom.");
        }
    }
    void MainWindow::trierEvenementsParID()
    {
        QSqlQueryModel *model = new QSqlQueryModel();
        QSqlQuery query;

        query.prepare("SELECT * FROM EVT ORDER BY ID_EVENEMENT ASC"); // Trie du plus petit ID au plus grand

        if (!query.exec()) {
            QMessageBox::critical(this, "Erreur", "Erreur lors de l'exécution du tri !");
            return;
        }

        model->setQuery(std::move(query)); // Important : éviter la copie (Qt 6.7+)

        ui->tableView_2->setModel(model);
    }
    void MainWindow::revenirAffichageNormal()
    {
        on_pushButton_Afficher_clicked(); // Recharge tout simplement tous les événements
    }
    void MainWindow::confirmerFermeture()
    {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Quitter", "Voulez-vous vraiment quitter ?",
                                      QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::Yes) {
            qApp->quit();  // Ferme l'application si l'utilisateur confirme.
        }
    }

    void MainWindow::envoyerSMS(const QString &numero, const QString &message)
    {
        const QString sid = "ACc522b3ef6dcac4ee87356f40c5bab126";  // Ton Account SID Twilio
        const QString token = "78626b4eb7cffd7422f06addd0e62251";            // Ton Auth Token Twilio correct
        const QString messagingServiceSid = "MG0af624cf0f61009cfc23195ac5eaf495"; // Messaging Service SID Twilio

        QUrl url("https://api.twilio.com/2010-04-01/Accounts/ACc522b3ef6dcac4ee87356f40c5bab126/Messages.json");

        QUrlQuery postData;
        postData.addQueryItem("To", numero);
        postData.addQueryItem("MessagingServiceSid", messagingServiceSid);
        postData.addQueryItem("Body", message);

        QNetworkRequest request(url);
        QString concatenated = sid + ":" + token;
        QString authHeader = "Basic " + QByteArray(concatenated.toUtf8()).toBase64();
        request.setRawHeader("Authorization", authHeader.toUtf8());
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

        QNetworkAccessManager *manager = new QNetworkAccessManager(this);
        QNetworkReply *reply = manager->post(request, postData.query(QUrl::FullyEncoded).toUtf8());

        connect(reply, &QNetworkReply::finished, this, [=]() {
            if (reply->error() == QNetworkReply::NoError) {
                QMessageBox::information(this, "Succès", "Message envoyé avec succès !");
            } else {
                QMessageBox::critical(this, "Erreur", "Erreur d'envoi du message : " + reply->errorString());
            }
            reply->deleteLater();
        });
    }



    void MainWindow::afficherEvenementsDansCalendrier()
    {
        // Effacer les anciens formats
        QTextCharFormat defaultFormat;
        ui->calendarWidget_events->setDateTextFormat(QDate(), defaultFormat);  // Réinitialiser le calendrier

        // Charger les dates des événements à partir de la base de données
        QSqlQuery query;
        query.prepare("SELECT DATE_EV FROM EVT");  // Assure-toi que la colonne date s'appelle bien DATE_EV
        if (query.exec()) {
            QTextCharFormat highlightFormat;
            highlightFormat.setBackground(Qt::yellow);  // Met en surbrillance les dates en jaune
            highlightFormat.setForeground(Qt::black);   // Texte noir pour les dates

            // Parcours les résultats de la requête
            while (query.next()) {
                QDate dateEvenement = query.value(0).toDate();  // Récupérer la date de l'événement
                ui->calendarWidget_events->setDateTextFormat(dateEvenement, highlightFormat);  // Marquer la date
            }
        } else {
            QMessageBox::critical(this, "Erreur", "Erreur lors du chargement des événements pour le calendrier.");
        }
    }
    void MainWindow::on_pushButton_Afficher_2_clicked()
    {
        // Affichage des événements dans la table ou liste
        ui->tableView_3->setModel(e.afficher());  // Assure-toi que `e.afficher()` renvoie un modèle valide

        // Affichage des événements dans le calendrier
        afficherEvenementsDansCalendrier();
    }
    void MainWindow::onDateClicked(const QDate &date)
    {
        // Exemple de gestion du clic sur une date
        qDebug() << "Date cliquée:" << date.toString();

        // Tu peux aussi afficher des événements spécifiques à cette date dans une autre vue
        // Exemple : récupérer et afficher les événements pour cette date
        QSqlQuery query;
        query.prepare("SELECT * FROM EVT WHERE DATE_EV = :date");
        query.bindValue(":date", date);
        if (query.exec()) {
            while (query.next()) {
                QString evenement = query.value("nom").toString();  // Exemple d'affichage d'événement
                qDebug() << "Événement trouvé: " << evenement;
            }
        } else {
            qDebug() << "Erreur lors de la récupération des événements pour la date:" << query.lastError().text();
        }
    }

    void MainWindow::on_pushButton_7_clicked()
    {
        // Générer un nombre aléatoire entre 0 et 1, puis le convertir dans la plage [25.0, 40.0]
        float temperatureSimulee = 25.0f + (float)(QRandomGenerator::global()->generate() / (float)UINT32_MAX) * (40.0f - 25.0f);

        if (temperatureSimulee > 30.0) {
            QString message = QString("⚠️ Alerte : température élevée détectée ( %1 °C ) dans la salle !").arg(temperatureSimulee);
            QMessageBox::warning(this, "Température critique", message);

            // Utiliser lineEdit_telephone2 pour récupérer le numéro
            QString numero = ui->lineEdit_tel->text();  // Remplacer par ton champ réel contenant le numéro
            if (!numero.isEmpty()) {
                envoyerSMS(numero, message);
            } else {
                QMessageBox::warning(this, "Erreur", "Le numéro de téléphone est vide.");
            }
        } else {
            QMessageBox::information(this, "Température normale", QString("Température : %1 °C").arg(temperatureSimulee));
        }
    }

    void MainWindow::readArduinoData()
    {
        Arduino A;  // Déclaration de l'objet Arduino
        QByteArray data = A.read_from_arduino();
        if (!data.isEmpty()) {
            QString tempStr = QString(data);
            float temperature = tempStr.toFloat();

            // Vérification de la température
            if (temperature > 30.0) {  // Si la température est trop élevée
                envoyerSMS("+216xxxxxxxx", "⚠️ Température critique détectée !");
                QMessageBox::warning(this, "Alerte", "⚠️ Température critique détectée !");
            }
        }
    }




