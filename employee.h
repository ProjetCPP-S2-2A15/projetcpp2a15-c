#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <QString>
#include <QDate>

class Employee
{
public:
    Employee(int id, const QString &name, const QString &lastName, const QString &position, double salary,
             const QString &status, const QString &address, const QString &role, const QDate &hireDate);

    bool ajouter();
    bool modifier();
    bool supprimer();

private:
    int m_id;
    QString m_name;
    QString m_lastName;
    QString m_position;
    double m_salary;
    QString m_status;
    QString m_address;
    QString m_role;
    QDate m_hireDate;
};

#endif // EMPLOYEE_H
