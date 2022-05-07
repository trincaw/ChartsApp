#include "LineChart.h"

LineChart::LineChart(QVXYModelMapper *mapper)
{this->mapper=mapper;}
void LineChart::setModel(Model* model){
    mapper->setXColumn(0);
    mapper->setYColumn(1);

    mapper->setModel(model);
}
void LineChart::start(){
    chart->setAnimationOptions(QChart::AllAnimations);
    QLineSeries *series = new QLineSeries;
    series->setName("Line1");
    mapper->setSeries(series);
    chart->addSeries(series);
    chart->createDefaultAxes();
}
