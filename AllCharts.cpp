#include "AllCharts.h"

QChart* LineChart::generateChart(Model* model,vector<QVXYModelMapper*> *mapper){
    (*mapper)[0]->setXColumn(0);
    (*mapper)[0]->setYColumn(1);

    (*mapper)[0]->setModel(model);

    QLineSeries *series = new QLineSeries;
    series->setName("Line 1");
    (*mapper)[0]->setSeries(series);

    chart->addSeries(series);
    chart->createDefaultAxes();




    series = new QLineSeries;
    series->setName("Line 2");


    (*mapper)[1]->setXColumn(2);
    (*mapper)[1]->setYColumn(3);
    (*mapper)[1]->setSeries(series);
    (*mapper)[1]->setModel(model);
    chart->addSeries(series);
    return chart;
}
