#ifndef CHART_H
#define CHART_H

#include <QChart>

#include <vector>
#include <string>

#include "Model.h"

using std::vector;
using QtCharts::QChart;
using std::string;
class Chart
{
protected:
    QChart* chart;
    string titolo;

public:
    Chart(string titolo);
    virtual QChart* generateChart(Model* model)const;
};

#endif // CHART_H
