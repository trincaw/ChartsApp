#include "Chart.h"

Chart::Chart()
{
    chart = new QChart();
    //chart->addSeries(series);
    //chart->setTitle("Simple chart");
    chart->setAnimationOptions(QChart::SeriesAnimations);
}
QChart* Chart::getChart(){
    return chart;
}

