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
    qDebug("mainwindow init");
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

    centerwindow = new CenterWindow();
    pstatusbar = new QStatusBar;
    setCentralWidget(centerwindow);
    setStatusBar(pstatusbar);

    trayicon = new QSystemTrayIcon(QIcon(QString(":/skin/images/QFramer.ico")), this);
    trayicon->setContextMenu(centerwindow->titleBar->settingMenu);
    trayicon->show();
    QString qss = getQssFromFile(QString(":/skin/qss/main.qss"));
    setStyleSheet(qss);
}

void MainWindow::initConnect()
{
    connect(centerwindow->titleBar, SIGNAL(minimuned()), this, SLOT(showMinimized()));
    connect(centerwindow->titleBar, SIGNAL(maximumed()), this, SLOT(swithMaxNormal()));
    connect(centerwindow->titleBar, SIGNAL(closed()), this, SLOT(close()));
    connect(trayicon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)),
            this, SLOT(onSystemTrayIconClicked(QSystemTrayIcon::ActivationReason)));
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
    if(e->y() < Title_Height and e->x() < centerwindow->titleBar->width() - 120)
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

        if(e->y() < Title_Height and e->x() > centerwindow->titleBar->width() - 120)
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
        centerwindow->titleBar->maxButton->click();
    }
}

void MainWindow::onSystemTrayIconClicked(QSystemTrayIcon::ActivationReason reason)
{
    switch(reason)
        {
        //单击
        case QSystemTrayIcon::Trigger:
            //双击
        case QSystemTrayIcon::DoubleClick:
            if(this->isHidden())
            {
                //恢复窗口显示
                this->show();
                //一下两句缺一均不能有效将窗口置顶
                this->setWindowState(Qt::WindowActive);
                this->activateWindow();
            }
            else
            {
                this->hide();
            }
            break;
        case QSystemTrayIcon::Context:
            break;
        default:
            break;
        }
}

MainWindow::~MainWindow()
{
    printf("111111\n");
}
