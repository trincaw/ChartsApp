#ifndef TABLE_H
#define TABLE_H

#include <vector>
#include <string>

#include <iostream>

typedef unsigned int u_int;
using std::vector;
using std::string;

class Table
{
private:
    vector<vector<double>>* table;
    vector<string>* rowsNames;
    vector<string>* columnsNames;
    u_int rowsCount;
    u_int columnsCount;

public:
    Table();
    Table(vector<vector<double>>& table, vector<string>& rowsNames, vector<string>& columnsNames);
    ~Table();

    u_int getRowCount() const;
    u_int getColumnCount() const;

    void addRow(const vector<double> &row,u_int index=0, const string &rowName="");
    void addColumn(const vector<double> &column,u_int index=0, const string &columnName="");
    void deleteRow(const u_int index);
    void deleteColumn(const u_int index);

    vector<double> getColumn(const u_int index) const;
    vector<double> getRow(const u_int index) const;
    vector<string>* getRowsNames() const;
    vector<string>* getColumnsNames() const;
    vector<vector<double>>* getTable() const;

    //Deboug
    void printModel() const;
    void loadModelRandom(const u_int columns,const u_int rows);
};

#endif // TABLE_H
