#ifndef CHART_H
#define CHART_H

#include <QtCharts>
#include "TableData.h"


class Chart
{
public:
    virtual ~Chart()=default;
    virtual QChart* generateChart(TableData* table)=0;
};

#endif // CHART_H
