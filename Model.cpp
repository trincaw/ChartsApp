#include "Model.h"

Model::Model(QObject *parent) : QAbstractTableModel(parent){
    createNewTable();
}
Model::~Model(){
    delete table;
}
int Model::rowCount(const QModelIndex & /*parent*/) const{
    return table->getRowCount();
}
int Model::columnCount(const QModelIndex & /*parent*/) const{
    return table->getColumnCount();
}
QVariant Model::data(const QModelIndex &index, int role) const{
    if (role == Qt::DisplayRole){
        qreal temp = table->getTable().at(index.row()).at(index.column());
        return temp;
    }else if (role == Qt::BackgroundRole) {
    for (const QRect &rect : m_mapping) {
        if (rect.contains(index.column(), index.row()))
            return QColor(m_mapping.key(rect));
    }
    // cell not mapped return white color
    return QColor(Qt::white);
}
return QVariant();
}
bool Model::setData(const QModelIndex &index, const QVariant &value, int role){
    if (role == Qt::EditRole){
        table->changeValue(index.row(),index.column(),value.toDouble());
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
        if(((int)table->getRowCount()) > section)
            return QString::fromStdString(table->getRowsNames().at(section));
    } else{
        if(((int)table->getColumnCount()) > section)
            return QString::fromStdString(table->getColumnsNames().at(section));
    }
    return QString();
}
void Model::addMapping(QString color, QRect area)
{
    m_mapping.insertMulti(color, area);
}
void Model::addRow(u_int i, std::string label){
    vector<double> v(table->getColumnCount(),0);
    table->addRow(v,i,label);
}
void Model::addColumn(u_int i, std::string label){
    vector<double> v(table->getRowCount(),0);
    table->addColumn(v,i,label);
}
void Model::removeColumn(u_int i){table->deleteColumn(i);}
void Model::removeRow(u_int i){table->deleteRow(i);}
void Model::createNewTable(){
    vector<double> column={0};
    vector<double> row={0};
    if(table!=nullptr)
    delete table;
    table=new TableData();
    table->addColumn(column,0,"x");
    table->addRow(row,0,"y");
}

void Model::SaveCSV(QString path) const{
    if(!(path.contains(".csv")))
        path=path+".csv";
    QFile csvFile(path);
    if (csvFile.open(QFile::WriteOnly | QFile::Truncate)){
        QTextStream output(&csvFile);
        for(unsigned long j = 0; j < table->getColumnCount(); j++){
            if (j == table->getColumnCount() - 1){
                output << QString::fromStdString(table->getColumnsNames()[j]);
            } else{
                output << QString::fromStdString(table->getColumnsNames()[j]) << ",";
            }
        }
        output << '\n';
        for(unsigned long i = 0; i < table->getRowCount(); i++){
            output << QString::fromStdString(table->getRowsNames()[i]) << ",";
            for(unsigned long j = 0; j < table->getColumnCount(); j++){
                if (j == table->getColumnCount() - 1){
                    output << table->getTable()[i][j];
                } else{
                    output << table->getTable()[i][j] << ",";
                }
            }
            output << '\n';
        }
    }
    csvFile.close();
}

void Model::LoadCSV(QString path) {
    QFile file(path);
    vector<vector<double>> tab;
    vector<string> rowsNames;
    vector<string> columnsNames;
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << file.errorString();
        return;
    }
    QByteArray line = file.readLine();
    for (auto &c : line.split(','))
    {
        columnsNames.push_back(c.toStdString());
    }
    QList<QByteArray> splitted;
    while (!file.atEnd()) {
        line = file.readLine();
        splitted = line.split(',');
        rowsNames.push_back(splitted[0].toStdString());
        vector<double> riga;
        for(int i = 1; i < splitted.count(); i++){
            riga.push_back(splitted[i].toDouble());
        }
        tab.push_back(riga);
    }
    delete table;
    table = new TableData(tab,rowsNames,columnsNames);
}

void Model::SaveXML(QString path) const{
    if(!(path.contains(".chart")))
        path=path+".chart";

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
    Cols.setAttribute("CollumnCount",QString::number(table->getColumnCount()));
    for (const string &c : table->getColumnsNames())
    {
        QDomElement child = document.createElement("Col");
        child.setAttribute("value", QString::fromStdString(c));
        Cols.appendChild(child);
    }
    root.appendChild(Cols);
    // SAVE ROW TITLE
    QDomElement Rows = document.createElement("Rows");
    Rows.setAttribute("RowCount",QString::number(table->getRowCount()));
    for (const string &c : table->getRowsNames())
    {
        QDomElement child = document.createElement("Row");
        child.setAttribute("value", QString::fromStdString(c));
        Rows.appendChild(child);
    }
    root.appendChild(Rows);
    // SAVE TABLE DATA
    QDomElement Data = document.createElement("Data");
    for (const auto &data : table->getTable())
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
       qDebug() << "errore nel file"; // Error while loading file
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
            ColsChild = ColsChild.nextSiblingElement();
        }
    } else {
    }
    // LOAD ROWS TITLE
    if (!Row.isNull()){
        QDomElement RowChild = Row.firstChildElement();
        while(!RowChild.isNull()){
            rowsNames.push_back(RowChild.attribute("value","x").toStdString());
            RowChild = RowChild.nextSiblingElement();
        }
    } else {
    }
    // LOAD TABLE DATA
    if (!Table.isNull()){
        QDomElement Row = Table.firstChildElement();
        while (!Row.isNull()){
            vector<double> riga;
            QDomElement RowElement = Row.firstChildElement();
            while (!RowElement.isNull()){
                riga.push_back(RowElement.attribute("value","0").toDouble());
                RowElement = RowElement.nextSiblingElement();
            }
            tab.push_back(riga);
            Row = Row.nextSiblingElement();
        }
    }
    delete table;
    table = new TableData(tab,rowsNames,columnsNames);

}
TableData* Model::getTable(){
    return table;
}

