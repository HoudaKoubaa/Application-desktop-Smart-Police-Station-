#include "nvcompte.h"

nvcompte::nvcompte()
{
nom="";
email="";
tel=0;
code="";
}
nvcompte::nvcompte( QString nom,QString email ,int tel ,QString mdp,QString code)
{
    this->nom=nom;
    this->email=email;
    this->mdp=mdp;
    this->tel=tel;
    this->code=code;

}

//getters

QString nvcompte::getNom()
   {
    return nom;
   }
QString nvcompte::getEmail()
   {
    return email;
   }

int nvcompte::getTel()
   {
    return tel;
   }
QString nvcompte::getMdp()
   {
    return mdp;
   }
void nvcompte ::setNom(QString nom)
{
    this->nom=nom;
}
void nvcompte ::setEmail(QString email)
{
    this->email=email;
}

void nvcompte ::setMdp(QString mdp)
{
    this->mdp=mdp;
}

void nvcompte ::setTel(int tel)
{
    this->tel=tel;
}
void nvcompte ::setCode(QString code)
{
    this->code=code;
}

bool nvcompte::ajouter()
{
    QSqlQuery query;


     //prepare() prend la requête en paramétre pour la préparer a l'exécution
    query.prepare("insert into USERS(username,password,tel,code,email)""values(:nom, :mdp , :tel, :code, :email)");

    //Création des variables liées

    query.bindValue(":nom",nom);
    query.bindValue(":email",email);
   query.bindValue(":tel",tel);
   query.bindValue(":code",code);
   query.bindValue(":mdp",mdp);
    return query.exec();//exec() envoie la requête pour l'exécution
}
