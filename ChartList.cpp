#include "ChartList.h"

ChartLine::ChartLine()
{
    series = new QLineSeries;
    series->setName("Line1");
    //mapper->setSeries(series);
    chart->addSeries(series);
    chart->createDefaultAxes();
}
QLineSeries* ChartLine::getSeries(){
    return series;
}
