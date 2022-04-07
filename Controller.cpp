#include "Controller.h"

Controller::Controller(QObject* parent): QObject(parent) {}

void Controller::setModel(Model* m) { model = m; }//DEBOUG

void Controller::setView(MainWindow* v) { view = v; }

Model* Controller::getModel(){ return model; }

void Controller::showDebougTable() const{
    model->LoadXML("/home/olo/Progetti/ChartsApp/Example/sample1.xml");view->addTableView();
}
void Controller::insert_Row(u_int index){
    if(view!=nullptr && model!=nullptr ){
        model->addRow(index,"");
        view->addTableView();
    }
    else
    throw ;
}
void Controller::insert_Row_Before_Selected(){
    if(view->getSelectedRow()==0)
         insert_Row(0);
    else
         insert_Row(view->getSelectedRow()-1);

}
void Controller::insert_Row_After_Selected(){
    insert_Row(view->getSelectedRow()+1);
}
void Controller::insert_Column(u_int index){
    if(view!=nullptr && model!=nullptr){
        model->addColumn(index,"");
        view->addTableView();
    }
    else
    throw ;
}
void Controller::insert_Column_Before_Selected(){
    if(view->getSelectedColumn()==0)
         insert_Column(0);
    else
    insert_Column(view->getSelectedColumn()-1);
}

void Controller::insert_Column_After_Selected(){
    insert_Column(view->getSelectedColumn()+1);
}

void Controller::remove_Selected_Row(){
    if(view!=nullptr && model!=nullptr){
        u_int i= view->getSelectedRow();
        model->removeRow(i);
        view->addTableView();
    }
    else
    throw ;
}
void Controller::remove_Selected_Column(){
    if(view!=nullptr && model!=nullptr){
        u_int i= view->getSelectedColumn();
        model->removeColumn(i);
        view->addTableView();
    }
    else
    throw ;
}
void Controller::clearTable(){
    model->clearTable();
     view->addTableView();
}
void Controller::saveXML(){
    if(view!=nullptr && model!=nullptr){
        model->SaveXML(QFileDialog::getSaveFileName(view, "Save File","", "XML (*.xml)"));
    }
    else
    throw ;
}
void Controller::loadXML(){
    if(view!=nullptr && model!=nullptr){
        model->LoadXML(QFileDialog::getOpenFileName(view, "Load File","", "XML (*.xml)"));
        view->addTableView();

    }
    else
    throw ;
}

