#include "mainwindow.h"

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

    c = new CenterWindow();
    setCentralWidget(c);
    QString qss = getQssFromFile(QString(":/skin/qss/main.qss"));
    setStyleSheet(qss);
    initConnect();
}

void MainWindow::initConnect()
{
    connect(c->titleBar, SIGNAL(minimuned()), this, SLOT(showMinimized()));
    connect(c->titleBar, SIGNAL(maximumed()), this, SLOT(swithMaxNormal()));
    connect(c->titleBar, SIGNAL(closed()), this, SLOT(close()));
}

void MainWindow::swithMaxNormal()
{
    if(isFullScreen())
    {
        showNormal();
    }else{
        showFullScreen();
    }
}

void MainWindow::mousePressEvent(QMouseEvent *e)
{
    if(e->button() & Qt::LeftButton)
    {
        dragPosition = e->globalPos() - frameGeometry().topLeft();
    }
    e->accept();
}

void MainWindow::mouseDoubleClickEvent(QMouseEvent *e)
{
    if(e->y() < Title_Height and e->x() < c->titleBar->width() - 120)
    {
        swithMaxNormal();
        e->accept();
    }else{
        e->ignore();
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *e)
{
    e->accept();
}

void MainWindow::mouseMoveEvent(QMouseEvent *e)
{
    if(e->y() < Title_Height and e->x() > c->titleBar->width() - 120)
    {
        e->ignore();
    }else{
        move(e->globalPos() - dragPosition);
        e->accept();
    }

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
