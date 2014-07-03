#include "mainwindow.h"
#include "centerwindow.h"

MainWindow* MainWindow::instance = NULL;

MainWindow::MainWindow(QWidget *parent) :
    FMainWindow(parent)
{
    centerWindow = CenterWindow::getInstance();
    setCentralWidget(centerWindow);
//    centerWindow->navagationBar->setFixedHeight(centerWindow->height());

}

MainWindow* MainWindow::getInstance()
{
    if(!instance)
    {
        instance = new MainWindow();
    }
    return instance;
}
