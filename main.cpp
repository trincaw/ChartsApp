#include <Table.h>

int main(int argc, char *argv[])
{
    Table* d=new  Table();
    d->loadModelRandom(5,5);
    vector<double> temp= vector<double>{1,1,1,1,1};
    d->addRow(temp,0);
    d->printModel();
}
