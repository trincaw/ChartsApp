#ifndef CHART_H
#define CHART_H
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include <vector>

QT_USE_NAMESPACE
using namespace QtCharts;
using std::vector;
class Chart
{
protected:
    QChart *chart;
public:
    Chart();
    QChart* getChart();

};

#endif // CHART_H
