#ifndef ACCIDENT_H
#define ACCIDENT_H
#include<QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDateTime>

class accident
{
public:
    accident();
    accident(int,QString,QString,int,int,QString,QString,QString,QString,int,QString,QString,QString,QDateTime);
    //getters
    int         getId();
    QString    getMat();
    QString    getEmail();
     int       getCina();
     int       getTel();
    QString    getMat2();
    QString    getLocalisation();
    QString    getConsequence();
    QString    getGenre();
    int        getVitesse();
    QString    getIntensite();
    QString    getEtat();
    QString    getEclairage();
    QDateTime getDate();
    //Setters

      void setId(int);
      void setMat(QString);
      void setEmail(QString);
      void setCina(int);
      void setTel(int);
      void setMat2(QString);
      void setLocalisation(QString);
      void setConsequence(QString);
      void setGenre(QString);
      void setVitesse(int);
      void setIntensite(QString);
      void setEtat(QString);
      void setEclairage(QString);
      void setDate(QDateTime);

      bool ajouterAccidentacc();
      bool ajouter();

      QSqlQueryModel * afficher2();
      QSqlQueryModel * afficher3();
      QSqlQueryModel * AfficherTrieDate();
      QSqlQueryModel * rechercherCIN(QString);
      bool supprimer(int);
      //bool modifierAccident ();
      QString  apercu_pdf();

    private:
    int id,cina,tel,vitesse;
    QString mat,email,mat2,localisation,consequence,genre,intensite,etat,eclairage;
    QDateTime date;
};

#endif // ACCIDENT_H
