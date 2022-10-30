#ifndef VEHICULE_H
#define VEHICULE_H
#include<QString>
#include <QSqlQuery>
#include <QDateTime>
#include <QSqlQueryModel>


class Vehicule
{
public:
    Vehicule(); // non parametrÃ©
    Vehicule(QString,QString,QString,QDateTime);// constructeur parametrÃ©e

    //getters
    QString getmatricule();
    QString getType();
    QString getNom_chauffeur();
    QDateTime getdatesortie();
    //Setters

    void setmatricule(QString);
    void setType(QString);
    void setNom_chauffeur(QString);
    void setdatesortie(QDateTime);


    bool ajouterVehicule();
    QSqlQueryModel * afficherVehicule();
    bool supprimerVehicule(int);
    bool modifierVehicule ();

    //MÃ©tiers
    QSqlQueryModel * AfficherTriematricule();

    QSqlQueryModel * rechercherNom_chauffeur(QString);


private:

    QString matricule,Type,Nom_chauffeur;
    QDateTime datesortie;
};

#endif // VEHICULE_H
