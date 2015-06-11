/****************************************************************************
**
** Copyright (C) 2014 dragondjf
**
** QFramer is a frame based on Qt5.3, you will be more efficient with it. 
** As an Qter, Qt give us a nice coding experience. With user interactive experience(UE) 
** become more and more important in modern software, deveployers should consider business and UE.
** So, QFramer is born. QFramer's goal is to be a mature solution 
** which you only need to be focus on your business but UE for all Qters.
**
** Version	: 0.2.5.0
** Author	: dragondjf
** Website	: https://github.com/dragondjf
** Project	: https://github.com/dragondjf/QCFramer
** Blog		: http://my.oschina.net/dragondjf/home/?ft=atme
** Wiki		: https://github.com/dragondjf/QCFramer/wiki
** Lincence: LGPL V2
** QQ: 465398889
** Email: dragondjf@gmail.com, ding465398889@163.com, 465398889@qq.com
** 
****************************************************************************/

#include "mainwindow.h"
#include "centerwindow.h"
#include "QFramer/futil.h"
#include "thememenu.h"
#include "functionpages/rightfloatwindow.h"


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
        }else if(index <= (count - 1) && index > 0){
            centerWindow->getNavgationBar()->setCurrentIndex(index - 1);
        }
    }
    else if(event->key() == Qt::Key_Right)
    {
        int index = centerWindow->getNavgationBar()->currentIndex();
        int count = centerWindow->getNavgationBar()->count();
        if(index == (count - 1)){
            centerWindow->getNavgationBar()->setCurrentIndex(0);
        }else if(index >= 0 && index < (count - 1)){
            centerWindow->getNavgationBar()->setCurrentIndex(index + 1);
        }
    }
    else if(event->key() == Qt::Key_F1)
    {
        delete centerWindow->getNavgationBar()->layout();
        centerWindow->setAlignment(centerWindow->TopCenter);
    }
    else if(event->key() == Qt::Key_Space)
    {
        delete centerWindow->getNavgationBar()->layout();
        int i = 1 + (int)12 * rand() / (RAND_MAX + 1);
        switch (i) {
        case 1:
            centerWindow->setAlignment(centerWindow->TopLeft);
            break;
        case 2:
            centerWindow->setAlignment(centerWindow->TopCenter);
            break;
        case 3:
            centerWindow->setAlignment(centerWindow->TopRight);
            break;
        case 4:
            centerWindow->setAlignment(centerWindow->RightTop);
            break;
        case 5:
            centerWindow->setAlignment(centerWindow->RightCenter);
            break;
        case 6:
            centerWindow->setAlignment(centerWindow->RightBottom);
            break;
        case 7:
            centerWindow->setAlignment(centerWindow->BottomRight);
            break;
        case 8:
            centerWindow->setAlignment(centerWindow->BottomCenter);
            break;
        case 9:
            centerWindow->setAlignment(centerWindow->BottomLeft);
            break;
        case 10:
            centerWindow->setAlignment(centerWindow->LeftBottom);
            break;
        case 11:
            centerWindow->setAlignment(centerWindow->LeftCenter);
            break;
        case 12:
            centerWindow->setAlignment(centerWindow->LeftTop);
            break;
        default:
            break;
        }
    }

    FMainWindow::keyPressEvent(event);
}
