#include "Controller.h"

Controller::Controller(QObject* parent): QObject(parent) {}

void Controller::setModel(Model* m) { model = m; }

void Controller::setView(MainWindow* v) { view = v; }

Model* Controller::getModel(){ return model; }

void Controller::showViewTable() const{
   view->showTable(model->getTable());
}

void Controller::insertRow(u_int index, string label){
    if(view!=nullptr && model!=nullptr){
        model->addRow(index,label);
        showViewTable();
    }
    throw ;
}
void Controller::insertColumn(){
    if(view!=nullptr && model!=nullptr){
        u_int i= view->getSelectedColumn()+1;
        model->addColumn(i,"");
    }
    else
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

