#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "connection.h"
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
    void on_pushButton_18_clicked();
    void rechercherLocaux();
    void on_pushButton_telecharger_clicked();
    void on_pushButton_statistique_clicked();
    void on_pushButton_envoyer_clicked();
    void on_pushButton_clear_clicked();
    void on_pushButton_11_clicked();
    void jeuDevineNombre();
    void verifierCaptchaEtLancerJeu() ;
  //  void afficherLocalisationMall();

private:
    Ui::MainWindow *ui;
    Local local; // Instance de la classe Local
signals:
    void setCenter(QVariant, QVariant);
    void addMarker(QVariant, QVariant);
};

#endif // MAINWINDOW_H
