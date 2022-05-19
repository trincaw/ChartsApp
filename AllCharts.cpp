#include "AllCharts.h"

LineChart::LineChart(string titolo,vector<string>* seriesNames):Chart(titolo,seriesNames){};
QChart* LineChart::generateChart(TableData* table){

    QChart *chart = new QChart();
    chart->setTitle("Bar chart");

    QStackedBarSeries *series = new QStackedBarSeries(chart);
    for (u_int i(0); i < table->getColumnCount(); i++) {
        QBarSet *set = new QBarSet("Bar set " + QString::number(i+1));
        for (u_int j=0;j < table->getRowCount();++j)
            *set << table->getTable()->at(i).at(j);
        series->append(set);
        chart->createDefaultAxes();
    }
    chart->addSeries(series);
chart->createDefaultAxes();


    return chart;
}
