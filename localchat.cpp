#include "localchat.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QDate>

LocalChat::LocalChat(QObject *parent) : QObject(parent), currentState("initial")
{
}

void LocalChat::initialize()
{
    QString welcome = "Bonjour! Je suis le Mall Assistant. Je peux vous aider avec:\n\n"
                      "1. Consulter les dates de location d'un locataire\n"
                      "2. Générer un contrat\n"
                      "3. Voir les statistiques des locataires\n\n"
                      "Que souhaitez-vous faire? (Entrez le numéro correspondant)";
    emit responseReceived(welcome);
}

void LocalChat::processMessage(const QString &message)
{
    if (currentState == "initial") {
        handleInitialState(message);
    }
    else if (currentState == "awaiting_locataire_id") {
        handleAwaitingLocataireId(message);
    }
    else if (currentState == "awaiting_contrat_id") {
        handleAwaitingContratId(message);
    }
}

void LocalChat::handleInitialState(const QString &message)
{
    if (message == "1") {
        currentState = "awaiting_locataire_id";
        emit responseReceived("Quel est l'ID du locataire dont vous souhaitez consulter les dates?");
    }
    else if (message == "2") {
        currentState = "awaiting_contrat_id";
        emit responseReceived("Pour quel ID de locataire souhaitez-vous générer un contrat?");
    }
    else if (message == "3") {
        emit responseReceived(getStatistics());
        currentState = "initial";
    }
    else {
        emit responseReceived("Je n'ai pas compris. Veuillez entrer 1, 2 ou 3.");
    }
}

void LocalChat::handleAwaitingLocataireId(const QString &message)
{
    if (isValidLocataireId(message)) {
        QString dates = getLocationDates(message);
        emit responseReceived(dates);
        currentState = "initial";
        initialize();
    }
    else {
        emit responseReceived("ID de locataire invalide. Veuillez réessayer.");
    }
}

void LocalChat::handleAwaitingContratId(const QString &message)
{
    if (isValidLocataireId(message)) {
        QString contract = generateContract(message);
        emit responseReceived(contract);
        currentState = "initial";
        initialize();
    }
    else {
        emit responseReceived("ID de locataire invalide. Veuillez réessayer.");
    }
}
QString LocalChat::getLocationDates(const QString &locataireId)
{
    QSqlQuery query;
    query.prepare("SELECT NOM, DEBUT_CONTRAT, FIN_CONTRAT FROM LOCATAIRES WHERE ID_LOCATAIRE = ?");
    query.addBindValue(locataireId);

    if (query.exec() && query.next()) {
        QString nom = query.value(0).toString();
        QDate dateDebut = QDate::fromString(query.value(1).toString(), "yyyy-MM-dd");
        QDate dateFin = QDate::fromString(query.value(2).toString(), "yyyy-MM-dd");

        return QString("Informations du locataire :\n"
                       "Nom : %1\n"
                       "Début du contrat : %2\n"
                       "Fin du contrat : %3")
            .arg(nom)
            .arg(dateDebut.toString("dd/MM/yyyy"))
            .arg(dateFin.toString("dd/MM/yyyy"));
    }
    return "Aucune information trouvée pour ce locataire.";
}

QString LocalChat::generateContract(const QString &locataireId)
{
    QSqlQuery query;
    query.prepare("SELECT NOM, DEBUT_CONTRAT, FIN_CONTRAT, LOYER FROM LOCATAIRES WHERE ID_LOCATAIRE = ?");
    query.addBindValue(locataireId);

    if (query.exec() && query.next()) {
        QString nom = query.value(0).toString();
        QDate dateDebut = QDate::fromString(query.value(1).toString(), "yyyy-MM-dd");
        QDate dateFin = QDate::fromString(query.value(2).toString(), "yyyy-MM-dd");
        QString loyer = query.value(3).toString();

        return QString("CONTRAT DE LOCATION\n\n"
                       "Locataire : %1\n"
                       "Période de location : du %2 au %3\n"
                       "Montant du loyer : %4 DT\n"
                       "\nContrat généré avec succès!")
            .arg(nom)
            .arg(dateDebut.toString("dd/MM/yyyy"))
            .arg(dateFin.toString("dd/MM/yyyy"))
            .arg(loyer);
    }
    return "Impossible de générer le contrat pour ce locataire.";
}

QString LocalChat::getStatistics()
{
    QSqlQuery query("SELECT COUNT(*) FROM LOCATAIRES");
    int totalLocataires = 0;
    if (query.exec() && query.next()) {
        totalLocataires = query.value(0).toInt();
    }

    // Utilisation de la date actuelle pour comparer
    QString currentDate = QDate::currentDate().toString("yyyy-MM-dd");
    QSqlQuery activeQuery;
    activeQuery.prepare("SELECT COUNT(*) FROM LOCATAIRES WHERE FIN_CONTRAT > ?");
    activeQuery.addBindValue(currentDate);

    int locatairesActifs = 0;
    if (activeQuery.exec() && activeQuery.next()) {
        locatairesActifs = activeQuery.value(0).toInt();
    }

    return QString("Statistiques :\n"
                   "Nombre total de locataires : %1\n"
                   "Locataires actifs : %2\n"
                   "Date de consultation : %3")
        .arg(totalLocataires)
        .arg(locatairesActifs)
        .arg(QDate::currentDate().toString("dd/MM/yyyy"));
}

bool LocalChat::isValidLocataireId(const QString &id)
{
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM LOCATAIRES WHERE ID_LOCATAIRE = ?");
    query.addBindValue(id);
    return query.exec() && query.next() && query.value(0).toInt() > 0;
}
