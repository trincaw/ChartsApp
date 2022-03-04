#ifndef DATAHOLDER_H
#define DATAHOLDER_H

#include <vector>

typedef unsigned int u_int;

class DataHolder
{
private:
    std::vector<std::vector<double>>* table;
public:
    DataHolder();
    u_int rowSize();
    u_int columnSize();
};

#endif // DATAHOLDER_H
