#include "mainwindow.h"
#include "centerwindow.h"
#include "QFramer/futil.h"
#include "thememenu.h"
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
    centerWindow->getNavgationBar()->setCurrentIndex(0);

    settingMenu = new SettingMenu;
    getTitleBar()->getSettingButton()->setMenu(settingMenu);
    getQSystemTrayIcon()->setContextMenu(settingMenu);
    getFlyWidget()->setMenu(settingMenu);

    themeMenu = new ThemeMenu;
    getTitleBar()->getSkinButton()->setMenu(themeMenu);
//    lockMenu = new LockMenu(this);
//    getTitleBar()->getFixButton()->setMenu(lockMenu);

    rightfloatWindow = new RightFloatWindow;
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

void MainWindow::showEvent(QHideEvent *event)
{
    rightfloatWindow->setVisible(true);
    event->accept();
}

void MainWindow::hideEvent(QHideEvent *event)
{
    rightfloatWindow->setVisible(false);
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

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Left)
    {
        int index = centerWindow->getNavgationBar()->currentIndex();
        int count = centerWindow->getNavgationBar()->count();
        if(index == 0){
            centerWindow->getNavgationBar()->setCurrentIndex(count - 1);
        }else if(index > 0){
            centerWindow->getNavgationBar()->setCurrentIndex(index - 1);
        }
    }
    else if(event->key() == Qt::Key_Right)
    {
        int index = centerWindow->getNavgationBar()->currentIndex();
        int count = centerWindow->getNavgationBar()->count();
        if(index == count){
            centerWindow->getNavgationBar()->setCurrentIndex(0);
        }else if(index > 0){
            centerWindow->getNavgationBar()->setCurrentIndex(index + 1);
        }
    }

    FMainWindow::keyPressEvent(event);
}
