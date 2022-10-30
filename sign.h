#ifndef SIGN_H
#define SIGN_H

#include <QDialog>
#include"nvcompte.h"

namespace Ui {
class sign;
}

class sign : public QDialog
{
    Q_OBJECT

public:
    explicit sign(QWidget *parent = nullptr);
    ~sign();

private slots:
    void on_pushButton_clicked();

private:
    Ui::sign *ui;
    sign* s;
};

#endif // SIGN_H
