#include "DataHolder.h"
using std::vector;
using std::string;

DataHolder::DataHolder():table(new vector<vector<double>>), rowsNames(new vector<string>), columnsNames(new vector<string>), rowsCount(0),columnsCount(0){}
DataHolder::~DataHolder(){
    vector<vector<double>>().swap(*table);//deallocate all the table cells memory
    vector<string>().swap(*rowsNames);
    vector<string>().swap(*columnsNames);
    delete table;
    delete rowsNames;
    delete columnsNames;
}
u_int DataHolder::GetRowCount(){
    return table->size();
}
u_int DataHolder::GetColumnCount(){
    if(GetRowCount()>0)
           return (*table)[0].size();
       else
           return 0;
}
void DataHolder::addRow(const vector<double> &row,u_int index, const string &rowName){
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
void DataHolder::addColumn(const vector<double> &column,u_int index, const string &columnName){
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
void DataHolder::PrintModel() const
{
    for(auto data: *table){
        for(auto d: data)
            std::cout << d;
        std::cout << std::endl;
    }
    std::cout << "Columns:"<< columnsCount<<" ";
    std::cout << "Rows:"<< rowsCount<<" ";
}
void DataHolder::LoadModelRandom(const u_int columns,const u_int rows){
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
