#include "quitter.h"
#include "ui_quitter.h"

quitter::quitter(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::quitter)
{
    ui->setupUi(this);
}

quitter::~quitter()
{
    delete ui;
}

void quitter::on_pushButton_2_clicked()
{
    close();
}

void quitter::on_pushButton_clicked()
{
exit(1);
}

