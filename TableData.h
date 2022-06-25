#ifndef TABLEDATA_H
#define TABLEDATA_H

#include <vector>
#include <string>

#include <iostream>

typedef unsigned int u_int;
using std::vector;
using std::string;

class TableData
{
private:
    vector<vector<double>> table;
    vector<string> rowsNames;
    vector<string> columnsNames;
    u_int rowsCount;
    u_int columnsCount;
    void clearTable();

public:
    TableData();
    TableData(vector<vector<double>> table, vector<string> rowsNames, vector<string> columnsNames);

    //size getters
    u_int getRowCount() const;
    u_int getColumnCount() const;

    //basic operations
    void changeValue(const u_int x,const u_int y,double value);
    void addRow( vector<double> &row,const u_int index=0, const string &rowName="");
    void addColumn(vector<double> &column,const u_int index=0, const string columnName="");
    void deleteRow(const u_int index);
    void deleteColumn(const u_int index);

    //data getters
    vector<string> getRowsNames() const;
    vector<string> getColumnsNames() const;
    vector<vector<double>> getTable() const;
};

#endif // TABLEDATA_H
