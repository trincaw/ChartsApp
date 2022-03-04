#include "model.h"

using std::vector;
Model::Model(QObject *parent) : QAbstractTableModel(parent){
    std::vector<std::vector<double>> mat{{1}};
    std::vector<std::string> matRow{"row"};
    std::vector<std::string> matCol{"col"};
    DataHolder x(mat, matRow, matCol);
    table = x;
    //Da definire costruttore matrice
}
int Model::rowCount(const QModelIndex &parent) const{
    Q_UNUSED(parent)
    return table.GetRowSize();
}
int Model::columnCount(const QModelIndex &parent) const{
    Q_UNUSED(parent)
    return table.GetColumnSize();
}
QVariant Model::data(const QModelIndex &index, int role) const{
    if (role == Qt::DisplayRole){
        qreal temp = table.getData()->at(index.row()).at(index.column());
        return temp;
    }
}
std::vector<Data*> Model::getTable() const{
    return table;
}
void Model::readJson(std::string path) const{
    table->read(path);
}
void Model::writeJson(std::string path) const{
    table->write(path);
}
QVariant Model::headerData(int section, Qt::Orientation orientation, int role) const{
    if (role == Qt::DisplayRole){
        if (Qt::Orientation::Vertical == orientation){
            if(((int)table->getRowCount()) > section)
                return QString::fromStdString(table.getRowLabel()->at(section));
        } else{
            if(((int)table->getColumnCount()) > section)
                return QString::fromStdString(table.getColumnLabel()->at(section));
        }
    }
}
Qt::ItemFlags Model::flags(const QModelIndex &index) const{
    return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;
}

bool Model::setData(const QModelIndex &index, const QVariant &value, int role){
    if (role == Qt::EditRole){
        table->getData()->at(index.row()).at(index.column()) = value.toDouble();
        emit dataChanged(index, index);
    }
    return true;
}
void Model::addRow(unsigned int i, std::string label){
    vector<double> v(table.getColumnCount(),0);
    table->addRow(v,i,label);
}
void Model::addColumn(unsigned int i, std::string label){
    vector<double> v(table.getRowCount(),0);
    table->addColumn(v,i,label);
}
void Model::removeColumn(unsigned int i){table->deleteColumn(i);}
void Model::removeRow(unsigned int i){table->deleteRow(i);}
void Model::newModel(std::string rowLabel, std::string columnLabel){
    if (table->getData()){
        for (long unsigned int i = 0; i < table->getData().size(); i++){
            table->getData()[i].clear();
            table->getData()[i].shrink_to_fit();
        }
        table->getData()->clear();
        table->shrink_to_fit();
    }
}
