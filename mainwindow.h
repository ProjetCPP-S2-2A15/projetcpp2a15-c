#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "services.h"
#include <QTableWidgetItem>
#include "NotificationPanel.h" // Assure-toi que le fichier est bien inclus
#include "arduino.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void afficherServices();  // Déclaration de la fonction afficherServices()
 void checkServiceStatus(); // Déclare bien ici la méthode
    void ajouterHistorique(const QString &operation);

private slots:
    void on_pushButton_ajouter_clicked();
    void on_pushButton_modifier_clicked();
    void on_pushButton_supprimer_clicked();

    void on_pushButton_annuler_clicked();



    void on_pushButton_annuler_2_clicked();

    void on_pushButton_annuler_3_clicked();

    void on_pb_rechercher_clicked();

    void on_pushButton_annuler_search_clicked();




    void on_pushButton_telecharger_pdf_clicked();

    void exportTableToPDF(QTableView *table, const QString &filename);



void on_tab_Services_clicked(const QModelIndex &index);

void on_pb_tier_clicked();


void on_pushButton_fonctionnalites_2_clicked();

void on_pushButton_crud_2_clicked();


void on_actualiser_clicked();

void on_pushButton_exp_clicked();



private:
    Ui::MainWindow *ui;
    Services s;
 NotificationPanel *notificationPanel;
   Arduino *arduinoWindow;

};

#endif // MAINWINDOW_H
