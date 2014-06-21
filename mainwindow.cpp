#include "mainwindow.h"

#include "util.h"
#include<QtCore>
#include<QMouseEvent>
#include<QKeyEvent>
#include <QDesktopWidget>
#include<QApplication>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    initData();
    initUI();
    initConnect();
}

void MainWindow::initData()
{
    leftbuttonpressed = false;
}

void MainWindow::initUI()
{
    QDesktopWidget* desktopWidget = QApplication::desktop();
    resize(desktopWidget->availableGeometry().width() * 0.8, desktopWidget->availableGeometry().height() *0.8);
    setMaximumSize(desktopWidget->availableGeometry().size());
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinimizeButtonHint);
    setWindowTitle("QFramer");

    c = new CenterWindow();
    pstatusbar = new QStatusBar;
    setCentralWidget(c);
    setStatusBar(pstatusbar);
    QString qss = getQssFromFile(QString(":/skin/qss/main.qss"));
    setStyleSheet(qss);
}

void MainWindow::initConnect()
{
    connect(c->titleBar, SIGNAL(minimuned()), this, SLOT(showMinimized()));
    connect(c->titleBar, SIGNAL(maximumed()), this, SLOT(swithMaxNormal()));
    connect(c->titleBar, SIGNAL(closed()), this, SLOT(close()));
}

void MainWindow::swithMaxNormal()
{
    if(isMaximized())
    {
        showNormal();
    }else{
        showMaximized();
    }
}

void MainWindow::mousePressEvent(QMouseEvent *e)
{
    if(e->button() & Qt::LeftButton)
    {
        dragPosition = e->globalPos() - frameGeometry().topLeft();
        leftbuttonpressed = true;
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

void MainWindow::SetCursorStyle(enum_Direction direction)
{
    //设置上下左右以及右上、右下、左上、坐下的鼠标形状
    switch(direction)
    {
    case eTop:
    case eBottom:
        setCursor(Qt::SizeVerCursor);
        break;
    case eRight:
    case eLeft:
        setCursor(Qt::SizeHorCursor);
        break;
    case eNormal:
        setCursor(Qt::ArrowCursor);
    default:
        setCursor(Qt::ArrowCursor);
        break;
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *e)
{
    leftbuttonpressed = false;
    e->accept();
}

void MainWindow::mouseMoveEvent(QMouseEvent *e)
{
    if(isMaximized())
    {
        e->ignore();
    }
    else
    {

        if(e->y() < Title_Height and e->x() > c->titleBar->width() - 120)
        {
            e->ignore();
        }
        else{
            move(e->globalPos() - dragPosition);
            e->accept();
        }
    }

}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
    if(e->key() == Qt::Key_Escape){
        close();
    }
    else if (e->key() == Qt::Key_F11) {
        c->titleBar->maxButton->click();
    }
}

MainWindow::~MainWindow()
{
    printf("111111\n");
}
