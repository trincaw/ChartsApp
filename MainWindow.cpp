#include <MainWindow.h>
#include <Controller.h>

#include <iostream>

MainWindow::MainWindow(QWidget *parent) : QWidget(parent){

    mainLayout= new QVBoxLayout;
    chartsLayout= new QHBoxLayout();

    //costruisce di default un barChart
    chart= new BarChart();


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

    addMenuBar();
    mainLayout->addLayout(chartsLayout);
}
MainWindow::~MainWindow(){

    delete file;
    delete edit;
    delete view;
    delete credits;
    delete menu;

    delete tableView;
    delete chartView;

    delete chartsLayout;
    delete mainLayout;
}
void MainWindow::refreshTableView(){
    if(tableView==nullptr){
    tableView = new QTableView(this);
    chartsLayout->addWidget(tableView);
    }
    tableView->setModel(controller->getModel());

    tableView->resizeColumnsToContents();
    tableView->resizeRowsToContents();
    tableView->setGeometry(0,30,300,300);
    tableView->setMinimumSize(640,480);
    tableView->setStyleSheet("QHeaderView::section {background-color:lightblue}");
    tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    tableView->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    //controller->setTableViewOnModel(tableView);

}
void MainWindow::refreshChartView(){
    if(chartView==nullptr){
    chartView = new ChartView();
    chartsLayout->addWidget(chartView);
    }

    chart->setModel(controller->getModel());
    if(auto c=chart->generateChart())
    chartView->setChart(c);

    if(colorsItem!=nullptr && colorsItem->isChecked())
        chart->addColorMapping();
    else
        chart->removeColorMapping();

    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setMinimumSize(640,480);
}

void MainWindow::refreshGui(){
    refreshTableView();
    refreshChartView();
}
//return selected column
u_int MainWindow::getSelectedColumn() const{
    return tableView->selectionModel()->currentIndex().column();
}
//return selected row
u_int MainWindow::getSelectedRow() const{
    return tableView->selectionModel()->currentIndex().row();
}

//create the menu with his items
void MainWindow::addMenuBar(){
    menu=new QMenuBar();

    //File
    file=new QMenu("&File");
    menu->addMenu(file);

    //Menu
    file->addAction(new QAction(QIcon("://Icons/new.png"),"New",file));
    file->addAction(new QAction(QIcon("://Icons/open.png"),"Open",file));
    file->addAction(new QAction(QIcon("://Icons/save.png"),"Save XML",file));
    file->addAction(new QAction(QIcon("://Icons/save.png"),"Export CSV",file));
    file->addAction(new QAction(QIcon("://Icons/image.png"),"Save Image",file));
    file->addSeparator();
    file->addAction(new QAction(QIcon("://Icons/close.png"),"Exit",file));

    //Edit
    edit=new QMenu("&Edit",menu);
    menu->addMenu(edit);
    edit->addAction(new QAction(QIcon("://Icons/row.png"),"Add row before",menu));
    edit->addAction(new QAction(QIcon("://Icons/row.png"),"Add row after",menu));
    edit->addSeparator();
    edit->addAction(new QAction(QIcon("://Icons/column.png"),"Add column before",menu));
    edit->addAction(new QAction(QIcon("://Icons/column.png"),"Add column after",menu));
    edit->addSeparator();
    edit->addAction(new QAction(QIcon("://Icons/delete-column.png"),"Delete selected column",menu));
    edit->addAction(new QAction(QIcon("://Icons/delete-row.png"),"Delete selected row",menu));

    //View
    view=new QMenu("&View",menu);
    menu->addMenu(view);
    vector<QAction*>items=vector<QAction*>();
    QAction* item1=new QAction("Pie chart");
    item1->setIcon(QIcon("://Icons/pie.png"));
    items.push_back(item1);
    QAction* item2=new QAction("Scatter chart");
    item2->setIcon(QIcon("://Icons/scatter.png"));
    items.push_back(item2);
    QAction* item3=new QAction("Bar chart");
    item3->setIcon(QIcon("://Icons/bar.png"));
    items.push_back(item3);
    QAction* item4=new QAction("StackedBar chart");
    item4->setIcon(QIcon("://Icons/stkbar.png"));
    items.push_back(item4);
    QAction* item5=new QAction("Spline chart");
    item5->setIcon(QIcon("://Icons/spline.png"));
    items.push_back(item5);
    QAction* item6=new QAction("Line chart");
    item6->setIcon(QIcon("://Icons/line.png"));
    items.push_back(item6);
    QAction* item7=new QAction("Nested Pie chart");
    item7->setIcon(QIcon("://Icons/pie.png"));
    items.push_back(item7);
    QAction* item8=new QAction("Donut chart");
    item8->setIcon(QIcon("://Icons/donut.png"));
    items.push_back(item8);



    QActionGroup* myGroup= new QActionGroup(this);
    myGroup->setExclusive(true);

    for (auto &item : items){
        item->setCheckable(true);
        view->addAction(item);
        myGroup->addAction(item);
    }

    view->addSeparator();
    colorsItem=new QAction("Show table colors");
    colorsItem->setCheckable(true);
    view->addAction(colorsItem);
    colorsItem->setChecked(true);

    //Credits
    credits=new QMenu("&Credits",menu);
    credits->addAction(new QAction("Credits",menu));

    menu->addMenu(credits);
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
    //controller->setTableViewOnModel(tableView);
    layout()->addWidget(tableView);
}

void MainWindow::setController(Controller* c){
    controller=c;


    refreshGui();

    //Connect all events needed with the controller

    //file
    connect(file->actions().at(0),SIGNAL(triggered()),controller,SLOT(newChart()));
    connect(file->actions().at(1),SIGNAL(triggered()),controller,SLOT(loadXML()));
    connect(file->actions().at(2),SIGNAL(triggered()),controller,SLOT(saveXML()));
    connect(file->actions().at(3),SIGNAL(triggered()),controller,SLOT(saveCSV()));

    connect(file->actions().at(4),SIGNAL(triggered()),this,SLOT(getGraphImage()));

    connect(file->actions().at(6),SIGNAL(triggered()),this,SLOT(close()));

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
    connect(view->actions().at(3),SIGNAL(triggered()),this,SLOT(setStackedBarChart()));
    connect(view->actions().at(4),SIGNAL(triggered()),this,SLOT(setSplineChart()));
    connect(view->actions().at(5),SIGNAL(triggered()),this,SLOT(setLineChart()));
    connect(view->actions().at(6),SIGNAL(triggered()),this,SLOT(setNestedPieChart()));
    connect(view->actions().at(7),SIGNAL(triggered()),this,SLOT(setDonutChart()));


    connect(view->actions().at(9),SIGNAL(triggered()),this,SLOT(showColors()));


    //credits
    connect(credits->actions().at(0),&QAction::triggered,[&](){
        QMessageBox msgBox;
        msgBox.setText("Developed by Nicolo' Trinca & Marco Bernardi");
        msgBox.exec();});

    //update on edits
    connect(controller->getModel(),&QAbstractItemModel::dataChanged,[&](){refreshGui();});

}
void MainWindow::showColors(){
    refreshGui();
}
//these functions create a graph of the required type
void MainWindow::setPieChart(){
    delete chart;
    chart=new PieChart();
    refreshGui();
}
void MainWindow::setNestedPieChart(){
    delete chart;
    chart=new NestedPieChart();
    refreshGui();
}
void MainWindow::setBarChart(){
    delete chart;
    chart=new BarChart();
    refreshGui();
}
void MainWindow::setStackedBarChart(){
    delete chart;
    chart=new StackedBarChart();
    refreshGui();
}
void MainWindow::setLineChart(){
    delete chart;
    chart=new LineChart();
    refreshGui();
}
void MainWindow::setSplineChart(){
    delete chart;
    chart=new SplineChart();
    refreshGui();
}
void MainWindow::setScatterChart(){
    delete chart;
    chart=new ScatterChart();
    refreshGui();
}
void MainWindow::setDonutChart(){
    delete chart;
    chart=new DonutChart();
    refreshGui();
}
void MainWindow::getGraphImage(){
    QPixmap p = chartView->grab();
    QOpenGLWidget *glWidget  = chartView->findChild<QOpenGLWidget*>();
    if(glWidget){
        QPainter painter(&p);
        QPoint d = glWidget->mapToGlobal(QPoint())-chartView->mapToGlobal(QPoint());
        painter.setCompositionMode(QPainter::CompositionMode_SourceAtop);
        painter.drawImage(d, glWidget->grabFramebuffer());
        painter.end();
    }
    p.save(QFileDialog::getSaveFileName(this, "Save Image","../ChartsApp/Projects", "PNG (*.png)"), "PNG");
}
