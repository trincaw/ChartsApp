#include "DataHolder.h"
using std::vector;
using std::string;

DataHolder::DataHolder():table(new vector<vector<double>>), rowsNames(new vector<string>), columnsNames(new vector<string>) {}
DataHolder::~DataHolder(){
    vector<vector<double>>().swap(*table);//deallocate all the table cells memory
    vector<string>().swap(*rowsNames);
    vector<string>().swap(*columnsNames);
    delete table;
    delete rowsNames;
    delete columnsNames;
}
u_int DataHolder::GetRowSize(){
    return table->size();
}
u_int DataHolder::GetColumnSize(){
    if(GetRowSize()>0)
           return (*table)[0].size();
       else
           return 0;
}
