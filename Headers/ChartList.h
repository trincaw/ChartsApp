#ifndef CHARTLIST_H
#define CHARTLIST_H
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include <vector>

#include "Chart.h"

QT_USE_NAMESPACE
using namespace QtCharts;
using std::vector;

class ChartLine: public Chart
{
private:
    vector<QLineSeries>* sets;
    QLineSeries *series;
public:
    ChartLine();
    QLineSeries* getSeries();
};

#endif // CHARTLIST_H
