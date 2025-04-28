#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QCloseEvent> // Add this for QCloseEvent

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


protected:
    void closeEvent(QCloseEvent *event) override;


private slots:
    void on_button_ajouter_clicked();
    void on_button_modifier_clicked();
    void on_button_supprimer_clicked();
private:
    Ui::MainWindow *ui;
    bool connectToDatabase();
    void updateTableView();
    bool validateInputs(const QString &nom, const QString &description, const QString &type,
                        const QString &telephone, const QString &lieu);
};

#endif // MAINWINDOW_H
