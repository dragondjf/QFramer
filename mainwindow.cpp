#include "mainwindow.h"
#include "centerwindow.h"
#include<QtCore>
#include<QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->resize(800, 600);
    this->setWindowTitle("QFramer");

    CenterWindow *c = new CenterWindow(this);
    this->setCentralWidget(c);
    qDebug("init Mainwindow");
}

MainWindow::~MainWindow()
{
    printf("111111\n");
}
