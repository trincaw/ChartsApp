#include "Chart.h"

Chart::Chart(string titolo,vector<string>* seriesNames){
    chart = new QChart();
    this->titolo=titolo;
    this->seriesNames=seriesNames;
    chart->setTitle(QString::fromStdString(titolo));
}


