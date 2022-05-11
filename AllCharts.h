#ifndef ALLCHARTS_H
#define ALLCHARTS_H

#include "Chart.h"

class LineChart:public Chart{
public:
    QChart* generateChart(Model* model,vector<QVXYModelMapper*> *mapper);
};

#endif // ALLCHARTS_H
