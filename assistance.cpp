#include "assistance.h"
#include <QString>
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
Assistance::Assistance()
{
    CIN_assis=0; numero_assis=0;
    nom_assis=""; prenom_assis=""; type_consultation=""; date_consultation="";
}


Assistance::Assistance(int CIN_assis,QString nom_assis, QString prenom_assis, int numero_assis, QString date_consultation, QString type_consultation)
{   this->CIN_assis=CIN_assis;
    this->numero_assis=numero_assis;
    this->date_consultation=date_consultation;

    this->nom_assis=nom_assis;
    this->prenom_assis=prenom_assis;
    this->type_consultation=type_consultation;
}
int Assistance::getcinAssis(){return CIN_assis;}
int Assistance::getnumeroAssis(){return numero_assis;}
QString Assistance::getdateConsultation(){return date_consultation;}

QString Assistance::getnomAssis(){return nom_assis;}
QString Assistance::getprenomAssis(){return prenom_assis;}
QString Assistance::gettypeConsultation(){return type_consultation;}

void Assistance::setcinAssis(int CIN_assis){this->CIN_assis=CIN_assis;}
void Assistance::setnumeroAssis(int numero_assis){this->numero_assis=numero_assis;}
void Assistance::setdateConsultation(QString date_consultation){this->date_consultation=date_consultation;}

void Assistance::setnomAssis(QString nom_assis){this->nom_assis=nom_assis;}
void Assistance::setprenomAssis(QString prenom_assis){this->prenom_assis=prenom_assis;}
void Assistance::settypeConsultation(QString type_consultation){this->type_consultation=type_consultation;}


bool Assistance::ajouter_consultation(){

    QSqlQuery query;
    QString CIN_assis_string = QString::number(CIN_assis);
    QString numero_assis_string = QString::number(numero_assis);


    query.prepare("INSERT INTO ASSISTANCE (CIN_assis, nom_assis, prenom_assis, numero_assis, date_consultation , type_consultation) "
                  "VALUES (:cin_assis, :nom_assis,  :prenom_assis, :numero_assis, :date_consultation, :type_consultation)");

    query.bindValue(":cin_assis", CIN_assis_string);
    query.bindValue(":nom_assis", nom_assis);
    query.bindValue(":prenom_assis", prenom_assis);
    query.bindValue(":numero_assis", numero_assis_string);
    query.bindValue(":date_consultation", date_consultation);
    query.bindValue(":type_consultation", type_consultation);

    return query.exec();
}

/************************************************************/

QSqlQueryModel* Assistance::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();

         model->setQuery("SELECT * FROM ASSISTANCE");
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN_assis"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom_assis"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom_assis"));
         model->setHeaderData(3, Qt::Horizontal, QObject::tr("numero_assis"));
         model->setHeaderData(4, Qt::Horizontal, QObject::tr("date_consultation"));
         model->setHeaderData(5, Qt::Horizontal, QObject::tr("type_consultation"));


         return model;

}

/******************************************************************/


bool Assistance::supprimer(int cin)
{
    QSqlQuery query;
    query.prepare("Delete from Assistance where CIN_assis=:cin ");
     query.bindValue(0, cin);

     return query.exec();
}

/******************************************************************/

bool Assistance::modifier(int CIN_assis)
{
    QSqlQuery query;

     QString cin_string = QString::number(CIN_assis);
     QString numero_tele_string = QString::number(numero_assis);

    query.prepare("UPDATE ASSISTANCE set nom_assis='"+nom_assis+"',prenom_assis='"+prenom_assis+"',numero_assis='"+numero_tele_string+"',date_consultation='"+date_consultation+"',type_consultation='"+type_consultation+"' WHERE CIN_assis LIKE '"+cin_string+"' ");

       query.bindValue(":CIN_assis",CIN_assis);
       query.bindValue(":nom_assis",nom_assis);
       query.bindValue(":prenom_assis",prenom_assis);
       query.bindValue(":numero_assis",numero_assis);
       query.bindValue(":date_consultation",date_consultation);
       query.bindValue(":type_consultation",type_consultation);






   return query.exec();

}
/*********************************************************************/

QSqlQueryModel * Assistance ::AfficherTrieNom()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM ASSISTANCE ORDER BY nom_assis");

    model->setHeaderData(0,Qt::Horizontal,QObject::tr("CIN_assis"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom_assis"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom_assis"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("numero_assis"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("date_consultation"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("type_consultation"));

    return model;
}

/*****************************************************************************/
QSqlQueryModel * Assistance::rechercherNom(QString nom_assis)
{
    QSqlQueryModel *model= new QSqlQueryModel();
    QSqlQuery q;
    q.prepare("select * from ASSISTANCE where nom_assis LIKE '"+nom_assis+"%' or CIN_assis LIKE '"+nom_assis+"%'");
    q.addBindValue("%"+ nom_assis +"%");
    q.exec();
    model->setQuery(q);
    return (model);

}
/***************************************************************************************/

QSqlQueryModel * Assistance::affecter_citoyen()
{
    QSqlQueryModel * model= new QSqlQueryModel();

        model->setQuery("select citoyen.nom from citoyen ");

            return model;
}
