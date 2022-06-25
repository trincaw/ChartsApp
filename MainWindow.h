#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QChartView>
#include <QLineSeries>
#include <QWidget>
#include <QMenuBar>
#include <QVBoxLayout>
#include <QAbstractItemModel>
#include <QScreen>
#include <QMessageBox>
#include <QtCharts>

#include <QVXYModelMapper>
#include <QTableView>
#include <QChartView>

#include "Chart.h"
#include "AllCharts.h"
#include "Model.h"
#include "TableData.h"

#include <vector>
using std::vector;
using QtCharts::QVXYModelMapper;
using QtCharts::QChartView;

typedef unsigned int u_int;
class Controller;
class MainWindow : public QWidget
{
    Q_OBJECT
private:
    Controller* controller;

    QVBoxLayout* mainLayout;
    QHBoxLayout* chartsLayout;
    Chart* chart;

    //menu items
    QMenuBar* menu;
    QMenu* file;
    QMenu* edit;
    QMenu* view;
    QMenu* help;

    QTableView* tableView= nullptr;
    QChartView* chartView= nullptr;
public:
    MainWindow(QWidget* parent=nullptr);
    ~MainWindow();

    //required sets
    void setController(Controller* controller);
    void setTableView();
    void setChartView();

    //add grapichal interface
    void addMenuBar();
    void addTableView();
    void addChartView();
    void refreshGui();

    //get tableview selected cells
    u_int getSelectedRow() const;
    u_int getSelectedColumn() const;

private slots:
    //set a chart tipe
     void setPieChart();
     void setBarChart();
     void setLineChart();
     void setSplineChart();
     void setScatterChart();
     void setNestedPieChart();
};

#endif // MAINWINDOW_H
