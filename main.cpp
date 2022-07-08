#include <QtWidgets/QApplication>
#include "MainWindow.h"
#include "Controller.h"
#include "Model.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Controller c;
    Model m;

    a.setWindowIcon(QIcon("://Icons/ChartApp.png"));
    c.setModel(&m);
    c.setView(&w);
    w.setController(&c);
    w.show();
    return a.exec();
}
