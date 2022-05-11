#ifndef CHART_H
#define CHART_H

#include <QtCharts>

#include "Model.h"
#include <vector>
using std::vector;
class Chart
{
protected:
    QChart* chart;
    //QAbstractSeries* serie;

public:
    Chart();
    virtual QChart* generateChart(Model* model,vector<QVXYModelMapper*> *mapper)=0;
};

#endif // CHART_H
