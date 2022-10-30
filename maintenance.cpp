#include "maintenance.h"
#include<QSqlQuery>
#include<QDebug>
#include<QDateTime>
#include <QtPrintSupport/QPrintDialog>
#include<QtPrintSupport/QPrinter>

#include <QPrinter>
#include <QPrintDialog>

#include<mainwindow.h>
Maintenance::Maintenance()
{


 this->matricule="";
 this->type="";
 this->etat="";
 this->cout="";


}

Maintenance::Maintenance (QString matricule,QString type,QString cout,QString etat,QDateTime datepanne)
 {
     this->matricule=matricule;

     this->type=type;
       this->cout=cout;
    this->etat=etat;
     this->datepanne=datepanne;


 }



QString Maintenance:: getmatricule(){

   return matricule;
 }

QString Maintenance::gettype()
 {
       return type;
 }

QString Maintenance::getcout()
 {
       return cout;
 }
QString Maintenance::getetat()
 {
       return etat;
 }


QDateTime Maintenance::getDatepanne()
 {
       return datepanne;
 }


void Maintenance::setmatricule(QString matricule){
    this->matricule=matricule;
}
void Maintenance::settype(QString type){
    this->type=type;
}

void Maintenance::setcout(QString cout){
    this->cout=cout;
}

void Maintenance::setetat(QString etat){
    this->etat=etat;
}


void Maintenance::setDatepanne(QDateTime datepanne){
    this->datepanne=datepanne;
}



bool Maintenance::ajouterMaintenance()
{
    QSqlQuery query;



    //prepare() prend la requête en paramétre pour la préparer a l'exécution
    query.prepare("insert into Maintenance(matricule,type,cout,etat,datepanne)""values(:matricule,:type,:cout,:etat,:datepanne)");

    //Création des variables liées
    query.bindValue(":matricule",matricule);
    query.bindValue(":type",type);
    query.bindValue(":cout",cout);
    query.bindValue(":etat",etat);
    query.bindValue(":datepanne",datepanne);


    return query.exec();//exec() envoie la requête pour l'exécution
}

QSqlQueryModel * Maintenance::afficherMaintenance()
{

QSqlQueryModel * model=new QSqlQueryModel();
model->setQuery("select * from Maintenance");


return model;

}

bool Maintenance::supprimerMaintenance(int matricule)
{
           QSqlQuery query;


           query.prepare("Delete from Maintenance where matricule=:matricule");
query.bindValue("matricule=",matricule);
           return query.exec();
}




QSqlQueryModel * Maintenance::AfficherTriecout()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM Maintenance ORDER BY cout");

    return model;
}



QSqlQueryModel * Maintenance::recherchermatricule(QString matricule)
{
    QSqlQueryModel *model= new QSqlQueryModel();
    QSqlQuery q;
    q.prepare("select * from Maintenance where matricule like ?");
    q.addBindValue("%"+ matricule +"%");
    q.exec();
    model->setQuery(q);
    return (model);
}


QString Maintenance:: apercu_pdf()
 {
    QString text="          ****** Les Maintenances  ******      \n \n " ;
     QSqlQuery query ;
     QString i,x,z,a,b;
QString p="%p%";

      query.exec("select * from Maintenance left join VEHICULEM on VEHICULEM.matricule=Maintenance.matricule ");
      while (query.next())
      {
         i=query.value(0).toString();
         x=query.value(3).toString();
         z=query.value(2).toString();
         a=query.value(4).toString();
         b=query.value(1).toString();

if((a!=p) && (a!="0%")){
        text += "\n Maintenance matricule : "+i+"\n\n - type : "+ x+"\n - cout : "+ z+"\n - etat:"+a+"\n - datepanne :"+b+"\n" ;
}

     }

             return text ;
 }



