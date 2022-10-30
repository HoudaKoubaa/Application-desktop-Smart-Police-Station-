#include "rdv.h"
#include <QString>
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include<QSqlQueryModel>
#include "assistance.h"
#include "citoyen.h"


rdv::rdv()
{
   id_rdv =0;
   nom_citoyen ="";
   nom_assis="";
   date_rdv.fromString("26.07.2015 15:35","dd.MM.yyyy HH:mm");
   type_rdv="";

}
rdv::rdv(int id_rdv , QString nom_citoyen ,QString nom_assis, QDateTime date_rdv, QString type_rdv){
    this->id_rdv=id_rdv;
    this->nom_citoyen=nom_citoyen;
    this->nom_assis=nom_assis;
    this->date_rdv=date_rdv;
    this->type_rdv=type_rdv;
}

int rdv::getId_rdv(){return id_rdv;}
void rdv::setrdv(int id_rdv){this->id_rdv=id_rdv;}






/*******************************************************************************************************/
QSqlQueryModel * rdv::affecter_citoyen()
{
    QSqlQueryModel * model= new QSqlQueryModel();

        model->setQuery("select citoyen.nom from citoyen ");

            return model;
}

/*********************************************************************************************************/

QSqlQueryModel * rdv::affecter_assistance()
{
    QSqlQueryModel * model= new QSqlQueryModel();

        model->setQuery("select assistance.nom_assis from assistance ");

            return model;
}

/***********************************************************************************************************/

/*QSqlQueryModel * rdv::rechercherNom_citoyen (QString nom)
{
    QSqlQueryModel *model= new QSqlQueryModel();
    QSqlQuery q;
    q.prepare("select nom from citoyen where cin like '"+nom+"%' ");
    q.addBindValue("%"+ nom +"%");
    q.exec();
    model->setQuery(q);
    return (model);
}*/

/*************************************************************************************************************/

bool rdv::ajouter(){
    QSqlQuery query;
    QString cin_string = QString::number(id_rdv);

     query.prepare("INSERT INTO RDV (id_rdv, nom_citoyen , nom_assis , date_rdv , type_rdv ) "
                            "VALUES (:id_rdv, :nom_citoyen, :nom_assis, :date_rdv, :type_rdv)");

             query.bindValue(":id_rdv", cin_string);
             query.bindValue(":nom_citoyen", nom_citoyen);
             query.bindValue(":nom_assis", nom_assis);
             query.bindValue(":date_rdv", date_rdv);
             query.bindValue(":type_rdv", type_rdv);

             return query.exec();
}


/**********************************************************************************************************/

QSqlQueryModel* rdv::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();

         model->setQuery("SELECT * FROM RDV");
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_rdv"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom_citoyen"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("nom_assis"));
         model->setHeaderData(3, Qt::Horizontal, QObject::tr("date_rdv"));
         model->setHeaderData(4, Qt::Horizontal, QObject::tr("type_rdv"));

         return model;

}

/****************************************************************************************************************/

bool rdv::supprimer(int id_rdv)
{
    QSqlQuery query;
    query.prepare("Delete from rdv where id_rdv=:id_rdv ");
     query.bindValue(0, id_rdv);

     return query.exec();

}

/********************************************************************************************************************/


QSqlQueryModel * rdv::AfficherTrieId()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM rdv ORDER BY id_rdv");

    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id_rdv"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom_citoyen"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("nom_assis"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("date_rdv"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("type_rdv"));

    return model;
}

/***************************************************************************************************************************/
QSqlQueryModel * rdv::rechercherId(QString recherche)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from rdv where id_rdv LIKE '"+recherche+"%' ");
    return model;

}









