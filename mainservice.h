#ifndef MAINSERVICE_H
#define MAINSERVICE_H
#include <QMainWindow>
#include "services.h"
#include "mainmaintenance.h"
#include <QTableWidgetItem>
#include "NotificationPanel.h"
#include "arduino.h"
#include <QMap>

namespace Ui {
class MainService;
}

class MainService : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainService(QWidget *parent = nullptr);
    ~MainService();
    void afficherServices();
    void checkServiceStatus();
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
    void afficherStatistiquesDansTable();
    void on_pushButton_12_clicked(); // For navigation to mainmaintenance.ui

private:
    Ui::MainService *ui;
    Services s;
    NotificationPanel *notificationPanel;
    Arduino *arduinoWindow;
    MainMaintenance *mainMaintenance; // Pointer to MainMaintenance
};

#endif // MAINSERVICE_H
