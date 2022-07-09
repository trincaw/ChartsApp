#ifndef CHART_H
#define CHART_H

#include <QtCharts>
#include "TableData.h"


class Chart
{
protected:
    TableData table;
public:
    void setTableData(TableData table){this->table=table;};
    virtual ~Chart()=default;
    virtual QChart* generateChart()=0;
};

#endif // CHART_H
