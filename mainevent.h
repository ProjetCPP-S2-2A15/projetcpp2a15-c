#ifndef MAINEVENT_H
#define MAINEVENT_H

#include <QMainWindow>
#include "arduino.h"
#include "events.h"
#include <QSqlQueryModel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainEvent; }
QT_END_NAMESPACE

class MainEvent : public QMainWindow
{
    Q_OBJECT

public:
    MainEvent(QWidget *parent = nullptr);
    ~MainEvent();
public slots:
    void onDateClicked(const QDate &date);
private slots:
    void on_pushButton_Ajouter_clicked();
    void on_pushButton_Supprimer_clicked();
    void on_pushButton_Modifier_clicked();
    void on_pushButton_Afficher_clicked();
    bool createConnection();
    void on_pushButton_afficherstatistiques_clicked();
    void afficherStatistiques();
    void exporterStatistiquesEnPDF();
    void rechercherEvenements();
    void trierEvenementsParID();
    void revenirAffichageNormal();
    void confirmerFermeture();
    void envoyerSMS(const QString &numero, const QString &message);
    void afficherEvenementsDansCalendrier();
    void on_pushButton_Afficher_2_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_10_clicked(); // New slot for pushButton_10
    void readArduinoData();

private:
    Ui::MainEvent *ui;
    Events e;
    Arduino *arduino;    // Instance d'événement
};

#endif // MAINEVENT_H
