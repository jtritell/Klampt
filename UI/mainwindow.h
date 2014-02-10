#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Modeling/World.h"
#include "logoptions.h"
#include <QDir>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void Initialize(int argc, const char **argv);
    QString filename;
    void PopulatePaths();
    void OpenDrivers();
    RobotWorld *world;
    void SetupPlotOptions();
    LogOptions *l;
    QDir directory;
    void SaveSelected();
public slots:
    void ShowPlotOptions();
    void LoadSelectedMultipath();
//    void ToggleIK(int mode);
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
