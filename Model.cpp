#include "Model.h"



Model::Model(QObject *parent) : QAbstractTableModel(parent){
    vector<vector<double>> tab={{0}};
    vector<string> rowsNames{"y"};
    vector<string> columnsNames{"x"};
    TableData t(tab,rowsNames,columnsNames);
    table=t;
}

int Model::rowCount(const QModelIndex & /*parent*/) const{
    return table.getRowCount();
}
int Model::columnCount(const QModelIndex & /*parent*/) const{
    return table.getColumnCount();
}
QVariant Model::data(const QModelIndex &index, int role) const{
    if (role == Qt::DisplayRole){
        qreal temp = table.getTable()->at(index.row()).at(index.column());
        return temp;
    }
    return QVariant();
}
bool Model::setData(const QModelIndex &index, const QVariant &value, int role){
    if (role == Qt::EditRole){
        table.printTable();
        table.getTable()->at(index.row()).at(index.column()) = value.toDouble();
        table.printTable();
        emit dataChanged(index, index);
    }
    return true;
}
Qt::ItemFlags Model::flags(const QModelIndex &index) const{
    return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;
}
QVariant Model::headerData(int section, Qt::Orientation orientation, int role) const{
    if (role == Qt::DisplayRole){
        if (Qt::Orientation::Vertical == orientation){
            if(((int)table.getRowCount()) > section)
                return QString::fromStdString(table.getRowsNames()->at(section));
        } else{
            if(((int)table.getColumnCount()) > section)
                return QString::fromStdString(table.getColumnsNames()->at(section));
        }
    }
    return QString();//??
}



TableData Model::getTable() const{
    return table;
}
void Model::setTable(TableData table){
    this->table=table;
}
void Model::addRow(u_int i, std::string label){
    vector<double> v(table.getColumnCount(),0);
    table.addRow(v,i,label);
}
void Model::addColumn(u_int i, std::string label){
    //vector<double> v(table->getRowCount(),0);
    table.addColumn(i,label);
}
void Model::removeColumn(u_int i){table.deleteColumn(i);}
void Model::removeRow(u_int i){table.deleteRow(i);}
