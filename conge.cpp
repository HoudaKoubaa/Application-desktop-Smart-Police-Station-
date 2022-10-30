#include "conge.h"

Conge::Conge()
{
        id_conge=0;
        id_emp=0;

}

Conge::Conge(int id_conge ,QDateTime debut ,QDateTime fin,int id_emp)
 {
     this->id_conge=id_conge;
     this->debut_conge=debut;
     this->fin_conge=fin;
     this->id_emp=id_emp;
 }


int Conge::getId_conge()
 {
     return id_conge;
 }

int Conge::getId_emp()
 {
     return id_emp;
 }


QDateTime Conge:: getDebut_conge(){

   return debut_conge;
 }

QDateTime Conge:: getFin_conge(){

   return fin_conge;
 }


void Conge ::setId_conge(int id)
{
    this->id_conge=id;
}

void Conge ::setId_emp(int id)
{
    this->id_emp=id;

}

void Conge ::setDebut_conge(QDateTime debut)
{
    this->debut_conge=debut;

}

void Conge ::setFin_conge(QDateTime fin)
{
    this->fin_conge=fin;

}



bool Conge::ajouterConge()
{
    QSqlQuery query;
    QString res1 = QString::number(id_conge);
    QString res2 = QString::number(id_emp);

    //prepare() prend la requête en paramétre pour la préparer a l'exécution
    query.prepare("insert into conge(id_conge,debut_conge,fin_conge,cin_emp)""values(:id_conge,:debut_conge,:fin_conge,:cin_emp)");

    //Création des variables liées
    query.bindValue(":id_conge",res1);
    query.bindValue(":debut_conge",debut_conge);
    query.bindValue(":fin_conge",fin_conge);
    query.bindValue(":cin_emp",res2);
    return query.exec();//exec() envoie la requête pour l'exécution
}


QSqlQueryModel * Conge::afficherConge()
{

QSqlQueryModel * model=new QSqlQueryModel();
model->setQuery("select * from conge");

return model;

}


bool Conge::supprimerConge(int idA)
{
    QSqlQuery query;
    QSqlQuery query1;
    int b=0;
    QString res=QString::number(idA);
    query1.prepare("SELECT id_conge FROM conge WHERE id_conge=:idA");
               query1.bindValue(":idA",res);
               query1.exec();
               while(query1.next())
               {
                   b++;
               }

               if (b!=0)
               {
    query.prepare("Delete from conge where id_conge=:idA");
    query.bindValue(":idA",res);
    return query.exec();}
               else
                          {
                              return false;
                          }
}

bool Conge::modifierConge()
{
    QSqlQuery query;
    QSqlQuery query1;
               int b=0;
    QString res1 = QString::number(id_conge);
    QString res2 = QString::number(id_emp);
    query1.prepare("SELECT id_conge FROM conge WHERE id_conge=:idA");
               query1.bindValue(":idA",res1);
               query1.exec();
               while(query1.next())
               {
                   b++;
               }

               if (b!=0)
               {


    query.prepare("UPDATE conge set id_conge = :id_conge,debut_conge = :debut_conge,fin_conge=:fin_conge, cin_emp = :cin_emp WHERE id_conge =:id_conge");
    //Création des variables liées
    query.bindValue(":id_conge",res1);
    query.bindValue(":debut_conge",debut_conge);
    query.bindValue(":fin_conge",fin_conge);
    query.bindValue(":cin_emp",res2);

    return query.exec();}
               else
                          {
                              return false;
                          }
}



QSqlQueryModel * Conge::AfficherTrieID()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM conge ORDER BY id_conge");

    return model;
}

QSqlQueryModel * Conge::AfficherTrieIDE()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM conge ORDER BY cin_emp");

    return model;
}

QSqlQueryModel * Conge::AfficherTrieDate_debut()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM conge ORDER BY debut_conge");


    return model;
}


QSqlQueryModel * Conge::rechercherID(QString cin)
{
    QSqlQueryModel *model= new QSqlQueryModel();
    QSqlQuery q;
    q.prepare("select * from conge where id_conge like ?");
    q.addBindValue("%"+ cin +"%");
    q.exec();
    model->setQuery(q);
    return (model);
}

QSqlQueryModel * Conge::rechercherID_emp(QString cin)
{
    QSqlQueryModel *model= new QSqlQueryModel();
    QSqlQuery q;
    q.prepare("select * from conge where cin_emp like ?");
    q.addBindValue("%"+ cin +"%");
    q.exec();
    model->setQuery(q);
    return (model);
}

