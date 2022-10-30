#ifndef CITOYEN_H
#define CITOYEN_H
#include <QString>
#include<QSqlQueryModel>
#include<QDate>

class Citoyen
{
public:
    Citoyen();
    Citoyen(int,QString,QString,int,QString,QString,QString);

    int getCin();
    QString getnom();
    QString getprenom();
    int getnumero_tele();
    QString getdaten();
    QString getsexe();
    QString getremarque();

    void setCin(int);
    void setnom(QString);
    void setprenom(QString);
    void setnumero_tele(int);
    void setdaten(QString);
    void setsexe(QString);
    void setremarque(QString);

    bool ajouter();
     QSqlQueryModel* afficher();
     bool supprimer(int);
     bool modifier(int);

     QSqlQueryModel * tri();
     QSqlQueryModel * AfficherTrieNom();
     QSqlQueryModel * rechercherNom(QString);


private:
    int cin , numero_tele;
    QString nom, prenom, daten, sexe, remarque;


};

#endif // CITOYEN_H
