#ifndef MAILING_H
#define MAILING_H

#include <QDialog>
#include <QMediaPlayer>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include<QSound>

namespace Ui {
class mailing;
}

class mailing : public QDialog
{
    Q_OBJECT

public:
    explicit mailing(QWidget *parent = nullptr);
    ~mailing();
private slots:
    void on_envoyer_clicked();
    void on_envoyer_2_clicked();



private:
    Ui::mailing *ui;
    QMediaPlayer*	player;
};

#endif // MAILING_H

