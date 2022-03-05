#include <DataHolder.h>

int main(int argc, char *argv[])
{
    DataHolder* d=new  DataHolder();
    d->LoadModelRandom(5,5);
    vector<double> temp= vector<double>{1,1,1,1,1};
    d->addRow(temp,0);
    d->PrintModel();
}
