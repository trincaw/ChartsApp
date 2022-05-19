#include "AllCharts.h"

BarChart::BarChart(string titolo):Chart(titolo){};
QChart* BarChart::generateChart(TableData* table,vector<QColor>* colors) const
{
    QChart *chart = new QChart();
    chart->setTitle("Bar chart");

    QStackedBarSeries *series = new QStackedBarSeries(chart);
    for (u_int i(0); i < table->getColumnCount(); i++) {
        QBarSet *set = new QBarSet("Bar set " + QString::number(i+1));
        for (u_int j=0;j < table->getRowCount();++j)
            *set << table->getTable()->at(i).at(j);
        series->append(set);
        colors->push_back(set->color());
        chart->createDefaultAxes();
    }
    chart->addSeries(series);
    chart->createDefaultAxes();


    return chart;
}
PieChart::PieChart(string titolo):Chart(titolo){};
QChart* PieChart::generateChart(TableData* table,vector<QColor>* colors) const
{
    QChart *chart = new QChart();
    chart->setTitle("Pie chart");

    QPieSeries *series = new QPieSeries(chart);

    bool frist=true;

    for (u_int i(0); i < table->getColumnCount(); i++) {
        QPieSlice *slice = series->append(QString::fromStdString(table->getColumnsNames()->at(i)),table->getTable()->at(0).at(i));
        colors->push_back(slice->color());
        if (table->getTable()->at(0).at(i)>0 && frist) {
            // Show the first slice exploded with label
            frist=false;
            slice->setLabelVisible();
            slice->setExploded();
            slice->setExplodeDistanceFactor(0.4);
        }
    }
    series->setPieSize(0.6);
    chart->addSeries(series);

    return chart;
}
