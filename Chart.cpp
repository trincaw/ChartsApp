#include "Chart.h"
#include "AllCharts.h"

Chart::Chart(string titolo){
    chart = new QChart();
    this->titolo=titolo;
    chart->setTitle(QString::fromStdString(titolo));
}

QChart* Chart::generateChart(TableData* table,vector<QColor>* colors)const{
    BarChart br= BarChart(this->titolo);
    return br.generateChart(table,colors);
}
