#ifndef ALLCHARTS_H
#define ALLCHARTS_H

#include "ChartTypes.h"
#include <QtCharts>
#include <vector>
using std::vector;

class StackedBarChart:public BarredChart{
private:
QStackedBarSeries *series;
public:
    QChart* generateChart();
    void colorChart();
};
class BarChart:public BarredChart{
private:
    QBarSeries *series = new QBarSeries(chart);
public:
    QChart* generateChart();
    void colorChart();
};
class PieChart:public RoundChart{
private:
    QPieSeries *series;
public:
    QChart* generateChart();
    void colorChart();
};
class LineChart:public ContinuousChart{
private:
    vector<QLineSeries*> series;
public:
    QChart* generateChart();
    void colorChart();
};
class SplineChart:public ContinuousChart{
private:
    vector<QSplineSeries*> series;
public:
    QChart* generateChart();
    void colorChart();
};
class ScatterChart:public ContinuousChart{
private:
    vector<QScatterSeries*> series;
public:
    QChart* generateChart();
    void colorChart();
};
class NestedPieChart:public RoundChart{
private:
    vector<QPieSeries*> donuts;
public:
    QChart* generateChart();
    void colorChart();
};

#endif // ALLCHARTS_H
