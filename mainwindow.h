#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "employee1.h"
#include "mainmaintenance.h"
#include "arduino.h"

// Forward declarations for classes we’ll navigate to
class MainEvent;
class MainLoclac;
class MainService;
class Statistique;
class employee1;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_ajouter_clicked();
    void onAjouterEmploye();
    void on_pushButton_supprimer_clicked();
    void on_pushButton_annuler_clicked();
    void on_pushButton_annuler_3_clicked();
    void on_pushButton_annuler_2_clicked();
    void on_pushButton_ok_clicked();
    void on_pushButton_modifier_clicked();
    void on_le_recherche_textChanged(const QString &text);
    void on_pushButton_rechercher_clicked();
    void on_pushButton_tri_clicked();
    void on_pushButton_telecharger_2_clicked();
    void on_pushButton_stat_clicked();
    void handleSerialData();
    void on_pushButton_12_clicked(); // For navigation to mainmaintenance.ui
    void on_gestionservicebtn_clicked();  // Slot for mainservice.ui
    void on_gestionlocatairesbtn_clicked(); // Slot for mainloclac.ui
    void on_gestionlocauxbtn_clicked();    // Slot for mainloclac.ui
    void on_gestioneventbtn_clicked();     // Slot for mainevent.ui

private:
    Ui::MainWindow *ui;
    Statistique *stat;
    employee1 emp;
    MainMaintenance *mainMaintenance; // Pointer to MainMaintenance
    MainEvent *mainEvent;            // Pointer to MainEvent
    MainLoclac *mainLoclac;          // Pointer to MainLoclac
    MainService *mainService;        // Pointer to MainService
    Arduino A; // Arduino instance for serial communication
};

#endif // MAINWINDOW_H
