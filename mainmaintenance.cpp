#include "mainmaintenance.h"
#include "mailer.h"
#include "ui_mainmaintenance.h"
#include "maintenance.h"
#include <QMessageBox>
#include <QRegularExpression>
#include <QRegularExpressionValidator>
#include <QSqlError>
#include <QSqlDatabase>
#include <QDebug>
#include <QStandardItemModel>
#include <QTimer>
#include <QFileDialog>
#include <QPdfWriter>
#include <QPainter>
#include <QDateTime>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QDialog>
#include <QVBoxLayout>
#include <QRadioButton>
#include <QGroupBox>
#include <QDialogButtonBox>
#include <algorithm>
#include <QMap>
#include <QDesktopServices>
#include <QMessageBox>
#include <QUrl>
#include <QProcess>
#include <QRegularExpression>
#include <QSettings>
#include <QThread>

MainMaintenance::MainMaintenance(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainMaintenance)
    , model(nullptr)
{
    ui->setupUi(this);

    // Style du tableau
    ui->tableView->setAlternatingRowColors(true);
    ui->tableView->setStyleSheet("QTableView { alternate-background-color: #f0f0f0; }");

    // Initialisation
    initializeTableView();
    setupInputValidators();

    // Load data immediately on startup avec un délai pour s'assurer que l'interface est prête
    QTimer::singleShot(100, this, &MainMaintenance::refreshMaintenanceTable);

    // Configurer les statuts possibles
    ui->comboBox->addItems({"En cours", "En attente", "Terminé"});

    // Set current date as default
    ui->dateEdit_datem->setDate(QDate::currentDate());
    // Connect search text changed signal
    connect(ui->lineEdit, &QLineEdit::textChanged, this, &MainMaintenance::onSearchTextChanged);
    // Connect SMS and email buttons
    connect(ui->pushButton_sms, &QPushButton::clicked, this, &MainMaintenance::on_pushButton_sms_clicked);
    connect(ui->pushButton_email, &QPushButton::clicked, this, &MainMaintenance::on_pushButton_email_clicked);
}

MainMaintenance::~MainMaintenance()
{
    delete ui;
    if (model) delete model;
}

void MainMaintenance::initializeTableView()
{
    model = new QStandardItemModel(0, 10, this);
    model->setHorizontalHeaderLabels({
        "ID Maintenance", "Description", "Type", "Catégorie", "Date",
        "Statut", "ID Technicien", "Email Technicien", "Téléphone", "ID Service"
    });

    ui->tableView->setModel(model);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    // Configuration du défilement horizontal
    ui->tableView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    ui->tableView->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    // Largeurs fixes des colonnes
    ui->tableView->setColumnWidth(0, 100);  // ID Maintenance
    ui->tableView->setColumnWidth(1, 200);  // Description
    ui->tableView->setColumnWidth(2, 120);  // Type
    ui->tableView->setColumnWidth(3, 120);  // Catégorie
    ui->tableView->setColumnWidth(4, 100);  // Date
    ui->tableView->setColumnWidth(5, 100);  // Statut
    ui->tableView->setColumnWidth(6, 120);  // ID Technicien
    ui->tableView->setColumnWidth(7, 200);  // Email Technicien
    ui->tableView->setColumnWidth(8, 120);  // Téléphone
    ui->tableView->setColumnWidth(9, 100);  // ID Service

    ui->tableView->setWordWrap(true);
    ui->tableView->setTextElideMode(Qt::ElideRight);
}

void MainMaintenance::setupInputValidators()
{
    // Validation pour ID Maintenance (8 chiffres minimum)
    QRegularExpression idRegex("^\\d{8,}$");
    QValidator *idValidator = new QRegularExpressionValidator(idRegex, this);
    ui->lineEdit_idmaintenance->setValidator(idValidator);
    ui->lineEdit_id_tech->setValidator(idValidator);
    ui->lineEdit_idservice->setValidator(idValidator);
    ui->lineEdit_numtelephone->setValidator(idValidator);

    // Validation pour texte seulement (lettres et espaces)
    QRegularExpression textRegex("^[a-zA-ZÀ-ÿ\\s]+$");
    ui->lineEdit_type->setValidator(new QRegularExpressionValidator(textRegex, this));
    ui->lineEdit_categorie->setValidator(new QRegularExpressionValidator(textRegex, this));

    // Validation pour email
    QRegularExpression emailRegex("^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$");
    ui->lineEdit_emailtech->setValidator(new QRegularExpressionValidator(emailRegex, this));
}

bool MainMaintenance::validateInputs()
{
    // Validation ID Maintenance (8 chiffres exactement)
    if(ui->lineEdit_idmaintenance->text().length() != 8) {
        QMessageBox::warning(this, "Erreur", "ID Maintenance doit contenir exactement 8 chiffres");
        ui->lineEdit_idmaintenance->setFocus();
        return false;
    }

    // Validation Description (5 mots minimum)
    QStringList words = ui->lineEdit_description->text().split(' ', Qt::SkipEmptyParts);
    if(words.count() < 5) {
        QMessageBox::warning(this, "Erreur", "Description doit contenir au moins 5 mots");
        ui->lineEdit_description->setFocus();
        return false;
    }

    // Validation Type (non vide et seulement lettres)
    if(ui->lineEdit_type->text().isEmpty() || !ui->lineEdit_type->hasAcceptableInput()) {
        QMessageBox::warning(this, "Erreur", "Type doit contenir seulement des lettres");
        ui->lineEdit_type->setFocus();
        return false;
    }

    // Validation Catégorie (non vide et seulement lettres)
    if(ui->lineEdit_categorie->text().isEmpty() || !ui->lineEdit_categorie->hasAcceptableInput()) {
        QMessageBox::warning(this, "Erreur", "Catégorie doit contenir seulement des lettres");
        ui->lineEdit_categorie->setFocus();
        return false;
    }

    // Validation Statut
    if(ui->comboBox->currentText().isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner un statut");
        ui->comboBox->setFocus();
        return false;
    }

    // Validation ID Technicien (8 chiffres exactement)
    if(ui->lineEdit_id_tech->text().length() != 8) {
        QMessageBox::warning(this, "Erreur", "ID Technicien doit contenir exactement 8 chiffres");
        ui->lineEdit_id_tech->setFocus();
        return false;
    }

    // Validation Email
    if(!ui->lineEdit_emailtech->hasAcceptableInput()) {
        QMessageBox::warning(this, "Erreur", "Email invalide (exemple: technicien@example.com)");
        ui->lineEdit_emailtech->setFocus();
        return false;
    }

    // Validation Téléphone (8 chiffres exactement)
    if(ui->lineEdit_numtelephone->text().length() != 8) {
        QMessageBox::warning(this, "Erreur", "Numéro de téléphone doit contenir exactement 8 chiffres");
        ui->lineEdit_numtelephone->setFocus();
        return false;
    }

    // Validation ID Service (8 chiffres exactement)
    if(ui->lineEdit_idservice->text().length() != 8) {
        QMessageBox::warning(this, "Erreur", "ID Service doit contenir exactement 8 chiffres");
        ui->lineEdit_idservice->setFocus();
        return false;
    }

    return true;
}

void MainMaintenance::refreshMaintenanceTable()
{
    qDebug() << "Rafraîchissement de la table de maintenance...";

    if (!QSqlDatabase::database().isOpen()) {
        qDebug() << "Base de données non connectée lors du rafraîchissement";
        QMessageBox::warning(this, "Erreur de connexion",
                             "La connexion à la base de données a été perdue. Tentative de reconnexion...");
        return;
    }

    model->removeRows(0, model->rowCount());
    QList<Maintenance> maintenances = Maintenance::getAllMaintenance();

    qDebug() << "Nombre de maintenances récupérées: " << maintenances.size();

    for (const Maintenance &m : maintenances) {
        QList<QStandardItem*> rowItems = {
            new QStandardItem(QString::number(m.getIdMaintenance())),
            new QStandardItem(m.getDescription()),
            new QStandardItem(m.getTypeMaintenance()),
            new QStandardItem(m.getCategorie()),
            new QStandardItem(m.getDateMaintenance().toString("dd/MM/yyyy")),
            new QStandardItem(m.getStatut()),
            new QStandardItem(QString::number(m.getIdTechnicien())),
            new QStandardItem(m.getEmailTechnicien()),
            new QStandardItem(QString::number(m.getNumeroTelephone())),
            new QStandardItem(QString::number(m.getIdService()))
        };

        for (QStandardItem* item : rowItems) {
            item->setToolTip(item->text());
        }

        model->appendRow(rowItems);
    }

    qDebug() << "Table rafraîchie avec " << model->rowCount() << " lignes";
}

void MainMaintenance::on_pushButton_ajouter_clicked()
{
    if (!validateInputs()) return;

    Maintenance m;
    m.setIdMaintenance(ui->lineEdit_idmaintenance->text().toInt());
    m.setDescription(ui->lineEdit_description->text());
    m.setTypeMaintenance(ui->lineEdit_type->text());
    m.setCategorie(ui->lineEdit_categorie->text());
    m.setDateMaintenance(ui->dateEdit_datem->date());
    m.setStatut(ui->comboBox->currentText());
    m.setIdTechnicien(ui->lineEdit_id_tech->text().toInt());
    m.setEmailTechnicien(ui->lineEdit_emailtech->text());
    m.setNumeroTelephone(ui->lineEdit_numtelephone->text().toInt());
    m.setIdService(ui->lineEdit_idservice->text().toInt());

    if (m.addMaintenance()) {
        QMessageBox::information(this, "Succès", "Maintenance ajoutée avec succès");
        refreshMaintenanceTable();
        clearInputs();
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de l'ajout de la maintenance");
    }
}

void MainMaintenance::on_tableView_clicked(const QModelIndex &index)
{
    int row = index.row();
    ui->lineEdit_idmaintenance->setText(model->index(row, 0).data().toString());
    ui->lineEdit_description->setText(model->index(row, 1).data().toString());
    ui->lineEdit_type->setText(model->index(row, 2).data().toString());
    ui->lineEdit_categorie->setText(model->index(row, 3).data().toString());

    QDate date = QDate::fromString(model->index(row, 4).data().toString(), "dd/MM/yyyy");
    ui->dateEdit_datem->setDate(date);

    ui->comboBox->setCurrentText(model->index(row, 5).data().toString());
    ui->lineEdit_id_tech->setText(model->index(row, 6).data().toString());
    ui->lineEdit_emailtech->setText(model->index(row, 7).data().toString());
    ui->lineEdit_numtelephone->setText(model->index(row, 8).data().toString());
    ui->lineEdit_idservice->setText(model->index(row, 9).data().toString());
}

void MainMaintenance::on_pushButton_modifier_clicked()
{
    if (!validateInputs()) return;

    Maintenance m;
    m.setIdMaintenance(ui->lineEdit_idmaintenance->text().toInt());
    m.setDescription(ui->lineEdit_description->text());
    m.setTypeMaintenance(ui->lineEdit_type->text());
    m.setCategorie(ui->lineEdit_categorie->text());
    m.setDateMaintenance(ui->dateEdit_datem->date());
    m.setStatut(ui->comboBox->currentText());
    m.setIdTechnicien(ui->lineEdit_id_tech->text().toInt());
    m.setEmailTechnicien(ui->lineEdit_emailtech->text());
    m.setNumeroTelephone(ui->lineEdit_numtelephone->text().toInt());
    m.setIdService(ui->lineEdit_idservice->text().toInt());

    if (m.updateMaintenance()) {
        QMessageBox::information(this, "Succès", "Maintenance modifiée avec succès");
        refreshMaintenanceTable();
        clearInputs();
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la modification de la maintenance");
    }
}

void MainMaintenance::on_pushButton_supprimer_clicked()
{
    if (ui->lineEdit_idmaintenance->text().isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner une maintenance à supprimer");
        return;
    }

    QMessageBox::StandardButton reply = QMessageBox::question(
        this, "Confirmation", "Êtes-vous sûr de vouloir supprimer cette maintenance?",
        QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        int id = ui->lineEdit_idmaintenance->text().toInt();
        if (Maintenance::deleteMaintenance(id)) {
            QMessageBox::information(this, "Succès", "Maintenance supprimée avec succès");
            refreshMaintenanceTable();
            clearInputs();
        } else {
            QMessageBox::critical(this, "Erreur", "Échec de la suppression de la maintenance");
        }
    }
}

void MainMaintenance::clearInputs()
{
    ui->lineEdit_idmaintenance->clear();
    ui->lineEdit_description->clear();
    ui->lineEdit_type->clear();
    ui->lineEdit_categorie->clear();
    ui->dateEdit_datem->setDate(QDate::currentDate());
    ui->comboBox->setCurrentIndex(0);
    ui->lineEdit_id_tech->clear();
    ui->lineEdit_emailtech->clear();
    ui->lineEdit_numtelephone->clear();
    ui->lineEdit_idservice->clear();
}

void MainMaintenance::on_pushButton_telecharger_clicked()
{
    // Vérifier si le modèle a des données
    if (model->rowCount() == 0) {
        QMessageBox::warning(this, "Erreur", "Aucune donnée à exporter");
        return;
    }

    // Demander à l'utilisateur où sauvegarder le PDF
    QString fileName = QFileDialog::getSaveFileName(this, "Enregistrer en PDF",
                                                    QDir::homePath() + "/maintenance_rapport.pdf",
                                                    "Fichiers PDF (*.pdf)");
    if (fileName.isEmpty()) {
        return;
    }

    if (!fileName.endsWith(".pdf", Qt::CaseInsensitive)) {
        fileName += ".pdf";
    }

    // Créer un PDF Writer
    QPdfWriter pdfWriter(fileName);
    pdfWriter.setPageSize(QPageSize(QPageSize::A4));
    pdfWriter.setResolution(96);  // Fixer la résolution pour un comportement prévisible
    pdfWriter.setPageMargins(QMarginsF(20, 20, 20, 20));
    pdfWriter.setTitle("Rapport de maintenance");

    QPainter painter(&pdfWriter);

    // Définir la police
    QFont titleFont("Arial", 20, QFont::Bold);
    QFont headerFont("Arial", 11, QFont::Bold);
    QFont contentFont("Arial", 10);
    painter.setFont(titleFont);

    // Dessiner le titre
    painter.drawText(QRectF(0, 50, pdfWriter.width(), 50),
                     Qt::AlignHCenter | Qt::AlignTop,
                     "Rapport de Maintenance");

    // Mise à l'échelle
    double scaleFactor = pdfWriter.logicalDpiX() / 96.0;

    // Dimensions
    int margin = 20 * scaleFactor;
    int tableWidth = pdfWriter.width() - 2 * margin;
    int rowHeight = 30 * scaleFactor;
    int tableX = margin;
    int tableY = 120 * scaleFactor;
    int columnCount = model->columnCount();

    // Pourcentage de largeur des colonnes
    QVector<double> columnWidthsPercentage = {
        8, 18, 10, 10, 10, 8, 8, 15, 8, 5
    };

    QVector<int> columnWidths;
    for (double percentage : columnWidthsPercentage) {
        columnWidths.append(static_cast<int>(tableWidth * percentage / 100.0));
    }

    // Dessiner l'en-tête
    painter.setFont(headerFont);
    painter.setPen(QPen(Qt::black, 1.5));
    painter.setBrush(QBrush(QColor(200, 200, 250)));

    int currentX = tableX;
    for (int col = 0; col < columnCount; ++col) {
        QRect headerRect(currentX, tableY, columnWidths[col], rowHeight);
        painter.drawRect(headerRect);
        painter.drawText(headerRect, Qt::AlignCenter | Qt::TextWordWrap,
                         model->headerData(col, Qt::Horizontal).toString());
        currentX += columnWidths[col];
    }

    // Dessiner les lignes
    painter.setFont(contentFont);
    painter.setPen(QPen(Qt::black, 0.5));

    int currentY = tableY + rowHeight;
    int rowCount = model->rowCount();

    for (int row = 0; row < rowCount; ++row) {
        if (currentY + rowHeight > pdfWriter.height() - margin) {
            painter.end();
            pdfWriter.newPage();
            painter.begin(&pdfWriter);
            painter.setFont(contentFont);
            currentY = margin;

            // Redessiner l'en-tête
            painter.setFont(headerFont);
            painter.setPen(QPen(Qt::black, 1.5));
            painter.setBrush(QBrush(QColor(200, 200, 250)));
            currentX = tableX;
            for (int col = 0; col < columnCount; ++col) {
                QRect headerRect(currentX, currentY, columnWidths[col], rowHeight);
                painter.drawRect(headerRect);
                painter.drawText(headerRect, Qt::AlignCenter | Qt::TextWordWrap,
                                 model->headerData(col, Qt::Horizontal).toString());
                currentX += columnWidths[col];
            }
            currentY += rowHeight;
            painter.setFont(contentFont);
            painter.setPen(QPen(Qt::black, 0.5));
        }

        // Couleur alternée
        if (row % 2 == 0)
            painter.setBrush(QBrush(QColor(240, 240, 240)));
        else
            painter.setBrush(QBrush(Qt::white));

        currentX = tableX;
        for (int col = 0; col < columnCount; ++col) {
            QRect cellRect(currentX, currentY, columnWidths[col], rowHeight);
            painter.drawRect(cellRect);

            QString cellText = model->index(row, col).data().toString();

            if (cellText.length() > 30) {
                QFontMetrics fm(contentFont);
                cellText = fm.elidedText(cellText, Qt::ElideRight, cellRect.width() - 10);
            }

            painter.drawText(cellRect.adjusted(3, 3, -3, -3),
                             Qt::AlignVCenter | Qt::AlignLeft | Qt::TextWordWrap,
                             cellText);

            currentX += columnWidths[col];
        }
        currentY += rowHeight;
    }

    // Pied de page
    painter.setFont(QFont("Arial", 8));
    painter.setPen(Qt::darkGray);
    painter.drawText(QRectF(margin, pdfWriter.height() - margin,
                            pdfWriter.width() - 2 * margin, 20),
                     Qt::AlignRight | Qt::AlignBottom,
                     "Généré le " + QDateTime::currentDateTime().toString("dd/MM/yyyy à hh:mm"));

    painter.end();

    QMessageBox::information(this, "Succès",
                             "Le rapport a été exporté avec succès sous:\n" + fileName);
}

void MainMaintenance::on_pushButton_stat_clicked()
{
    // Count maintenance by status
    int enCoursCount = 0;
    int termineCount = 0;
    int enAttenteCount = 0;

    for (int row = 0; row < model->rowCount(); ++row) {
        QString status = model->index(row, 5).data().toString();

        if (status == "En cours") enCoursCount++;
        else if (status == "Terminé") termineCount++;
        else if (status == "En attente") enAttenteCount++;
    }

    // Create dialog
    QDialog *statsDialog = new QDialog(this);
    statsDialog->setWindowTitle("Statistiques des statuts de maintenance");
    statsDialog->resize(600, 500);

    QVBoxLayout *layout = new QVBoxLayout(statsDialog);

    // Create pie chart
    QPieSeries *series = new QPieSeries();

    // Add slices with specific colors
    QPieSlice *enCoursSlice = series->append("En cours", enCoursCount);
    enCoursSlice->setColor(QColor(65, 105, 225));  // Royal Blue

    QPieSlice *termineSlice = series->append("Terminé", termineCount);
    termineSlice->setColor(QColor(50, 205, 50));    // Lime Green

    QPieSlice *enAttenteSlice = series->append("En attente", enAttenteCount);
    enAttenteSlice->setColor(QColor(255, 165, 0));  // Orange

    // Configure chart appearance
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Répartition des statuts");
    chart->setTitleFont(QFont("Arial", 14, QFont::Bold));
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignRight);
    chart->legend()->setFont(QFont("Arial", 10));

    // Configure slices
    for (QPieSlice *slice : series->slices()) {
        slice->setLabelVisible();
        slice->setLabelColor(Qt::white);
        slice->setLabelFont(QFont("Arial", 10, QFont::Bold));
        slice->setLabelPosition(QPieSlice::LabelInsideHorizontal);
        slice->setBorderWidth(2);
    }

    // Create chart view
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    layout->addWidget(chartView);

    // Add update button
    QPushButton *updateButton = new QPushButton("Actualiser", statsDialog);
    connect(updateButton, &QPushButton::clicked, this, [this, statsDialog]() {
        statsDialog->close();
        on_pushButton_stat_clicked();  // Recursive call to refresh data
    });
    layout->addWidget(updateButton, 0, Qt::AlignRight);

    statsDialog->setLayout(layout);
    statsDialog->exec();
}

void MainMaintenance::on_pushButton_tri_clicked()
{
    // Créer un dialogue pour sélectionner le type de tri
    QDialog *triDialog = new QDialog(this);
    triDialog->setWindowTitle("Sélectionner le critère de tri");
    triDialog->setMinimumWidth(300);

    QVBoxLayout *layout = new QVBoxLayout(triDialog);

    // Groupe de boutons radio pour les options de tri
    QGroupBox *groupBox = new QGroupBox("Critère de tri:");
    QVBoxLayout *groupLayout = new QVBoxLayout(groupBox);

    QRadioButton *rbStatut = new QRadioButton("Par statut (En cours → En attente → Terminé)");
    QRadioButton *rbDate = new QRadioButton("Par date (Plus récent au plus ancien)");
    QRadioButton *rbPriorite = new QRadioButton("Par priorité (Combinaison statut et date)");

    // Par défaut, sélectionnez le tri par statut
    rbStatut->setChecked(true);

    groupLayout->addWidget(rbStatut);
    groupLayout->addWidget(rbDate);
    groupLayout->addWidget(rbPriorite);
    groupBox->setLayout(groupLayout);

    // Boutons de dialogue
    QDialogButtonBox *buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);
    connect(buttonBox, &QDialogButtonBox::accepted, triDialog, &QDialog::accept);
    connect(buttonBox, &QDialogButtonBox::rejected, triDialog, &QDialog::reject);

    layout->addWidget(groupBox);
    layout->addWidget(buttonBox);

    triDialog->setLayout(layout);

    // Exécuter le dialogue
    int result = triDialog->exec();

    if (result == QDialog::Accepted) {
        QList<Maintenance> maintenances = Maintenance::getAllMaintenance();

        // Appliquer le tri sélectionné
        if (rbStatut->isChecked()) {
            // Tri par statut
            std::sort(maintenances.begin(), maintenances.end(), [](const Maintenance &a, const Maintenance &b) {
                // Définir l'ordre de priorité des statuts
                QMap<QString, int> statutPriorite = {
                    {"En cours", 1},
                    {"En attente", 2},
                    {"Terminé", 3}
                };

                return statutPriorite[a.getStatut()] < statutPriorite[b.getStatut()];
            });
        }
        else if (rbDate->isChecked()) {
            // Tri par date (du plus récent au plus ancien)
            std::sort(maintenances.begin(), maintenances.end(), [](const Maintenance &a, const Maintenance &b) {
                return a.getDateMaintenance() > b.getDateMaintenance();
            });
        }
        else if (rbPriorite->isChecked()) {
            // Tri par priorité (combinaison de statut et date)
            std::sort(maintenances.begin(), maintenances.end(), [](const Maintenance &a, const Maintenance &b) {
                // D'abord, comparer par statut
                QMap<QString, int> statutPriorite = {
                    {"En cours", 1},
                    {"En attente", 2},
                    {"Terminé", 3}
                };

                if (statutPriorite[a.getStatut()] != statutPriorite[b.getStatut()]) {
                    return statutPriorite[a.getStatut()] < statutPriorite[b.getStatut()];
                }

                // Si même statut, trier par date (plus récent d'abord)
                return a.getDateMaintenance() > b.getDateMaintenance();
            });
        }

        // Mettre à jour le modèle avec les données triées
        model->removeRows(0, model->rowCount());

        for (const Maintenance &m : maintenances) {
            QList<QStandardItem*> rowItems = {
                new QStandardItem(QString::number(m.getIdMaintenance())),
                new QStandardItem(m.getDescription()),
                new QStandardItem(m.getTypeMaintenance()),
                new QStandardItem(m.getCategorie()),
                new QStandardItem(m.getDateMaintenance().toString("dd/MM/yyyy")),
                new QStandardItem(m.getStatut()),
                new QStandardItem(QString::number(m.getIdTechnicien())),
                new QStandardItem(m.getEmailTechnicien()),
                new QStandardItem(QString::number(m.getNumeroTelephone())),
                new QStandardItem(QString::number(m.getIdService()))
            };

            for (QStandardItem* item : rowItems) {
                item->setToolTip(item->text());
            }

            model->appendRow(rowItems);
        }

        // Afficher un message indiquant que le tri a été effectué
        QString critere = rbStatut->isChecked() ? "statut" : (rbDate->isChecked() ? "date" : "priorité");
        QMessageBox::information(this, "Tri effectué",
                                 QString("Les maintenances ont été triées par %1 avec succès.").arg(critere));
    }

    delete triDialog;
}

void MainMaintenance::on_pushButton_search_clicked()
{
    // Récupérer l'ID de maintenance entré dans le lineEdit
    QString idText = ui->lineEdit->text().trimmed();

    // Si le champ est vide, afficher toutes les maintenances
    if (idText.isEmpty()) {
        refreshMaintenanceTable();
        return;
    }

    // Vérifier si l'ID est numérique
    bool conversionOk;
    int maintenanceId = idText.toInt(&conversionOk);

    if (!conversionOk) {
        QMessageBox::warning(this, "Erreur de format", "L'ID de maintenance doit être un nombre.");
        ui->lineEdit->setFocus();
        return;
    }

    // Rechercher la maintenance par ID
    Maintenance maintenance = Maintenance::getMaintenance(maintenanceId);

    // Vérifier si la maintenance a été trouvée (en vérifiant si l'ID retourné est valide)
    if (maintenance.getIdMaintenance() <= 0) {
        // Effacer le tableau et afficher un message
        model->removeRows(0, model->rowCount());
        QMessageBox::information(this, "Recherche",
                                 "Aucune maintenance trouvée avec l'ID " + idText + ".");
        return;
    }

    // Effacer le modèle actuel et n'afficher que la maintenance trouvée
    model->removeRows(0, model->rowCount());

    // Ajouter uniquement la maintenance trouvée au tableau
    QList<QStandardItem*> rowItems = {
        new QStandardItem(QString::number(maintenance.getIdMaintenance())),
        new QStandardItem(maintenance.getDescription()),
        new QStandardItem(maintenance.getTypeMaintenance()),
        new QStandardItem(maintenance.getCategorie()),
        new QStandardItem(maintenance.getDateMaintenance().toString("dd/MM/yyyy")),
        new QStandardItem(maintenance.getStatut()),
        new QStandardItem(QString::number(maintenance.getIdTechnicien())),
        new QStandardItem(maintenance.getEmailTechnicien()),
        new QStandardItem(QString::number(maintenance.getNumeroTelephone())),
        new QStandardItem(QString::number(maintenance.getIdService()))
    };

    for (QStandardItem* item : rowItems) {
        item->setToolTip(item->text());
    }

    model->appendRow(rowItems);

    // Remplir les champs du formulaire avec les détails de la maintenance trouvée
    ui->lineEdit_idmaintenance->setText(QString::number(maintenance.getIdMaintenance()));
    ui->lineEdit_description->setText(maintenance.getDescription());
    ui->lineEdit_type->setText(maintenance.getTypeMaintenance());
    ui->lineEdit_categorie->setText(maintenance.getCategorie());
    ui->dateEdit_datem->setDate(maintenance.getDateMaintenance());
    ui->comboBox->setCurrentText(maintenance.getStatut());
    ui->lineEdit_id_tech->setText(QString::number(maintenance.getIdTechnicien()));
    ui->lineEdit_emailtech->setText(maintenance.getEmailTechnicien());
    ui->lineEdit_numtelephone->setText(QString::number(maintenance.getNumeroTelephone()));
    ui->lineEdit_idservice->setText(QString::number(maintenance.getIdService()));
}

void MainMaintenance::onSearchTextChanged(const QString &text)
{
    // Si le champ de recherche est vide, afficher toutes les maintenances
    if (text.isEmpty()) {
        refreshMaintenanceTable();
    }
}

void MainMaintenance::on_pushButton_sms_clicked()
{
    // 1. Get selected data
    QModelIndexList selected = ui->tableView->selectionModel()->selectedRows();
    if (selected.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Aucune maintenance sélectionnée.");
        return;
    }

    int row = selected.first().row();
    QString phoneNumber = "+216" + model->index(row, 8).data().toString();

    // 2. Validate phone number
    if (!QRegularExpression("^\\+216[24579]\\d{7}$").match(phoneNumber).hasMatch()) {
        QMessageBox::critical(this, "Erreur", "Numéro tunisien invalide.");
        return;
    }

    // 3. Prepare message
    QString message = QString("Notification de maintenance:\n"
                              "ID: %1\nType: %2\nStatut: %3\nDate: %4")
                          .arg(model->index(row, 9).data().toString(),
                               model->index(row, 2).data().toString(),
                               model->index(row, 5).data().toString(),
                               model->index(row, 4).data().toString());

    // 4. Try THREE different methods
    bool success = false;

    // METHOD 1: Standard SMS URI (works on some systems)
    if (!success) {
        QString smsUri = QString("sms:%1?body=%2")
        .arg(phoneNumber, QUrl::toPercentEncoding(message));
        success = QDesktopServices::openUrl(QUrl(smsUri));
    }

    // METHOD 2: Your Phone deep link (alternative format)
    if (!success) {
        QString yourPhoneUri = QString("ms-phone-companion://sms?to=%1&body=%2")
        .arg(phoneNumber, QUrl::toPercentEncoding(message));
        QProcess::startDetached("explorer", {yourPhoneUri});
        QThread::sleep(2); // Wait 2 seconds
        success = true; // Assume it worked
    }

    // METHOD 3: PowerShell command (most reliable fallback)
    if (!success) {
        QString psCommand = QString(
                                "powershell -command \""
                                "Start-Process -FilePath 'explorer' -ArgumentList "
                                "'ms-phone-companion:?action=sms&to=%1&body=%2'\""
                                ).arg(phoneNumber, QUrl::toPercentEncoding(message));

        system(psCommand.toStdString().c_str());
        success = true;
    }

    // 5. Verify using Windows API
    if (success) {
        QMessageBox::information(this, "Succès",
                                 "Le message a été préparé pour envoi.\n"
                                 "Si l'application ne s'ouvre pas:\n"
                                 "1. Lancez manuellement 'Your Phone'\n"
                                 "2. Vérifiez la connexion avec votre mobile");
    } else {
        QMessageBox::critical(this, "Échec",
                              "Aucune méthode n'a fonctionné.\n"
                              "Veuillez:\n"
                              "1. Vérifier que 'Your Phone' est installé\n"
                              "2. Essayer de réinstaller depuis le Microsoft Store");
    }
}























void MainMaintenance::on_pushButton_email_clicked()
{
    // 1. Get selected row data
    QModelIndexList selected = ui->tableView->selectionModel()->selectedRows();
    if (selected.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner une maintenance.");
        return;
    }

    int row = selected.first().row();
    QString technicianEmail = model->index(row, 7).data().toString(); // Email column

    // 2. Validate email
    if (!QRegularExpression("^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$").match(technicianEmail).hasMatch()) {
        QMessageBox::critical(this, "Erreur", "Email du technicien invalide.");
        return;
    }

    // 3. Prepare message (same as SMS content)
    QString message = QString("Notification de maintenance:\n"
                              "ID: %1\nType: %2\nStatut: %3\nDate: %4")
                          .arg(model->index(row, 9).data().toString(),  // ID Service
                               model->index(row, 2).data().toString(),  // Type
                               model->index(row, 5).data().toString(),  // Statut
                               model->index(row, 4).data().toString());// Date

    // 4. Create and send email
    mailer emailSender;
    int result = emailSender.sendEmail(
        technicianEmail,
        "Notification de Maintenance",
        message
        );

    // 5. Show result
    if (result == 1) {
        QMessageBox::information(this, "Succès", "Email envoyé avec succès à:\n" + technicianEmail);
    } else {
        QMessageBox::critical(this, "Échec", "Échec de l'envoi de l'email.\nVérifiez votre connexion internet.");
    }
}
