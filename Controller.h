#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>

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
    void showViewTable() const;

public:
    explicit Controller(QObject *parent = nullptr);
    //~Controller();

    void setModel(Model* m);
    void setView(MainWindow* v);
    Model* getModel();

public slots:
    void insertRow(unsigned int index, std::string label);
    void insertColumn();
    void removeRow(u_int index);
    void removeColumn(u_int index);

    //void addMapping(QString color, QRect area);
};


#endif // CONTROLLER_H
