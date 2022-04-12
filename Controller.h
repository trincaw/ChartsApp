#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>

#include "MainWindow.h"
#include "Model.h"
#include <QInputDialog>
#include <QFileDialog>
#include <QInputDialog>

typedef unsigned int u_int;
using std::string;

class Controller : public QObject
{
    Q_OBJECT
private:
    MainWindow* view;
    Model* model;
    void insert_Row(u_int index);
    void insert_Column(u_int index);


public:
    explicit Controller(QObject *parent = nullptr);
    //~Controller();

    void setModel(Model* m);
    void setView(MainWindow* v);
    Model* getModel();

    void showDebougTable() const;

public slots:
    void insert_Row_Before_Selected();
    void insert_Row_After_Selected();
    void insert_Column_Before_Selected();
    void insert_Column_After_Selected();
    void remove_Selected_Row();
    void remove_Selected_Column();
    void clearTable();

    void saveXML();
    void loadXML();

    //void addMapping(QString color, QRect area);
};


#endif // CONTROLLER_H
