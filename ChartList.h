#ifndef CHARTLIST_H
#define CHARTLIST_H
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include <vector>
#include "qvxymodelmapper.h"

#include "Model.h"
#include "Chart.h"

QT_USE_NAMESPACE
using namespace QtCharts;
using std::vector;

class ChartLine: public Chart
{
private:
public:
    ChartLine(Model* m);
};

#endif // CHARTLIST_H
