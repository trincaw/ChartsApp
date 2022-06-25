#ifndef ALLCHARTS_H
#define ALLCHARTS_H

#include "Chart.h"
#include <QtCharts>

class BarChart:public Chart{
public:
    QChart* generateChart(TableData* table)  const;
};
class PieChart:public Chart{
public:
    QChart* generateChart(TableData* table) const;
};
class LineChart:public Chart{
public:
    QChart* generateChart(TableData* table) const;
};
class SplineChart:public Chart{
public:
    QChart* generateChart(TableData* table) const;
};
class ScatterChart:public Chart{
public:
    QChart* generateChart(TableData* table) const;
};
class NestedPieChart:public Chart{
public:
    QChart* generateChart(TableData* table) const;
};
#endif // ALLCHARTS_H
