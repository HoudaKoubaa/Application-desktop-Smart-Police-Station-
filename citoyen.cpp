#include "citoyen.h"
#include <QString>
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include<QSqlQueryModel>

Citoyen::Citoyen()
{
 cin=0; numero_tele=0;

 nom=""; prenom=""; daten=""; sexe=""; remarque="";

}
Citoyen::Citoyen(int cin ,QString nom ,QString prenom ,int numero_tele ,QString daten ,QString sexe ,QString remarque){

    this->cin=cin;
    this->nom=nom;
    this->prenom=prenom;
    this->numero_tele=numero_tele;
    this->daten=daten;
    this->sexe=sexe;
    this->remarque=remarque;
}


int Citoyen::getCin(){return cin;}
QString Citoyen::getnom(){return nom;}
QString Citoyen::getprenom(){return prenom;}
int Citoyen::getnumero_tele(){return numero_tele;}
QString Citoyen::getdaten(){return daten;}
QString Citoyen::getsexe(){return sexe;}
QString Citoyen::getremarque(){return remarque;}

void Citoyen::setCin(int cin){this->cin=cin;}
void Citoyen::setnom(QString nom){this->nom=nom;}
void Citoyen::setprenom(QString prenom){this->prenom=prenom;}
void Citoyen::setnumero_tele(int numero_tele){this->numero_tele=numero_tele;}
void Citoyen::setdaten(QString daten){this->daten=daten;}
void Citoyen::setsexe(QString sexe){this->sexe=sexe;}
void Citoyen::setremarque(QString remarque){this->remarque=remarque;}


/**************************************************************************/

bool Citoyen::ajouter(){
    QSqlQuery query;
     QString cin_string = QString::number(cin);
     QString numero_tele_string = QString::number(numero_tele);
     query.prepare("INSERT INTO citoyen (cin, nom, prenom, numero_tele, daten, sexe ,remarque) "
                            "VALUES (:cin, :nom, :prenom, :numero_tele, :daten, :sexe, :remarque)");
             query.bindValue(":cin", cin_string);
             query.bindValue(":nom", nom);
             query.bindValue(":prenom", prenom);
             query.bindValue(":numero_tele", numero_tele_string);
             query.bindValue(":daten", daten);
             query.bindValue(":sexe", sexe);
             query.bindValue(":remarque", remarque);
             return query.exec();
}

/*********************************************************************/

QSqlQueryModel* Citoyen::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();

         model->setQuery("SELECT * FROM citoyen");
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
         model->setHeaderData(3, Qt::Horizontal, QObject::tr("numero_tele"));
         model->setHeaderData(4, Qt::Horizontal, QObject::tr("daten"));
         model->setHeaderData(5, Qt::Horizontal, QObject::tr("sexe"));
         model->setHeaderData(6, Qt::Horizontal, QObject::tr("remarque"));

         return model;

}

/************************************************************************/

bool Citoyen::supprimer(int cin)
{
    QSqlQuery query;
    query.prepare("Delete from Citoyen where cin=:cin ");
     query.bindValue(0, cin);

     return query.exec();
}




/************************************************************************/

bool Citoyen::modifier(int cin)
{
    QSqlQuery query;

     QString cin_string = QString::number(cin);
     QString numero_tele_string = QString::number(numero_tele);

    query.prepare("UPDATE Citoyen set nom='"+nom+"',prenom='"+prenom+"',numero_tele='"+numero_tele_string+"',daten='"+daten+"',sexe='"+sexe+"',remarque='"+remarque+"' WHERE cin LIKE '"+cin_string+"' ");

      query.bindValue(":cin",cin);
       query.bindValue(":nom",nom);
       query.bindValue(":prenom",prenom);
       query.bindValue(":daten",daten);
       query.bindValue(":sexe",sexe);
       query.bindValue(":numero_tele",numero_tele);
       query.bindValue(":remarque",remarque);




   return query.exec();

}


/*************************************************************************/

QSqlQueryModel * Citoyen::AfficherTrieNom()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM citoyen ORDER BY nom");

    model->setHeaderData(3,Qt::Horizontal,QObject::tr("grade"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom_emp"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom_emp"));
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("cin_emp"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("date_naissance"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("mot_de_passe"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("email"));
    return model;
}
/**************************************************************************/


QSqlQueryModel * Citoyen::rechercherNom(QString nom)
{
    QSqlQueryModel *model= new QSqlQueryModel();
    QSqlQuery q;
    q.prepare("select * from citoyen where nom like '"+nom+"%' or cin LIKE '"+nom+"%'");
    q.addBindValue("%"+ nom +"%");
    q.exec();
    model->setQuery(q);
    return (model);

}
