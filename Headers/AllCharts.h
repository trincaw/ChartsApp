#ifndef ALLCHARTS_H
#define ALLCHARTS_H

#include "ChartTypes.h"
#include <QtCharts>
#include <vector>
using std::vector;

class BarChart:public BarredChart{
private:
    QBarSeries *series;
public:
    void addColorMapping();
    void removeColorMapping(){model->clearMapping();};
    ~BarChart();
    QChart* generateChart();
};
class StackedBarChart:public BarredChart{
private:
    QStackedBarSeries *series;
public:
    void addColorMapping();
    void removeColorMapping(){model->clearMapping();};
    ~StackedBarChart();
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
class DonutChart:public RoundChart{
private:
    QPieSeries *series;
public:
    void addColorMapping();
    void removeColorMapping(){model->clearMapping();};
    ~DonutChart();
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
class ScatterChart:public Chart{
private:
    vector<QScatterSeries*> series;
public:
    void addColorMapping();
    void removeColorMapping(){model->clearMapping();};
    ~ScatterChart();
    QChart* generateChart();
};
class NestedPieChart:public Chart{
private:
    vector<QPieSeries*> donuts;
public:
    void addColorMapping();
    void removeColorMapping(){model->clearMapping();};
    ~NestedPieChart();
    QChart* generateChart();
};

#endif // ALLCHARTS_H
