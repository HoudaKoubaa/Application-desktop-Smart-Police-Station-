#include "sms.h"
#include <QString>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlQueryModel>
#include <QDebug>
#include <QTableView>
#include <QSqlError>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include<QDate>

sms::sms()
{

}

sms::sms(QString tel,QString objet,QString message)
{
        this->tel=tel;
        this->objet=objet;
        this->message=message;
}

void sms::ajoutersms(QString tel,QString objet, QString message,QString date_sms)
{
    QSqlQuery query;

        query.prepare("INSERT INTO SMS VALUES ('"+tel+"', '"+objet+"', '"+message+"',to_date('"+date_sms+"','dd/mm/yyyy'))");


                         query.addBindValue(tel);
                         query.addBindValue(objet);
                         query.addBindValue(message);
                         query.addBindValue(date_sms);

                     if(query.exec()){
                         qDebug()<<"AJOUTER AVEC SUCCEE";
                     }
                     else
                     {qDebug()<<"ERREUR";}
                        // return true;

}
QSqlQueryModel* sms:: afficherListesms(QString tel)
{
    QSqlQueryModel *Model = new QSqlQueryModel;
    if(tel==0)
        Model->setQuery("SELECT * FROM SMS");
    else
    Model->setQuery("SELECT * FROM SMS where tel= '"+tel+"'");
            return Model;
}

bool sms:: supprimer_sms()
{
                    QSqlQuery query;
                    query.prepare("DELETE FROM SMS where 1=1");
                     return  query.exec();
}


bool sms:: supprimer_sms(QString date)
{
                    QSqlQuery query;
                    query.prepare("DELETE FROM SMS where tel =:tel");
                    query.bindValue(":tel",date);
                     return  query.exec();
}
