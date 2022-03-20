#include "Controller.h"

Controller::Controller(QObject* parent): QObject(parent) {}

void Controller::setModel(Model* m) { model = m; }

void Controller::setView(MainWindow* v) { view = v; }

Model* Controller::getModel(){ return model; }

void Controller::addRow(u_int index, string label){
    if(view!=nullptr && model!=nullptr){
        model->addRow(index,label);
    }
    throw ;
}
void Controller::addColumn(u_int index, string label){
    if(view!=nullptr && model!=nullptr){
        model->addColumn(index,label);
    }
    throw ;
}
void Controller::removeRow(u_int index){
    if(view!=nullptr && model!=nullptr){
        model->removeRow(index);
    }
    throw ;
}
void Controller::removeColumn(u_int index){
    if(view!=nullptr && model!=nullptr){
        model->removeColumn(index);
    }
    throw ;
}
