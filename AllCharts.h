#ifndef ALLCHARTS_H
#define ALLCHARTS_H

#include "ChartTypes.h"
#include <QtCharts>

//per creare un nuovo grafco basta selezionare il tipo padre e definire le series
class BarChart:public BarTypeChart<QStackedBarSeries,QBarSet>{};
class PieChart:public PieTypeChart<QPieSeries,QPieSlice>{};
class LineChart:public LineTypeChart<QLineSeries>{};
class SplineChart:public LineTypeChart<QSplineSeries>{};
class ScatterChart:public LineTypeChart<QScatterSeries>{};
class NestedPieChart:public NestedPieTypeChart<QPieSeries,QPieSlice>{};

#endif // ALLCHARTS_H
