#include "AllCharts.h"

QChart* BarChart::generateChart(TableData* table) const
{
    QChart *chart = new QChart();

    QStackedBarSeries *series = new QStackedBarSeries(chart);
    for (u_int i(0); i < table->getColumnCount(); i++) {
        QBarSet *set = new QBarSet("Bar set " + QString::number(i+1));
        for (u_int j=0;j < table->getRowCount();++j)
            *set << table->getTable()->at(j).at(i);
        series->append(set);
        chart->createDefaultAxes();
    }
    chart->addSeries(series);
    chart->createDefaultAxes();


    return chart;
}
QChart* PieChart::generateChart(TableData* table) const
{
    QChart *chart = new QChart();

    QPieSeries *series = new QPieSeries(chart);

    bool frist=true;

    for (u_int i(0); i < table->getColumnCount(); i++) {
        QPieSlice *slice = series->append(QString::fromStdString(table->getColumnsNames()->at(i)),table->getTable()->at(0).at(i));
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
QChart* LineChart::generateChart(TableData* table) const{
    QChart *chart = new QChart();

    QString name("Series ");
    int nameIndex = 0;
    for (u_int i(0); i < table->getColumnCount(); i++) {
        QLineSeries *series = new QLineSeries(chart);
        for (u_int j=0;j < table->getRowCount();j=j+2)
            series->append(table->getTable()->at(j).at(i),table->getTable()->at(j).at(i+1));
        series->setName(name + QString::number(nameIndex));
        nameIndex++;
        chart->addSeries(series);
         chart->createDefaultAxes();
    }

    return chart;
}
QChart* SplineChart::generateChart(TableData* table) const{
    QChart *chart = new QChart();
    QString name("Series ");
    int nameIndex = 0;
    u_int columns=table->getColumnCount();
    if(!columns%2==0)
        columns-=1;
    for (u_int i(0); i < table->getRowCount(); ++i) {
        QSplineSeries *series = new QSplineSeries(chart);
        for (u_int j=0;j < columns;j=j+2)
            series->append(table->getTable()->at(i).at(j),table->getTable()->at(i).at(j+1));
        series->setName(name + QString::number(nameIndex));
        nameIndex++;
        chart->addSeries(series);
    }

    chart->createDefaultAxes();
    return chart;
}
//template<typename T>
//void f(T s,TableData* table,QChart *chart)
//{
//    QString name("Series ");
//    int nameIndex = 0;
//    u_int columns=table->getColumnCount();
//    if(!columns%2==0)
//        columns-=1;
//    for (u_int i(0); i < table->getRowCount(); ++i) {
//        s = new T(chart);
//        for (u_int j=0;j < columns;j=j+2)
//            s->append(table->getTable()->at(i).at(j),table->getTable()->at(i).at(j+1));
//        s->setName(name + QString::number(nameIndex));
//        nameIndex++;
//        chart->addSeries(s);
//    }
//}
QChart* ScatterChart::generateChart(TableData* table) const{
    QChart *chart = new QChart();
    int nameIndex = 0;
    int shots=(table->getColumnCount()%2==0) ? 0:1;
    QString name("Series ");
    for (u_int i(0); i < table->getRowCount(); i++) {
        QScatterSeries *series = new QScatterSeries(chart);
        for (u_int j=0;j <table->getColumnCount()-shots; j=j+2)
            series->append(table->getTable()->at(i).at(j),table->getTable()->at(i).at(j+1));
        series->setName(name + QString::number(nameIndex));
        nameIndex++;
        chart->addSeries(series);
        chart->createDefaultAxes();
    }

    chart->createDefaultAxes();
    return chart;
}
