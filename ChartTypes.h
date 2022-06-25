#ifndef CHARTTYPES_H
#define CHARTTYPES_H
#include <QChart>

#include <vector>
#include <string>

#include "Chart.h"

using QtCharts::QChart;
//definizioni di template vanno nel .h
//template per ogni genere di grafico
template <class T1,class T2> class BarTypeChart: public Chart
{
protected:
    QChart* generateChart(TableData* table){
        QChart *chart = new QChart();

        T1 *series = new T1(chart);
        for (u_int i(0); i < table->getRowCount(); i++) {
            T2 *set = new T2(QString::fromUtf8(table->getRowsNames().at(i).c_str()));
            for (u_int j=0;j < table->getColumnCount();++j)
                *set << table->getTable().at(i).at(j);
            series->append(set);
        }
        chart->addSeries(series);
        chart->createDefaultAxes();

        return chart;
    }
};
template <class T1,class T2> class PieTypeChart: public Chart
{
protected:
    QChart* generateChart(TableData* table){
        QChart *chart = new QChart();

         T1 *series = new T1(chart);

        for (u_int i(0); i < table->getColumnCount(); i++) {
            T2 *slice = series->append(QString::fromStdString(table->getColumnsNames().at(i)),table->getTable().at(0).at(i));
            slice->setLabelVisible();
        }
        series->setPieSize(0.6);
        chart->addSeries(series);

        return chart;
    }
};
template <class T1> class LineTypeChart: public Chart
{
protected:
    QChart* generateChart(TableData* table){
        QChart *chart = new QChart();

        int nameIndex = 0;
        //int shots=table->getColumnCount();
        for (u_int i(0); i < table->getRowCount(); i++) {
            T1 *series = new T1(chart);
            for (u_int j=0;j < table->getColumnCount();j++)
                series->append(j+1,table->getTable().at(i).at(j));
            series->setName(QString::fromUtf8(table->getRowsNames().at(nameIndex).c_str()));
            nameIndex++;
            chart->addSeries(series);

        }
        chart->createDefaultAxes();
        return chart;
    }
};
template <class T1,class T2> class NestedPieTypeChart: public Chart
{
protected:
    QChart* generateChart(TableData* table){
        QChart *chart = new QChart();
        qreal minSize = 0.1;
        qreal maxSize = 0.9;
            for (u_int i = 0; i < table->getRowCount(); i++) {
                T1 *donut = new T1;
                for (u_int j = 0; j < table->getColumnCount(); j++) {
                    qreal value = table->getTable().at(i).at(j);
                    T2 *slice = new T2(QString("%1").arg(value), value);
                    slice->setLabelVisible(true);
                    slice->setLabelColor(Qt::white);
                    slice->setLabelPosition(T2::LabelInsideTangential);
                    donut->append(slice);
                    donut->setHoleSize(minSize + i * (maxSize - minSize) / table->getRowCount());
                    donut->setPieSize(minSize + (i + 1) * (maxSize - minSize) / table->getRowCount());
                }
                chart->addSeries(donut);
            }
            chart->legend()->setVisible(false);
            return chart;
    }
};


#endif // CHARTTYPES_H
