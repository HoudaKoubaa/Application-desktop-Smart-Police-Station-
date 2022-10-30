#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>
#include <QMessageBox>
#include <QString>
#include <QDebug>
#include <QSplashScreen>
#include <QTimer>
#include "login.h"
#include "acceuil.h"
#include "sign.h"
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QtCharts/QChart>
#include <QtCharts/QPieSeries>
#include<arduino.h>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void GetLogin();

private slots:
    void on_pushButton_clicked();
    void on_pushButton1_clicked();


private:
    Ui::MainWindow *ui;
    QString username="",password="";
    QMediaPlayer *musicLogin= new QMediaPlayer;
    login e;
    acceuil a;
    sign* s;
    arduino A;
    QByteArray data,ard;
    QSerialPort *arduino;
};
#endif // MAINWINDOW_H
