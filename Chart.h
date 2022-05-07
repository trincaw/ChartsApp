#ifndef CHART_H
#define CHART_H

#include <QtCharts>
#include "Model.h"

class Chart
{
protected:
    QChart* chart;
    //QAbstractSeries* serie;

public:
    Chart();
    QChart* getChart();
    virtual void setModel(Model* model)=0;
};

#endif // CHART_H
