#ifndef ALLCHARTS_H
#define ALLCHARTS_H

#include "ChartTypes.h"
#include <QtCharts>
#include <QVBarModelMapper>

class StackedBarChart:public BarredChart{
    QChart* generateChart(TableData* table){
            QChart *chart = new QChart();

            QStackedBarSeries *series = new QStackedBarSeries(chart);
            QStringList categories;
            for (u_int i(0); i < table->getRowCount(); i++) {
                QBarSet *set = new QBarSet(QString::fromUtf8(table->getRowsNames().at(i).c_str()));
                for (u_int j=0;j < table->getColumnCount();++j){
                    *set << table->getTable().at(i).at(j);
                    categories.append(table->getColumnsNames().at(j).c_str());
                }
                series->append(set);
            }

            //QBarCategoryAxis *axisX = new QBarCategoryAxis();
            //axisX->append(categories);
            //QValueAxis *axisY = new QValueAxis();
            //axisY->setRange(table->getMinValue(),table->getMaxValue());

            chart->addSeries(series);
            chart->createDefaultAxes();

            //chart->addAxis(axisX, Qt::AlignBottom);
            //chart->addAxis(axisY, Qt::AlignLeft);

            return chart;
        }
};
class BarChart:public BarredChart{
    QChart* generateChart(TableData* table){
            QChart *chart = new QChart();

            QBarSeries *series = new QBarSeries(chart);
            QStringList categories;
            for (u_int i(0); i < table->getRowCount(); i++) {
                QBarSet *set = new QBarSet(QString::fromUtf8(table->getRowsNames().at(i).c_str()));
                for (u_int j=0;j < table->getColumnCount();++j){
                    *set << table->getTable().at(i).at(j);
                    categories.append(table->getColumnsNames().at(j).c_str());
                }
                series->append(set);
            }
            QBarCategoryAxis *axisX = new QBarCategoryAxis();
            axisX->append(categories);
            QValueAxis *axisY = new QValueAxis();
            axisY->setRange(table->getMinValue(),table->getMaxValue());
            chart->addSeries(series);
            chart->addAxis(axisX, Qt::AlignBottom);
            chart->addAxis(axisY, Qt::AlignLeft);
            return chart;
        }
};
class PieChart:public RoundChart{
    QChart* generateChart(TableData* table){
            QChart *chart = new QChart();

             QPieSeries *series = new QPieSeries(chart);

            for (u_int i(0); i < table->getColumnCount(); i++) {
                QPieSlice *slice = series->append(QString::fromStdString(table->getColumnsNames().at(i)),table->getTable().at(0).at(i));
                slice->setLabelVisible();
            }
            series->setPieSize(0.6);
            chart->addSeries(series);

            return chart;
        }
};
class LineChart:public ContinuousChart{
    QChart* generateChart(TableData* table){
            QChart *chart = new QChart();

            int nameIndex = 0;
            for (u_int i(0); i < table->getRowCount(); i++) {
                QLineSeries *series = new QLineSeries(chart);
                for (u_int j=0;j < table->getColumnCount();j++){
                    series->append(j+1,table->getTable().at(i).at(j));
                }
                series->setName(QString::fromUtf8(table->getRowsNames().at(nameIndex).c_str()));
                nameIndex++;
                chart->addSeries(series);
            }
            chart->createDefaultAxes();
            return chart;
        }
};
class SplineChart:public ContinuousChart{
    QChart* generateChart(TableData* table){
            QChart *chart = new QChart();

            int nameIndex = 0;
            for (u_int i(0); i < table->getRowCount(); i++) {
                QSplineSeries *series = new QSplineSeries(chart);
                for (u_int j=0;j < table->getColumnCount();j++){
                    series->append(j+1,table->getTable().at(i).at(j));
                }
                series->setName(QString::fromUtf8(table->getRowsNames().at(nameIndex).c_str()));
                nameIndex++;
                chart->addSeries(series);
            }
            chart->createDefaultAxes();
            return chart;
        }
};
class ScatterChart:public ContinuousChart{
    QChart* generateChart(TableData* table){
            QChart *chart = new QChart();

            int nameIndex = 0;
            for (u_int i(0); i < table->getRowCount(); i++) {
                QScatterSeries *series = new QScatterSeries(chart);
                for (u_int j=0;j < table->getColumnCount();j++){
                    series->append(j+1,table->getTable().at(i).at(j));
                }
                series->setName(QString::fromUtf8(table->getRowsNames().at(nameIndex).c_str()));
                nameIndex++;
                chart->addSeries(series);
            }
            chart->createDefaultAxes();
            return chart;
        }
};
class NestedPieChart:public RoundChart{
    QChart* generateChart(TableData* table){
            QChart *chart = new QChart();
            qreal minSize = 0.1;
            qreal maxSize = 0.9;
                for (u_int i = 0; i < table->getRowCount(); i++) {
                    QPieSeries *donut = new QPieSeries;
                    for (u_int j = 0; j < table->getColumnCount(); j++) {
                        qreal value = table->getTable().at(i).at(j);
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
};

#endif // ALLCHARTS_H
