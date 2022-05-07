#ifndef LINECHART_H
#define LINECHART_H

#include "Chart.h"


class LineChart:public Chart{
private:
    QLineSeries* series;
    QVXYModelMapper *mapper;
public:
    LineChart(QVXYModelMapper *mapper);
    void setModel(Model* model);
};

#endif // LINECHART_H
