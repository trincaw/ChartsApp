#include "Chart.h"
#include "AllCharts.h"


QChart* Chart::generateChart(TableData* table)const{
    BarChart br= BarChart();
    return br.generateChart(table);
}
