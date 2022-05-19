#ifndef ALLCHARTS_H
#define ALLCHARTS_H

#include "Chart.h"
#include "QLineSeries"
#include <QtCharts>

class LineChart:public Chart{
public:
    LineChart(string titolo,vector<string>* seriesNames);
    QChart* generateChart(TableData* table);
};
#endif // ALLCHARTS_H
