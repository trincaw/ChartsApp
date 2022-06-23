#include "AllCharts.h"

QChart* BarChart::generateChart(TableData* table) const
{
    QChart *chart = new QChart();

    QStackedBarSeries *series = new QStackedBarSeries(chart);
    for (u_int i(0); i < table->getColumnCount(); i++) {
        QBarSet *set = new QBarSet("Bar " + QString::number(i+1));
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
    int shots=(table->getColumnCount()%2==0) ? 0:1;
    for (u_int i(0); i < table->getRowCount(); i++) {
        QLineSeries *series = new QLineSeries(chart);
        for (u_int j=0;j < table->getColumnCount()-shots;j=j+2)
            series->append(table->getTable()->at(i).at(j),table->getTable()->at(i).at(j+1));
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
    int shots=(table->getColumnCount()%2==0) ? 0:1;
    for (u_int i(0); i < table->getRowCount(); ++i) {
        QSplineSeries *series = new QSplineSeries(chart);
        for (u_int j=0;j < table->getColumnCount()-shots;j=j+2)
            series->append(table->getTable()->at(i).at(j),table->getTable()->at(i).at(j+1));
        series->setName(name + QString::number(nameIndex));
        nameIndex++;
        chart->addSeries(series);
    }
    chart->createDefaultAxes();
    return chart;
}

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
    }
    chart->createDefaultAxes();
    return chart;
}
QChart* NestedPieChart::generateChart(TableData* table) const{
    QChart *chart = new QChart();
    qreal minSize = 0.1;
    qreal maxSize = 0.9;
        for (u_int i = 0; i < table->getRowCount(); i++) {
            QPieSeries *donut = new QPieSeries;
            for (u_int j = 0; j < table->getColumnCount(); j++) {
                qreal value = table->getTable()->at(i).at(j);
                QPieSlice *slice = new QPieSlice(QString("%1").arg(value), value);
                slice->setLabelVisible(true);
                slice->setLabelColor(Qt::white);
                slice->setLabelPosition(QPieSlice::LabelInsideTangential);
                donut->append(slice);
                donut->setHoleSize(minSize + i * (maxSize - minSize) / table->getRowCount());
                donut->setPieSize(minSize + (i + 1) * (maxSize - minSize) / table->getRowCount());
            }
            chart->addSeries(donut);
        }
        chart->legend()->setVisible(false);
        return chart;
}

