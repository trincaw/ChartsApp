#ifndef ALLCHARTS_H
#define ALLCHARTS_H

#include "Chart.h"

class LineChart:public Chart{
public:
    void setUp(Model* model,QVXYModelMapper *mapper);
};

#endif // ALLCHARTS_H
