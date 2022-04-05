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
    vector<double> v(table.getRowCount(),0);
    table.addColumn(v,i,label);
}
void Model::removeColumn(u_int i){table.deleteColumn(i);}
void Model::removeRow(u_int i){table.deleteRow(i);}
void Model::clearTable(){
    vector<vector<double>> tab={{0}};
    vector<string> rowsNames{"y"};
    vector<string> columnsNames{"x"};
    TableData t(tab,rowsNames,columnsNames);
    table=t;
}

void Model::SaveXML(QString path){
    QFile xmlFile(path);

    if (!xmlFile.open(QFile::WriteOnly | QFile::Text )){
        qDebug() << "Already opened or there is another issue";
        xmlFile.close();
    }
    QTextStream xmlContent(&xmlFile);
    QDomDocument document;
    QDomElement root = document.createElement("Graph");
    document.appendChild(root);
    QDomElement Header = document.createElement("Cols");
    for (auto c : *table.getColumnsNames())
    {
        QDomElement child = document.createElement("Col");
        child.setAttribute("value", QString::fromStdString(c));
        Header.appendChild(child);
    }
    root.appendChild(Header);
    QDomElement Rows = document.createElement("Rows");
    for (auto c : *table.getColumnsNames())
    {
        QDomElement child = document.createElement("Row");
        child.setAttribute("value", QString::fromStdString(c));
        Rows.appendChild(child);
    }
    root.appendChild(Rows);
    QDomElement Data = document.createElement("Data");
    for (auto data : *table.getTable())
    {
        QDomElement test = document.createElement("Row");
        for (auto d : data){
            QDomElement child = document.createElement(QString::number(d));
            test.appendChild(child);
        }
        Data.appendChild(test);
    }
    root.appendChild(Data);
    xmlContent << document.toString();

}

void Model::LoadXML(QString path){
    QDomDocument tableXML;
    QFile xmlFile(path);
    if (!xmlFile.open(QIODevice::ReadOnly ))
    {
        // Error while loading file
    }
    tableXML.setContent(&xmlFile);
    xmlFile.close();
    QDomElement root = tableXML.documentElement();
    QDomElement Header = root.firstChildElement();
    QDomElement Row = Header.nextSiblingElement();
    QDomElement Table = Row.nextSiblingElement();


    if (!Header.isNull()){
        QDomElement HeaderChild = Header.firstChildElement();
        while(HeaderChild.isNull() == false){
            qDebug() << HeaderChild.attribute("value","x") << " ";
            HeaderChild = HeaderChild.nextSiblingElement();
        }
    } else {
    }

    if (!Row.isNull()){
        QDomElement RowChild = Row.firstChildElement();
        while(!RowChild.isNull()){
            qDebug() << RowChild.attribute("value","x") << " ";
            RowChild = RowChild.nextSiblingElement();
        }
    } else {
    }
    if (!Table.isNull()){
        qDebug() << Table.tagName();
        QDomElement Row = Table.firstChildElement();
        while (!Row.isNull()){
            qDebug() << Row.tagName();

            QDomElement RowElement = Row.firstChildElement();
            while (!RowElement.isNull()){
                qDebug() << RowElement.tagName() << " ";
                RowElement = RowElement.nextSiblingElement();
            }
            Row = Row.nextSiblingElement();
        }
    } else {
        qDebug() << "è null" << "";
    }


}
