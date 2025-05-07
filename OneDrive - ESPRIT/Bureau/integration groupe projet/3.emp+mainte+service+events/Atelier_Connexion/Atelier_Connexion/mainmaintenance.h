#ifndef MAINMAINTENANCE_H
#define MAINMAINTENANCE_H

#include <QMainWindow>
#include <QStandardItemModel>

class Maintenance; // Forward declaration

namespace Ui {
class MainMaintenance;
}

class MainMaintenance : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainMaintenance(QWidget *parent = nullptr);
    ~MainMaintenance();

private slots:
    void on_pushButton_ajouter_clicked();
    void on_tableView_clicked(const QModelIndex &index);
    void on_pushButton_modifier_clicked();
    void on_pushButton_supprimer_clicked();

    void on_pushButton_telecharger_clicked();

    void on_pushButton_stat_clicked();

    void on_pushButton_tri_clicked();

    void on_pushButton_search_clicked();
    void onSearchTextChanged(const QString &text);

    void on_pushButton_sms_clicked();
    bool isAppActuallyRunning(const QString &processName);

    void on_pushButton_email_clicked();

private:
    Ui::MainMaintenance *ui;
    QStandardItemModel *model;

    void initializeTableView();
    void setupInputValidators();
    bool validateInputs();
    void refreshMaintenanceTable();
    void clearInputs();
};

#endif // MAINMAINTENANCE_H
