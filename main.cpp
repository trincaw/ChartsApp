#include <Tabel.h>

int main(int argc, char *argv[])
{
    Tabel* d=new  Tabel();
    d->LoadModelRandom(5,5);
    vector<double> temp= vector<double>{1,1,1,1,1};
    d->addRow(temp,0);
    d->PrintModel();
}
