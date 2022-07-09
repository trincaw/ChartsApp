#include "AllCharts.h"


QChart* StackedBarChart::generateChart(){
        chart = new QChart();

        series = new QStackedBarSeries(chart);
        QStringList categories;
        for (u_int i(0); i < model->getTable()->getRowCount(); i++) {
            QBarSet *set = new QBarSet(QString::fromUtf8(model->getTable()->getRowsNames().at(i).c_str()));
            for (u_int j=0;j < model->getTable()->getColumnCount();++j){
                *set << model->getTable()->getTable().at(i).at(j);
                categories.append(model->getTable()->getColumnsNames().at(j).c_str());
            }
            series->append(set);
        }

        //QBarCategoryAxis *axisX = new QBarCategoryAxis();
        //axisX->append(categories);
        //QValueAxis *axisY = new QValueAxis();
        //axisY->setRange(model->getTable()->getMinValue(),model->getTable()->getMaxValue());

        chart->addSeries(series);
        chart->createDefaultAxes();

        //chart->addAxis(axisX, Qt::AlignBottom);
        //chart->addAxis(axisY, Qt::AlignLeft);

        colourChart();
        return chart;
    }
void StackedBarChart::colourChart(){
    model->clearMapping();
    QString seriesColorHex = "#000000";
    QList<QBarSet *> barsets = series->barSets();
    for (int i = 0; i < series->count(); i++) {
        for (int j = 0; j < barsets.count(); j++) {
            seriesColorHex = "#" + QString::number(barsets.at(i)->brush().color().rgb(), 16).right(6).toUpper();
            model->addMapping(seriesColorHex, QRect(j, i, 1, 1));
        }
    }
};
StackedBarChart::~StackedBarChart(){delete series;}
QChart* BarChart::generateChart(){
        chart = new QChart();

        series = new QBarSeries(chart);
        QStringList categories;
        for (u_int i(0); i < model->getTable()->getRowCount(); i++) {
            QBarSet *set = new QBarSet(QString::fromUtf8(model->getTable()->getRowsNames().at(i).c_str()));
            for (u_int j=0;j < model->getTable()->getColumnCount();++j){
                *set << model->getTable()->getTable().at(i).at(j);
                categories.append(model->getTable()->getColumnsNames().at(j).c_str());
            }
            series->append(set);
        }
        QBarCategoryAxis *axisX = new QBarCategoryAxis();
        axisX->append(categories);
        QValueAxis *axisY = new QValueAxis();
        axisY->setRange(model->getTable()->getMinValue(),model->getTable()->getMaxValue());
        chart->addSeries(series);
        chart->addAxis(axisX, Qt::AlignBottom);
        chart->addAxis(axisY, Qt::AlignLeft);

        colourChart();
        return chart;
}
void BarChart::colourChart(){
    model->clearMapping();
    QString seriesColorHex = "#000000";
    QList<QBarSet *> barsets = series->barSets();
    for (int i = 0; i < series->count(); i++) {
        for (int j = 0; j < barsets.count(); j++) {
        seriesColorHex = "#" + QString::number(barsets.at(i)->brush().color().rgb(), 16).right(6).toUpper();
        model->addMapping(seriesColorHex, QRect(j, i, barsets.at(i)->count(), 1));
        }
    }
};
BarChart::~BarChart(){delete series;}
QChart* PieChart::generateChart(){
        chart = new QChart();

        series = new QPieSeries(chart);

        for (u_int i(0); i < model->getTable()->getColumnCount(); i++) {
            QPieSlice *slice = series->append(QString::fromStdString(model->getTable()->getColumnsNames().at(i)),model->getTable()->getTable().at(0).at(i));
            slice->setLabelVisible();
        }
        series->setPieSize(0.6);
        chart->addSeries(series);

        colourChart();
        return chart;

    }
void PieChart::colourChart(){
    model->clearMapping();
    QString seriesColorHex = "#000000";
    QList<QPieSlice *> slices = series->slices();
    for (u_int j = 0; j <  model->getTable()->getColumnCount(); j++) {
        seriesColorHex = "#" + QString::number(slices.at(j)->brush().color().rgb(), 16).right(6).toUpper();
        model->addMapping(seriesColorHex, QRect(j, 0, 1, 1));
    }

};
PieChart::~PieChart(){if(!series){delete series;}}
QChart* LineChart::generateChart(){
        chart = new QChart();

        int nameIndex = 0;
        series=vector<QLineSeries*>();
        for (u_int i(0); i < model->getTable()->getRowCount(); i++) {
            QLineSeries* serie = new QLineSeries();
            for (u_int j=0;j < model->getTable()->getColumnCount();j++){
                serie->append(j+1,model->getTable()->getTable().at(i).at(j));

            }

            serie->setName(QString::fromUtf8(model->getTable()->getRowsNames().at(nameIndex).c_str()));
            nameIndex++;
            chart->addSeries(serie);
            series.push_back(serie);
        }
        chart->createDefaultAxes();
        colourChart();
        return chart;
    }
void LineChart::colourChart(){
    model->clearMapping();
    QString seriesColorHex = "#000000";
    for (u_int i = 0; i < series.size(); i++) {
        for (int j = 0; j < series.at(i)->count(); j++) {
        seriesColorHex = "#" + QString::number(series.at(i)->color().rgb(), 16).right(6).toUpper();
        model->addMapping(seriesColorHex, QRect(j, i, series.at(i)->count(), 1));
        }
    }
};
LineChart::~LineChart(){for (auto s : series){delete s;}series.clear();}
QChart* SplineChart::generateChart(){
        chart = new QChart();

        int nameIndex = 0;
        for (u_int i(0); i < model->getTable()->getRowCount(); i++) {
            QSplineSeries* serie = new QSplineSeries(chart);
            for (u_int j=0;j < model->getTable()->getColumnCount();j++){
                serie->append(j+1,model->getTable()->getTable().at(i).at(j));
            }
            serie->setName(QString::fromUtf8(model->getTable()->getRowsNames().at(nameIndex).c_str()));
            nameIndex++;
            chart->addSeries(serie);
            series.push_back(serie);
        }
        chart->createDefaultAxes();
        colourChart();
        return chart;
    }
void SplineChart::colourChart(){
    model->clearMapping();
    QString seriesColorHex = "#000000";
    for (u_int i = 0; i < series.size(); i++) {
        for (int j = 0; j < series.at(i)->count(); j++) {
        seriesColorHex = "#" + QString::number(series.at(i)->color().rgb(), 16).right(6).toUpper();
        model->addMapping(seriesColorHex, QRect(j, i, series.at(i)->count(), 1));
        }
    }
};
SplineChart::~SplineChart(){for (auto s : series){delete s;}series.clear();}
QChart* ScatterChart::generateChart(){
        chart = new QChart();

        int nameIndex = 0;
        for (u_int i(0); i < model->getTable()->getRowCount(); i++) {
            QScatterSeries* serie = new QScatterSeries(chart);
            for (u_int j=0;j < model->getTable()->getColumnCount();j++){
                serie->append(j+1,model->getTable()->getTable().at(i).at(j));
            }
            serie->setName(QString::fromUtf8(model->getTable()->getRowsNames().at(nameIndex).c_str()));
            nameIndex++;
            chart->addSeries(serie);
            series.push_back(serie);
        }
        chart->createDefaultAxes();
        colourChart();
        return chart;
    }
void ScatterChart::colourChart(){
    model->clearMapping();
    QString seriesColorHex = "#000000";
    for (u_int i = 0; i < series.size(); i++) {
        for (int j = 0; j < series.at(i)->count(); j++) {
        seriesColorHex = "#" + QString::number(series.at(i)->color().rgb(), 16).right(6).toUpper();
        model->addMapping(seriesColorHex, QRect(j, i, series.at(i)->count(), 1));
        }
    }
};
ScatterChart::~ScatterChart(){for (auto s : series){delete s;}series.clear();}
QChart* NestedPieChart::generateChart(){
        chart = new QChart();
        qreal minSize = 0.1;
        qreal maxSize = 0.9;
            for (u_int i = 0; i < model->getTable()->getRowCount(); i++) {
                QPieSeries* donut = new QPieSeries;
                for (u_int j = 0; j < model->getTable()->getColumnCount(); j++) {
                    qreal value = model->getTable()->getTable().at(i).at(j);
                    QPieSlice *slice = new QPieSlice(QString("%1").arg(value), value);
                    slice->setLabelVisible(true);
                    slice->setLabelColor(Qt::white);
                    slice->setLabelPosition(QPieSlice::LabelInsideTangential);
                    donut->append(slice);
                    donut->setHoleSize(minSize + i * (maxSize - minSize) / model->getTable()->getRowCount());
                    donut->setPieSize(minSize + (i + 1) * (maxSize - minSize) / model->getTable()->getRowCount());
                }
                chart->addSeries(donut);
                donuts.push_back(donut);
            }
            chart->legend()->setVisible(false);

            colourChart();
            return chart;
    }
// model->clearMapping();
// QString seriesColorHex = "#000000";
// for (auto series : donuts) {
//     QList<QPieSlice *> slices = series->slices();
//     for (u_int j = 0; j <  model->getTable()->getColumnCount(); j++) {
//         seriesColorHex = "#" + QString::number(slices.at(j)->brush().color().rgb(), 16).right(6).toUpper();
//         model->addMapping(seriesColorHex, QRect(j, 0, 1, 1));
//     }
// }
void NestedPieChart::colourChart(){
    model->clearMapping();
    QString seriesColorHex = "#000000";
    for (auto series : donuts) {
        QList<QPieSlice *> slices = series->slices();
        for (u_int j = 0; j <  model->getTable()->getColumnCount(); j++) {
            seriesColorHex = "#" + QString::number(slices.at(j)->brush().color().rgb(), 16).right(6).toUpper();
            model->addMapping(seriesColorHex, QRect(j, 0, 1, 1));
        }
    }
};
NestedPieChart::~NestedPieChart(){for (auto s : donuts){if(!s){delete s;}}donuts.clear();}
