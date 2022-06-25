#include "TableData.h"
using std::string;
using std::vector;

TableData::TableData() : table(vector<vector<double>>()), rowsNames( vector<string>()), columnsNames( vector<string>()), rowsCount(0), columnsCount(0) {}
TableData::TableData(vector<vector<double>> table, vector<string> rowsNames, vector<string> columnsNames) : rowsCount(rowsNames.size()), columnsCount(columnsNames.size())
{
    this->table =  table;
    this->rowsNames =  rowsNames;
    this->columnsNames =  columnsNames;
}
u_int TableData::getRowCount() const
{
    return rowsCount;
}
u_int TableData::getColumnCount() const
{
    return columnsCount;
}
vector<vector<double>> TableData::getTable() const
{
    return table;
}
void TableData::changeValue(const u_int x,const u_int y,double value){
     table.at(x).at(y) = value;
}
void TableData::clearTable(){
    table.clear();
    columnsNames.clear();
    rowsNames.clear();
    columnsCount=0;
    rowsCount=0;
}
void TableData::addRow(vector<double> &row, u_int index, const string &rowName)
{
    if (row.size() == columnsCount)
    {
        if (rowsCount > index)
        {
            rowsNames.insert(rowsNames.begin() + index, rowName);
            table.insert(table.begin() + index, row);
        }
        else //if (rowsCount == index)
        {
            rowsNames.push_back(rowName);
            table.push_back(row);
        }
        rowsCount += 1;
    }
    else
        std::cout << "Add row out of range or overflow" << std::endl;
}
void TableData::addColumn(vector<double> &column, u_int index, const string columnName)
{
    if (column.size() == rowsCount)
    {
        if (columnsCount > index)
        {
            for (u_int i = 0; rowsCount > i; ++i)
                (table)[i].insert((table)[i].begin() + index, column[i]);
            columnsNames.insert(columnsNames.begin() + index, columnName);
        }
        else //if (columnsCount == index)
        {
            for (u_int i = 0; rowsCount > i; ++i)
                (table)[i].push_back(column[i]);
            columnsNames.push_back(columnName);
        }
        columnsCount += 1;
    }
    else
        std::cout << "Add column out of range or overflow" << std::endl;
}
vector<string> TableData::getRowsNames() const
{
    return rowsNames;
}
vector<string> TableData::getColumnsNames() const
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
        columnsNames.erase(columnsNames.begin() + index);
        for (u_int i = 0; rowsCount > i; ++i)
            (table)[i].erase((table)[i].begin() + index);
        columnsCount -= 1;
        }
    }
    else
        std::cout << "Remove column out of range or overflow" << std::endl;
}
void TableData::deleteRow(const u_int index)
{
    if (rowsCount > index)
    {
        if(rowsCount==1){
            clearTable();
        }
        else{
        rowsNames.erase(rowsNames.begin() + index);
        table.erase(table.begin() + index);
        rowsCount -= 1;
        }
    }
    else
        std::cout << "Remove row out of range or overflow" << std::endl;
}
