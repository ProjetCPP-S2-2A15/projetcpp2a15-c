#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>

class loginwindow: public QWidget {
    Q_OBJECT

public:
    explicit loginwindow(QWidget *parent = nullptr);

private:
    QLineEdit *emailInput;
    QLineEdit *passwordInput;

private slots:
    void checkLogin(); // À définir plus tard
};

#endif // LOGINWINDOW_H
