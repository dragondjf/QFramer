#include "mainwindow.h"
#include "centerwindow.h"
#include "util.h"
#include<QtCore>
#include<QMouseEvent>
#include<QKeyEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    resize(800, 600);
    setWindowFlags(Qt::FramelessWindowHint);
    setWindowTitle("QFramer");

    CenterWindow *c = new CenterWindow();
    setCentralWidget(c);
//    qDebug("init Mainwindow");
    QString qss = getQssFromFile(QString(":/skin/qss/main.qss"));
    setStyleSheet(qss);
}

void MainWindow::mousePressEvent(QMouseEvent *e)
{
    if(e->button() & Qt::LeftButton)
    {
        dragPosition = e->globalPos() - frameGeometry().topLeft();
    }
    e->accept();
}

void MainWindow::mouseReleaseEvent(QMouseEvent *e)
{
    e->accept();
}

void MainWindow::mouseMoveEvent(QMouseEvent *e)
{

    move(e->globalPos() - dragPosition);

    e->accept();
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
    if(e->key() == Qt::Key_Escape){
        close();
    }
    else if (e->key() == Qt::Key_F11) {
        if(isFullScreen()){
            showNormal();
        }
        else{
            showFullScreen();
        }
    }
}

MainWindow::~MainWindow()
{
    printf("111111\n");
}
