#include "mailing.h"
#include "ui_mailing.h"
#include "QMessageBox"
#include "smtp.h"


mailing::mailing(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mailing)
{
    ui->setupUi(this);
    player = new QMediaPlayer;


}

mailing::~mailing()
{
    delete ui;
}

void mailing::on_envoyer_clicked()
{
    player->setMedia(QUrl::fromLocalFile("C:/Users/Zeineb/Desktop/Source2/son.wav"));
    player->play();
    qDebug() << player->errorString();

    QString mail_destinataire=ui->comboBox_3->text();
      QString sujet=ui->lineedit_sujet->text();
      QString message=ui->lineedit_msg->text();


     Smtp* smtp = new Smtp("houda.koubaa@esprit.tn","191JFT51352020","smtp.gmail.com");
     smtp->sendMail("houda.koubaa@esprit.tn",ui->comboBox_3->text(),ui->lineedit_sujet->text(),ui->lineedit_msg->text());
     ui->comboBox_3->clear();
     ui->lineedit_sujet->clear();
     ui->lineedit_msg->clear();

   this->close();

}
void mailing::on_envoyer_2_clicked()
{
    this->close();
}


