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

#include "FlyWidget.h"
#include <QMouseEvent>
#include <QPaintEvent>
#include <QEvent>
#include <QPainter>
#include <QBitmap>
#include <QCursor>

FlyWidget::FlyWidget(QWidget *parent) :
    QWidget(parent),
    m_parent(parent),
    m_settingMenu(nullptr)
{
    initData();
    initUI();
    initConnect();
}

void FlyWidget::initData()
{

}

void FlyWidget::initUI()
{
    setWindowFlags(Qt::FramelessWindowHint | Qt::ToolTip);
    m_pixmap.load(QString(":/skin/images/QFramer.png"));
    resize(m_pixmap.size());
    setMask(m_pixmap.mask());
}

void FlyWidget::initConnect()
{

}

void FlyWidget::setMenu(QMenu *menu)
{
    m_settingMenu = menu;
}

QMenu* FlyWidget::getMenu()
{
    return m_settingMenu;
}

void FlyWidget::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton) {
        move(event->globalPos() - m_currentPos);
    } else {
        QWidget::mouseMoveEvent(event);
    }
}

void FlyWidget::mousePressEvent(QMouseEvent *event)
{
    if (event->button() & Qt::LeftButton) {
        m_currentPos = event->globalPos() - frameGeometry().topLeft();
    } else if (event->button() & Qt::RightButton) {
        if (m_settingMenu) {
            m_settingMenu->exec(QCursor::pos());
        }
    } else {
        QWidget::mousePressEvent(event);
    }
}

void FlyWidget::mouseDoubleClickEvent(QMouseEvent *)
{
    m_parent->setVisible(!m_parent->isVisible());
    hide();
}

void FlyWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(0, 0, m_pixmap);
}

void FlyWidget::leaveEvent(QEvent *)
{
    //鼠标离开窗口时是普通的指针
    setCursor(Qt::ArrowCursor);
}

void FlyWidget::enterEvent(QEvent *)
{
    //鼠标留在窗口上时是一个手指
    setCursor(Qt::PointingHandCursor);
}
