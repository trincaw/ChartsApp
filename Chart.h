#ifndef CHART_H
#define CHART_H

#include <QtCharts>
#include "Model.h"

class Chart
{
protected:
    Model* model = nullptr;
    QChart *chart = nullptr;
public:
    void setModel(Model* model){this->model=model;};
    virtual ~Chart()=default;
    virtual QChart* generateChart()=0;
    virtual void addColorMapping()=0;
    virtual void removeColorMapping()=0;
};

#endif // CHART_H
