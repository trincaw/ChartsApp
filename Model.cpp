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
    if (role != Qt::DisplayRole)
        return QVariant();

    if (Qt::Orientation::Vertical == orientation){
        if(((int)table.getRowCount()) > section)
            return QString::fromStdString(table.getRowsNames()->at(section));
    } else{
        if(((int)table.getColumnCount()) > section)
            return QString::fromStdString(table.getColumnsNames()->at(section));
    }
    return QString();//??
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
    // SAVE COLS HEADER
    QDomElement Cols = document.createElement("Cols");
    Cols.setAttribute("CollumnCount",QString::number(table.getColumnCount()));
    for (auto c : *table.getColumnsNames())
    {
        QDomElement child = document.createElement("Col");
        child.setAttribute("value", QString::fromStdString(c));
        Cols.appendChild(child);
    }
    root.appendChild(Cols);
    // SAVE ROW TITLE
    QDomElement Rows = document.createElement("Rows");
    Rows.setAttribute("RowCount",QString::number(table.getRowCount()));
    for (auto c : *table.getRowsNames())
    {
        QDomElement child = document.createElement("Row");
        child.setAttribute("value", QString::fromStdString(c));
        Rows.appendChild(child);
    }
    root.appendChild(Rows);
    // SAVE TABLE DATA
    QDomElement Data = document.createElement("Data");
    for (auto data : *table.getTable())
    {
        QDomElement test = document.createElement("Row");
        for (auto d : data){
            QDomElement child = document.createElement("Num");
            child.setAttribute("value", QString::number(d));
            test.appendChild(child);
        }
        Data.appendChild(test);
    }
    root.appendChild(Data);
    xmlContent << document.toString();

}

void Model::LoadXML(QString path){
    vector<vector<double>> tab;
    vector<string> rowsNames;
    vector<string> columnsNames;


    QDomDocument tableXML;
    QFile xmlFile(path);
    if (!xmlFile.open(QIODevice::ReadOnly ))
    {
        // Error while loading file
    }
    tableXML.setContent(&xmlFile);
    xmlFile.close();
    QDomElement root = tableXML.documentElement();
    QDomElement Cols = root.firstChildElement();
    QDomElement Row = Cols.nextSiblingElement();
    QDomElement Table = Row.nextSiblingElement();

    // LOAD COLS HEADER
    if (!Cols.isNull()){
        QDomElement ColsChild = Cols.firstChildElement();
        while(ColsChild.isNull() == false){
            columnsNames.push_back(ColsChild.attribute("value","x").toStdString());
            qDebug() << ColsChild.attribute("value","x") << " ";
            ColsChild = ColsChild.nextSiblingElement();
        }
    } else {
    }
    // LOAD ROWS TITLE
    if (!Row.isNull()){
        QDomElement RowChild = Row.firstChildElement();
        while(!RowChild.isNull()){
            rowsNames.push_back(RowChild.attribute("value","x").toStdString());
            qDebug() << RowChild.attribute("value","x") << " ";
            RowChild = RowChild.nextSiblingElement();
        }
    } else {
    }
    // LOAD TABLE DATA
    if (!Table.isNull()){
        qDebug() << Table.tagName();
        QDomElement Row = Table.firstChildElement();
        while (!Row.isNull()){
            vector<double> riga;
            QDomElement RowElement = Row.firstChildElement();
            while (!RowElement.isNull()){
                riga.push_back(RowElement.attribute("value","0").toDouble());
                qDebug() << RowElement.attribute("value","0") << " ";
                RowElement = RowElement.nextSiblingElement();
            }
            tab.push_back(riga);
            Row = Row.nextSiblingElement();
        }
    } else {
        qDebug() << "è null DC" << "";
    }

    TableData t(tab,rowsNames,columnsNames);
    table = t;
    table.printTable();

}
TableData* Model::getTable(){
    return &table;
}
