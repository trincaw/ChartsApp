#include "Controller.h"

Controller::Controller(QObject* parent): QObject(parent) {}

void Controller::setModel(Model* m) { model = m; }

void Controller::setView(MainWindow* v) { view = v; }

Model* Controller::getModel(){ return model; }

void Controller::showViewTable() const{
   view->showTable(model->getTable());
}

void Controller::insertRow(){
    if(view!=nullptr && model!=nullptr){
        u_int i= view->getSelectedColumn()+1;
        model->addRow(i,"");
        view->addTableView();
    }
    else
    throw ;
}
void Controller::insertColumn(){
    if(view!=nullptr && model!=nullptr){
        u_int i= view->getSelectedColumn()+1;
        model->addColumn(i,"");
        view->addTableView();
    }
    else
    throw ;
}
void Controller::removeRow(){
    if(view!=nullptr && model!=nullptr){
        //model->removeRow(index);
    }
    throw ;
}
void Controller::removeColumn(){
    if(view!=nullptr && model!=nullptr){
        //model->removeColumn(index);
    }
    throw ;
}
void Controller::clearTable(){
    model->clearTable();
     view->addTableView();
}
void Controller::saveXML(){
    if(view!=nullptr && model!=nullptr){
        model->SaveXML(QFileDialog::getSaveFileName(view, "Save File"));
    }
    else
    throw ;
}
void Controller::loadXML(){
    if(view!=nullptr && model!=nullptr){
        model->LoadXML(QFileDialog::getOpenFileName(view, "Get Any File"));
        view->addTableView();
    }
    else
    throw ;
}

