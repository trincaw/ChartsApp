#ifndef ALLCHARTS_H
#define ALLCHARTS_H

#include "Chart.h"
#include <QtCharts>

class BarChart:public Chart{
public:
    BarChart(string titolo);
    QChart* generateChart(TableData* table,vector<QColor>* colors) const;
};
class PieChart:public Chart{
public:
    PieChart(string titolo);
    QChart* generateChart(TableData* table,vector<QColor>* colors) const;
};
#endif // ALLCHARTS_H
