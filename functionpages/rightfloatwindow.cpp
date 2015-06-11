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

#include "rightfloatwindow.h"
#include "mainwindow/mainwindow.h"
#include <QGraphicsDropShadowEffect>


RightFloatWindow::RightFloatWindow(QWidget *parent) :
    FMovableWidget(parent)
{
    initData();
    initUI();
    initConnect();

}

void RightFloatWindow::initData()
{
    cwidth = 200;
}

void RightFloatWindow::initUI()
{
    setWindowFlags(Qt::FramelessWindowHint);
    setWindowFlags(Qt::ToolTip);
    setObjectName(QString("RightFloatWindow"));
}

void RightFloatWindow::initConnect()
{

}

void RightFloatWindow::showEvent(QShowEvent *event)
{
    move(MainWindow::getInstance()->x()+ MainWindow::getInstance()->width() + 2,\
         MainWindow::getInstance()->y());
    resize(cwidth, MainWindow::getInstance()->height());
    MainWindow::getInstance()->settingMenu->\
            getActionMaps()["Show rightBar"]->setText(tr("Hide rightBar"));
    QWidget::showEvent(event);
}

void RightFloatWindow::hideEvent(QHideEvent *event)
{
    Q_UNUSED(event)
    MainWindow::getInstance()->settingMenu->\
            getActionMaps()["Show rightBar"]->setText(tr("Show rightBar"));
}

void RightFloatWindow::mouseMoveEvent(QMouseEvent *event)
{
    move(x() + width(), y());
    FMovableWidget::mouseMoveEvent(event);
}

