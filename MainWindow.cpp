#include <MainWindow.h>
//#include <Controller.h>

#include <iostream>

MainWindow::MainWindow(QWidget* parent):QWidget(parent){
    QHBoxLayout* mainLayout=new QHBoxLayout(this);
    mainLayout->setAlignment(Qt::AlignTop);
    mainLayout->setContentsMargins(0,0,0,0);
    mainLayout->setSpacing(0);

    resize(1500,750);

    QRect screenSize= QApplication::desktop()->screenGeometry();
    const QRect wr{{},frameSize().boundedTo(screenSize.size())};
    move(screenSize.center()-wr.center());

    //setWindowIcon(QIcon(":/images/icon.png"));

    setBar();
}
void MainWindow::setBar(){
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

    edit->addAction(new QAction("Add column before",menu));
    edit->addAction(new QAction("Add column after",menu));
    edit->addAction(new QAction("Add row before",menu));
    edit->addAction(new QAction("Add row after",menu));
    edit->addSeparator();
    edit->addAction(new QAction("Delete selected column",menu));
    edit->addAction(new QAction("Delete selected row",menu));
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
    menu->addMenu(help);

    edit->addAction(new QAction("About",menu));
    this->layout()->setMenuBar(menu);
}
void MainWindow::setTableView()
{
    if(tableView!=nullptr)
        layout()->removeWidget(tableView);
    else
        tableView= new QTableView();
    //tableView->setModel(controller->getModel())
    tableView->resizeColumnsToContents();
    tableView->resizeRowsToContents();
    tableView->setGeometry(0,30,300,300);
    tableView->setStyleSheet("QHeaderView::section {background-color:lightblue}");
    tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    tableView->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    layout()->addWidget(tableView);
}
void MainWindow::setController(Controller* controller){
    this->controller=controller;
    //file
    //connect(file->actions().at(0),SIGNAL(triggered()),controller,SLOT(newChart()));
    //+altre
    //view
//    connect(view->actions().at(0),&QAction::triggered, [&](){
//        auto tabella= controller->getModel()->getTable();
//        chart= new PieChart(tabella);
//        drawChart(chart);
//        if(tabella.getColumnCount()>1){
//            QMessageBox msgBox;
//            msgBox.setText("Dount charts can only consider the frist column of the dataset");
//            msgBox.exec();
//        }
//    });
    //+altre
}
u_int MainWindow::getSelectedColumn() const{
    return tableView->selectionModel()->currentIndex().column();
}
u_int MainWindow::getSelectedRow() const{
    return tableView->selectionModel()->currentIndex().row();
}
QWidget* MainWindow::getChartView() const{
    return chartView;
}
//Chart* MainWindow::getChart() const{
//    return chart;
//}
