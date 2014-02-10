#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "logoptions.h"
#include "driveredit.h"
#include "Interface/UserInterface.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    ui->displaywidget->installEventFilter(this);
    ui->displaywidget->setFocusPolicy(Qt::WheelFocus);
    world = new RobotWorld();
    ui->displaywidget->SetWorld(world);
    PopulatePaths();
    SetupPlotOptions();
    //ToggleIK(0);
    //    ui->displaywidget->LoadAndInitSim(file);
    //ui->displaywidget->LoadAndInitSim(2,&file);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Initialize(int argc,const char** argv){
  ui->displaywidget->LoadAndInitSim(argc,argv);
  ui->displaywidget->Initialize();
  //OpenDrivers();
  //  ui->displaywidget->InitializeGL();

}

void MainWindow::PopulatePaths(){
    QStringList nameFilter("*.xml");
    //QDir dir(directory);
    directory.cd("multipath");
    QStringList paths = directory.entryList(nameFilter);
    ui->path_listWidget->addItems(paths);
    directory.cdUp();
}

void MainWindow::LoadSelectedMultipath(){
    //QString path=directory+ui->path_listWidget->selectedItems()[0]->text();
    directory.cd("multipath");
    QString path=directory.absoluteFilePath(ui->path_listWidget->selectedItems()[0]->text());
    ui->displaywidget->LoadMultiPath(path.toStdString().c_str());
    directory.cdUp();

}

void MainWindow::SaveSelected(){
    directory.cd("multipath");
    int i=0;
    QString newname="MultiPath["+QString::number(i)+QString(".xml");
    while(directory.exists(newname)){
        i++;
        newname="MultiPath["+QString::number(i)+QString(".xml");
    }
    ui->path_listWidget->addItem(newname);
    QString path=directory.absoluteFilePath(ui->path_listWidget->selectedItems()[0]->text());
    //ui->displaywidget->SaveMultiPath(path.toStdString().c_str());
    directory.cdUp();
}

void MainWindow::SetupPlotOptions(){
    l=new LogOptions;
    connect(ui->displaywidget,SIGNAL(AddSensor(QString)),l,SLOT(AddSensor(QString)));
    connect(ui->displaywidget,SIGNAL(AddMeasurement(QString)),l,SLOT(AddMeasurement(QString)));
    connect(l,SIGNAL(SyncSensorMeasurements(int)),ui->displaywidget,SLOT(SyncSensorMeasurements(int)));
    connect(l,SIGNAL(toggle_measurement(int,int)),ui->displaywidget,SLOT(ToggleSensorMeasurement(int,int)));
    connect(l,SIGNAL(toggle_plot(bool)),ui->displaywidget,SLOT(SetSensorPlot(bool)));
    connect(l,SIGNAL(toggle_logging(bool)),ui->displaywidget,SLOT(SetLogCheck(bool)));
}

void MainWindow::ShowPlotOptions(){
    l->show();
}

void MainWindow::OpenDrivers(){
    DriverEdit* de=new DriverEdit();
    connect(ui->displaywidget,SIGNAL(SendDriverName(QString)),de,SLOT(AddDriver(QString)));
    connect(de,SIGNAL(GetDriverValues(int)),ui->displaywidget,SLOT(SendDriverValues(int)));
    connect(ui->displaywidget,SIGNAL(SendDriverState(float,float,float)),de,SLOT(GetDriverParameters(float,float,float)));
    connect(de,SIGNAL(SetDriverValue(int,float)),ui->displaywidget,SLOT(SetDriverValue(int,float)));
    de->show();
    de->addDrivers(ui->displaywidget->GetDriverNames());
    ui->displaywidget->SendDriverValues(0);
}
/*
void MainWindow::ToggleIK(int mode){
    if(mode==1){
        ui->btn_constrain->show();
        ui->btn_delete->show();
    }
    else{
        ui->btn_constrain->hide();
        ui->btn_delete->hide();
    }
}
*/
