#include "Model.h"

using std::vector;

Model::Model(QObject *parent) : QAbstractTableModel(parent){
    std::vector<std::vector<double>> mat{{1}};
    std::vector<std::string> matRow{"row"};
    std::vector<std::string> matCol{"col"};
    TableData x(mat, matRow, matCol);
    table = x;
    //Da definire costruttore matrice
}
int Model::rowCount(const QModelIndex &parent) const{
    Q_UNUSED(parent)
    return table.getRowCount();
}
int Model::columnCount(const QModelIndex &parent) const{
    Q_UNUSED(parent)
    return table.getColumnCount();
}
QVariant Model::data(const QModelIndex &index, int role) const{
    if (role == Qt::DisplayRole){
        qreal temp = table.getTable()->at(index.row()).at(index.column());
        return temp;
    }
}
TableData Model::getTable() const{
    return table;
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
}
Qt::ItemFlags Model::flags(const QModelIndex &index) const{
    return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;
}

bool Model::setData(const QModelIndex &index, const QVariant &value, int role){
    if (role == Qt::EditRole){
        table.getTable()->at(index.row()).at(index.column()) = value.toDouble();
        emit dataChanged(index, index);
    }
    return true;
}
void Model::addRow(u_int i, std::string label){
    vector<double> v(table.getColumnCount(),0);
    table.addRow(v,i,label);
}
void Model::addColumn(u_int i, std::string label){
    vector<double> v(table.getRowCount(),0);
    table.addColumn(v,i,label);
}
void Model::removeColumn(u_int i){table.deleteColumn(i);}
void Model::removeRow(u_int i){table.deleteRow(i);}
void Model::newModel(string rowLabel, string columnLabel){
    if (table.getTable()){
        vector<vector<double>>().swap(*table.getTable());
    }
}
