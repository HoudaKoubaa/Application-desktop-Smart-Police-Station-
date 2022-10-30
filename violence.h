#ifndef VIOLENCE_H
#define VIOLENCE_H
#include<QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class violence
{
public:
    violence();
    violence(int,QString,QString,QString,int,int,QString,QString,QString);
    //getters
    int getId();
    QString getNom();
    QString getPrenom();
    QString getEmail();
    int getCIN();
    int getTel();
    QString getNomaccuse();
    QString getType();
    QString getAutre();


    //Setters
    void setId(int);
    void setNom(QString);
    void setPrenom(QString);
    void setEmail(QString);
    void setCin(int);
    void setTel(int);
    void setNomaccuse(QString);
    void setType(QString);
    void setAutre(QString);


    bool ajouter();
   bool modifierViolence();
    QSqlQueryModel * afficher();
    QSqlQueryModel * afficher2();
    bool supprimer_violence(int);
    QSqlQueryModel * AfficherTrieCIN();
    QSqlQueryModel * rechercherCIN(QString);

    bool controleNumTel(int test);

    bool controleVide(QString test);

    bool controleVideInt(int test);

    bool controleEmail(QString test);

private:
    int id,tel,cin;
    QString nom,prenom,email,nomaccuse,autre,type;
};

#endif // VIOLENCE_H
