#ifndef ALLCHARTS_H
#define ALLCHARTS_H

#include "ChartTypes.h"
#include <QtCharts>
#include <vector>
using std::vector;

class StackedBarChart:public BarredChart{
private:
QStackedBarSeries *series;
    void colourChart();
public:
    QChart* generateChart();
};
class BarChart:public BarredChart{
private:
    QBarSeries *series = new QBarSeries(chart);
    void colourChart();
public:
    QChart* generateChart();
};
class PieChart:public RoundChart{
private:
    QPieSeries *series;
    void colourChart();
public:
    QChart* generateChart();
};
class LineChart:public ContinuousChart{
private:
    vector<QLineSeries*> series;
    void colourChart();
public:
    QChart* generateChart();
};
class SplineChart:public ContinuousChart{
private:
    vector<QSplineSeries*> series;
    void colourChart();
public:
    QChart* generateChart();
};
class ScatterChart:public ContinuousChart{
private:
    vector<QScatterSeries*> series;
    void colourChart();
public:
    QChart* generateChart();
};
class NestedPieChart:public RoundChart{
private:
    vector<QPieSeries*> donuts;
    void colourChart();
public:
    QChart* generateChart();
};

#endif // ALLCHARTS_H
