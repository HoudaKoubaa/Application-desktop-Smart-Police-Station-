#ifndef ACCEUIL_H
#define ACCEUIL_H
#include "ui_acceuil.h"

#include <QDialog>
#include <QSqlQuery>
#include <QCheckBox>
#include <sms.h>
#include <QMessageBox>
#include <QDebug>
#include <QComboBox>
#include <arduino.h>
//stat
#include<QtCharts>
#include<QChartView>
#include<QPieSeries>
#include<QPieSlice>
#include <QPropertyAnimation>
#include <QSystemTrayIcon>
#include <qsystemtrayicon.h>
#include <QMainWindow>
#include <QFileDialog>

//les INCLUDES **********
#include "violence.h"
#include "accident.h"
#include "notification.h"
#include "sms.h"
#include "dialogemploye.h"
#include "employes.h"
#include "conge.h"
#include "nvcompte.h"

#include "citoyen.h"
#include "assistance.h"
#include "rdv.h"
//Sound

#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QSound>
//animation
#include <QPropertyAnimation>

namespace Ui {
class acceuil;
}

class acceuil : public QDialog
{
    Q_OBJECT

public:
    explicit acceuil(QWidget *parent = nullptr);
    ~acceuil();


    void update_id();
    void updatee_id();
    void refrechir();
    //Statistuque table violance **********//

    int G_PVS1();
    int G_PVS2();
    int G_PVS3();
    QChartView* piechart();

//**********nvCompte**************//
    void Get_utilisateur();
    void Set_Identifiant(QString id){
        identifiant=id;
    }




private slots:

    void on_gestionViolance_clicked();

    void on_gestionAccident_clicked();

    void on_ajouter_4_clicked();

    void on_Modifier_5_clicked();

    void on_Supprimer_3_clicked();

    void on_ajouter_clicked();

    void on_Supprimer_clicked();

    void on_pushButton_tri_3_clicked();

    void on_comboBox_3_currentIndexChanged();

    void on_comboBox2_currentIndexChanged();

    void on_Modifier_2_clicked();

    void on_gestionAccident_2_clicked();


    void on_envoyer_5_clicked();

    void on_pushButton_envoyerSMS_3_clicked();

    void on_pushButton_affichersms_4_clicked();

    void on_pushButton_suprimersms_4_clicked();

    void on_tabWidget_2_tabBarClicked();


    void on_Impdos_2_clicked();

    void on_dark_clicked();

    void on_white_clicked();

    void on_pushButton_3_clicked();

    void on_pushButtonquitter_clicked();


    /***************************travail de Ahmed*************************************/

    void on_pb_ajouter_clicked();

    void on_ajouter_citoyen_clicked();

    void on_pb_supp_clicked();

    void on_modifier_citoyen_clicked();

    void on_tri_citoyen_clicked();

    void on_le_cin_supp_textChanged(const QString &arg1);

    void on_pb_consultation_supp_clicked();

    void on_pb_consultation_modifier_clicked();

    void on_pb_tri_consultation_clicked();

    void on_le_consultation_supp_textChanged(const QString &arg1);

    void on_affec_citoyen_clicked();



    void on_pb_enregistrer_3_clicked();

    void on_print_rdv_3_clicked();

    void on_pb_supp_rdv_3_clicked();

    void on_trie_rdv_3_clicked();

    void on_le_rdv_supp_3_textChanged(const QString &arg1);

/*************************** FIN travail de Ahmed***************************************/



    void on_gestionCitoyen_clicked();

    void on_gestionAssistance_clicked();

    void on_gestionRDV_clicked();


    void on_dec_clicked();

    void on_pause_2_clicked();

    void on_start_2_clicked();

    void on_horizontalSlider_2_sliderMoved(int position);

    void on_LeIdRT_textChanged(const QString &arg1);

    void on_supcin_2_textChanged(const QString &arg1);

private:
    Ui::acceuil *ui;
    violence etd;
   acceuil* acc;
   QMediaPlayer* player;

   accident acciden;
   nvcompte nv;
   QMediaPlayer*	playermusic;
   QString identifiant;

   QSystemTrayIcon *notifier;
   /*************travail de ahmed ******************/

   Citoyen tmpcitoyen;
   Assistance tmpassistance;
   rdv tmprdv;
   arduino a;
   QByteArray data,ard;

   /*************************** FIN travail de Ahmed***************************************/


};

#endif // ACCEUIL_H
