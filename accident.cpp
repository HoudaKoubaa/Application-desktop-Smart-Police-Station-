#include "accident.h"
#include<QSqlQuery>
#include<QDebug>


accident::accident()
{
id=0;
mat="";
email="";
cina=0;
tel=0;
mat2="";
localisation="";
consequence="";
genre="";
vitesse=0;
intensite="";
etat="";
eclairage="";
}
accident::accident(int id,QString mat,QString email,int cina,int tel,QString mat2,QString localisation,QString consequence,QString genre,int vitesse,QString intensite,QString etat,QString eclairage,QDateTime date)
{
    this->id=id;
    this->mat=mat;
    this->email=email;
    this->cina=cina;
    this->tel=tel;
    this->mat2=mat2;
    this->localisation=localisation;
    this->consequence=consequence;
    this->genre=genre;
    this->vitesse=vitesse;
    this->intensite=intensite;
    this->etat=etat;
    this->eclairage=eclairage;
    this->date=date;

}

int accident::getId()
   {
    return id;
   }
QString accident:: getMat(){

  return mat;
}
QString accident:: getEmail(){

  return email;
}
int accident::getCina()
   {
    return cina;
   }
int accident::getTel()
   {
    return tel;
   }
QString accident:: getMat2(){

  return mat2;
}

QString accident:: getLocalisation(){

  return localisation;
}


QString accident:: getConsequence(){

  return consequence;
}
QString accident:: getGenre(){

  return genre;
}
int accident::getVitesse()
   {
    return vitesse;
   }
QString accident:: getIntensite()
{
  return intensite;
}
QString accident:: getEtat(){

  return etat;
}
QString accident:: getEclairage(){

  return eclairage;

}

void accident::setDate(QDateTime date)
{
    this->date=date;
}
//setters

void accident ::setId(int id)
{
    this->id=id;
}
void accident::setMat(QString mat)
{
    this->mat=mat;
}
void accident::setEmail(QString email){
    this->email=email;
}

void accident ::setCina(int cina)
{
    this->cina=cina;
}
void accident ::setTel(int tel)
{
    this->tel=tel;
}
void accident::setMat2(QString mat2)
{
    this->mat2=mat2;
}

void accident::setLocalisation(QString localisation)
{
    this->localisation=localisation;
}
void accident::setConsequence(QString consequence)
{
    this->consequence=consequence;
}
void accident::setGenre(QString genre)
{
    this->genre=genre;
}
void accident ::setVitesse(int vitesse)
{
    this->vitesse=vitesse;
}
void accident ::setIntensite(QString intensite)
{
    this->intensite=intensite;
}
void accident ::setEtat(QString etat)
{
    this->etat=etat;
}
void accident ::setEclairage(QString eclairage)
{
    this->eclairage=eclairage;
}
QDateTime accident::getDate()
 {
       return date;
 }
bool accident::ajouter()
{
    QSqlQuery query;


    //prepare() prend la requête en paramétre pour la préparer a l'exécution
    query.prepare("insert into TRAFFICS_DES_ACCIDENTS(ID_ACCIDENT,MATRICULE,CIN_ACC,EMAIL_ACC,TEL_ACC,NUM_MATRICULE,DATE_ACCIDENT,ADRESSE_ACC,VITESSE_ACC,INTENSITE_ACC,ETAT_ACC,ECLAIRAGE_ACC,CONSE_ACC,GENRE_ACC)""values(:id,:mat,:cina,:email,:tel,:mat2,:date,:localisation,:vitesse,:intensite,:etat,:eclairage,:consequence,:genre)");

    //Création des variables liées
    query.bindValue(":id",id);
    query.bindValue(":mat",mat);
    query.bindValue(":cina",cina);
    query.bindValue(":email",email);
    query.bindValue(":tel",tel);
    query.bindValue(":mat2",mat2);
    query.bindValue(":date",date);
    query.bindValue(":localisation",localisation);
    query.bindValue(":vitesse",vitesse);
    query.bindValue(":intensite",intensite);
    query.bindValue(":etat",etat);
    query.bindValue(":eclairage",eclairage);
    query.bindValue(":consequence",consequence);
    query.bindValue(":genre",genre);

    return query.exec();//exec() envoie la requête pour l'exécution
}

QSqlQueryModel * accident::afficher2()
{
QSqlQueryModel * model=new QSqlQueryModel();
model->setQuery("select * from TRAFFICS_DES_ACCIDENTS");
model->setHeaderData(3,Qt::Horizontal,QObject::tr("email"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("matricule"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("cin"));
model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
model->setHeaderData(4,Qt::Horizontal,QObject::tr("tel"));
model->setHeaderData(5,Qt::Horizontal,QObject::tr("matricule dommagé"));
model->setHeaderData(6,Qt::Horizontal,QObject::tr("date"));
model->setHeaderData(7,Qt::Horizontal,QObject::tr("Localisation"));
model->setHeaderData(8,Qt::Horizontal,QObject::tr("vitesse"));
model->setHeaderData(9,Qt::Horizontal,QObject::tr("vitesse"));
                        return model;
}

//Pour tel de SMS
QSqlQueryModel * accident::afficher3()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT TEL_ACC FROM TRAFFICS_DES_ACCIDENTS");

return model;
}

QSqlQueryModel * accident::AfficherTrieDate()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM TRAFFICS_DES_ACCIDENTS ORDER BY cin");

    model->setHeaderData(3,Qt::Horizontal,QObject::tr("cin"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom_emp"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("matricule"));
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("email"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("tel"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("matricule2"));
    model->setHeaderData(7,Qt::Horizontal,QObject::tr("date"));
    model->setHeaderData(8,Qt::Horizontal,QObject::tr("localisation"));
    model->setHeaderData(9,Qt::Horizontal,QObject::tr("vitesse"));
    return model;
}
QSqlQueryModel * accident::rechercherCIN(QString cin)
{
    QSqlQueryModel *model= new QSqlQueryModel();
    QSqlQuery q;
    q.prepare("select * from TRAFFICS_DES_ACCIDENTS where cin_acc like ?");
    q.addBindValue("%"+ cin +"%");
    q.exec();
    model->setQuery(q);
    return (model);
}

bool accident::supprimer(int cin)
     {
    QSqlQuery query;
    QString res=QString::number(cin);
    query.prepare("Delete from TRAFFICS_DES_ACCIDENTS  where cin_acc=:cin ");
    query.bindValue(":cin",res);
    return query.exec();
      }
//*******************************PDF**************************************************************//
QString accident:: apercu_pdf()
 {
    QString text="          ** Les Declarations  **      \n \n " ;
     QSqlQuery query ;
     QString i,x,z,a,b,c,d,h,h1,h2,h3;


      query.exec("select * from TRAFFICS_DES_ACCIDENTS ");
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


        text += "\n  Id : "+i+"\n\n - Matricule : "+ x+"\n - Cin : "+ z+"\n - Email:"+a+"\n - Tel :"+b+"\n - Num_matricule : "+c+"\n - Date accident:"+d+"_______\n\n Adresse Accident:"+h+"\n" "\n -Vitesse"+h1+"\n" " -Intensite:"+h2+"\n" " -Etat:"+h3+"\n"  ;


     }


             return text ;
 }
