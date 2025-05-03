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

    // Slots du chatbot
    void handleChatResponse(const QString &response);
    void handleChatError(const QString &error);
    void on_sendChatMessage_clicked();

    // Slot pour le port série
    void detecterIncendie(QString idLocal);
    void incendieEmail(QString destinataire, QString idLocataire);
    void on_readyRead();

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
};

#endif // MAINWINDOW_H
