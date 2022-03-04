#ifndef DATAHOLDER_H
#define DATAHOLDER_H

#include <vector>
#include <string>

typedef unsigned int u_int;
using std::vector;
using std::string;

class DataHolder
{
private:
    vector<vector<double>>* table;
    vector<string>* rowsNames;
    vector<string>* columnsNames;
    u_int rowsSize;
    u_int columnsSize;

public:
    DataHolder();
    //DataHolder(vector<vector<double>>* table, vector<string>* rowsNames, vector<string>* columnsNames);
    ~DataHolder();

    u_int GetRowSize();
    u_int GetColumnSize();

    void addRow(const vector<double> &row,u_int index=0, const string &rowName="");
    void addColumn(const vector<double> &column,u_int index=0, const string &columnName="");
    void deleteRow(const u_int index);
    void deleteColumn(const u_int index);
};

#endif // DATAHOLDER_H
