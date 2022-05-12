#include "AllCharts.h"

LineChart::LineChart(string titolo,vector<string>* seriesNames):Chart(titolo,seriesNames){};
QChart* LineChart::generateChart(Model* model,vector<QVXYModelMapper*> *mapper){
    if(!(mapper->empty())){
        int col=0;
        QLineSeries *series;

        for(unsigned long i=0;i<mapper->size();++i){
            series = new QLineSeries;

            if(seriesNames==nullptr || seriesNames->size()!=mapper->size())
                series->setName("Line "+QString::number(i+1));
            else
                series->setName(QString::fromStdString((*seriesNames)[i]));

            (*mapper)[i]->setXColumn(col++);
            (*mapper)[i]->setYColumn(col++);
            (*mapper)[i]->setModel(model);
            (*mapper)[i]->setSeries(series);

            chart->addSeries(series);
            chart->createDefaultAxes();
        }
    }
    return chart;
}
