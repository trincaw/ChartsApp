#include <MainWindow.h>
#include <Controller.h>

#include <iostream>

MainWindow::MainWindow(QWidget *parent) : QWidget(parent){


    mainLayout= new QVBoxLayout;
    chartsLayout= new QHBoxLayout();

    chart= new Chart("new chart");


    //addControls(mainLayout);

    chartsLayout->setSpacing(0);
    chartsLayout->setAlignment(Qt::AlignCenter);
    chartsLayout->setContentsMargins(0,0,0,0);

    mainLayout->setSpacing(0);
    mainLayout->setAlignment(Qt::AlignTop);
    mainLayout->setContentsMargins(0,0,0,0);


    setLayout(mainLayout);
    resize(QSize(1024, 720));

    QRect screenSize= QGuiApplication::screens().first()->geometry();
    const QRect wr{{},frameSize().boundedTo(screenSize.size())};
    move(screenSize.center()-wr.center());

    //setWindowIcon(QIcon(":/images/icon.png"));

    addMenuBar();
    mainLayout->addLayout(chartsLayout);




}

void MainWindow::addTableView(){
    chartsLayout->removeWidget(tableView);
    tableView = new QTableView();
    //QAbstractTableModel *myModel = new Model(this);

    tableView->setModel(controller->getModel());

    tableView->resizeColumnsToContents();
    tableView->resizeRowsToContents();
    tableView->setGeometry(0,30,300,300);
    tableView->setMinimumSize(640,480);
    tableView->setStyleSheet("QHeaderView::section {background-color:lightblue}");
    tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    tableView->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    //QLineSeries *series = new QLineSeries;
    //series->setName("Line 1");

    //mapper->setXColumn(0);
    //mapper->setYColumn(1);
    //mapper->setSeries(series);
    //mapper->setModel(controller->getModel());
    chartsLayout->addWidget(tableView);

}
vector<QColor>* MainWindow::addChartView(){
    chartsLayout->removeWidget(chartView);

    mapper=new vector<QVXYModelMapper*>();

    chartView = new QChartView(chart->generateChart(controller->getModel()));
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setMinimumSize(640,480);

    chartsLayout->addWidget(chartView);

}

void MainWindow::refreshGui(){
    addTableView();
    auto colors=addChartView();
    updateTableColors(colors);
}
void MainWindow::updateTableColors(vector<QColor>* colors){

}
void MainWindow::addMenuBar(){
    menu=new QMenuBar();
    //File
    file=new QMenu("&File");
    menu->addMenu(file);

    //Menu
    file->addAction(new QAction("New",file));
    file->addAction(new QAction("Open",file));
    file->addAction(new QAction("Save",file));

    file->addSeparator();
    file->addAction(new QAction("Exit",file));
    //Edit
    edit=new QMenu("&Edit",menu);
    menu->addMenu(edit);

    edit->addAction(new QAction("Add row before",menu));
    edit->addAction(new QAction("Add row after",menu));
    edit->addSeparator();
    edit->addAction(new QAction("Add column before",menu));
    edit->addAction(new QAction("Add column after",menu));
    edit->addSeparator();
    edit->addAction(new QAction("Delete selected column",menu));
    edit->addAction(new QAction("Delete selected row",menu));
    edit->addSeparator();
    edit->addAction(new QAction("Clear table",menu));
    //View
    view=new QMenu("&View",menu);
    menu->addMenu(view);

    QAction* item1=new QAction("Pie chart");
    item1->setCheckable(true);
    QAction* item2=new QAction("Donut chart");
    item2->setCheckable(true);
    QAction* item3=new QAction("Bar chart");
    item3->setCheckable(true);
    QAction* item4=new QAction("Stacked bar chart");
    item4->setCheckable(true);
    QAction* item5=new QAction("Line chart");
    item5->setCheckable(true);

    view->addAction(item1);
    view->addAction(item2);
    view->addAction(item3);
    view->addAction(item4);
    view->addAction(item5);

    QActionGroup* myGroup= new QActionGroup(this);
    myGroup->setExclusive(true);
    myGroup->addAction(item1);
    myGroup->addAction(item2);
    myGroup->addAction(item3);
    myGroup->addAction(item4);
    myGroup->addAction(item5);

//help
    help=new QMenu("&help",menu);
    help->addAction(new QAction("About",menu));

    menu->addMenu(help);

    mainLayout->addWidget(menu);
}
void MainWindow::setTableView()
{
    if(tableView!=nullptr)
        layout()->removeWidget(tableView);
    else
        tableView= new QTableView();
    tableView->setModel(controller->getModel());
    tableView->resizeColumnsToContents();
    tableView->resizeRowsToContents();
    tableView->setGeometry(0,30,300,300);
    tableView->setStyleSheet("QHeaderView::section {background-color:lightblue}");
    tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    tableView->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    layout()->addWidget(tableView);
}
void MainWindow::setController(Controller* c){
    controller=c;


    refreshGui();


    //file
    //connect(file->actions().at(0),SIGNAL(triggered()),controller,SLOT(newChart()));

    connect(file->actions().at(1),SIGNAL(triggered()),controller,SLOT(loadXML()));
    connect(file->actions().at(2),SIGNAL(triggered()),controller,SLOT(saveXML()));
    connect(file->actions().at(4),SIGNAL(triggered()),this,SLOT(close()));

    //+altre
    //edit
    connect(edit->actions().at(0),SIGNAL(triggered()),controller,SLOT(insert_Row_Before_Selected()));//before
    connect(edit->actions().at(1),SIGNAL(triggered()),controller,SLOT(insert_Row_After_Selected()));//after

    connect(edit->actions().at(3),SIGNAL(triggered()),controller,SLOT(insert_Column_Before_Selected()));//before
    connect(edit->actions().at(4),SIGNAL(triggered()),controller,SLOT(insert_Column_After_Selected()));//after

    connect(edit->actions().at(6),SIGNAL(triggered()),controller,SLOT(remove_Selected_Column()));
    connect(edit->actions().at(7),SIGNAL(triggered()),controller,SLOT(remove_Selected_Row()));

    connect(edit->actions().at(9),SIGNAL(triggered()),controller,SLOT(clearTable()));

    //views
    connect(view->actions().at(0),SIGNAL(triggered()),this,SLOT(setPieChart()));
    connect(view->actions().at(1),SIGNAL(triggered()),this,SLOT(setPieChart()));
    connect(view->actions().at(2),SIGNAL(triggered()),this,SLOT(setBarChart()));


    //+altre
    connect(controller->getModel(),&QAbstractItemModel::dataChanged,[&](){refreshGui();});

}
void MainWindow::setPieChart(){
    chart=new PieChart("New chart");
    refreshGui();
}
void MainWindow::setBarChart(){
    chart=new BarChart("New chart");
    refreshGui();
}
u_int MainWindow::getSelectedColumn() const{
    return tableView->selectionModel()->currentIndex().column();
}
u_int MainWindow::getSelectedRow() const{
    return tableView->selectionModel()->currentIndex().row();
}
//Chart* MainWindow::getChart() const{
//    return chart;
//}
