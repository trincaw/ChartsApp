#ifndef CHARTTYPES_H
#define CHARTTYPES_H
#include <QChart>
#include <vector>
#include <string>
#include "Chart.h"

using QtCharts::QChart;
class BarredChart: public Chart{
protected:
    template <class T1, class T2> T1* toSeries() const{
        T1* series = new T1();
        QStringList categories;
        for (u_int i(0); i < model->getTable()->getRowCount(); i++) {
            T2 *set = new T2(QString::fromUtf8(model->getTable()->getRowsNames().at(i).c_str()));
            for (u_int j=0;j < model->getTable()->getColumnCount();++j){
                *set << model->getTable()->getTable().at(i).at(j);
                categories.append(model->getTable()->getColumnsNames().at(j).c_str());
            }
            series->append(set);
        }
        return series;
    }
};
class RoundChart: public Chart{
protected:
    QPieSeries* toSeries() const{
        QPieSeries* series = new QPieSeries(chart);

        for (u_int i(0); i < model->getTable()->getColumnCount(); i++) {
            QPieSlice *slice = series->append(QString::fromStdString(model->getTable()->getColumnsNames().at(i)),model->getTable()->getTable().at(0).at(i));
            slice->setLabelVisible();
        }
        return series;
    };
};
class ContinuousChart: public Chart{
protected:
    template <class T> vector<T*> toSeries(){
    int nameIndex = 0;
    vector<T*> series=vector<T*>();
    for (u_int i(0); i < model->getTable()->getRowCount(); i++) {
        T* serie = new T();
        for (u_int j=0;j < model->getTable()->getColumnCount();j++){
            serie->append(j+1,model->getTable()->getTable().at(i).at(j));}
        serie->setName(QString::fromUtf8(model->getTable()->getRowsNames().at(nameIndex).c_str()));
        nameIndex++;
        chart->addSeries(serie);
        series.push_back(serie);
        }
     return series;
    }

};

#endif // CHARTTYPES_H
