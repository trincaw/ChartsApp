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
    void addColorMapping();
    void removeColorMapping(){model->clearMapping();};
    ~StackedBarChart();
    QChart* generateChart();
};
class BarChart:public BarredChart{
private:
    QBarSeries *series = new QBarSeries(chart);
public:
    void addColorMapping();
    void removeColorMapping(){model->clearMapping();};
    ~BarChart();
    QChart* generateChart();
};
class PieChart:public RoundChart{
private:
    QPieSeries *series;
public:
    void addColorMapping();
    void removeColorMapping(){model->clearMapping();};
    ~PieChart();
    QChart* generateChart();
};
class LineChart:public ContinuousChart{
private:
    vector<QLineSeries*> series;
public:
    void addColorMapping();
    void removeColorMapping(){model->clearMapping();};
    ~LineChart();
    QChart* generateChart();
};
class SplineChart:public ContinuousChart{
private:
    vector<QSplineSeries*> series;
public:
    void addColorMapping();
    void removeColorMapping(){model->clearMapping();};
    ~SplineChart();
    QChart* generateChart();
};
class ScatterChart:public ContinuousChart{
private:
    vector<QScatterSeries*> series;
public:
    void addColorMapping();
    void removeColorMapping(){model->clearMapping();};
    ~ScatterChart();
    QChart* generateChart();
};
class NestedPieChart:public RoundChart{
private:
    vector<QPieSeries*> donuts;
public:
    void addColorMapping();
    void removeColorMapping(){model->clearMapping();};
    ~NestedPieChart();
    QChart* generateChart();
};

#endif // ALLCHARTS_H
