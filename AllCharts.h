#ifndef ALLCHARTS_H
#define ALLCHARTS_H

#include "Chart.h"
#include <QtCharts>

class BarChart:public Chart{
public:
    BarChart(string titolo);
    QChart* generateChart(Model* model) const;
};
class PieChart:public Chart{
public:
    PieChart(string titolo);
    QChart* generateChart(Model* model) const;
};
class LineChart:public Chart{
public:
    LineChart(string titolo);
    QChart* generateChart(Model* model) const;
};
#endif // ALLCHARTS_H
