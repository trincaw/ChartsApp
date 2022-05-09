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
    virtual void setUp(Model* model,QVXYModelMapper *mapper)=0;
};

#endif // CHART_H
