#include "TableData.h"
using std::string;
using std::vector;

TableData::TableData() : table(new vector<vector<double>>), rowsNames(new vector<string>), columnsNames(new vector<string>), rowsCount(0), columnsCount(0) {}
TableData::TableData(vector<vector<double>> &table, vector<string> &rowsNames, vector<string> &columnsNames) : rowsCount(rowsNames.size()), columnsCount(columnsNames.size())
{
    this->table = &table;
    this->rowsNames = &rowsNames;
    this->columnsNames = &columnsNames;
}
TableData::~TableData()
{
    vector<vector<double>>().swap(*table); // deallocate all the table cells memory
    vector<string>().swap(*rowsNames);
    vector<string>().swap(*columnsNames);
    delete table;
    delete rowsNames;
    delete columnsNames;
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
void TableData::addRow(const vector<double> &row, u_int index, const string &rowName)
{
    if (row.size() == rowsCount)
    {
        if (rowsCount == 0 && columnsCount == 0)
        {
            table->push_back(row);
            rowsNames->insert(rowsNames->begin() + index, rowName);
            columnsCount += 1;
        }
        else if (rowsCount > index)
        {
            rowsNames->insert(rowsNames->begin() + index, rowName);
            table->insert(table->begin() + index, row);
        }
        else if (rowsCount == index)
        {
            rowsNames->push_back(rowName);
            table->push_back(row);
        }
        rowsCount += 1;
    }
    else
        std::cout << "Add row out of range or overflow" << std::endl;
}
void TableData::addColumn(const vector<double> &column, u_int index, const string &columnName)
{
    if (column.size() == columnsCount)
    {
        if (rowsCount == 0 && columnsCount == 0)
        {
            rowsNames->insert(rowsNames->begin() + index, columnName);
            table->push_back(column);
            rowsCount += 1;
        }
        else if (columnsCount > index)
        {
            for (u_int i = 0; columnsCount > i; ++i)
                (*table)[i].insert((*table)[i].begin() + index, column[i]);
            columnsNames->insert(rowsNames->begin() + index, columnName);
        }
        else if (columnsCount == index)
        {
            for (u_int i = 0; columnsCount > i; ++i)
                (*table)[i].push_back(column[i]);
            columnsNames->push_back(columnName);
        }
        columnsCount += 1;
    }
    else
        std::cout << "Add column out of range or overflow" << std::endl;
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
        columnsNames->erase(columnsNames->begin() + index);
        for (u_int i = 0; rowsCount > i; ++i)
            (*table)[i].erase((*table)[i].begin() + index);
        columnsCount -= 1;
    }
    else
        std::cout << "Remove column out of range or overflow" << std::endl;
}
void TableData::deleteRow(const u_int index)
{
    if (rowsCount > index)
    {
        rowsNames->erase(rowsNames->begin() + index);
        table->erase(table->begin() + index);
        rowsCount -= 1;
    }
    else
        std::cout << "Remove row out of range or overflow" << std::endl;
}

void TableData::printModel() const
{
    for (auto data : *table)
    {
        for (auto d : data)
            std::cout << d << " ";
        std::cout << std::endl;
    }
    std::cout << "Columns:" << columnsCount << " ";
    std::cout << "Rows:" << rowsCount << " ";
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
        table->push_back(d);
        columnsNames->push_back("");
    }
    for (u_int i = 0; rows > i; i++)
    {
        rowsNames->push_back("");
    }
    columnsCount = columns;
    rowsCount = rows;
}
