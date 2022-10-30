#ifndef QUITTER_H
#define QUITTER_H
#include <QDialog>

namespace Ui {
class quitter;
}

class quitter : public QDialog
{
    Q_OBJECT

public:
    explicit quitter(QWidget *parent = 0);
    ~quitter();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::quitter *ui;
};


#endif // QUITTER_H

