#include "mainwindow.h"

MainWindow* MainWindow::instance = NULL;

MainWindow::MainWindow(QWidget *parent) :
    FMainWindow(parent)
{

}

MainWindow* MainWindow::getInstance()
{
    if(!instance)
    {
        instance = new MainWindow();
    }
    return instance;
}
