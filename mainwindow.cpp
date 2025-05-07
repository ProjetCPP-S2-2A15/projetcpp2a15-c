#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employee1.h"
#include "statistique.h"
#include "arduino.h"
#include "arduinowidget.h"
#include "mainevent.h"    // Include MainEvent
#include "mainloclac.h"   // Include MainLoclac
#include "mainservice.h"  // Include MainService
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
    stat(new Statistique()),
    mainMaintenance(nullptr),
    mainEvent(nullptr),
    mainLoclac(nullptr),
    mainService(nullptr)
{
    ui->setupUi(this);
    ui->tab_employee1->setModel(emp.afficher());
    QDateTime today = QDateTime::currentDateTime();
    ui->le_dateE_2->setDate(today.date());
    connect(ui->le_recherche, &QLineEdit::textChanged, this, &MainWindow::on_le_recherche_textChanged);
    connect(ui->pushButton_rechercher, &QPushButton::clicked, this, &MainWindow::on_pushButton_rechercher_clicked);
    connect(ui->pushButton_stat, &QPushButton::clicked, this, &MainWindow::on_pushButton_stat_clicked);
    connect(A.getserial(), SIGNAL(readyRead()), this, SLOT(handleSerialData()));

    // Connect navigation buttons to their slots
    connect(ui->gestionservicebtn, &QPushButton::clicked, this, &MainWindow::on_gestionservicebtn_clicked);
    connect(ui->gestionlocatairesbtn, &QPushButton::clicked, this, &MainWindow::on_gestionlocatairesbtn_clicked);
    connect(ui->gestionlocauxbtn, &QPushButton::clicked, this, &MainWindow::on_gestionlocauxbtn_clicked);
    connect(ui->gestioneventbtn, &QPushButton::clicked, this, &MainWindow::on_gestioneventbtn_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete stat;
    delete mainMaintenance;
    delete mainEvent;
    delete mainLoclac;
    delete mainService;
}

void MainWindow::on_pushButton_ajouter_clicked()
{
    QString nom = ui->le_nom->text();
    QString prenom = ui->le_prenom->text();
    QString poste = ui->le_poste->currentText();
    double salaire = ui->le_salaire->text().toDouble();
    QString status = ui->le_status->currentText();
    QString adresse = ui->le_adresse->text();
    QString role = ui->le_role->currentText();
    QDateTime dateE = ui->le_dateE_2->dateTime();
    static const QRegularExpression regexLettres("^[a-zA-Z\\s]+$");
    static const QRegularExpression regexAdresse("^[a-zA-Z0-9\\s,.-]+$");

    if (nom.isEmpty() || prenom.isEmpty() || poste.isEmpty() || status.isEmpty() || role.isEmpty() || adresse.isEmpty() || !dateE.isValid()) {
        QMessageBox::critical(this, "Erreur", "Veuillez remplir tous les champs obligatoires !");
        return;
    }

    if (salaire <= 0) {
        QMessageBox::critical(this, "Erreur", "Le salaire doit être un nombre valide et supérieur à zéro.");
        return;
    }

    if (dateE > QDateTime::currentDateTime()) {
        QMessageBox::critical(this, "Erreur", "La date d'embauche ne peut pas être dans le futur.");
        return;
    }

    if (!regexLettres.match(nom).hasMatch()) {
        QMessageBox::critical(this, "Erreur", "Le nom ne doit contenir que des lettres et des espaces.");
        return;
    }

    if (!regexLettres.match(prenom).hasMatch()) {
        QMessageBox::critical(this, "Erreur", "Le prénom ne doit contenir que des lettres et des espaces.");
        return;
    }

    if (adresse.length() < 10 || adresse.length() > 20) {
        QMessageBox::critical(this, "Erreur de validation", "L'adresse doit contenir entre 10 et 20 caractères.");
        return;
    }

    if (!regexAdresse.match(adresse).hasMatch()) {
        QMessageBox::critical(this, "Erreur de validation", "L'adresse ne doit contenir que des lettres, chiffres, espaces, virgules, points ou tirets.");
        return;
    }

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

    QString posteNormalise = poste.toLower().trimmed();
    QString posteExact;
    bool posteTrouve = false;

    for (const QString &key : salairePoste.keys()) {
        if (key.toLower().trimmed() == posteNormalise) {
            posteExact = key;
            posteTrouve = true;
            break;
        }
    }

    if (!posteTrouve) {
        QMessageBox::critical(this, "Erreur", QString("Poste inconnu : '%1'. Veuillez choisir un poste valide.").arg(poste));
        return;
    }

    QPair<double, double> intervalle = salairePoste.value(posteExact);
    if (salaire < intervalle.first || salaire > intervalle.second) {
        QMessageBox::critical(this, "Erreur", QString("Le salaire pour %1 doit être compris entre %2 et %3.")
                                                  .arg(posteExact).arg(intervalle.first).arg(intervalle.second));
        return;
    }

    QStringList responsables = {"Responsable Maintenance", "Responsable Evenements", "Responsable Services",
                                "Responsable Locataires", "Responsable locaux comerciaux", "Responsable Employees"};
    QStringList rolesResponsables = { "Responsable" };
    QStringList postesRestreints = {"Technicien", "Agent de Sécurité"};

    if (responsables.contains(posteExact)) {
        if (role == "Employee") {
            QMessageBox::critical(this, "Erreur", "Le rôle 'Employé' n'est pas valide pour un poste de responsable.");
            return;
        }
    } else if (postesRestreints.contains(posteExact)) {
        if (rolesResponsables.contains(role)) {
            QMessageBox::critical(this, "Erreur", "Le rôle 'Responsable' n'est pas valide pour ce poste.");
            return;
        }
    } else {
        if (rolesResponsables.contains(role)) {
            QMessageBox::critical(this, "Erreur", "Le rôle 'Responsable' n'est pas valide pour ce poste.");
            return;
        }
        if (role == "Employee" && responsables.contains(posteExact)) {
            QMessageBox::critical(this, "Erreur", "Le rôle 'Employé' ne peut pas être associé à un poste de Responsable.");
            return;
        }
    }

    int id = 0;
    employee1 emp(id, nom, prenom, poste, salaire, status, adresse, role, dateE);
    bool test = emp.ajouter();

    if (test) {
        ui->tab_employee1->setModel(emp.afficher());
        QMessageBox::information(this, "Succès", "Employé ajouté avec succès !");
    } else {
        QMessageBox::critical(this, "Erreur", "L'ajout de l'employé a échoué.");
    }
}

void MainWindow::onAjouterEmploye()
{
    QDateTime dateE = ui->le_dateE_2->dateTime();
    if (dateE > QDateTime::currentDateTime()) {
        QMessageBox::critical(this, "Erreur", "La date d'embauche ne peut pas être dans le futur.");
        return;
    }
}

void MainWindow::on_pushButton_supprimer_clicked()
{
    int id = ui->id_supp->text().toInt();
    if (id <= 0) {
        QMessageBox::critical(this, "Erreur", "L'ID doit être un nombre positif.");
        return;
    }

    bool test = emp.supprimer(id);
    if (test) {
        ui->tab_employee1->setModel(emp.afficher());
        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Suppression effectuée\nClick Cancel to exit."), QMessageBox::Cancel);
    } else {
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                              QObject::tr("Suppression non effectuée\nClick Cancel to exit."), QMessageBox::Cancel);
    }
}

QString initialPoste = "Responsable Employees";
QString initialStatus = "Actif";
QString initialRole = "Responsable";

void MainWindow::on_pushButton_annuler_clicked()
{
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

    employee1 emp = employee1::chercherParId(id);
    if (emp.getId() == 0) {
        QMessageBox::warning(this, "Employé introuvable", "Aucun employé trouvé avec cet ID !");
        return;
    }

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
    int id = ui->le_modif_id_emp->text().toInt();
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Confirmer", "Voulez-vous modifier cet employé ?", QMessageBox::Yes | QMessageBox::No);

    QString nom = ui->le_modif_nom->text();
    QString prenom = ui->le_modif_prenom->text();
    QString poste = ui->le_modif_poste->currentText();
    double salaire = ui->le_modif_salaire->text().toDouble();
    QString status = ui->le_modif_status->currentText();
    QString adresse = ui->le_modif_adresse->text();
    QString role = ui->le_modif_role->currentText();
    QDateTime dateE = ui->le_modif_dateE->dateTime();

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
        ui->tab_employee1->setColumnHidden(3, true);
        ui->tab_employee1->setColumnHidden(4, true);
    } else {
        QMessageBox::information(this, "Résultat", "Aucun employé trouvé avec ce nom.");
    }
}

void MainWindow::on_pushButton_tri_clicked()
{
    static bool asc = true;
    QString ordre = asc ? "ASC" : "DESC";
    asc = !asc;

    QSqlQueryModel* model = emp.trier("DATE_E", ordre);
    ui->tab_employee1->setModel(model);
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
    int colWidthPoste = 600;
    int colWidthSalaire = 300;
    int colWidthDate = 400;
    int colWidthAdresse = 500;
    int colWidthID = 250;
    int colWidthRole = 400;

    int tableWidth = colWidthNom + colWidthPrenom + colWidthPoste + colWidthSalaire +
                     colWidthDate + colWidthAdresse + colWidthID + colWidthRole;

    xStart = (pageWidth - tableWidth) / 2;

    QFont titleFont = painter.font();
    titleFont.setPointSize(16);
    titleFont.setBold(true);
    painter.setFont(titleFont);
    painter.setPen(Qt::green);
    QString title = "Liste des Employés";
    int titleWidth = painter.fontMetrics().horizontalAdvance(title);
    int titleX = (pageWidth - titleWidth) / 2;
    painter.drawText(titleX, 100, title);

    QFont font = painter.font();
    font.setPointSize(10);
    painter.setFont(font);
    painter.setPen(Qt::black);

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

        if (yStart > pdfWriter.height() - 200) {
            pdfWriter.newPage();
            yStart = 200;
        }
    }

    QMessageBox::information(this, "Succès", "Le fichier PDF a été généré avec succès !");
}

void MainWindow::on_pushButton_stat_clicked()
{
    Statistique statistique;
    QChart *chart = statistique.creerGraphiqueSalaireParPoste();
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setBackgroundBrush(Qt::transparent);

    int largeur = ui->graphicsView->width() * 1.4;
    int hauteur = ui->graphicsView->height();
    chartView->setMinimumSize(largeur, hauteur);

    if (ui->graphicsView->scene()) {
        delete ui->graphicsView->scene();
    }

    QGraphicsScene *scene = new QGraphicsScene(this);
    scene->addWidget(chartView);
    scene->setSceneRect(-largeur / 4, 0, largeur * 1.2, hauteur);

    ui->graphicsView->setScene(scene);
    ui->graphicsView->fitInView(scene->itemsBoundingRect(), Qt::KeepAspectRatio);
}

void MainWindow::handleSerialData()
{
    QByteArray data = A.read_from_arduino();
    QString rfid = QString(data).trimmed();
    QByteArray result = A.cherchercode(rfid);
    A.write_to_arduino(result + "\n");
}

void MainWindow::on_pushButton_12_clicked()
{
    if (!mainMaintenance) {
        mainMaintenance = new MainMaintenance(this);
    }
    mainMaintenance->show();

}

void MainWindow::on_gestionservicebtn_clicked()
{
    if (!mainService) {
        mainService = new MainService(this);
    }
    mainService->show();

}

void MainWindow::on_gestionlocatairesbtn_clicked()
{
    if (!mainLoclac) {
        mainLoclac = new MainLoclac(this);
    }
    mainLoclac->show();

}

void MainWindow::on_gestionlocauxbtn_clicked()
{
    if (!mainLoclac) {
        mainLoclac = new MainLoclac(this);
    }
    mainLoclac->show();

}

void MainWindow::on_gestioneventbtn_clicked()
{
    if (!mainEvent) {
        mainEvent = new MainEvent(this);
    }
    mainEvent->show();

}
