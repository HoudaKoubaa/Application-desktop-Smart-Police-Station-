#ifndef RDV_H
#define RDV_H
#include <QString>
#include<QSqlQueryModel>
#include<QDate>
#include "assistance.h"
#include "citoyen.h"
#include <QTime>
#include <QDate>
#include <QDateTime>
#include <QDateEdit>
class rdv
{
public:
    rdv();
    rdv(int, QString, QString, QDateTime, QString);

    int getId_rdv();


    void setrdv(int);


    bool ajouter();
    bool supprimer(int);
    QSqlQueryModel* afficher();




     QSqlQueryModel * affecter_citoyen();
     QSqlQueryModel * affecter_assistance();
     QSqlQueryModel * rechercherNom_citoyen();
     QSqlQueryModel * AfficherTrieId();
     QSqlQueryModel * rechercherId(QString);



private:
    int id_rdv;

    QString nom_citoyen;
    QString nom_assis;
    QDateTime date_rdv;
    QString type_rdv;
    Citoyen C;
    Assistance A;

};

#endif // RDV_H
