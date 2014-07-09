#include "mainwindow.h"
#include "centerwindow.h"
#include "QFramer/futil.h"
#include"functionpages/rightfloatwindow.h"
MainWindow* MainWindow::instance = NULL;

MainWindow::MainWindow(QWidget *parent) :
    FMainWindow(parent)
{
    initData();
    initUI();
    initConnect();
}

void MainWindow::initData()
{
}

void MainWindow::initUI()
{
    centerWindow = new CenterWindow;
    setCentralWidget(centerWindow);

    settingmenu = new SettingMenu;
    getTitleBar()->getSettingButton()->setMenu(settingmenu);
    getQSystemTrayIcon()->setContextMenu(settingmenu);
    getFlyWidget()->setMenu(settingmenu);

    lockMenu = new LockMenu(this);
    getTitleBar()->getFixButton()->setMenu(lockMenu);

    rightfloatWindow = new RightFloatWindow;
    QString qss = getQssFromFile(QString(":/qss/skin/qss/main.qss"));
    setStyleSheet(qss);
}

void MainWindow::initConnect()
{
    connect(this, SIGNAL(Hidden()), rightfloatWindow, SLOT(hide()));
}

MainWindow* MainWindow::getInstance()
{
    if(!instance)
    {
        instance = new MainWindow();
    }
    return instance;
}

RightFloatWindow* MainWindow::getRightFloatWindow()
{
    return rightfloatWindow;
}


void MainWindow::resizeEvent(QResizeEvent *event)
{
    rightfloatWindow->resize(rightfloatWindow->width(), event->size().height());
    rightfloatWindow->hide();
    QMainWindow::resizeEvent(event);
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    rightfloatWindow->move(x() + width() + 2, y());
    FMainWindow::mouseMoveEvent(event);
}

void MainWindow::hideEvent(QHideEvent *event)
{
//    rightfloatWindow->setVisible(not rightfloatWindow->isVisible());
    event->accept();
}

void MainWindow::mouseDoubleClickEvent(QMouseEvent *event)
{
    if(event->y() > getTitleBar()->height())
    {
        rightfloatWindow->setVisible(not rightfloatWindow->isVisible());
    }
    FMainWindow::mouseDoubleClickEvent(event);
}
