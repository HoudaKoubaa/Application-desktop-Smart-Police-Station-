#ifndef DIALOGEMPLOYE_H
#define DIALOGEMPLOYE_H
#include "employes.h"
#include "conge.h"
#include <QDialog>
#include <QMediaPlayer>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include<QSound>
#include <QtCharts>
#include <QSystemTrayIcon>
#include <qsystemtrayicon.h>
#include <QPixmap>
#include <QPropertyAnimation>
#include <QPrinter>
#include <QPrintDialog>
#include "maintenance.h"
#include "vehicule.h"

namespace Ui {
class Dialogemploye;
}

class Dialogemploye : public QDialog
{
    Q_OBJECT

public:
    explicit Dialogemploye(QWidget *parent = nullptr);
    ~Dialogemploye();

    void update_id();
    void updatee_id();


    int R_BCS1();
    int R_BCS2();
    int R_BCS3();
    int R_BCS4();
    int R_BCS5();
    int R_BCS6();

    int G_PVS1();
    int G_PVS2();
    int G_PVS3();

        QChartView* barchart();
        QChartView* piechart();

private slots:


    bool controleVide(QString test);

    bool controleVideInt(int test);
    bool auto_mail();

    bool controleEmail(QString test);
    bool controledate(QDateTime debut,QDateTime fin);

    void on_pushButtonAjouter_clicked();

    void on_pushButtonSupprimer_clicked();

    void on_pushButtonModifier_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_LeIdRT_textChanged(const QString &arg1);

    void on_LeTitreRT_textChanged(const QString &arg1);

    void on_tableView_activated(const QModelIndex &index);

    void on_tableView_clicked(const QModelIndex &index);

    void on_Impdos_2_clicked();



    void on_lineEdit_3_textChanged(const QString &arg1);

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();



   // void on_tabWidget_tabBarClicked(int index);

    void on_pushButtonmail_clicked();



    void on_pushButtonAjouterr_clicked();

    void on_pushButtonModifierr_clicked();

    void on_pushButtonSupprimerr_clicked();

    void on_LeIdRTT_textChanged(const QString &arg1);

    void on_LeTitreRTT_textChanged(const QString &arg1);

    void on_pushButton_33_clicked();

    void on_pushButtonn_clicked();

    void on_pushButton_22_clicked();

    void on_tableViewww_activated(const QModelIndex &index);

    void on_tableViewww_clicked(const QModelIndex &index);

    void on_tabWidget_2_tabBarClicked();

    void on_tabWidget_tabBarClicked();
    /******************************************************************************************/
    void update_idd();


    void on_pb_ajouter_v_clicked();

    void on_modifier_clicked();



    void on_supr_2_clicked();

    void on_trier_clicked();

    void on_rech_textChanged(const QString &arg1);

    void on_audio_clicked();

    void on_ajouter_m_clicked();

    void on_suprimer_m_clicked();

    void on_rech_m_textChanged(const QString &arg1);

    void on_trier_m_clicked();

    void on_pdf_clicked();

    void on_modifier_m_clicked();





    /******************************************************************************************/
private:
    Ui::Dialogemploye *ui;
    Employes emp;
    int id_emp=0;
    QMediaPlayer*	player;
    Conge C;
    int id_con=0;
    QSystemTrayIcon *notifier;
    Vehicule V;
    Maintenance M;
};

#endif // DIALOGEMPLOYE_H

