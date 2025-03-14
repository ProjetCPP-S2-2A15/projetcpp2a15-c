#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "connection.h"
#include <QMainWindow>
#include "local.h" // Inclure la classe Local

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_ajouter_clicked(); // Slot pour ajouter un local
    void on_pushButton_annuler_clicked();    // Slot pour annuler (effacer les champs)
    void on_pushButton_supprimer_clicked();
    void on_pushButton_modifier_clicked();
    void mettreAJourAffichage();


private:
    Ui::MainWindow *ui;
    Local local; // Instance de la classe Local
};

#endif // MAINWINDOW_H
