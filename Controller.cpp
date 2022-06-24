#include "Controller.h"

Controller::Controller(QObject* parent): QObject(parent) {}

void Controller::setModel(Model* m) { model = m; }//DEBOUG

void Controller::setView(MainWindow* v) {view = v;}

Model* Controller::getModel(){ return model; }

void Controller::loadAChart() const{
    //Takes frist simple from Projects folder that is .chart
     for (const auto & entry : std::filesystem::directory_iterator((qApp->applicationDirPath()+"/../Projects").toStdString())){
         if(string s=entry.path();s.find(".chart") != std::string::npos){
             model->LoadXML(QString::fromStdString(entry.path()));break;}
     }
    view->refreshGui();
}
void Controller::insert_Row(u_int index){
    if(view!=nullptr && model!=nullptr ){
        bool ok;
        QString text = QInputDialog::getText(view, tr("Enter Row Name"),
                                             tr("Label:"), QLineEdit::Normal,
                                             "", &ok);
        if (ok && !text.isEmpty()){
            model->addRow(index,text.toStdString());
            view->refreshGui();
        }
    }
    else
    throw ;
}
void Controller::insert_Row_Before_Selected(){
    insert_Row(view->getSelectedRow());
}
void Controller::insert_Row_After_Selected(){
    insert_Row(view->getSelectedRow()+1);
}
void Controller::insert_Column(u_int index){
    if(view!=nullptr && model!=nullptr){
        bool ok;
        QString text = QInputDialog::getText(view, tr("Enter Col Name"),
                                             tr("Label:"), QLineEdit::Normal,
                                             "", &ok);
        if (ok && !text.isEmpty()){
            model->addColumn(index,text.toStdString());
            view->refreshGui();
        }

    }
    else
    throw ;
}
void Controller::insert_Column_Before_Selected(){
    insert_Column(view->getSelectedColumn());
}

void Controller::insert_Column_After_Selected(){
    insert_Column(view->getSelectedColumn()+1);
}

void Controller::remove_Selected_Row(){
    if(view!=nullptr && model!=nullptr){
        u_int i= view->getSelectedRow();
        model->removeRow(i);
        view->refreshGui();
    }
    else
    throw ;
}
void Controller::remove_Selected_Column(){
    if(view!=nullptr && model!=nullptr){
        u_int i= view->getSelectedColumn();
        model->removeColumn(i);
        view->refreshGui();
    }
    else
    throw ;
}
void Controller::clearTable(){
    model->clearTable();
     view->refreshGui();
}
void Controller::saveXML(){
    if(view!=nullptr && model!=nullptr){
        model->SaveXML(QFileDialog::getSaveFileName(view, "Save File","", "XML (*.chart)"));
    }
    else
    throw ;
}
void Controller::loadXML(){
    if(view!=nullptr && model!=nullptr){
        model->LoadXML(QFileDialog::getOpenFileName(view, "Load File","", "XML (*.chart)"));
        view->refreshGui();
    }
    else
    throw ;
}
void Controller::newChart(){
    if(view!=nullptr && model!=nullptr){
        model->newModel();
        view->refreshGui();
    }
    else
    throw ;
}

