#include "employes.h"
#include<QSqlQuery>
#include<QDebug>


Employes::Employes()
{

 this->cin=0;
 this->nom="";
 this->prenom="";
 this->grade="";
 this->mdp="";
 this->email="";

}

Employes::Employes(int cin ,QString nom,QString prenom,QString grade,QDateTime date,QString mdp,QString email)
 {
     this->cin=cin;
     this->nom=nom;
     this->prenom=prenom;
     this->grade=grade;
     this->date=date;
     this->mdp=mdp;
     this->email=email;

 }

int Employes::getId()
 {
     return cin;
 }

QString Employes:: getNom(){

   return nom;
 }

QString Employes::getPrenom()
 {
       return prenom;
 }

QString Employes::getEmail()
 {
       return email;
 }
QString Employes::getMdp()
 {
       return mdp;
 }
QString Employes::getGrade()
 {
       return grade;
 }
QDateTime Employes::getDate()
 {
       return date;
 }


void Employes ::setId(int id)
{
    this->cin=id;
}

void Employes::setNom(QString nom)
{
    this->nom=nom;
}

void Employes::setPrenom(QString prenom){
    this->prenom=prenom;
}

void Employes::setGrade(QString grade){
    this->grade=grade;
}

void Employes::setEmail(QString email){
    this->email=email;
}

void Employes::setDate(QDateTime date){
    this->date=date;
}

void Employes::setMdp(QString mdp){
    this->mdp=mdp;
}


bool Employes::ajouterEmployes()
{
    QSqlQuery query;
    QString res = QString::number(cin);

    //prepare() prend la requête en paramétre pour la préparer a l'exécution
    query.prepare("insert into Employes(cin_emp,nom_emp,prenom_emp,grade,date_naissance,mot_de_passe,email)""values(:cin_emp,:nom_emp,:prenom_emp,:grade,:date_naissance,:mot_de_passe,:email)");

    //Création des variables liées
    query.bindValue(":cin_emp",res);
    query.bindValue(":nom_emp",nom);
    query.bindValue(":prenom_emp",prenom);
    query.bindValue(":grade",grade);
    query.bindValue(":date_naissance",date);
    query.bindValue(":mot_de_passe",mdp);
    query.bindValue(":email",email);

    return query.exec();//exec() envoie la requête pour l'exécution
}

QSqlQueryModel * Employes::afficherEmployes()
{

QSqlQueryModel * model=new QSqlQueryModel();
model->setQuery("select * from employes");
return model;

}

bool Employes::supprimerEmployes(int idA)
{



                      QSqlQuery query;
                      QSqlQuery query1;
                                 int b=0;
                                 QString res=QString::number(idA);

                                 query1.prepare("SELECT cin_emp FROM Employes WHERE cin_emp=:idA");
                                            query1.bindValue(":idA",res);
                                            query1.exec();
                                            while(query1.next())
                                            {
                                                b++;
                                            }

                                            if (b!=0)
                                            {

                                 query.prepare("Delete from conge where cin_emp=:idA");
                                 query.bindValue(":idA",res);
                                 query.exec();

                                 query.prepare("Delete from employes where cin_emp=:idA");
                                 query.bindValue(":idA",res);
                                 return query.exec();}
                                            else
                                                       {
                                                           return false;
                                                       }
}

bool Employes::modifierEmployes()
{
    QSqlQuery query ;
    QSqlQuery query1;
    int b=0;
    QString res = QString::number(cin);

    query1.prepare("SELECT cin_emp FROM Employes WHERE cin_emp=:idA");
               query1.bindValue(":idA",res);
               query1.exec();
               while(query1.next())
               {
                   b++;
               }

               if (b!=0)
               {

    query.prepare("UPDATE employes set cin_emp=:cin_emp,nom_emp=:nom_emp,prenom_emp=:prenom_emp,grade=:grade,date_naissance=:date_naissance,mot_de_passe=:mot_de_passe,email=:email WHERE cin_emp=:cin_emp");

    //Création des variables liées
    query.bindValue(":cin_emp",res);
    query.bindValue(":nom_emp",nom);
    query.bindValue(":prenom_emp",prenom);
    query.bindValue(":grade",grade);
    query.bindValue(":date_naissance",date);
    query.bindValue(":mot_de_passe",mdp);
    query.bindValue(":email",email);
    return query.exec();}
    else
               {
                   return false;
               }
}


QSqlQueryModel * Employes::AfficherTrieCIN()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM Employes ORDER BY grade");
    return model;
}


QSqlQueryModel * Employes::AfficherTrieNom()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM employes ORDER BY nom_emp");
    return model;
}


QSqlQueryModel * Employes::AfficherTrieDate()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM employes ORDER BY date_naissance");
    return model;
}


QSqlQueryModel * Employes::rechercherCIN(QString cin)
{
    QSqlQueryModel *model= new QSqlQueryModel();
    QSqlQuery q;
    q.prepare("select * from employes where cin_emp like ?");
    q.addBindValue("%"+ cin +"%");
    q.exec();
    model->setQuery(q);
    return (model);
}


QSqlQueryModel * Employes::rechercherNom(QString nom)
{
    QSqlQueryModel *model= new QSqlQueryModel();
    QSqlQuery q;
    q.prepare("select * from employes where nom_emp like ?");
    q.addBindValue("%"+ nom +"%");
    q.exec();
    model->setQuery(q);
    return (model);

}

QSqlQueryModel * Employes::rechercherGrade(QString nom)
{
    QSqlQueryModel *model= new QSqlQueryModel();
    QSqlQuery q;
    q.prepare("select * from employes where grade like ?");
    q.addBindValue("%"+ nom +"%");
    q.exec();
    model->setQuery(q);
    return (model);

}


QString Employes:: apercu_pdf()
 {
    QString text="          **** Les employes  ****      \n \n " ;
     QSqlQuery query ;
     QString i,x,z,a,b,c,d,h,h1,h2,h3;


      query.exec("select * from employes left join conge on conge.cin_emp=employes.cin_emp ");
      while (query.next())
      {
         i=query.value(0).toString();
         x=query.value(1).toString();
         z=query.value(2).toString();
         a=query.value(3).toString();
         b=query.value(4).toString();
         c=query.value(5).toString();
         d=query.value(6).toString();
         h=query.value(7).toString();
         h1=query.value(8).toString();
         h2=query.value(9).toString();
         h3=query.value(10).toString();


        text += "\n Employe Id : "+i+"\n\n - Nom : "+ x+"\n - prenom : "+ z+"\n - grade:"+a+"\n - date_naissance :"+b+"\n - mot_de_passe : "+c+"\n - email:"+d+"_______\n\n Conge Id:"+h+"\n" "\n -Id conge:"+h1+"\n" " -Debut conge:"+h2+"\n" " -Fin conge:"+h3+"\n"  ;


     }


             return text ;
 }

