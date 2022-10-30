#include "sign.h"
#include "ui_sign.h"
#include "nvcompte.h"
#include "acceuil.h"

sign::sign(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sign)
{
    ui->setupUi(this);
}

sign::~sign()
{
    delete ui;
}

void sign::on_pushButton_clicked()
{
    notification no;
       // player->setMedia(QUrl::fromLocalFile("C:/Users/houda/Desktop/music1/son.wav"));
       // player->play();
        //qDebug() << player->errorString();
        //Récuprération des informations saisies dans les 3 champs

         int tel=ui->tel_2->text().toInt(); //convertir une chaine de caractére en un entier

        QString nom=ui->nom->text();
        QString mdp=ui->mdp->text();
        QString email=ui->sec->text();
        QString code=ui->sec->text();



        //tester les conditions :
        //bool test2;
       // test2=(controleEmail(email)&&controleVide(nom)&&controleVide(prenom)&&controleVide(email)&&controleVideInt(tel)&&controleVideInt(cin)&&controleVideInt(id) );
        nvcompte nv(nom,mdp,tel,code,email);
        //insérer l'objet etudiant instancié dans la table etudiant et recuperer la valeur de retour de query.exec();
        bool test =nv.ajouter();
            if(test)//si requête executée ==>QMessageBox::information
            {

                QMessageBox::information(nullptr,QObject::tr("ok"),
                QObject::tr("Ajout effectué \n Click Cancel to exit."), QMessageBox::Cancel);
                no.ajout_notification();
               sign s;
               s.show();
            }

            else //si requête non exécutée ==>QMessageBox::critical
                QMessageBox::critical(nullptr,QObject::tr("Not Ok"),
                                      QObject::tr("Ajout non effectué. \n ""Click Cancel to exit."),QMessageBox::Cancel);
}
