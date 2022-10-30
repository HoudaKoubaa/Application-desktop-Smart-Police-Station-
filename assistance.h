#ifndef ASSISTANCE_H
#define ASSISTANCE_H
#include <QString>
#include<QSqlQueryModel>
#include<QDate>
#include<QtPrintSupport/QPrinter>
#include<QtPrintSupport/QPrintDialog>

class Assistance
{
public:
    Assistance();
    Assistance(int, QString, QString, int, QString, QString);
    int getcinAssis();
    int getnumeroAssis();
    QString getdateConsultation();
    QString getnomAssis();
    QString getprenomAssis();
    QString gettypeConsultation();

    void setcinAssis(int);
    void setnumeroAssis(int);
    void setdateConsultation(QString);

    void setnomAssis(QString);
    void setprenomAssis(QString);
    void settypeConsultation(QString);

    bool ajouter_consultation();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier(int);

    QSqlQueryModel * AfficherTrieNom();
    QSqlQueryModel * rechercherNom(QString);

    QSqlQueryModel * affecter_citoyen();

private:
    int CIN_assis, numero_assis;

    QString nom_assis, prenom_assis, type_consultation, date_consultation ;
};

#endif // ASSISTANCE_H
