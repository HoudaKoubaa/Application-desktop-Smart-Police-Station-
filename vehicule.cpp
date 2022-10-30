#include "vehicule.h"
#include<QSqlQuery>
#include<QDebug>
#include <QDateTime>
#include<mainwindow.h>

Vehicule::Vehicule()
{


 this->matricule="";
 this->Type="";
 this->Nom_chauffeur="";

}

Vehicule::Vehicule(QString matricule,QString Type,QString Nom_chauffeur,QDateTime datesortie)
 {
     this->matricule=matricule;
     this->Type=Type;
     this->Nom_chauffeur=Nom_chauffeur;
     this->datesortie=datesortie;


 }




QString Vehicule:: getmatricule(){

   return matricule;
 }

QString Vehicule::getType()
 {
       return Type;
 }


QString Vehicule::getNom_chauffeur()
 {
       return Nom_chauffeur;

 }
QDateTime Vehicule::getdatesortie()
 {
       return datesortie;
 }




void Vehicule::setmatricule(QString matricule)
{
    this->matricule=matricule;
}

void Vehicule::setType(QString Type){
    this->Type=Type;
}

void Vehicule::setNom_chauffeur(QString Nom_chauffeur){
    this->Nom_chauffeur=Nom_chauffeur;
}


void Vehicule::setdatesortie(QDateTime datesortie){
    this->datesortie=datesortie;
}



bool Vehicule::ajouterVehicule()
{
    QSqlQuery query;



    //prepare() prend la requête en paramétre pour la préparer a l'exécution
    query.prepare("insert into VEHICULEM (matricule,Type,Nom_chauffeur,datesortie)""values(:matricule,:Type,:Nom_chauffeur,:datesortie)");

    //Création des variables liées
    query.bindValue(":matricule",matricule);
    query.bindValue(":Type",Type);
    query.bindValue(":Nom_chauffeur",Nom_chauffeur);
    query.bindValue(":datesortie",datesortie);


    return query.exec();//exec() envoie la requête pour l'exécution
}

QSqlQueryModel * Vehicule::afficherVehicule()
{

QSqlQueryModel * model=new QSqlQueryModel();
model->setQuery("select * from VEHICULEM");
model->setHeaderData(3,Qt::Horizontal,QObject::tr("datesortie"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("Type"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("Nom_chauffeur"));
model->setHeaderData(0,Qt::Horizontal,QObject::tr("matricule"));

return model;

}

bool Vehicule::supprimerVehicule(int)
{
           QSqlQuery query;

           query.prepare("alter table Maintenance DROP CONSTRAINT FK");
           query.exec();

           query.prepare("Delete from Maintenance where matricule=:matricule");
           query.bindValue(":matricule",matricule);
           query.exec();

           query.prepare("Delete from VEHICULEM where matricule=:matricule");
           query.bindValue(":matricule",matricule);

           return query.exec();
}

bool Vehicule::modifierVehicule()
{
    QSqlQuery query ;




  query.prepare("update VEHICULEM  set MATRICULE=:atricule,Type=:Type,datesortie=:Nom_chauffeur,datesortie=:date_sortie where MATRICULE=:matricule");
    //Création des variables liées
    query.bindValue(":matricule",matricule);
    query.bindValue(":Type",Type);
    query.bindValue(":Nom_chauffeur",Nom_chauffeur);
    query.bindValue(":datesortie",datesortie);
    return query.exec();
}


QSqlQueryModel * Vehicule::AfficherTriematricule()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM VEHICULEM ORDER BY matricule");

    model->setHeaderData(3,Qt::Horizontal,QObject::tr("datesortie"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Type"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Nom_chauffeur"));
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("matricule"));
    return model;
}





QSqlQueryModel * Vehicule::rechercherNom_chauffeur(QString Nom_chauffeur)
{
    QSqlQueryModel *model= new QSqlQueryModel();
    QSqlQuery q;
    q.prepare("select * from VEHICULEM where Nom_chauffeur like ?");
    q.addBindValue("%"+ Nom_chauffeur +"%");
    q.exec();
    model->setQuery(q);
    return (model);

}


