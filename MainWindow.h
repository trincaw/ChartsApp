#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QChartView>
#include <QLineSeries>
#include <QtCharts>
#include <QChart>
#include <QWidget>
#include <QMenuBar>
#include <QVBoxLayout>
#include <QAbstractItemModel>
#include <QScreen>
#include <QMessageBox>

#include "Model.h"
#include "TableData.h"

typedef unsigned int u_int;
class Controller;
class MainWindow : public QWidget
{
    Q_OBJECT
private:
    Controller* controller;

    QVBoxLayout* mainLayout;
    QHBoxLayout* chartsLayout;

    QMenuBar* menu;
    QMenu* file;
    QMenu* edit;
    QMenu* view;
    QMenu* help;

    QTableView* tableView= nullptr;
    QChartView* chartView= nullptr;
    //ChartItem* chartItem=nullptr;
public:
    MainWindow(QWidget* parent=nullptr);
    void setController(Controller* controller);
    void setTableView();
    void setChartView();

    void addMenuBar();
    void addTableView();
    void addChartView();

    u_int getSelectedRow() const;
    u_int getSelectedColumn() const;
    //Chart* getChart() const;
public slots:
    //void drawChart(Chart* chart)

};

#endif // MAINWINDOW_H
