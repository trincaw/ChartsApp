#ifndef DATAHOLDER_H
#define DATAHOLDER_H

#include <vector>
#include <string>

#include <iostream>

typedef unsigned int u_int;
using std::vector;
using std::string;

class DataHolder
{
private:
    vector<vector<double>>* table;
    vector<string>* rowsNames;
    vector<string>* columnsNames;
    u_int rowsCount;
    u_int columnsCount;

public:
    DataHolder();
    //DataHolder(vector<vector<double>>* table, vector<string>* rowsNames, vector<string>* columnsNames);
    ~DataHolder();

    u_int GetRowCount();
    u_int GetColumnCount();

    void addRow(const vector<double> &row,u_int index=0, const string &rowName="");
    void addColumn(const vector<double> &column,u_int index=0, const string &columnName="");
    void deleteRow(const u_int index);
    void deleteColumn(const u_int index);

    //Deboug
    void PrintModel() const;
    void LoadModelRandom(const u_int columns,const u_int rows);
};

#endif // DATAHOLDER_H
