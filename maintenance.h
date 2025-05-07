#ifndef MAINTENANCE_H
#define MAINTENANCE_H

#include <QString>
#include <QDate>

class Maintenance
{
public:
    Maintenance();
    Maintenance(int id, const QString &desc, const QString &type,
                const QString &cat, const QDate &date, const QString &stat,
                int id_tech, const QString &email, int tel, int id_serv);

    // Getters
    int getIdMaintenance() const;
    QString getDescription() const;
    QString getTypeMaintenance() const;
    QString getCategorie() const;
    QDate getDateMaintenance() const;
    QString getStatut() const;
    int getIdTechnicien() const;
    QString getEmailTechnicien() const;
    int getNumeroTelephone() const;
    int getIdService() const;

    // Setters
    void setIdMaintenance(int id);
    void setDescription(const QString &desc);
    void setTypeMaintenance(const QString &type);
    void setCategorie(const QString &cat);
    void setDateMaintenance(const QDate &date);
    void setStatut(const QString &stat);
    void setIdTechnicien(int id);
    void setEmailTechnicien(const QString &email);
    void setNumeroTelephone(int tel);
    void setIdService(int id);

    // CRUD Operations
    bool addMaintenance() const;
    bool updateMaintenance() const;
    static bool deleteMaintenance(int id);  // Changed to static
    static QList<Maintenance> getAllMaintenance();
    static Maintenance getMaintenance(int id);

private:
    int id_maintenance;
    QString description;
    QString type_maintenance;
    QString categorie;
    QDate date_maintenance;
    QString statut;
    int id_technicien;
    QString email_technicien;
    int numero_telephone;
    int id_service;
};

#endif // MAINTENANCE_H
