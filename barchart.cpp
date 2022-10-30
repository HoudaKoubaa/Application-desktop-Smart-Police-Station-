#include <QSqlDatabase>
#include <QSqlQuery>
#include <QString>
#include <string>
#include <QMessageBox>
#include <QLineEdit>
#include <QSqlQueryModel>
#include <QtCharts>
#include "dialogemploye.h"





QChartView* Dialogemploye::barchart()
{

QBarSet *set0 = new QBarSet("gouverneur de la police");
QBarSet *set1 = new QBarSet("officier de police");
QBarSet *set2 = new QBarSet("officier de police adjoint");
QBarSet *set3 = new QBarSet("inspecteur de police");
QBarSet *set4 = new QBarSet("lieutenant");
QBarSet *set5 = new QBarSet("Chef de police");


*set0 << R_BCS1()  ;
*set1 << R_BCS2()  ;
*set2 << R_BCS3()  ;
*set3 << R_BCS4()  ;
*set4 << R_BCS5()  ;
*set5 << R_BCS6()  ;

//![1]

//![2]
QBarSeries *series = new QBarSeries();
series->append(set0);
series->append(set1);
series->append(set2);
series->append(set3);
series->append(set4);
series->append(set5);



//![2]

//![3]


QChart *chart = new QChart();
chart->addSeries(series);
chart->setTitle("GRADE des Employes");
chart->setAnimationOptions(QChart::SeriesAnimations);
chart->resize(50,30);
//![3]

//![4]
QStringList categories;
categories << "2021"  ;
QBarCategoryAxis *axis = new QBarCategoryAxis();
axis->append(categories);
chart->createDefaultAxes();
chart->setAxisX(axis, series);
//![4]

//![5]
chart->legend()->setVisible(true);
chart->legend()->setAlignment(Qt::AlignBottom);
//![5]

//![6]
QChartView *chartView = new QChartView(chart);
chartView->setRenderHint(QPainter::Antialiasing);
return chartView;
}

int Dialogemploye::R_BCS1()
{
    QSqlQuery query;
    query.exec("SELECT CIN_EMP FROM employes WHERE grade='gouverneur de la police'");
    int f=0;
    while(query.next())
    {
        f++;
    }
    return f;
}

int Dialogemploye::R_BCS2()
{
    QSqlQuery query;
    query.exec("SELECT CIN_EMP FROM employes WHERE grade='officier de police' ");
    int f=0;
    while(query.next())
    {
        f++;
    }
    return f;
}

int Dialogemploye::R_BCS3()
{
    QSqlQuery query;
    query.exec("SELECT CIN_EMP FROM employes WHERE grade='officier de police adjoint' ");
    int f=0;
    while(query.next())
    {
        f++;
    }
    return f;
}



int Dialogemploye::R_BCS4()
{
    QSqlQuery query;
    query.exec("SELECT CIN_EMP FROM employes WHERE grade='inspecteur de police' ");
    int f=0;
    while(query.next())
    {
        f++;
    }
    return f;
}

int Dialogemploye::R_BCS5()
{
    QSqlQuery query;
    query.exec("SELECT CIN_EMP FROM employes WHERE grade='lieutenant' ");
    int f=0;
    while(query.next())
    {
        f++;
    }
    return f;
}

int Dialogemploye::R_BCS6()
{
    QSqlQuery query;
    query.exec("SELECT CIN_EMP FROM employes WHERE grade='Chef de police' ");
    int f=0;
    while(query.next())
    {
        f++;
    }
    return f;
}

