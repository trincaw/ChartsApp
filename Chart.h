#ifndef CHART_H
#define CHART_H

#include <QChart>

#include <vector>
#include <string>

#include "Model.h"

using QtCharts::QChart;
class Chart
{
public:
    virtual QChart* generateChart(TableData* model) const =0;
    //Chart()=default;
    ~Chart()=default;
};

#endif // CHART_H
