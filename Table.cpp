#include "Table.h"
using std::vector;
using std::string;

Table::Table():table(new vector<vector<double>>), rowsNames(new vector<string>), columnsNames(new vector<string>), rowsCount(0),columnsCount(0){}
Table::Table(vector<vector<double>> &table, vector<string> &rowsNames, vector<string> &columnsNames):rowsCount(rowsNames.size()),columnsCount(columnsNames.size()){
    this->table=&table;
    this->rowsNames=&rowsNames;
    this->columnsNames=&columnsNames;
}
Table::~Table(){
    vector<vector<double>>().swap(*table);//deallocate all the table cells memory
    vector<string>().swap(*rowsNames);
    vector<string>().swap(*columnsNames);
    delete table;
    delete rowsNames;
    delete columnsNames;
}
u_int Table::getRowCount() const{
    return rowsCount;
}
u_int Table::getColumnCount() const{
    return columnsCount;
}
vector<vector<double>>* Table::getTable() const{
    return table;
}
void Table::addRow(const vector<double> &row,u_int index, const string &rowName){
    if(rowsCount==0 && columnsCount==0){
        table->push_back(row);
        rowsNames->insert(rowsNames->begin()+index,rowName);
        columnsCount+=1;
    }
    else if(rowsCount>index){
    rowsNames->insert(rowsNames->begin()+index,rowName);
    table->insert(table->begin()+index,row);
    }
    else if(rowsCount==index){
    rowsNames->push_back(rowName);
    table->push_back(row);
    }
    else
        std::cout <<"Add row out of range";
    rowsCount+=1;
}
void Table::addColumn(const vector<double> &column,u_int index, const string &columnName){
    if(rowsCount==0 && columnsCount==0 ){
        rowsCount+=1;
        rowsNames->insert(rowsNames->begin()+index,columnName);
        table->push_back(column);
    }
    else if(columnsCount>index){
             for(u_int i=0;columnsCount>i;++i)
                 (*table)[i].insert((*table)[i].begin()+index,column[i]);
             columnsNames->insert(rowsNames->begin()+index,columnName);
        }
    else if(columnsCount==index){
             for(u_int i=0;columnsCount>i;++i)
                 (*table)[i].push_back(column[i]);
             columnsNames->push_back(columnName);
        }
        else
            std::cout <<"Add column out of range ";
     columnsCount+=1;
}
vector<string>* Table::getRowsNames() const{
    return rowsNames;
}
vector<string>* Table::getColumnsNames() const{
    return columnsNames;
}






void Table::printModel() const
{
    for(auto data: *table){
        for(auto d: data)
            std::cout << d;
        std::cout << std::endl;
    }
    std::cout << "Columns:"<< columnsCount<<" ";
    std::cout << "Rows:"<< rowsCount<<" ";
}
void Table::loadModelRandom(const u_int columns,const u_int rows){
    for(u_int j=0;columns>j;j++){
        vector<double> d= vector<double>();
        for(u_int i=0;rows>i;i++){
            d.push_back(0);
        }
        table->push_back(d);
        columnsNames->push_back("");
    }
    for(u_int i=0;rows>i;i++){
        rowsNames->push_back("");
    }
    columnsCount=columns;
    rowsCount=rows;
}
