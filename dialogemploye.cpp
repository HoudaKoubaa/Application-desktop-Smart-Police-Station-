#include "dialogemploye.h"
#include "ui_dialogemploye.h"
#include "employes.h"
#include "conge.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include<QDebug>
#include<QLineEdit>
#include <QPixmap>
#include <QPrinter>
#include <QPrintDialog>
#include <QPropertyAnimation>
#include "mailing.h"
#include <QDialog>

Dialogemploye::Dialogemploye(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialogemploye)
{
     ui->setupUi(this);
     ui->tableV->setModel(V.afficherVehicule());
      ui->tableM->setModel(M.afficherMaintenance());
      update_idd();


     QPropertyAnimation *animation = new QPropertyAnimation(ui->label, "geometry");
     animation->setDuration(4000);
     animation->setStartValue(ui->label->geometry());
     animation->setStartValue(QRect(0, 0, 100, 30));
     animation->setEasingCurve(QEasingCurve::OutBounce);
     animation->start();

     QPropertyAnimation *animatio = new QPropertyAnimation(ui->label_14, "geometry");
     animatio->setDuration(4000);
     animatio->setStartValue(ui->label_14->geometry());
     animatio->setStartValue(QRect(0, 0, 100, 100));
     animatio->setEasingCurve(QEasingCurve::OutBounce);
     animatio->start();

     ui->tableView->setModel(emp.afficherEmployes());
     ui->tableViewww->setModel(C.afficherConge());

     update_id();
     updatee_id();
      auto_mail();

     player = new QMediaPlayer;

}

Dialogemploye::~Dialogemploye()
{
    delete ui;
}



bool Dialogemploye::controleVide(QString test)
{
    if(test!="")
        return  true;
    return false;

}


bool Dialogemploye::controledate(QDateTime debut,QDateTime fin)
{
    if(debut<fin)
        return  true;
    return false;

}

bool Dialogemploye::controleVideInt(int test)
{
    if(test!=0)
        return  true;
    return false;

}

bool Dialogemploye::controleEmail(QString test)
{
    for(int i=0;i<test.length();i++)
    {
        if (test.at(i)=='@')
        {
            return true;
        }
    }
    return false;
}

void Dialogemploye::update_id()
{

       QSqlQueryModel *m=new QSqlQueryModel();
       QSqlQuery *querry=new QSqlQuery();
       querry->prepare("SELECT cin_emp FROM employes");
       querry->exec();
       m->setQuery(*querry);
       ui->comboBox_22->setModel(m);



}


void Dialogemploye::updatee_id()
{

       QSqlQueryModel *m=new QSqlQueryModel();
       QSqlQuery *querry=new QSqlQuery();
       querry->prepare("SELECT cin_emp FROM employes");
       querry->exec();
       m->setQuery(*querry);


}



void Dialogemploye::on_pushButtonAjouter_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
               player->setMedia(QUrl::fromLocalFile("C:/Users/houda/Desktop/music1/son.wav"));
               player->setVolume(3000);
               player->play();
    //Récuprération des informations saisies dans les 3 champs
    int id=ui->LeId->text().toInt(); //convertir une chaine de caractére en un entie

      QString nom=ui->Lenom->text();
      QString prenom=ui->Leprenom->text();
      QString grade=ui->comboBox->currentText();
      QDateTime date=ui->dateEdit->dateTime();
      QString mdp=ui->lemdp->text();
      QString email=ui->leemail->text();


      bool test2;
          test2=(controleEmail(email)&&controleVide(nom)&&controleVide(prenom)&&controleVide(mdp)&&controleVide(email)&&controleVideInt(id) );

      //instancier un objet de la classe Etudiant en utilisant les informations saisies dans l interfaces
      Employes E(id,nom,prenom,grade,date,mdp,email);

      //insérer l'objet etudiant instancié dans la table etudiant et recuperer la valeur de retour de query.exec();

      bool test =E.ajouterEmployes();
if (test2){

      if(test)//si requête executée ==>QMessageBox::information
      {

         //refresh affichage
          ui->tableView->setModel(emp.afficherEmployes());
          QMessageBox::information(nullptr,QObject::tr("ok"),
                  QObject::tr("Ajout effectué \n Click Cancel to exit."), QMessageBox::Cancel);
      }

      else //si requête non exécutée ==>QMessageBox::critical
          QMessageBox::critical(nullptr,QObject::tr("Not Ok"),
                                QObject::tr("Ajout non effectué. \n ""Click Cancel to exit."),QMessageBox::Cancel);}
else

  {

      QMessageBox::information(nullptr, QObject::tr("Ajouter un employé "),
                                 QObject::tr("Employé non ajouté, vérifier les champs.\n""Click Cancel to exit."), QMessageBox::Cancel);


  }


}


void Dialogemploye::on_pushButtonModifier_clicked()
{

    QMediaPlayer *player = new QMediaPlayer;
               player->setMedia(QUrl::fromLocalFile("C:/Users/houda/Desktop/music1/son.wav"));
               player->setVolume(3000);
               player->play();

    //Récuprération des informations saisies dans les 3 champs
    int idaa =ui->LeId->text().toInt();
    QString nom=ui->Lenom->text();
    QString prenom=ui->Leprenom->text();
    QString grade=ui->comboBox->currentText();
    QDateTime date=ui->dateEdit->dateTime();
    QString mdp=ui->lemdp->text();
    QString email=ui->leemail->text();

    bool test2;
        test2=(controleEmail(email)&&controleVide(nom)&&controleVide(prenom)&&controleVide(mdp)&&controleVide(email) );
    //instancier un objet de la classe Etudiant en utilisant les informations saisies dans l interfaces
     Employes E(idaa,nom,prenom,grade,date,mdp,email);

    //insérer l'objet etudiant instancié dans la table etudiant et recuperer la valeur de retour de query.exec();
    bool test =E.modifierEmployes();


if (test2){
    if(test)//si requête executée ==>QMessageBox::information
    {

       //refresh affichage
        ui->tableView->setModel(emp.afficherEmployes());
        QMessageBox::information(nullptr,QObject::tr("ok"),
                QObject::tr("Modification effectué \n Click Cancel to exit."), QMessageBox::Cancel);
    }
    else //si requête non exécutée ==>QMessageBox::critical
        QMessageBox::critical(nullptr,QObject::tr("Not Ok"),
                              QObject::tr("Modification non effectué. \n ""Click Cancel to exit."),QMessageBox::Cancel);}
else

  {

      QMessageBox::information(nullptr, QObject::tr("Ajouter un employé "),
                                 QObject::tr("Employé non ajouté, vérifier les champs.\n""Click Cancel to exit."), QMessageBox::Cancel);


  }

}


void Dialogemploye::on_pushButtonSupprimer_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
               player->setMedia(QUrl::fromLocalFile("C:/Users/houda/Desktop/music1/son.wav"));
               player->setVolume(3000);
               player->play();
 int idaa =ui->LeId->text().toInt();

    bool test = emp.supprimerEmployes(idaa);
    if(test)
    {
        //refresh affichage
        ui->tableView->setModel(emp.afficherEmployes());
        updatee_id();

        QMessageBox::information(nullptr,QObject::tr("ok"),
                                 QObject::tr("suppression effectué \n ""Click Cancel to exit."),QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr,QObject::tr("not ok"),

QObject::tr("suppression non effectué.\n""Click Cancel to exit."),QMessageBox::Cancel);

}

void Dialogemploye::on_pushButton_clicked()
{
    player->setMedia(QUrl::fromLocalFile("C:/Users/Zeineb/Desktop/Source2/son.wav"));
    player->play();
    qDebug() << player->errorString();

    ui->tableView->setModel(emp.AfficherTrieCIN());
}

void Dialogemploye::on_pushButton_2_clicked()
{
     player->setMedia(QUrl::fromLocalFile("C:/Users/Zeineb/Desktop/Source2/son.wav"));
     player->play();
     qDebug() << player->errorString();
     ui->tableView->setModel(emp.AfficherTrieNom());
}


void Dialogemploye::on_LeIdRT_textChanged(const QString &arg1)
{
    ui->tableView->setModel(emp.rechercherCIN(arg1));
}

void Dialogemploye::on_LeTitreRT_textChanged(const QString &arg1)
{
    ui->tableView->setModel(emp.rechercherNom(arg1));
}


void Dialogemploye::on_tableView_activated(const QModelIndex &index)
{
    QString val=ui->tableView->model()->data(index).toString();
          QSqlQuery qry;
          qry.prepare("select * from Employes where"
                      " cin_emp='"+val+"' or nom_emp='"+val+"' or prenom_emp='"+val+"' or grade='"+val+"' or email ='"+val+"' or mot_de_passe='"+val+"' ");
          if(qry.exec())
            {while (qry.next())
           { ui->LeId->setText(qry.value(0).toString());
             ui->Lenom->setText(qry.value(1).toString());
             ui->Leprenom->setText(qry.value(2).toString());
             ui->comboBox->setCurrentText(qry.value(3).toString());
             ui->leemail->setText(qry.value(6).toString());
             ui->lemdp->setText(qry.value(5).toString());
             ui->dateEdit->setDateTime(qry.value(4).toDateTime());

           }
            }
}

void Dialogemploye::on_tableView_clicked(const QModelIndex &index)
{
    id_emp=ui->tableView->model()->data(index).toInt();
}

void Dialogemploye::on_Impdos_2_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
               player->setMedia(QUrl::fromLocalFile("C:/Users/houda/Desktop/music1/son.wav"));
               player->setVolume(3000);
               player->play();

    Employes c;

                 QString text=c.apercu_pdf();
                 ui->imp->setText(text);

                 QPrinter printer ;
                 printer.setPrinterName("imprim");
                 QPrintDialog dialog (&printer,this);
                 if(dialog.exec()==QDialog::Rejected) return ;
                 ui->imp->print(&printer);

}





void Dialogemploye::on_lineEdit_3_textChanged(const QString &arg1)
{
    ui->tableView->setModel(emp.rechercherGrade(arg1));
}

void Dialogemploye::on_pushButton_3_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
               player->setMedia(QUrl::fromLocalFile("C:/Users/houda/Desktop/music1/son.wav"));
               player->setVolume(3000);
               player->play();
 qDebug() << player->errorString();
 ui->tableView->setModel(emp.AfficherTrieDate());
}

void Dialogemploye::on_pushButton_4_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
               player->setMedia(QUrl::fromLocalFile("C:/Users/houda/Desktop/music1/son.wav"));
               player->setVolume(3000);
               player->play();
    close();
}





void Dialogemploye::on_pushButtonmail_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
               player->setMedia(QUrl::fromLocalFile("C:/Users/houda/Desktop/music1/son.wav"));
               player->setVolume(3000);
               player->play();
    mailing m;
    m.exec();
    m.setModal(true);


}




/************************************conge******************************/


void Dialogemploye::on_pushButtonAjouterr_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
               player->setMedia(QUrl::fromLocalFile("C:/Users/houda/Desktop/music1/son.wav"));
               player->setVolume(3000);
               player->play();

       //Récuprération des informations saisies dans les 3 champs


       int id=ui->LeId_222->text().toInt(); //convertir une chaine de caractére en un entier
       QDateTime debut_conge=ui->dateEdittt->dateTime();
       QDateTime fin_conge=ui->dateEdit_22->dateTime();
       int id2=ui->comboBox_22->currentText().toInt(); //convertir une chaine de caractére en un entier
       bool testdate;
       testdate=(controledate(debut_conge,fin_conge));
       bool test2;
           test2=(controleVideInt(id) );
       //instancier un objet de la classe Etudiant en utilisant les informations saisies dans l interfaces
           bool test;
if (testdate){
       Conge C(id,debut_conge,fin_conge,id2);

       //insérer l'objet etudiant instancié dans la table etudiant et recuperer la valeur de retour de query.exec();

        test =C.ajouterConge();}
else

  {

      QMessageBox::information(nullptr, QObject::tr("Ajouter un conge "),
                                 QObject::tr("conge non ajouté, vérifier les dates du conge.\n""Click Cancel to exit."), QMessageBox::Cancel);


  }
if(testdate){
       if (test2){
       if(test)//si requête executée ==>QMessageBox::information
       {

           notifier = new QSystemTrayIcon(this);
           notifier->setIcon(QIcon(":/notification.jpg"));
           notifier->show();

          notifier->showMessage(" NOTIFICATION ","conge affecte",QSystemTrayIcon::Information,10000); ;

          //refresh affichage
           ui->tableViewww->setModel(C.afficherConge());
           update_id();
           QMessageBox::information(nullptr,QObject::tr("ok"),
                   QObject::tr("Ajout effectué \n Click Cancel to exit."), QMessageBox::Cancel);
       }

       else //si requête non exécutée ==>QMessageBox::critical
           QMessageBox::critical(nullptr,QObject::tr("Not Ok"),
                                 QObject::tr("Ajout non effectué. \n ""Click Cancel to exit."),QMessageBox::Cancel);}

       else

         {

             QMessageBox::information(nullptr, QObject::tr("Ajouter un conge "),
                                        QObject::tr("conge non ajouté, vérifier les champs.\n""Click Cancel to exit."), QMessageBox::Cancel);


         }}
}

void Dialogemploye::on_pushButtonModifierr_clicked()
{

    QMediaPlayer *player = new QMediaPlayer;
               player->setMedia(QUrl::fromLocalFile("C:/Users/houda/Desktop/music1/son.wav"));
               player->setVolume(3000);
               player->play();
    //Récuprération des informations saisies dans les 3 champs
     int idaa =ui->LeId_222->text().toInt();

    QDateTime debut_conge=ui->dateEdittt->dateTime();
    QDateTime fin_conge=ui->dateEdit_22->dateTime();
    int id2=ui->comboBox_22->currentText().toInt(); //convertir une chaine de caractére en un entier

    bool test2;
        test2=(controleVideInt(id_con) );
       //instancier un objet de la classe Etudiant en utilisant les informations saisies dans l interfaces
            Conge C(idaa,debut_conge,fin_conge,id2);

       //insérer l'objet etudiant instancié dans la table etudiant et recuperer la valeur de retour de query.exec();
       bool test =C.modifierConge();


       if (test2){
       if(test)//si requête executée ==>QMessageBox::information
       {

          //refresh affichage
           ui->tableViewww->setModel(C.afficherConge());
           QMessageBox::information(nullptr,QObject::tr("ok"),
                   QObject::tr("Modification effectué \n Click Cancel to exit."), QMessageBox::Cancel);
       }
       else //si requête non exécutée ==>QMessageBox::critical
           QMessageBox::critical(nullptr,QObject::tr("Not Ok"),
                                 QObject::tr("Modification non effectué. \n ""Click Cancel to exit."),QMessageBox::Cancel);}
       else

         {

             QMessageBox::information(nullptr, QObject::tr("Ajouter un conge "),
                                        QObject::tr("conge non ajouté, vérifier les champs.\n""Click Cancel to exit."), QMessageBox::Cancel);


         }
}


void Dialogemploye::on_pushButtonSupprimerr_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
               player->setMedia(QUrl::fromLocalFile("C:/Users/houda/Desktop/music1/son.wav"));
               player->setVolume(3000);
               player->play();
    int idaa =ui->LeId_222->text().toInt();

    bool test = C.supprimerConge(idaa);
    if(test)
    {
        //refresh affichage
        ui->tableViewww->setModel(C.afficherConge());
        update_id();

        QMessageBox::information(nullptr,QObject::tr("ok"),
                                 QObject::tr("suppression effectué \n ""Click Cancel to exit."),QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr,QObject::tr("not ok"),

QObject::tr("suppression non effectué.\n""Click Cancel to exit."),QMessageBox::Cancel);
}




void Dialogemploye::on_LeIdRTT_textChanged(const QString &arg1)
{
   ui->tableViewww->setModel(C.rechercherID(arg1));
}

void Dialogemploye::on_LeTitreRTT_textChanged(const QString &arg1)
{
   ui->tableViewww->setModel(C.rechercherID_emp(arg1));
}

void Dialogemploye::on_pushButton_33_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
               player->setMedia(QUrl::fromLocalFile("C:/Users/houda/Desktop/music1/son.wav"));
               player->setVolume(3000);
               player->play();

     ui->tableViewww->setModel(C.AfficherTrieDate_debut());

}

void Dialogemploye::on_pushButtonn_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
               player->setMedia(QUrl::fromLocalFile("C:/Users/houda/Desktop/music1/son.wav"));
               player->setVolume(3000);
               player->play();

    ui->tableViewww->setModel(C.AfficherTrieID());
}

void Dialogemploye::on_pushButton_22_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
               player->setMedia(QUrl::fromLocalFile("C:/Users/houda/Desktop/music1/son.wav"));
               player->setVolume(3000);
               player->play();

    ui->tableViewww->setModel(C.AfficherTrieIDE());
}

void Dialogemploye::on_tableViewww_activated(const QModelIndex &index)
{

    QString val=ui->tableViewww->model()->data(index).toString();
              QSqlQuery qry;
              qry.prepare("select * from conge where"
                          " id_conge='"+val+"' or cin_emp='"+val+"' ");
              if(qry.exec())
                {while (qry.next())
               { ui->LeId_222->setText(qry.value(0).toString());
                 ui->dateEdittt->setDateTime(qry.value(1).toDateTime());
                 ui->dateEdit_22->setDateTime(qry.value(2).toDateTime());
                 ui->comboBox_22->setCurrentText(qry.value(3).toString());

                }

}
}

void Dialogemploye::on_tableViewww_clicked(const QModelIndex &index)
{
 id_con=ui->tableViewww->model()->data(index).toInt();
}



void Dialogemploye::on_tabWidget_2_tabBarClicked()
{
    qDeleteAll(ui->tabWidget_3->widget(0)->children());
    QWidget* barstats = new QWidget(this);
    barstats = barchart();
    QGridLayout* layout = new QGridLayout(this);
    layout->addWidget(barstats, 0, 0); // Top-Left
    layout->addWidget(NULL, 0, 1); // Top-Right
    layout->addWidget(NULL, 1, 0); // Bottom-Left
    layout->addWidget(NULL, 1, 1); // Bottom-Right
    ui->tab_6->setLayout(layout);

    qDeleteAll(ui->tabWidget_3->widget(1)->children());
    QWidget* piestats = new QWidget(this);
    piestats = piechart();
    QGridLayout* layout1 = new QGridLayout(this);
    layout1->addWidget(piestats, 0, 0); // Top-Left
    layout1->addWidget(NULL, 0, 1); // Top-Right
    layout1->addWidget(NULL, 1, 0); // Bottom-Left
    layout1->addWidget(NULL, 1, 1); // Bottom-Right
    ui->tab_7->setLayout(layout1);
}

void Dialogemploye::on_tabWidget_tabBarClicked()
{
    ui->tableViewww->setModel(C.afficherConge());
    update_id();
}
/****************************travail khalil*******************************************/
void Dialogemploye::on_pb_ajouter_v_clicked()
{
    //Récuprération des informations saisies dans les 3 champs

    QString matricule = ui->matricule->text();
    QString Type = ui->type->currentText();
    QString Nom_chauffeur = ui->nom_ch->text();
    QDateTime datesortie = ui->date->dateTime();


         //instancier un objet de la classe Vehicule en utilisant les informations saisies dans l interfaces
         Vehicule V(matricule,Type,Nom_chauffeur,datesortie);

         //insérer l'objet etudiant instancié dans la table etudiant et recuperer la valeur de retour de query.exec();

         bool test =V.ajouterVehicule();

         if(test)//si requête executée ==>QMessageBox::information
         {

            //refresh affichage
             ui->tableV->setModel(V.afficherVehicule());
             update_idd();
             QMessageBox::information(nullptr,QObject::tr("ok"),
                     QObject::tr("Ajout effectué \n Click Cancel to exit."), QMessageBox::Cancel);
         }

         else //si requête non exécutée ==>QMessageBox::critical
             QMessageBox::critical(nullptr,QObject::tr("Not Ok"),
                                   QObject::tr("Ajout non effectué. \n ""Click Cancel to exit."),QMessageBox::Cancel);


}

void Dialogemploye::on_modifier_clicked()
{
    QString matricule = ui->matricule->text();
    QString Type = ui->type->currentText();
    QString Nom_chauffeur = ui->nom_ch->text();
    QString datesortie = ui->date->text();
    QSqlQuery qry;
    qry.prepare("update VEHICULEM  set MATRICULE='"+matricule+"',Type='"+Type+"',Nom_chauffeur='"+Nom_chauffeur+"',DATESORTIE='"+datesortie+"' where MATRICULE='"+matricule+"'");
    if(qry.exec())
    {
        ui->tableV->setModel(V.afficherVehicule());
        update_idd();
        QMessageBox::critical(this,tr("Modifier"),tr("l'opération est effectué avec succès"));
    }
    else
    {
        QMessageBox::critical(this,tr("Erreur"),qry.lastError().text());

    }
}


void Dialogemploye::on_supr_2_clicked()
{

 QString sup = ui->sup_m->text();

 QSqlQuery query;

  query.prepare("alter table MAINTENANCE DROP CONSTRAINT FK");
  query.exec();

 query.prepare("Delete from MAINTENANCE where MATRICULE='"+sup+"'");
 query.exec();

query.prepare("Delete from VEHICULEM where MATRICULE='"+sup+"'");
     query.bindValue(0,"+sup+");
    if(query.exec())
    {
        ui->tableV->setModel(V.afficherVehicule());
          ui->tableM->setModel(M.afficherMaintenance());
         update_idd();
        QMessageBox::critical(this,tr("Suprimer"),tr("l'opération est effectué avec succès"));
    }
    else
    {
        QMessageBox::critical(this,tr("Erreur"),query.lastError().text());

    }


/*
    bool test = V.supprimerVehicule();
    if(test)
    {
        //refresh affichage
        ui->tableV->setModel(V.afficherVehicule());
        update_id();
        QMessageBox::information(nullptr,QObject::tr("ok"),
                                 QObject::tr("suppression effectué \n ""Click Cancel to exit."),QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr,QObject::tr("not ok"),

QObject::tr("suppression non effectué.\n""Click Cancel to exit."),QMessageBox::Cancel);
*/
}

void Dialogemploye::on_trier_clicked()

    {
         ui->tableV->setModel(V.AfficherTriematricule());
    }


void Dialogemploye::on_rech_textChanged(const QString &arg1)
{
       ui->tableV->setModel(V.rechercherNom_chauffeur(arg1));
}

void Dialogemploye::on_audio_clicked()
{

    QMediaPlayer *player = new QMediaPlayer;
               player->setMedia(QUrl::fromLocalFile("C:/Users/houda/Desktop/music1/son.wav"));
               player->setVolume(3000);
               player->play();

}

void Dialogemploye::on_ajouter_m_clicked()
{
    QString matricule = ui->affec_matricule->currentText();
    QString Type = ui->type_m->currentText();
    QString cout = ui->cout_m->text();
     QString etat = ui->etat->format();
     QDateTime datepanne = ui->date_m->dateTime();


         //instancier un objet de la classe Vehicule en utilisant les informations saisies dans l interfaces
        Maintenance M(matricule,Type,cout,etat,datepanne);

         //insérer l'objet etudiant instancié dans la table etudiant et recuperer la valeur de retour de query.exec();

         bool test =M.ajouterMaintenance();

         if(test)//si requête executée ==>QMessageBox::information
         {

            //refresh affichage
             ui->tableM->setModel(M.afficherMaintenance());
             update_idd();
             QMessageBox::information(nullptr,QObject::tr("ok"),
                     QObject::tr("Ajout effectué \n Click Cancel to exit."), QMessageBox::Cancel);
         }

         else //si requête non exécutée ==>QMessageBox::critical
             QMessageBox::critical(nullptr,QObject::tr("Not Ok"),
                                   QObject::tr("Ajout non effectué. \n ""Click Cancel to exit."),QMessageBox::Cancel);


}



void Dialogemploye::on_suprimer_m_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
               player->setMedia(QUrl::fromLocalFile("C:/Users/houda/Desktop/music1/son.wav"));
               player->setVolume(3000);
               player->play();

    QString sup = ui->sup_m->text();

    QSqlQuery qry;
    qry.prepare("Delete from MAINTENANCE where MATRICULE='"+sup+"'");
    if(qry.exec())
    {
        ui->tableM->setModel(M.afficherMaintenance());
        update_idd();

        QMessageBox::critical(this,tr("Suprimer"),tr("l'opération est effectué avec succès"));
    }
    else
    {
        QMessageBox::critical(this,tr("Erreur"),qry.lastError().text());

    }
}



void Dialogemploye::on_trier_m_clicked()
{
      ui->tableM->setModel(M.AfficherTriecout());
}


void Dialogemploye::on_rech_m_textChanged(const QString &arg1)
{
    ui->tableM->setModel(M.recherchermatricule(arg1));
}




void Dialogemploye::on_modifier_m_clicked()
{
    {
        QMediaPlayer *player = new QMediaPlayer;
                   player->setMedia(QUrl::fromLocalFile("C:/Users/houda/Desktop/music1/son.wav"));
                   player->setVolume(3000);
                   player->play();

        QString matricule = ui->affec_matricule->currentText();
        QString Type = ui->type_m->currentText();
        QString cout = ui->cout_m->text();
         QString etat = ui->etat->text();
         QString datepanne = ui->date_m->text();



        QSqlQuery qry;
        qry.prepare("update MAINTENANCE set MATRICULE='"+matricule+"',Type='"+Type+"',cout='"+cout+"',etat='"+etat+"',DATEPANNE='"+datepanne+"' where MATRICULE='"+matricule+"'");
        if(qry.exec())
        {
            ui->tableM->setModel(M.afficherMaintenance());

            QMessageBox::critical(this,tr("Modifier"),tr("l'opération est effectué avec succès"));
        }
        else
        {
            QMessageBox::critical(this,tr("Erreur"),qry.lastError().text());

        }
    }
}


void Dialogemploye::update_idd()
{

       QSqlQueryModel *m=new QSqlQueryModel();
       QSqlQuery *querry=new QSqlQuery();
       querry->prepare("select matricule from VEHICULEM");
       querry->exec();
       m->setQuery(*querry);
       ui->affec_matricule->setModel(m);
}




void Dialogemploye::on_pdf_clicked()
{
    {
        Maintenance M;

        QString text=M.apercu_pdf();
        ui->imp_2->setText(text);

                 QPrinter printer ;
                 printer.setPrinterName("imprim");
                 QPrintDialog dialog (&printer,this);
                 if(dialog.exec()==QDialog::Rejected) return ;
                  ui->imp_2->print(&printer);

    }
}


bool Dialogemploye::auto_mail()
{

     QSqlQuery query;
     QDate date = QDate::currentDate();
     query.prepare("SELECT email,nom_emp FROM Employes WHERE cin_emp IN ( SELECT cin_emp  FROM conge WHERE fin_conge=:date ) ");
     query.bindValue(":date",date);
     bool b=query.exec();
     while (query.next())
     {

      QString mail = query.value(0).toString();
      QString nom  = query.value(1).toString();
      QString sujet  ="Police Station" ;
      QString message="Bonjour monsieur "+nom+",\n Votre congée expirera bientot,vous devez nous contactez";

      Smtp* smtp = new Smtp("houda.koubaa@esprit.tn","191JFT51352020","smtp.gmail.com");
      smtp->sendMail("houda.koubaa@esprit.tn",mail,sujet,message);

     }
     return b;

}

/****************************END travail khalil*******************************************/
