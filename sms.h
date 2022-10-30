#ifndef SMS_H
#define SMS_H
#include <QDebug>
#include <QTableView>
#include <QSqlError>
#include <QDate>
#include <QSqlQueryModel>
//#include <QtWebEngine>
class sms
{
private:
    QString tel ;
    QString objet ;
    QString message ;
    QString date_sms;
public:
    sms();
    sms(QString tel,QString objet, QString message);
    void ajoutersms(QString tel,QString objet, QString message,QString date_sms);
    QSqlQueryModel* afficherListesms(QString);
    bool supprimer_sms(QString);
    bool supprimer_sms();
    //void modifier_sms(QString);
    //QSqlQueryModel* rechercher_sms(QString);

};

#endif // SMS_H
