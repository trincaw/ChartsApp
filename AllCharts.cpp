#include "AllCharts.h"

void LineChart::setUp(Model* model,QVXYModelMapper *mapper){
    //if(model->columnCount()%2==0)
    //for(int i=0;i<model->columnCount();++i)
    mapper->setXColumn(0);
    mapper->setYColumn(1);

    mapper->setModel(model);

    QLineSeries *series = new QLineSeries;
    series->setName("Line 1");
    //mapper->setSeries(series);

    chart->addSeries(series);
    chart->createDefaultAxes();




    series = new QLineSeries;
    series->setName("Line 2");

    mapper = new QVXYModelMapper();
    mapper->setXColumn(2);
    mapper->setYColumn(3);
    mapper->setSeries(series);
    mapper->setModel(model);
    chart->addSeries(series);

}
