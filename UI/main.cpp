#include <QtGui/QApplication>
#include <glut.h>
#include <mainwindow.h>
#include <stdio.h>
#include <QFileDialog>
#include <QDir>

int main(int argc, char *argv[])
{
  glutInit(&argc,argv);
  QApplication a(argc, argv);
  QString filename;

  //inithome directory
  QDir directory=QDir::home();
#ifdef WIN32
  directory.cd("Application Data");
  directory.mkdir("klampt");
  directory.cd("klampt");
#else
  directory.mkdir(".klampt");
  directory.cd(".klampt");
#endif
  directory.mkdir("states");
  directory.mkdir("linearpath");
  directory.mkdir("milestonepath");
  directory.mkdir("multipath");
  directory.mkdir("commandlog");

  if(argc==1){
      QFileDialog f;
      filename = f.getOpenFileName(0,"Open Scenario","../data","*.xml");
    }
    MainWindow w;
    if(argc==1){
        const char* args[2] = {"SimTest",filename.toStdString().c_str()};
        w.Initialize(2,(const char**)args);
    }
    else
        w.Initialize(argc,(const char**)argv);
//        QString fileName = QFileDialog::getOpenFileName(0,"Open File","","Files(*.xml)");
    w.directory=directory;
    w.PopulatePaths();
    w.show();
    return a.exec();
}
