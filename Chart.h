#ifndef CHART_H
#define CHART_H

#include <QChart>
#include <QVXYModelMapper>

#include <vector>
#include <string>

#include "Model.h"

using std::vector;
using QtCharts::QChart;
using QtCharts::QVXYModelMapper;
using std::string;
class Chart
{
protected:
    QChart* chart;

    string titolo;
    vector<string>* seriesNames;

public:
    Chart(string titolo,vector<string>* seriesNames);
    virtual QChart* generateChart(Model* model,vector<QVXYModelMapper*> *mapper)=0;
};

#endif // CHART_H
