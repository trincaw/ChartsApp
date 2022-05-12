#ifndef ALLCHARTS_H
#define ALLCHARTS_H

#include "Chart.h"
#include "QLineSeries"
#include <QtCharts>

class LineChart:public Chart{
public:
    LineChart(string titolo,vector<string>* seriesNames);
    QChart* generateChart(Model* model,vector<QVXYModelMapper*> *mapper);
};
class BarChart:public Chart{
public:
    QChart* generateChart(Model* model,vector<QVXYModelMapper*> *mapper);
};
#endif // ALLCHARTS_H
