#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "employee1.h"

#include <QTableWidgetItem>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void afficherEmployees();  // Mise à jour de la fonction d'affichage

private slots:
    void on_pushButton_ajouter_clicked();
    void on_pushButton_modifier_clicked();
    void on_pushButton_ok_clicked();
    void on_pushButton_supprimer_clicked();
    void on_pushButton_annuler_clicked();
    void on_pushButton_annuler_2_clicked();
    void on_pushButton_annuler_3_clicked();
    void on_btn_modifier_clicked();

private:
    Ui::MainWindow *ui;
    employee1 emp;
};
#endif // MAINWINDOW_H
