#include <TableData.h>

int main(int argc, char *argv[])
{
    TableData* d=new  TableData();
    d->loadModelRandom(3,5);
    vector<double> temp= vector<double>{1,1,1,1,1};
    d->addRow(temp,5);
    d->printModel();
}
