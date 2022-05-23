#include "Chart.h"
#include "AllCharts.h"

Chart::Chart(string titolo){
    chart = new QChart();
    this->titolo=titolo;
    chart->setTitle(QString::fromStdString(titolo));
}
QChart* Chart::generateChart(Model* model)const{
    LineChart br= LineChart(this->titolo);
    return br.generateChart(model);
}
