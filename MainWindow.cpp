#include <MainWindow.h>
#include <Controller.h>

#include <iostream>

MainWindow::MainWindow(QWidget *parent) : QWidget(parent){


    mainLayout= new QVBoxLayout;
    chartsLayout= new QHBoxLayout();

    chart= new Chart();


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
    tableView = new QTableView(this);

    tableView->setModel(controller->getModel());

    tableView->resizeColumnsToContents();
    tableView->resizeRowsToContents();
    tableView->setGeometry(0,30,300,300);
    tableView->setMinimumSize(640,480);
    tableView->setStyleSheet("QHeaderView::section {background-color:lightblue}");
    tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    tableView->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    chartsLayout->addWidget(tableView);
}
void MainWindow::addChartView(){
    chartsLayout->removeWidget(chartView);

    mapper=new vector<QVXYModelMapper*>();

    chartView = new QChartView(chart->generateChart(controller->getModel()->getTable()));
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setMinimumSize(640,480);

    chartsLayout->addWidget(chartView);
}

void MainWindow::refreshGui(){
    addTableView();
    addChartView();
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

    //View
    view=new QMenu("&View",menu);
    menu->addMenu(view);

    QAction* item1=new QAction("Pie chart");
    item1->setCheckable(true);
    QAction* item2=new QAction("Scatter chart");
    item2->setCheckable(true);
    QAction* item3=new QAction("Bar chart");
    item3->setCheckable(true);
    QAction* item4=new QAction("Spline chart");
    item4->setCheckable(true);
    QAction* item5=new QAction("Line chart");
    item5->setCheckable(true);
    QAction* item6=new QAction("Nested Pie chart");
    item6->setCheckable(true);

    view->addAction(item1);
    view->addAction(item2);
    view->addAction(item3);
    view->addAction(item4);
    view->addAction(item5);
    view->addAction(item6);

    QActionGroup* myGroup= new QActionGroup(this);
    myGroup->setExclusive(true);
    myGroup->addAction(item1);
    myGroup->addAction(item2);
    myGroup->addAction(item3);
    myGroup->addAction(item4);
    myGroup->addAction(item5);
    myGroup->addAction(item6);

    //Help
    help=new QMenu("&Help",menu);
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
    connect(file->actions().at(0),SIGNAL(triggered()),controller,SLOT(newChart()));
    connect(file->actions().at(1),SIGNAL(triggered()),controller,SLOT(loadXML()));
    connect(file->actions().at(2),SIGNAL(triggered()),controller,SLOT(saveXML()));
    connect(file->actions().at(4),SIGNAL(triggered()),this,SLOT(close()));

    //edit
    connect(edit->actions().at(0),SIGNAL(triggered()),controller,SLOT(insert_Row_Before_Selected()));//before
    connect(edit->actions().at(1),SIGNAL(triggered()),controller,SLOT(insert_Row_After_Selected()));//after

    connect(edit->actions().at(3),SIGNAL(triggered()),controller,SLOT(insert_Column_Before_Selected()));//before
    connect(edit->actions().at(4),SIGNAL(triggered()),controller,SLOT(insert_Column_After_Selected()));//after

    connect(edit->actions().at(6),SIGNAL(triggered()),controller,SLOT(remove_Selected_Column()));
    connect(edit->actions().at(7),SIGNAL(triggered()),controller,SLOT(remove_Selected_Row()));

    //views
    connect(view->actions().at(0),SIGNAL(triggered()),this,SLOT(setPieChart()));
    connect(view->actions().at(1),SIGNAL(triggered()),this,SLOT(setScatterChart()));
    connect(view->actions().at(2),SIGNAL(triggered()),this,SLOT(setBarChart()));
    connect(view->actions().at(3),SIGNAL(triggered()),this,SLOT(setSplineChart()));
    connect(view->actions().at(4),SIGNAL(triggered()),this,SLOT(setLineChart()));
    connect(view->actions().at(5),SIGNAL(triggered()),this,SLOT(setNestedPieChart()));

    //+altre
    connect(controller->getModel(),&QAbstractItemModel::dataChanged,[&](){refreshGui();});

    connect(help->actions().at(0),&QAction::triggered,[&](){
        QMessageBox msgBox;
        msgBox.setText("Developed by Nicolo' Trinca & Marco Bernardi");
        msgBox.exec();});

}
void MainWindow::setPieChart(){
    chart=new PieChart();
    refreshGui();
    QMessageBox msgBox;
    msgBox.setText("Pie Chart take only frist row");
    msgBox.exec();
}
void MainWindow::setNestedPieChart(){
    chart=new NestedPieChart();
    refreshGui();
}
void MainWindow::setBarChart(){
    chart=new BarChart();
    refreshGui();
}
void MainWindow::setLineChart(){
    chart=new LineChart();
    refreshGui();
}
void MainWindow::setSplineChart(){
    chart=new SplineChart();
    refreshGui();
}
void MainWindow::setScatterChart(){
    chart=new ScatterChart();
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
