#ifndef NVCOMPTE_H
#define NVCOMPTE_H

#include<QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class nvcompte
{
public:
    nvcompte();
    nvcompte(QString,QString,int,QString,QString);
      //getters
      QString getNom();
      QString getEmail();
      int     getTel();
      QString getMdp();
      QString getCode();
      //setters
       void setNom(QString);
       void setEmail(QString);
       void setTel(int);
       void setMdp(QString);
       void setCode(QString);



       bool ajouter();

  private:
      int tel;
      QString nom,email,code,mdp;
};

#endif // NVCOMPTE_H
