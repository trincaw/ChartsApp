#include "AllCharts.h"

BarChart::BarChart(string titolo):Chart(titolo){};
QChart* BarChart::generateChart(Model* model) const
{
    TableData* table=model->getTable();
    QChart *chart = new QChart();
    chart->setTitle(QString::fromStdString(titolo));

    QStackedBarSeries *series = new QStackedBarSeries(chart);
    QString seriesColorHex = "#00000000";

    for (u_int i(0); i < table->getColumnCount(); i++) {
        QBarSet *set = new QBarSet(QString::fromStdString(table->getColumnsNames()->at(i)));

        set->setColor(QColor(0,50+i*50,205));
        series->append(set);

        seriesColorHex = "#" + QString::number(series->barSets()[i]->color().rgb(), 16).right(6).toUpper();

        for (u_int j=0;j < table->getRowCount();++j){
            *set << table->getTable()->at(j).at(i);
            model->addMapping(seriesColorHex, QRect(i, j, 1, 1));

        }
        chart->createDefaultAxes();
    }
    chart->addSeries(series);
    chart->createDefaultAxes();


    return chart;
}
PieChart::PieChart(string titolo):Chart(titolo){};
QChart* PieChart::generateChart(Model* model) const
{
    TableData* table=model->getTable();
    QChart *chart = new QChart();
    chart->setTitle("Pie chart");

    QPieSeries *series = new QPieSeries(chart);

    bool frist=true;

    for (u_int i(0); i < table->getColumnCount(); i++) {
        QPieSlice *slice = series->append(QString::fromStdString(table->getColumnsNames()->at(i)),table->getTable()->at(0).at(i));
         slice->setColor(QColor(0,50+i*50,205));
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
LineChart::LineChart(string titolo):Chart(titolo){};
QChart *LineChart::generateChart(Model* model) const
{
    TableData* table=model->getTable();
    //![1]
    QChart *chart = new QChart();
    chart->setTitle("Line chart");
    //![1]

    //![2]
    QString name("Series ");
    int nameIndex = 0;
    for (u_int i(0); i < table->getColumnCount()-1; i=i+2) {
        QLineSeries *series = new QLineSeries(chart);
        for (u_int j=0;j < table->getRowCount();++j){
            series->append(table->getTable()->at(j).at(i+1),table->getTable()->at(j).at(i));
        series->setName(name + QString::number(nameIndex));
        nameIndex++;
        chart->addSeries(series);
    }
        chart->createDefaultAxes();
    }
    //![2]

    //![3]


    return chart;
}
