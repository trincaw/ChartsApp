#ifndef ALLCHARTS_H
#define ALLCHARTS_H

#include "ChartTypes.h"
#include <QtCharts>

//to create a new chart just select the parent type and define the series
class StackedBarChart:public BarTypeChart<QStackedBarSeries,QBarSet>{};
class BarChart:public BarTypeChart<QBarSeries,QBarSet>{};
class PieChart:public PieTypeChart<QPieSeries,QPieSlice>{};
class LineChart:public LineTypeChart<QLineSeries>{};
class SplineChart:public LineTypeChart<QSplineSeries>{};
class ScatterChart:public LineTypeChart<QScatterSeries>{};
class NestedPieChart:public NestedPieTypeChart<QPieSeries,QPieSlice>{};

#endif // ALLCHARTS_H
