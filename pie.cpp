/*#include "ui_acceuil.h"
#include "acceuil.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QString>
#include <string>
#include <QMessageBox>
#include <QLineEdit>
#include <QSqlQueryModel>

QChartView* acceuil::piechart()
{

    QPieSeries *series = new QPieSeries();
    QPieSeries *series1 = new QPieSeries();


    series->append("sexuelle", 1);
    series->append("physique", 2);
    series->append("psychologique", 3);

    series1->append("", 1);
    series1->append("", 2);
    series1->append("", 3);

    series1->hide();
    series->slices().at(0)->setValue(G_PVS1());
    series->slices().at(1)->setValue(G_PVS2());
    series->slices().at(2)->setValue(G_PVS3());
    series->slices().at(0)->setBrush(Qt::darkCyan);
    series->slices().at(1)->setBrush(Qt::darkBlue);
    series->slices().at(2)->setBrush(Qt::blue);

    series1->slices().at(0)->setValue(G_PVS1());
    series1->slices().at(1)->setValue(G_PVS2());
    series1->slices().at(2)->setValue(G_PVS3());

    series1->slices().at(0)->setBrush(Qt::darkCyan);
    series1->slices().at(1)->setBrush(Qt::darkBlue);
    series1->slices().at(2)->setBrush(Qt::blue);
    series->slices().at(2)->setExploded();
    series1->slices().at(2)->setExploded();

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->addSeries(series1);
    chart->setTitle("STATISTIQUE SELON TYPE DE VIOLANCE ");
    chart->setAnimationOptions(QChart::AllAnimations);



    QChartView *chartView1 = new QChartView(chart);
    chartView1->setRenderHint(QPainter::Antialiasing);




    series1->setLabelsVisible();

    for(auto slice : series1->slices())
    slice->setLabel(QString("%1%").arg(100*slice->percentage(), 0, 'f', 1));





    return chartView1;
}

int acceuil::G_PVS1()
{
    int c21=0;
    QSqlQuery qry21;
    qry21.exec("SELECT ID_TRAFFIC FROM VIOLANCE_ARNAQUE WHERE  SUBSTR(TYPE,1,9)=sexuelle");
    while(qry21.next())
    {
        c21++;
    }
    return c21;
}
int acceuil::G_PVS2()
{
    int c20=0;
    QSqlQuery qry20;
    qry20.exec("SELECT ID_TRAFFIC FROM VIOLANCE_ARNAQUE WHERE SUBSTR(TYPE,1,9)=physique ");
    while(qry20.next())
    {
        c20++;
    }
    return c20;
}
int acceuil::G_PVS3()
{
    int c19=0;
    QSqlQuery qry19;
    qry19.exec("SELECT ID_TRAFFIC FROM VIOLANCE_ARNAQUE WHERE SUBSTR(TYPE,1,13)=psychologique ");
    while(qry19.next())
    {
        c19++;
    }
    return c19;
}

*/
