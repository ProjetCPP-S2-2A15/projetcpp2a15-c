#include "employee.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QDate>
#include <QDebug>

Employee::Employee(int id, const QString &name, const QString &lastName, const QString &position, double salary,
                   const QString &status, const QString &address, const QString &role, const QDate &hireDate)
    : m_id(id), m_name(name), m_lastName(lastName), m_position(position), m_salary(salary),
    m_status(status), m_address(address), m_role(role), m_hireDate(hireDate)
{}

bool Employee::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO EMPLOYEE (ID_EMPLOYE, NOM, PRENOM, POSTE, SALAIRE, STATUS, ADRESSE, ROLE, DATE_E) "
                  "VALUES (:id, :nom, :prenom, :poste, :salaire, :status, :adresse, :role, :date_e)");
    query.bindValue(":id", m_id);
    query.bindValue(":nom", m_name);
    query.bindValue(":prenom", m_lastName);
    query.bindValue(":poste", m_position);
    query.bindValue(":salaire", m_salary);
    query.bindValue(":status", m_status);
    query.bindValue(":adresse", m_address);
    query.bindValue(":role", m_role);
    query.bindValue(":date_e", m_hireDate);

    if (query.exec()) {
        return true;
    } else {
        qDebug() << "Erreur d'ajout d'employé:" << query.lastError();
        return false;
    }
}

bool Employee::modifier()
{
    QSqlQuery query;
    query.prepare("UPDATE EMPLOYEE SET NOM = :nom, PRENOM = :prenom, POSTE = :poste, SALAIRE = :salaire, "
                  "STATUS = :status, ADRESSE = :adresse, ROLE = :role, DATE_E = :date_e WHERE ID_EMPLOYE = :id");
    query.bindValue(":id", m_id);
    query.bindValue(":nom", m_name);
    query.bindValue(":prenom", m_lastName);
    query.bindValue(":poste", m_position);
    query.bindValue(":salaire", m_salary);
    query.bindValue(":status", m_status);
    query.bindValue(":adresse", m_address);
    query.bindValue(":role", m_role);
    query.bindValue(":date_e", m_hireDate);

    if (query.exec()) {
        return true;
    } else {
        qDebug() << "Erreur de modification d'employé:" << query.lastError();
        return false;
    }
}

bool Employee::supprimer()
{
    QSqlQuery query;
    query.prepare("DELETE FROM EMPLOYEE WHERE ID_EMPLOYE = :id");
    query.bindValue(":id", m_id);

    if (query.exec()) {
        return true;
    } else {
        qDebug() << "Erreur de suppression d'employé:" << query.lastError();
        return false;
    }
}
