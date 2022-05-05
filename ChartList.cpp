#include "ChartList.h"

ChartLine::ChartLine(Model* m)
{
    QLineSeries *series = new QLineSeries;
    series->setName("Line 1");

    QVXYModelMapper *mapper = new QVXYModelMapper();
    mapper->setXColumn(0);
    mapper->setYColumn(1);
    mapper->setSeries(series);
    mapper->setModel(m);

    chart->addSeries(series);
    chart->createDefaultAxes();
}

