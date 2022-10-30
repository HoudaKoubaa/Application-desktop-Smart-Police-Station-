#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "login.h"
#include "acceuil.h"
#include "ui_acceuil.h"
#include "nvcompte.h"
#include "sign.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::GetLogin()
{
    username=ui->user->text();
    password=ui->password->text();
}


void MainWindow::on_pushButton_clicked()
{
    QSqlQuery qry;
    username=ui->user->text();
    password=ui->password->text();

    if(qry.exec("SELECT username, password FROM USERS WHERE Username=\'"+ username +"\' AND password=\'" + password + "\'"))
    {
        if(qry.next())
        {


                  ui->label_errur->setText("[+]Valid Username and Password");
                  QByteArray br = username.toUtf8();

                   A.write_to_arduino(br);
                  qDebug() << br;

                 acceuil a;
                 this->hide();
                 //  GetMusic();

                 this->hide();
                 a.Set_Identifiant(username);
                 a.Get_utilisateur();
                 a.show();
                 a.showFullScreen();
                 a.setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

                 a.exec();



                }
                else{
                      ui->label_errur->setText("[-]UnValid Username and Password");



        }

    }}
//******************************************Ajout User  ********************************************************//



void MainWindow::on_pushButton1_clicked()
{

    sign s;
    s.show();
    s.exec();


}
