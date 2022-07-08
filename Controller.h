#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QInputDialog>
#include <QFileDialog>
#include <QInputDialog>


#include "MainWindow.h"
#include "Model.h"

typedef unsigned int u_int;
using std::string;

class Controller : public QObject
{
    Q_OBJECT
private:
    MainWindow* view;
    Model* model;
    //Insert a new row
    void insert_Row(u_int index);
    //Insert a new column
    void insert_Column(u_int index);

public:
    explicit Controller(QObject *parent = nullptr);
    void setModel(Model* m);
    void setView(MainWindow* v);
    Model* getModel() const;
    //void setTableViewOnModel(QTableView* Table);

public slots:
    //Insert a new row before the selected one
    void insert_Row_Before_Selected();
    //Insert a new row after the selected one
    void insert_Row_After_Selected();
    //Insert a new column before the selected one
    void insert_Column_Before_Selected();
    //Insert a new column after the selected one
    void insert_Column_After_Selected();
    //Remove the selected row
    void remove_Selected_Row();
    //Remove the selected column
    void remove_Selected_Column();

    //Resets model to make a new chart
    void newChart();
    //Save the chart
    void saveXML();
    //Load a saved chart
    void loadXML();
};


#endif // CONTROLLER_H
