#ifndef EMPLOYES_H
#define EMPLOYES_H
#include<QString>
#include <QSqlQuery>
#include <QDateTime>
#include <QSqlQueryModel>
#include <QPrinter>
#include <QPrintDialog>


class Maintenance
{
public:
    Maintenance(); // non parametré
    Maintenance(QString,QString,QString,QString,QDateTime);// constructeur parametrée

    //getters

    QString getmatricule();
    QString gettype();
    QString getcout();
    QString getetat();
    QDateTime getDatepanne();


    //Setters
    void setmatricule(QString);
    void settype(QString);
    void setcout(QString);
      void setetat(QString);
    void setDatepanne(QDateTime);


    bool ajouterMaintenance();
    QSqlQueryModel * afficherMaintenance();
    bool supprimerMaintenance(int);
    bool modifierMaintenance ();


    //Métiers

    QSqlQueryModel * AfficherTriecout();

    QSqlQueryModel * recherchermatricule(QString);

 QString  apercu_pdf();

private:
    QString matricule,type,etat,cout;
    QDateTime datepanne;
};

#endif // EMPLOYES_H
