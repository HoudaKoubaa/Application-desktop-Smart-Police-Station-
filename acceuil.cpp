#define Transparent "color:transparent;"
#include "dialogemploye.h"
#include "employes.h"
#include "conge.h"
#include<QString>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QDebug>
#include<QLineEdit>
#include <QComboBox>
#include <QPropertyAnimation>
#include"violence.h"
#include "accident.h"
#include "smtp.h"
#include "sms.h"
#include <QPrinter>
#include <QPrintDialog>
#include "ui_acceuil.h"
#include "nvcompte.h"
#include"citoyen.h"
#include "acceuil.h"
#include <QPropertyAnimation>
#include <arduino.h>

#define colorFalse "color:red;"
#define colorTrue "color:rgb(28,255,33);"
acceuil::acceuil(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::acceuil)
{

    int ret =a.connect_arduino();
        switch(ret){
        case(0): qDebug()<<"arduino is available and connected to :"<<a.getarduino_port_name();
            break ;
        case(1): qDebug()<<"arduino is available but not connected to :"<<a.getarduino_port_name();
            break ;
        case(-1): qDebug()<<"arduino is not avaialable";
        }
        QObject::connect(a.getserial(),SIGNAL(readyRead()),this,SLOT(update_label()));

    ui->setupUi(this);
    refrechir();
    player = new QMediaPlayer;

    QPropertyAnimation *animation = new QPropertyAnimation(ui->logo, "geometry");
    animation->setDuration(4000);
    animation->setStartValue(ui->logo->geometry());
    animation->setStartValue(QRect(0, 0, 100, 30));
    animation->setEasingCurve(QEasingCurve::OutBounce);
    animation->start();
}

//**************************************IMPLIMENTATION PARTIE HOUDA ****************************************//
void acceuil::refrechir()
{

    //***************************************REFECHIR( table accidents) *************************//
       ui->comboBox2->setModel(acciden.afficher2());
       ui->tabview_5->setModel(acciden.afficher2());
       ui->tabview2->setModel(acciden.afficher2());

   //***************************************REFECHIR( table Violance) *************************//
       ui->comboBox_3->setModel(etd.afficher());
       ui->tabview->setModel(etd.afficher());
       ui->tabview_2->setModel(etd.afficher());
       ui->tableView->setModel(etd.afficher());



}

acceuil::~acceuil()
{
    delete ui;
}

void acceuil::on_gestionViolance_clicked()
{
     ui->stackedWidget_3->setCurrentIndex(1);
}

void acceuil::on_gestionAccident_clicked()
{

    ui->stackedWidget_3->setCurrentIndex(0);

}



void acceuil::on_gestionAccident_2_clicked()
{
ui->stackedWidget_3->setCurrentIndex(2);

}
//***************************************NOM D'utilisateur  *********************************************//

void acceuil::Get_utilisateur()
{
    QSqlQuery qry;
    qry.prepare("SELECT username FROM USERS where username=?");
    qry.addBindValue(identifiant);

    if(qry.exec())
        if(qry.next())
            {

            QString prenom = QVariant(qry.value(0)).toString();
            qDebug()<<prenom;
QString text="bienvenu ";
qDebug()<<text;
                ui->utilisateur_nom->setText(prenom);

            }
}
//****************************************Deconnection*********************************************//
void acceuil::on_dec_clicked()
{
    QSqlDatabase db;

        QString msg=ui->utilisateur_nom->text()+" Êtes-vous sûr de déconnecter ? ";
        int ret=QMessageBox::question(this,tr("Deconnexion"),msg,QMessageBox::Ok|QMessageBox::Cancel);

        switch (ret)
        {
        case QMessageBox::Ok:
        {    db.close();
           this->close();

       }
            break;
        case QMessageBox::Cancel:
            break;
        }
}

//*************************************************TABLE ACCIIDENTS*********************************//

//************************************COMBOBOX  accidents ***********************************//

void acceuil::on_comboBox2_currentIndexChanged()
{
    QString name=ui->comboBox2->currentText();
      QSqlQuery query;

      query.prepare ("select tel_acc,email_acc  from TRAFFICS_DES_ACCIDENTS where ID_ACCIDENT='"+name+"'");
      if(query.exec())
      {
          while(query.next())
          {
              ui->tel2->setText(query.value(0).toString());
              ui->email2->setText(query.value(1).toString());
          }
      }

}
//************************************AJOUT DECLARATION ACCIDENT***********************************//

void acceuil::on_ajouter_4_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
               player->setMedia(QUrl::fromLocalFile("C:/Users/houda/Desktop/music1/son.wav"));
               player->setVolume(3000);
               player->play();
    notification no;
    //Récupré1ration des informations saisies dans les champs
    int id=ui->accid->text().toInt(); //convertir une chaine de caractére en un entier
    int tel=ui->tel->text().toInt();
    int cina=ui->LeCina->text().toInt();
    int vitesse=ui->vitesse->text().toInt();
    QString mat=ui->Mat->text();
    QString mat2=ui->Mat2->text();
    QString localisation=ui->loc->text();
    QString email=ui->Email->text();
     QDateTime date=ui->dateTimeEdit->dateTime();
     QString eclairage="";
     QString intensite="";
     QString etat="";
     QString consequence;
     QString genre;
  //test de checkbox
     //genre de route :
         if(ui->c1->isChecked())
         {
             genre="Autouroute";
         }
         if(ui->c2->isChecked())
         {
             genre="semi autouroute";
         }
         if(ui->c3->isChecked())
         {
             genre="install annexe sur autouroute";
         }
         if(ui->c4->isChecked())
         {
             genre="Route principale";
         }
         if(ui->c5->isChecked())
         {
             genre="Route seconde";
         }
         if(ui->c6->isChecked())
         {
             genre="Autre";
         }
         //consequence
           if(ui->c7->isChecked())
         {
             consequence="pas blesse";
         }
         if(ui->c8->isChecked())
         {
             consequence="Légérement blessé";
         }
         if(ui->c9->isChecked())
         {
             consequence="En danger de morts ";
         }
    //instancier un objet de la classe Etudiant en utilisant les informations saisies dans l interfaces
    accident a(id,mat,email,cina,tel,mat2,localisation,consequence,genre,vitesse,intensite,etat,eclairage,date);
    if((id==0)&&(mat==0)&&(email=="")&&(cina==0)&&(tel==0)&&(mat2==0))
          {
              QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                          QObject::tr("Attention!! Les champs sont vides , Veuillez les remplir"), QMessageBox::Ok);

           }

    else if(cina == 0)

     {
         QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                     QObject::tr("Veuillez Vérifier le numéro de CIN"), QMessageBox::Ok);

     }


    //insérer l'objet etudiant instancié dans la table etudiant et recuperer la valeur de retour de query.exec();


    bool test =a.ajouter();
    if(test)//si requête executée ==>QMessageBox::information
    {
        refrechir();

        QMessageBox::information(nullptr,QObject::tr("ok"),
                QObject::tr("Ajout effectué \n Click Cancel to exit."), QMessageBox::Cancel);

        no.ajout_notification();
    }
    else //si requête non exécutée ==>QMessageBox::critical
        QMessageBox::critical(nullptr,QObject::tr("Not Ok"),
                              QObject::tr("Ajout non effectué. \n ""Click Cancel to exit."),QMessageBox::Cancel);
}

//************************************MODIFICATION DECLARATION ACCIDENT***********************************//

void acceuil::on_Modifier_5_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
               player->setMedia(QUrl::fromLocalFile("C:/Users/houda/Desktop/music1/son.wav"));
               player->setVolume(3000);
               player->play();

    notification no;

         QString cin=ui->comboBox2->currentText();
         QString tel=ui->tel2->text();
         QString  email=ui->email2->text();
         QSqlQuery query;
        query.prepare("update TRAFFICS_DES_ACCIDENTS set tel_acc='"+tel+"',email_acc='"+email+"'where ID_ACCIDENT='"+cin+"'");
    if(query.exec())
    {
        refrechir();

    QMessageBox::information(nullptr,QObject::tr("ok"),
                             QObject::tr("Modification effectué \n ""Click Cancel to exit."),QMessageBox::Cancel);
    no.notification_modifier();

}
else
    QMessageBox::critical(nullptr,QObject::tr("not ok"),
                          QObject::tr("Modification non effectué.\n""Click Cancel to exit."),QMessageBox::Cancel);
}

//************************************SUPRESSION DECLARATION ACCIDENT***********************************//


void acceuil::on_Supprimer_3_clicked()
{
    notification no;
   // player->setMedia(QUrl::fromLocalFile("C:/Users/houda/Desktop/music1/son.wav"));
   // player->play();
    //qDebug() << player->errorString();
    int cin =ui->supcin_2->text().toInt();
    bool test2 =acciden.supprimer(cin);
   if(test2)
   {
       QMessageBox::information(nullptr,QObject::tr("ok"),
       QObject::tr("suppression effectué \n ""Click Cancel to exit."),QMessageBox::Cancel);
       no.notification_supprimer();
       refrechir();

   }
   else
       QMessageBox::critical(nullptr,QObject::tr("not ok"),

QObject::tr("suppression non effectué.\n""Click Cancel to exit."),QMessageBox::Cancel);
}




//*************************************************TABLE VIOLANCE*********************************//

//************************************AJOUT DECLARATION VIOLANCE ***********************************//
void acceuil::on_ajouter_clicked()
{
    notification no;
    QMediaPlayer *player = new QMediaPlayer;
               player->setMedia(QUrl::fromLocalFile("C:/Users/houda/Desktop/music1/son.wav"));
               player->setVolume(3000);
               player->play();
       //Récuprération des informations saisies dans les 3 champs
       int id=ui->leId->text().toInt(); //convertir une chaine de caractére en un entier
       QString nom=ui->leNom->text();
       QString prenom=ui->lePrenom->text();
       QString email=ui->LeEmail->text();
       QString nomaccuse=ui->LeNomA->text();
       QString autre=ui->commentaire->text();
       int cin=ui->LeCin->text().toInt();
       int tel=ui->LeTel->text().toInt();
       QString type="";

   //type:
       if(ui->sex_2->isChecked())
       {
           type="sexuelle";
       }
       if(ui->phy_2->isChecked())
       {
           type="physique";
       }
       if(ui->psy_2->isChecked())
       {
           type="psychologique";
       }


       violence v(id,nom,prenom,email,tel,cin,nomaccuse,autre,type);
       if((id==0)&&(nom=="")&&(prenom=="")&&(email==0)&&(nomaccuse=="")&&(tel==0))
             {
                 QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                             QObject::tr("Attention!! Les champs sont vides , Veuillez les remplir"), QMessageBox::Ok);

              }

       else if(cin == 0)

        {
            QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                        QObject::tr("Veuillez Vérifier le numéro de CIN"), QMessageBox::Ok);

        }

       //insérer l'objet etudiant instancié dans la table etudiant et recuperer la valeur de retour de query.exec();
       bool test =v.ajouter();
           if(test)//si requête executée ==>QMessageBox::information
           {

              //refresh affichage
               refrechir();
               QMessageBox::information(nullptr,QObject::tr("ok"),
               QObject::tr("Ajout effectué \n Click Cancel to exit."), QMessageBox::Cancel);
               no.ajout_notification();

           }

           else //si requête non exécutée ==>QMessageBox::critical
               QMessageBox::critical(nullptr,QObject::tr("Not Ok"),
                                     QObject::tr("Ajout non effectué. \n ""Click Cancel to exit."),QMessageBox::Cancel);


}
//************************************Supression  DECLARATION VIOLANCE ***********************************//

void acceuil::on_Supprimer_clicked()
{

    QMediaPlayer *player = new QMediaPlayer;
               player->setMedia(QUrl::fromLocalFile("C:/Users/houda/Desktop/music1/son.wav"));
               player->setVolume(3000);
               player->play();
int idaa =ui->idA->text().toInt();

bool test = etd.supprimer_violence(idaa);
if(test)
{

   refrechir();

    QMessageBox::information(nullptr,QObject::tr("ok"),
                             QObject::tr("suppression effectué \n ""Click Cancel to exit."),QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr,QObject::tr("not ok"),

QObject::tr("suppression non effectué.\n""Click Cancel to exit."),QMessageBox::Cancel);

}


void acceuil::on_pushButton_tri_3_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
               player->setMedia(QUrl::fromLocalFile("C:/Users/houda/Desktop/music1/son.wav"));
               player->setVolume(3000);
               player->play();
    ui->tabview->setModel(etd.AfficherTrieCIN());
}
//************************************COMBOBOX  VIOLANCE ***********************************//

void acceuil::on_comboBox_3_currentIndexChanged()
{
    QString name=ui->comboBox_3->currentText();
    QSqlQuery query;

      query.prepare ("select tel_traffic,email_traffic  from VIOLANCE_ARNAQUE where ID_TRAFFIC='"+name+"'");
      if(query.exec())
      {
          while(query.next())
          {
              ui->tell->setText(query.value(0).toString());
              ui->emaill->setText(query.value(1).toString());
          }
      }
}


//************************************MODIFICATION  DECLARATION VIOLANCE ***********************************//

void acceuil::on_Modifier_2_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
               player->setMedia(QUrl::fromLocalFile("C:/Users/houda/Desktop/music1/son.wav"));
               player->setVolume(3000);
               player->play();

    //Récuprération des informations saisies dans les 3 champs
    int id=ui->leId->text().toInt(); //convertir une chaine de caractére en un entier
    QString nom=ui->leNom->text();
    QString prenom=ui->lePrenom->text();
    QString email=ui->emaill->text();
    QString nomaccuse=ui->LeNomA->text();
    QString autre=ui->commentaire->text();
    int cin=ui->comboBox_3->currentText().toInt();
    int tel=ui->tell->text().toInt();
    QString type="";

violence v(id,nom,prenom,email,tel,cin,nomaccuse,autre,type);
     bool test =v.modifierViolence();
         if(test)//si requête executée ==>QMessageBox::information
         {
    refrechir();
    QMessageBox::information(nullptr,QObject::tr("ok"),
                             QObject::tr("Modification effectué \n ""Click Cancel to exit."),QMessageBox::Cancel);
        }
else
    QMessageBox::critical(nullptr,QObject::tr("not ok"),
                          QObject::tr("Modification non effectué.\n""Click Cancel to exit."),QMessageBox::Cancel);
}

//******************************************EMAIL******************************************************//

void acceuil::on_envoyer_5_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
               player->setMedia(QUrl::fromLocalFile("C:/Users/houda/Desktop/music1/son.wav"));
               player->setVolume(3000);
               player->play();

    QString mail_destinataire=ui->dest->text();
    QString sujet=ui->sujet->text();
    QString message=ui->message->text();


   Smtp* smtp = new Smtp("houda.koubaa@esprit.tn","191JFT51352020","smtp.gmail.com");
   smtp->sendMail("houda.koubaa@esprit.tn",mail_destinataire,sujet,message);
   QMessageBox::information(nullptr,QObject::tr("ok"),
                            QObject::tr("Message envoyes avec succes  \n ""Click Cancel to exit."),QMessageBox::Cancel);
     ui->dest->clear();
     ui->sujet->clear();
     ui->message->clear();


}

//******************************************SMS********************************************************//


void acceuil::on_pushButton_envoyerSMS_3_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("C:/Users/houda/Desktop/music1/son.wav"));
    player->setVolume(3000);
    player->play();
    sms s;
        s.ajoutersms(ui->combotel->currentText(),
        ui->objet->text(),ui->messageS->text(),ui->date_2->text());

        Smtp* smtp = new Smtp("houda.koubaa@esprit.tn", "191JFT51352020", "smtp.Gmail.com",465);
                QObject::connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));
                smtp->sendMail("houda.koubaa@esprit.tn","+216"+ui->combotel->currentText()+"@sms.clicksend.com",ui->objet->text(),ui->messageS->text());
                ui->objet->clear();
                ui->messageS->clear();
                ui->date_2->clear();
}

void acceuil::on_pushButton_affichersms_4_clicked()
{
    sms s;
    ui->tableView_affichersms_4->setModel(s.afficherListesms(ui->lineEdit_recherchersms_4->text()));
    ui->tableView_affichersms_4->show();
}

void acceuil::on_pushButton_suprimersms_4_clicked()
{
    sms s;

    if(ui->checkBox_sms_4->isChecked())
    {
        s.supprimer_sms();
         this->on_pushButton_affichersms_4_clicked();
    }

    else{
    if(s.supprimer_sms(ui->tableView_affichersms_4->currentIndex().data().toString()))
       {
        this->on_pushButton_affichersms_4_clicked();
       }

    }
}

//******************************************STATISTIQUE********************************************************//

QChartView* acceuil::piechart()
{

    QPieSeries *series = new QPieSeries();
    QPieSeries *series1 = new QPieSeries();


    series->append("sexuelle", 1);
    series->append("physique", 2);
    series->append("psychologique", 3);

    series1->append("", 1);
    series1->append("", 2);
    series1->append("", 3);

    series1->hide();
    series->slices().at(0)->setValue(G_PVS1());
    series->slices().at(1)->setValue(G_PVS2());
    series->slices().at(2)->setValue(G_PVS3());
    series->slices().at(0)->setBrush(Qt::darkCyan);
    series->slices().at(1)->setBrush(Qt::darkBlue);
    series->slices().at(2)->setBrush(Qt::blue);

    series1->slices().at(0)->setValue(G_PVS1());
    series1->slices().at(1)->setValue(G_PVS2());
    series1->slices().at(2)->setValue(G_PVS3());

    series1->slices().at(0)->setBrush(Qt::darkCyan);
    series1->slices().at(1)->setBrush(Qt::darkBlue);
    series1->slices().at(2)->setBrush(Qt::blue);
    series->slices().at(2)->setExploded();
    series1->slices().at(2)->setExploded();

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->addSeries(series1);
    chart->setTitle("STATISTIQUE SELON TYPE DE VIOLANCE ");
    chart->setAnimationOptions(QChart::AllAnimations);



    QChartView *chartView1 = new QChartView(chart);
    chartView1->setRenderHint(QPainter::Antialiasing);




    series1->setLabelsVisible();

    for(auto slice : series1->slices())
    slice->setLabel(QString("%1%").arg(100*slice->percentage(), 0, 'f', 1));





    return chartView1;
}

int acceuil::G_PVS1()
{
    int c21=0;
    QSqlQuery qry21;
    qry21.exec("SELECT ID_TRAFFIC FROM VIOLANCE_ARNAQUE WHERE TYPE='sexuelle' ");
    while(qry21.next())
    {
        c21++;
    }
    return c21;
}
int acceuil::G_PVS2()
{
    int c20=0;
    QSqlQuery qry20;
    qry20.exec("SELECT ID_TRAFFIC FROM VIOLANCE_ARNAQUE WHERE TYPE='physique'");
    while(qry20.next())
    {
        c20++;
    }
    return c20;
}
int acceuil::G_PVS3()
{
    int c19=0;
    QSqlQuery qry19;
    qry19.exec("SELECT ID_TRAFFIC FROM VIOLANCE_ARNAQUE WHERE TYPE ='psychologique' ");
    while(qry19.next())
    {
        c19++;
    }
    return c19;
}

void acceuil::on_tabWidget_2_tabBarClicked()
{
    qDeleteAll(ui->tabWidget_2->widget(4)->children());
    QWidget* piestats = new QWidget(this);
    piestats = piechart();
    QGridLayout* layout1 = new QGridLayout(this);
    layout1->addWidget(piestats, 0, 0); // Top-Left
    layout1->addWidget(NULL, 0, 1); // Top-Right
    layout1->addWidget(NULL, 1, 0); // Bottom-Left
    layout1->addWidget(NULL, 1, 1); // Bottom-Right
    ui->tab_7->setLayout(layout1);
}
//******************************************IMPRESSION ********************************************************//


void acceuil::on_Impdos_2_clicked()
{

    QMediaPlayer *player = new QMediaPlayer;
               player->setMedia(QUrl::fromLocalFile("C:/Users/houda/Desktop/music1/son.wav"));
               player->setVolume(3000);
               player->play();

    accident c;

                 QString text=c.apercu_pdf();
                 ui->imp->setText(text);

                 QPrinter printer ;
                 printer.setPrinterName("imprim");
                 QPrintDialog dialog (&printer,this);
                 if(dialog.exec()==QDialog::Rejected) return ;
                 ui->imp->print(&printer);
}
//******************************************Theme(NOIR -blanc) ********************************************************//

void acceuil::on_dark_clicked()
{
ui->tabWidget->setStyleSheet("background-color:black;color:white");
ui->dark->setVisible(false);
ui->white->setVisible(true);
}


void acceuil::on_white_clicked()
{
 ui->tabWidget->setStyleSheet("background-color:white;color:black");
 ui->dark->setVisible(true);
 ui->white->setVisible(false);

}

/*********************************************gestion Des employees et conges(Zaineb)***********************************************/

void acceuil::on_pushButton_3_clicked()
{

    Dialogemploye E;
    E.exec();
}




void acceuil::on_pushButtonquitter_clicked()
{
       close();
}
/*******************************end gestion employes et conges**************************************/



/*********************************travail de Ahmed******************************************************/
  /***************************************************************************************************/

void acceuil::on_pb_ajouter_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
               player->setMedia(QUrl::fromLocalFile("C:/Users/houda/Desktop/music1/son.wav"));
               player->setVolume(3000);
               player->play();

    int CIN_assis = ui->le_cin_assis->text().toInt();
     ui->le_cin_assis->setMaxLength(8);
    int numero_assis = ui->le_numero_tele->text().toInt();
    QString date_consultation = ui->le_date->date().toString("dd/MM/yyyy");

    QString nom_assis= ui->le_nom_assis->text();
    QString prenom_assis = ui->le_prenom_assis->text();
    QString type_consultation = ui->le_type_consultation->currentText();


    Assistance A(CIN_assis, nom_assis, prenom_assis,numero_assis, date_consultation,type_consultation);

    if((prenom_assis=="")&&(nom_assis=="")&&(type_consultation=="")&&(CIN_assis==0)&&(date_consultation=="")&&(numero_assis==0))
          {
              QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                          QObject::tr("Attention!! Les champs sont vides , Veuillez les remplir"), QMessageBox::Ok);
           }
    //       else if(((numCin>=99999999) && (numCin<=9999999)) )
    //          {
    //              QMessageBox::critical(nullptr, QObject::tr("Erreur"),
    //                          QObject::tr("Attention ! Le numéro de Cin doit contenir 8 chiffres"), QMessageBox::Ok);

    //          }
       else if(CIN_assis == 0)
        {
            QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                        QObject::tr("Veuillez remplir le numéro de CIN"), QMessageBox::Ok);

        }
            else if(nom_assis =="")
               {
                   QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                               QObject::tr("Veuillez remplir le nom d'assistance"), QMessageBox::Ok);

               }
          else if(prenom_assis =="")
             {
                 QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                             QObject::tr("Veuillez remplir le prénom d'assistance"), QMessageBox::Ok);

             }
            else if(date_consultation=="")
               {
                   QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                               QObject::tr("Veuillez remplir la date de consultation"), QMessageBox::Ok);

               }
          else if(type_consultation =="")
             {
                 QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                             QObject::tr("Veuillez choisir le type de consultation"), QMessageBox::Ok);

             }

          else if(numero_assis ==0)
             {
                 QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                             QObject::tr("Veuillez remplir le numero de telephone"), QMessageBox::Ok);

             }

    else {

        if(A.ajouter_consultation())
              {
                   ui->tableAssistance->setModel(tmpassistance.afficher());
                   QMessageBox::information(nullptr, QObject::tr("BIEN"),
                               QObject::tr("Ajout effectuer avec succés.\n" ), QMessageBox::Cancel);

                           ui->le_cin_assis->setText("");
                           ui->le_nom_assis->setText("");
                           ui->le_prenom_assis->setText("");
                           ui->le_numero_tele->setText("");
                           ui->le_date->date().toString();




              }else{
                      QMessageBox::information(nullptr, QObject::tr("ECHEC!!!"),
                                  QObject::tr("Citoyen existe déja.\n"), QMessageBox::Cancel);
                  }


    }


}


    /*************************************************************************/




















/*************************************************************************
 * *****************************************************************
 * **************************************************/

void acceuil::on_ajouter_citoyen_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
               player->setMedia(QUrl::fromLocalFile("C:/Users/houda/Desktop/music1/son.wav"));
               player->setVolume(3000);
               player->play();

  int cin = ui->le_cin->text().toInt() ;
  ui->le_cin->setMaxLength(8);

 QString nom = ui->le_nom->text();
 ui->le_nom->setMaxLength(15);

 QString prenom = ui->le_prenom->text();
 ui->le_prenom->setMaxLength(15);
 int numero_tele = ui->le_numero22->text().toInt();
 QString daten = ui->le_daten1->date().toString("dd/MM/yyyy");
 QString sexe = ui->le_sexe1->currentText();
 QString remarque = ui->le_remarque->text();


Citoyen c(cin , nom , prenom, numero_tele , daten , sexe , remarque);

if((prenom=="")&&(nom=="")&&(sexe=="")&&(cin==0)&&(remarque=="")&&(daten==""))
      {
          QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                      QObject::tr("Attention!! Les champs sont vides , Veuillez les remplir"), QMessageBox::Ok);
       }
       /* else if( (cin>=10000000) && (cin<999999999) )
         {
              QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                          QObject::tr("Attention ! Le numéro de Cin doit contenir 8 chiffres"), QMessageBox::Ok);

          }*/
   else if(cin == 0)
    {
        QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                    QObject::tr("Veuillez remplir le numéro de CIN"), QMessageBox::Ok);

    }
        else if(nom =="")
           {
               QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                           QObject::tr("Veuillez remplir le nom"), QMessageBox::Ok);

           }
      else if(prenom =="")
         {
             QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                         QObject::tr("Veuillez remplir le prénom"), QMessageBox::Ok);

         }
        else if(daten=="")
           {
               QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                           QObject::tr("Veuillez remplir la date de naissance"), QMessageBox::Ok);

           }
      else if(sexe =="")
         {
             QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                         QObject::tr("Veuillez choisir le sexe"), QMessageBox::Ok);

         }

      else if(remarque =="")
         {
             QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                         QObject::tr("Veuillez remplir le remarque"), QMessageBox::Ok);

         }

else {

    if(c.ajouter())
          {
               ui->tableCitoyen->setModel(tmpcitoyen.afficher());
             QMessageBox::information(nullptr, QObject::tr("BIEN"),
                         QObject::tr("Ajout effectuer avec succés.\n" ), QMessageBox::Cancel);

                     ui->le_cin->setText("");
                     ui->le_nom->setText("");
                     ui->le_prenom->setText("");
                     ui->le_numero22->setText("");
                     //ui->le_daten11->date().toString();
                     //ui->le_sexe11->currentText();
                     ui->le_remarque->setText("");


        }else{
                QMessageBox::information(nullptr, QObject::tr("ECHEC!!!"),
                            QObject::tr("Citoyen existe déja.\n"), QMessageBox::Cancel);
            }


}


}

/*************************************************************************/


void acceuil::on_pb_supp_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
               player->setMedia(QUrl::fromLocalFile("C:/Users/houda/Desktop/music1/son.wav"));
               player->setVolume(3000);
               player->play();

    int cin = ui->le_cin_supp->text().toInt();
    bool test=tmpcitoyen.supprimer(cin);
    if(test)
    {ui->tableCitoyen->setModel(tmpcitoyen.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un citoyen"),
                    QObject::tr("Citoyen supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        ui->le_cin_supp->setText("");

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un citoyen"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}





/**********************************************************************************/




void acceuil::on_modifier_citoyen_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
               player->setMedia(QUrl::fromLocalFile("C:/Users/houda/Desktop/music1/son.wav"));
               player->setVolume(3000);
               player->play();

       int cin=ui->le_cin2->text().toInt();
       QString nom=ui->le_nom2->text();
       QString prenom=ui->le_prenom2->text();
       int numero_tele=ui->le_numero2->text().toInt();
       QString daten=ui->le_daten11->date().toString("dd/MM/yyyy");
       QString sexe=ui->le_sexe11->currentText();
       QString remarque=ui->le_remarque_2->text();

       Citoyen c (cin, nom , prenom, numero_tele , daten , sexe , remarque);
       if((prenom=="")&&(nom=="")&&(sexe=="")&&(cin== 0)&&(remarque=="")&&(daten==""))
          {
              QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                          QObject::tr("Attention!! Les champs sont vides , Veuillez les remplir"), QMessageBox::Ok);
           }
         else if(cin == 0)
          {
              QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                          QObject::tr("Veuillez remplir le numéro de CIN"), QMessageBox::Ok);

          }
          else if(prenom =="")
             {
                 QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                             QObject::tr("Veuillez remplir le prénom"), QMessageBox::Ok);

             }
          else if(nom =="")
             {
                 QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                             QObject::tr("Veuillez remplir le nom"), QMessageBox::Ok);

             }
          else if(sexe =="")
             {
                 QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                             QObject::tr("Veuillez choisir le sexe"), QMessageBox::Ok);

             }

          else if(remarque =="")
             {
                 QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                             QObject::tr("Veuillez remplir l'activité"), QMessageBox::Ok);

             }
       else if(daten=="")
          {
              QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                          QObject::tr("Veuillez remplir la date de naissance"), QMessageBox::Ok);

          }
       else {

           if(c.modifier(cin))
           {
                    QMessageBox::information(nullptr, QObject::tr("Modifier un Citoyen"),
                                QObject::tr("citoyen modifié.\n"), QMessageBox::Cancel);

                    ui->le_cin2->setText("");
                    ui->le_nom2->setText("");
                    ui->le_prenom2->setText("");
                    ui->le_numero2->setText("");
                    //ui->le_daten11->date().toString();
                    //ui->le_sexe11->currentText();
                    ui->le_remarque_2->setText("");

           }
           else
           {
              QMessageBox::critical(nullptr, QObject::tr("Modifier un Citoyen"),

                                    QObject::tr("Erreur !!!!!!!!\n"), QMessageBox::Cancel);
           }
       }

}

/************************************************************************/

void acceuil::on_tri_citoyen_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
               player->setMedia(QUrl::fromLocalFile("C:/Users/houda/Desktop/music1/son.wav"));
               player->setVolume(3000);
               player->play();

      ui->tableCitoyen->setModel(tmpcitoyen.AfficherTrieNom());
}

void acceuil::on_le_cin_supp_textChanged(const QString &arg1)
{
    ui->tableCitoyen->setModel(tmpcitoyen.rechercherNom(arg1));
}

/************************************************************************/

void acceuil::on_pb_consultation_supp_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
               player->setMedia(QUrl::fromLocalFile("C:/Users/houda/Desktop/music1/son.wav"));
               player->setVolume(3000);
               player->play();

    int cin = ui->le_consultation_supp->text().toInt();
    bool test=tmpassistance.supprimer(cin);
    if(test)
    {ui->tableAssistance->setModel(tmpassistance.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimerune consultation"),
                    QObject::tr("Consultation supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        ui->le_consultation_supp->setText("");

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer une consultation"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}


/********************************************************************************/


void acceuil::on_pb_consultation_modifier_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
               player->setMedia(QUrl::fromLocalFile("C:/Users/houda/Desktop/music1/son.wav"));
               player->setVolume(3000);
               player->play();

    int CIN_assis = ui->le_cin_assis2->text().toInt();
     ui->le_cin_assis->setMaxLength(8);
    int numero_assis = ui->le_numero2_2->text().toInt();
    QString date_consultation = ui->le_date2->date().toString("dd/MM/yyyy");

    QString nom_assis= ui->le_nom_assis2->text();
    QString prenom_assis = ui->le_prenom_assis2->text();
    QString type_consultation = ui->le_type_consultation2->currentText();

    Assistance A(CIN_assis, nom_assis, prenom_assis,numero_assis, date_consultation,type_consultation);

    if((prenom_assis=="")&&(nom_assis=="")&&(type_consultation=="")&&(CIN_assis==0)&&(date_consultation=="")&&(numero_assis==0))
          {
              QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                          QObject::tr("Attention!! Les champs sont vides , Veuillez les remplir"), QMessageBox::Ok);
           }
    //       else if(((numCin>=99999999) && (numCin<=9999999)) )
    //          {
    //              QMessageBox::critical(nullptr, QObject::tr("Erreur"),
    //                          QObject::tr("Attention ! Le numéro de Cin doit contenir 8 chiffres"), QMessageBox::Ok);

    //          }
       else if(CIN_assis == 0)
        {
            QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                        QObject::tr("Veuillez remplir le numéro de CIN"), QMessageBox::Ok);

        }
            else if(nom_assis =="")
               {
                   QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                               QObject::tr("Veuillez remplir le nom d'assistance"), QMessageBox::Ok);

               }
          else if(prenom_assis =="")
             {
                 QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                             QObject::tr("Veuillez remplir le prénom d'assistance"), QMessageBox::Ok);

             }
            else if(date_consultation=="")
               {
                   QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                               QObject::tr("Veuillez remplir la date de consultation"), QMessageBox::Ok);

               }
          else if(type_consultation =="")
             {
                 QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                             QObject::tr("Veuillez choisir le type de consultation"), QMessageBox::Ok);

             }

          else if(numero_assis ==0)
             {
                 QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                             QObject::tr("Veuillez remplir le numero de telephone"), QMessageBox::Ok);

             }

    else {


        if(A.modifier(CIN_assis))
        {
                 QMessageBox::information(nullptr, QObject::tr("Modifier une consultation"),
                             QObject::tr("consultation modifié.\n"), QMessageBox::Cancel);

                 ui->le_cin_assis2->setText("");
                 ui->le_nom_assis2->setText("");
                 ui->le_prenom_assis2->setText("");
                 ui->le_numero2_2->setText("");
                 ui->le_date2->date().toString();
                 ui->le_type_consultation2->currentText();

        }
        else
        {
           QMessageBox::critical(nullptr, QObject::tr("Modifier une consultation"),

                                 QObject::tr("Erreur !!!!!!!!\n"), QMessageBox::Cancel);
        }
    }

}

/*****************************************************************************/



void acceuil::on_pb_tri_consultation_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
               player->setMedia(QUrl::fromLocalFile("C:/Users/houda/Desktop/music1/son.wav"));
               player->setVolume(3000);
               player->play();

    ui->tableAssistance->setModel(tmpassistance.AfficherTrieNom());
}

void acceuil::on_le_consultation_supp_textChanged(const QString &arg1)
{
     ui->tableAssistance->setModel(tmpassistance.rechercherNom(arg1));

}


/********************************************************************************/


void acceuil::on_affec_citoyen_clicked()
{

    rdv V;
    ui->le_citoyen_affec_3->setModel(V.affecter_citoyen());
    ui->le_assis_affec_3->setModel(V.affecter_assistance());

}

/*********************************************************************************/


void acceuil::on_pb_enregistrer_3_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
               player->setMedia(QUrl::fromLocalFile("C:/Users/houda/Desktop/music1/son.wav"));
               player->setVolume(3000);
               player->play();

 int id_rdv = ui->le_id_rdv_3->text().toInt() ;
 ui->le_id_rdv_3->setMaxLength(8);

 QString nom_citoyen = ui->le_citoyen_affec_3->currentText();

 QString nom_assis = ui->le_assis_affec_3->currentText();
 QDateTime date_rdv = ui->le_date_RDV_3->dateTime();

 QString type_rdv = ui->le_type_RDV_3->currentText();



rdv v (id_rdv, nom_citoyen,nom_assis ,date_rdv, type_rdv );
QDateTime system_date = QDateTime::currentDateTime();

if((nom_citoyen=="")&&(nom_assis=="")&&(date_rdv<=system_date)&&(id_rdv==0)&&(type_rdv==""))
      {
          QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                      QObject::tr("Attention!! Les champs sont vides , Veuillez les remplir"), QMessageBox::Ok);
       }


   else if(id_rdv == 0)
    {
        QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                    QObject::tr("Veuillez remplir le numéro de id de rdv"), QMessageBox::Ok);

    }
        else if(nom_citoyen =="")
           {
               QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                           QObject::tr("Veuillez remplir le nom citoyen"), QMessageBox::Ok);

           }
      else if(nom_assis =="")
         {
             QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                         QObject::tr("Veuillez remplir le nom assis"), QMessageBox::Ok);

         }
        else if(date_rdv<=system_date)
           {
               QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                           QObject::tr("Vérifier le date de RDV!!!"), QMessageBox::Ok);

           }
      else if(type_rdv =="")
         {
             QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                         QObject::tr("Veuillez choisir le type de rdv"), QMessageBox::Ok);

         }


else {

    if(v.ajouter())
          {
               ui->tableRDV_3->setModel(v.afficher());
             QMessageBox::information(nullptr, QObject::tr("BIEN"),
                         QObject::tr("Ajout effectuer avec succés.\n" ), QMessageBox::Cancel);

                     ui->le_id_rdv_3->setText("");



        }else{
                QMessageBox::information(nullptr, QObject::tr("ECHEC!!!"),
                            QObject::tr("rdv existe déja.\n"), QMessageBox::Cancel);
            }


}



}

/*******************************************************************************************/


void acceuil::on_print_rdv_3_clicked()
{
    QPrinter print;
    print.setPrinterName("imprimer");
    QPrintDialog dialog(&print, this);
    if(dialog.exec()==QDialog::Rejected) return;
    ui->tableRDV_3->render(&print);
}

/***********************************************************************************************/
void acceuil::on_pb_supp_rdv_3_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
               player->setMedia(QUrl::fromLocalFile("C:/Users/houda/Desktop/music1/son.wav"));
               player->setVolume(3000);
               player->play();

    int id_rdv = ui->le_rdv_supp_3->text().toInt();
    bool test=tmprdv.supprimer(id_rdv);
    if(test)
    {ui->tableRDV_3->setModel(tmprdv.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un rdv"),
                    QObject::tr("rdv supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        ui->le_rdv_supp_3->setText("");

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un rdv"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}


/***************************************************************************************************/

void acceuil::on_trie_rdv_3_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
               player->setMedia(QUrl::fromLocalFile("C:/Users/houda/Desktop/music1/son.wav"));
               player->setVolume(3000);
               player->play();

    ui->tableRDV_3->setModel(tmprdv.AfficherTrieId());
}

void acceuil::on_le_rdv_supp_3_textChanged(const QString &arg1)
{
    ui->tableRDV_3->setModel(tmprdv.rechercherId(arg1));
}

void acceuil::on_gestionCitoyen_clicked()
{
    ui->stackedWidget5555->setCurrentIndex(1);
}
void acceuil::on_gestionAssistance_clicked()
{
    ui->stackedWidget5555->setCurrentIndex(2);
}
void acceuil::on_gestionRDV_clicked()
{
    ui->stackedWidget5555->setCurrentIndex(0);
}

  /***************************************************************************************************/
/*********************************** FIN travail de Ahmed***********************************************/










void acceuil::on_pause_2_clicked()
{
    player->pause();
}

void acceuil::on_start_2_clicked()
{
    player->setMedia(QUrl::fromLocalFile("C:/Users/houda/Desktop/music1/prison.mp3"));
    player->play();
    qDebug() << player->errorString();
}

void acceuil::on_horizontalSlider_2_sliderMoved(int position)
{
    player->setVolume(position);
}

void acceuil::on_LeIdRT_textChanged(const QString &arg1)
{
     ui->tabview->setModel(etd.rechercherCIN(arg1));
}

void acceuil::on_supcin_2_textChanged(const QString &arg1)
{ accident acc;
    ui->tabview_5->setModel(acc.rechercherCIN(arg1));
}
