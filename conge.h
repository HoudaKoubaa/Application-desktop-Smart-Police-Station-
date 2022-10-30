#ifndef CONGE_H
#define CONGE_H
#include<QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include<QDate>
#include <QDateTime>

class Conge
{
public:
    Conge();
    Conge(int,QDateTime,QDateTime,int);

    //getters
    int getId_conge();
    int getId_emp();
    QDateTime getFin_conge();
    QDateTime getDebut_conge();

    //Setters
    void setId_conge(int);
    void setId_emp(int);
    void setFin_conge(QDateTime);
    void setDebut_conge(QDateTime);

    bool ajouterConge();
    QSqlQueryModel * afficherConge();
    bool supprimerConge(int);
    bool modifierConge ();


    QSqlQueryModel * AfficherTrieID();
    QSqlQueryModel * AfficherTrieDate_debut();
    QSqlQueryModel * AfficherTrieIDE();

    QSqlQueryModel * rechercherID(QString);
    QSqlQueryModel * rechercherID_emp(QString);

private:
    int id_conge,id_emp;
    QDateTime  fin_conge,debut_conge;

};

#endif // CONGE_H

