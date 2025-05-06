#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "locataire.h"
#include "smtpclient.h"
#include "mimehtml.h"
#include "mimepart.h"
#include "mimemessage.h"
#include "mimeattachment.h"
#include "localchat.h"
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QMainWindow>
#include "local.h" // Inclure la classe Local
#include <QPrinter>
#include <QPrintPreviewDialog>
#include <QPainter>
#include <QTableView>
#include <QSqlQueryModel>
#include <QFileDialog>
#include <QTextDocument>
#include<QtCharts>
#include <QChartView>
#include <QPageSize>  // Inclure ce header pour utiliser QPageSize::A4
#include <QLabel>
#include <QVector>
#include <QVariant>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // Slots pour la gestion des locataires
    void on_pushButton_ajouter_clicked();
    void afficherLocataires();
    void on_pushButton_ok_clicked();
    void on_pushButton_modifier_clicked();
    void on_pushButton_supprimer_clicked();
    void on_pushButton_triedate_clicked();
    void on_pushButton_trieid_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_mailing_clicked();
    void on_pushButton_telecharger_2_clicked();
    void envoyerEmail(QString destinataire, QString idLocataire);
    void on_pushButton_afficherStats_clicked();
    //void on_pushButton_111_clicked();
    void on_pushButton_13_clicked();
    // Slots du chatbot
    void handleChatResponse(const QString &response);
    void handleChatError(const QString &error);
    void on_sendChatMessage_clicked();

    // Slot pour le port série
    void detecterIncendie(QString idLocal);
    void incendieEmail(QString destinataire, QString idLocataire);
    void on_readyRead();
    //fatma

    void on_pushButton_Ajouter_clicked(); // Slot pour ajouter un local
    void on_pushButton_Annuler_clicked();    // Slot pour annuler (effacer les champs)
    void on_pushButton_Supprimer_clicked();
    void on_pushButton_Modifier_clicked();
    void mettreAJourAffichage();
    void on_pushButton_18_clicked();
    void rechercherLocaux();
    void on_pushButton_telecharger_clicked();
    void on_pushButton_statistique_clicked();
    void on_pushButton_envoyer_clicked();
    void on_pushButton_clear_clicked();
    void on_pushButton_11_clicked();
    void jeuDevineNombre();
    void verifierCaptchaEtLancerJeu() ;
    void pushButton_26_clicked();

    void on_connecter_clicked();
    void handleSerialData(QString rfid); // Slot pour le bouton "connecter"

private:
    Ui::MainWindow *ui;
    bool ajoutEnCours;
    Locataire locataire;
    LocalChat *chatbot;
    void setupChatbot();
    QString calculerDuree(const QString& debut, const QString& fin);

    // Port série
    QSerialPort *arduino;
    QString portname = "COM15";
    QSerialPort *serial;
    QString bufferSerie; // Ajoute cette ligne
    Local local; // Instance de la classe Local
    //Arduino A;
    QString enteredNom;    // Pour stocker le nom saisi
    QString enteredPrenom; // Pour stocker le prénom saisi
signals:
    void setCenter(QVariant lat, QVariant lng);
    void setCenterWithZoom(QVariant lat, QVariant lng, QVariant zoom);
    void addMarker(QVariant lat, QVariant lng);
};

#endif // MAINWINDOW_H
