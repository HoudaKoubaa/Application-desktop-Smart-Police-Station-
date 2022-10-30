#ifndef EMPLOYE_H
#define EMPLOYE_H
#include<QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDateTime>

class Employes
{
public:
    Employes(); // non parametré
    Employes(int,QString,QString,QString,QDateTime,QString,QString);// constructeur parametrée

    //getters
    int getId();
    QString getNom();
    QString getPrenom();
    QString getGrade();
    QString getMdp();
    QDateTime getDate();
    QString getEmail();

    //Setters
    void setId(int);
    void setNom(QString);
    void setPrenom(QString);
    void setGrade(QString);
    void setMdp(QString);
    void setDate(QDateTime);
    void setEmail(QString);

    bool ajouterEmployes();
    QSqlQueryModel * afficherEmployes();
    bool supprimerEmployes(int);
    bool modifierEmployes ();


    //Métiers
    QSqlQueryModel * AfficherTrieCIN();
    QSqlQueryModel * AfficherTrieNom();
    QSqlQueryModel * AfficherTrieDate();

    QSqlQueryModel * rechercherCIN(QString);
    QSqlQueryModel * rechercherNom(QString);
    QSqlQueryModel * rechercherGrade(QString);
    QString  apercu_pdf();

private:
    int cin;
    QString nom,prenom,grade,mdp,email;
    QDateTime date;

};

#endif // EMPLOYE_H
