#include "Chart.h"

Chart::Chart(){

    chart = new QChart();
}

QChart* Chart::getChart(){
    return chart;
}

