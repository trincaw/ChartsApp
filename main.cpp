#include <TableData.h>

int main(int argc, char *argv[])
{
    TableData* d=new  TableData();
    d->loadModelRandom(5,5);
    vector<double> temp= vector<double>{1,1,1,1,1};
    d->addRow(temp,0);
    d->printModel();
}
