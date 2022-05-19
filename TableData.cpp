#include "TableData.h"
using std::string;
using std::vector;

TableData::TableData() : table(new vector<vector<double>>), rowsNames(new vector<string>), columnsNames(new vector<string>), rowsCount(0), columnsCount(0) {}
TableData::TableData(vector<vector<double>> &table, vector<string> &rowsNames, vector<string> &columnsNames) : rowsCount(rowsNames.size()), columnsCount(columnsNames.size())
{
    this->table = new auto(table);
    this->rowsNames = new auto(rowsNames);
    this->columnsNames = new auto(columnsNames);
}
u_int TableData::getRowCount() const
{
    return rowsCount;
}
u_int TableData::getColumnCount() const
{
    return columnsCount;
}
vector<vector<double>> *TableData::getTable() const
{
    return table;
}
vector<vector<double>> *TableData::getTable()
{
    return table;
}
void TableData::clearTable(){
    table->clear();
    columnsNames->clear();
    rowsNames->clear();
    columnsCount=0;
    rowsCount=0;
}
void TableData::addRow(vector<double> &row, u_int index, const string &rowName)
{
    if (row.size() == columnsCount)
    {
        if (rowsCount > index)
        {
            rowsNames->insert(rowsNames->begin() + index, rowName);
            table->insert(table->begin() + index, row);
        }
        else //if (rowsCount == index)
        {
            rowsNames->push_back(rowName);
            table->push_back(row);
        }
        rowsCount += 1;
    }
    else
        std::cout << "Add row out of range or overflow" << std::endl;
    printTable();
}
void TableData::addColumn(vector<double> &column, u_int index, const string columnName)
{
    if (column.size() == rowsCount)
    {
        if (columnsCount > index)
        {
            for (u_int i = 0; rowsCount > i; ++i)
                (*table)[i].insert((*table)[i].begin() + index, column[i]);
            columnsNames->insert(columnsNames->begin() + index, columnName);
        }
        else //if (columnsCount == index)
        {
            for (u_int i = 0; rowsCount > i; ++i)
                (*table)[i].push_back(column[i]);
            columnsNames->push_back(columnName);
        }
        columnsCount += 1;
    }
    else
        std::cout << "Add column out of range or overflow" << std::endl;
    printTable();

}
vector<string> *TableData::getRowsNames() const
{
    return rowsNames;
}
vector<string> *TableData::getColumnsNames() const
{
    return columnsNames;
}
void TableData::deleteColumn(const u_int index)
{
    if (columnsCount > index)
    {
        if(columnsCount==1){
            clearTable();
        }
        else{
        columnsNames->erase(columnsNames->begin() + index);
        for (u_int i = 0; rowsCount > i; ++i)
            (*table)[i].erase((*table)[i].begin() + index);
        columnsCount -= 1;
        }
    }
    else
        std::cout << "Remove column out of range or overflow" << std::endl;
    printTable();
}
void TableData::deleteRow(const u_int index)
{
    if (rowsCount > index)
    {
        if(rowsCount==1){
            clearTable();
        }
        else{
        rowsNames->erase(rowsNames->begin() + index);
        table->erase(table->begin() + index);
        rowsCount -= 1;
        }
    }
    else
        std::cout << "Remove row out of range or overflow" << std::endl;
    printTable();
}

void TableData::printTable() const
{
    std::cout << std::endl;
    std::cout << "Names:";
    std::cout << std::endl;std::cout << " ";
    for (auto c : *columnsNames)
    {
        std::cout << c << " ";
    }
    std::cout << std::endl;
    for (auto r : *rowsNames)
    {
        std::cout << r << " ";
        std::cout << std::endl;
    }
    std::cout << "Table:";
    std::cout << std::endl;
    for (auto data : *table)
    {
        for (auto d : data)
            std::cout << d << " ";
        std::cout << std::endl;
    }

    std::cout << "Columns:" << columnsCount << " ";
    std::cout << "Rows:" << rowsCount << " ";
    std::cout << std::endl;
}

void TableData::loadModelRandom(const u_int columns, const u_int rows)
{
    for (u_int j = 0; columns > j; j++)
    {
        vector<double> d = vector<double>();
        for (u_int i = 0; rows > i; i++)
        {
            d.push_back(i + j);
        }
        columnsNames->push_back("");
        table->push_back(d);

    }
    for (u_int i = 0; rows > i; i++)
    {
        rowsNames->push_back("");
    }
    columnsCount = columns;
    rowsCount = rows;
    printTable();
}
double TableData::getMaxValue() const{
    if(table){
        double max=0;
        for(int i=0;i<table->size();++i)
            for(int j=0;j<table[i].size();++j)
                if(double m=table->at(i).at(j)>max)
                    max=m;
        return max;

    }
}
