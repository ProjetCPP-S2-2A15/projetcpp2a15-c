#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "locataire.h"  // Inclure la classe Locataire
#include "smtpclient.h"
#include "mimehtml.h"
#include "mimepart.h"
#include "mimemessage.h"
#include "mimeattachment.h"
#include "localchat.h"  // Remplacer dialogflowchat.h par localchat.h

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
    // Garder tous vos slots existants pour la gestion des locataires
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

    // Modifier les slots du chatbot
    void handleChatResponse(const QString &response);
    void handleChatError(const QString &error);
    void on_sendChatMessage_clicked();


private:
    Ui::MainWindow *ui;
    bool ajoutEnCours;
    Locataire locataire;
    LocalChat *chatbot;  // Remplacer DialogflowChat par LocalChat
    void setupChatbot(); // Garder cette fonction mais elle sera modifiée
    QString calculerDuree(const QString& debut, const QString& fin);
};

#endif // MAINWINDOW_H
