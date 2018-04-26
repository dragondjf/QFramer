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

#include "fmainwindow.h"

#include <QApplication>
#include <QDesktopWidget>
#include <QPropertyAnimation>
#include <QStatusBar>
#include <QCloseEvent>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QSettings>
#include <QDebug>
#include <QDir>


FMainWindow::FMainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    qDebug("mainwindow init");
    initData();
    initUI();
    initConnect();
}

void FMainWindow::initData()
{
}

void FMainWindow::initUI()
{
    setWindowTitle(qApp->applicationName());
    setObjectName(QString("FMainWindow"));
    setWindowFlags(Qt::FramelessWindowHint);
    const QRect &desktopWidgetRect = QApplication::desktop()->availableGeometry();
    setMaximumSize(desktopWidgetRect.size());
    readSettings();

    titleBar = FTitleBar::getInstace();

    pstatusbar = new QStatusBar;
    pstatusbar->setFixedHeight(35);
    setStatusBar(pstatusbar);

    trayicon = new QSystemTrayIcon(QIcon(QString(":/skin/images/QFramer.ico")), this);
    trayicon->setObjectName(QString("trayicon"));
    trayicon->setToolTip(QString(qApp->applicationName()));
    trayicon->show();

    flyWidget = new FlyWidget(this);
    flyWidget->move(desktopWidgetRect.width() * 4 / 5, desktopWidgetRect.height() / 5);
}

void FMainWindow::initConnect( )
{
    connect(titleBar, SIGNAL(minimuned()), this, SIGNAL(Hidden()));
    connect(titleBar, SIGNAL(minimuned()), this, SLOT(hide()));
    connect(titleBar, SIGNAL(minimuned()), this, SLOT(showFlyWidget()));
    connect(titleBar, SIGNAL(maximumed()), this, SLOT(swithMaxNormal()));
    connect(titleBar, SIGNAL(closed()),    this, SIGNAL(Hidden()));
    connect(titleBar, SIGNAL(closed()),    this, SLOT(hide()));
    connect(titleBar, SIGNAL(closed()),    this, SLOT(showFlyWidget()));
    connect(trayicon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)),
            this, SLOT(onSystemTrayIconClicked(QSystemTrayIcon::ActivationReason)));
}

void FMainWindow::readSettings()
{
    QDesktopWidget* desktopWidget = QApplication::desktop();
    int w = desktopWidget->availableGeometry().width();
    int h = desktopWidget->availableGeometry().height();
    QSettings settings(QDir::currentPath() + "/QFramer.ini", QSettings::IniFormat);
    settings.beginGroup("FMainWindow");
    resize(settings.value("size", QSize(w * 3 / 5, h * 3 / 5)).toSize());
    move(settings.value("pos", QPoint(w / 5, h / 10)).toPoint());
    settings.endGroup();
}

void FMainWindow::writeSettings()
{
    QSettings settings(QDir::currentPath() + "/QFramer.ini", QSettings::IniFormat);
    qDebug(qPrintable(QDir::currentPath() + "/QFramer.ini"));
    settings.beginGroup("FMainWindow");
    settings.setValue("size", size());
    settings.setValue("pos", pos());
    settings.endGroup();
}

FTitleBar* FMainWindow::getTitleBar()
{
    return titleBar;
}

QStatusBar* FMainWindow::getStatusBar()
{
    return pstatusbar;
}

QSystemTrayIcon* FMainWindow::getQSystemTrayIcon()
{
    return trayicon;
}

FlyWidget* FMainWindow::getFlyWidget()
{
    return flyWidget;
}

void FMainWindow::swithMaxNormal()
{
    if (isMaximized()) {
        showNormal();
    } else {
        showMaximized();
    }
}

void FMainWindow::showFlyWidget()
{
    flyWidget->show();
}

void FMainWindow::mousePressEvent(QMouseEvent *e)
{
    if (e->button() & Qt::LeftButton) {
        dragPosition = e->globalPos() - frameGeometry().topLeft();
    } else {
        QMainWindow::mousePressEvent(e);
    }
}

void FMainWindow::mouseDoubleClickEvent(QMouseEvent *e)
{
    if (e->button() & Qt::LeftButton && !(e->y() < titleBar->height() && e->x() > titleBar->width() - 120)) {
        swithMaxNormal();
    } else {
        QMainWindow::mouseDoubleClickEvent(e);
    }
}

void FMainWindow::SetCursorStyle(enum_Direction direction)
{
    // 设置上下左右以及右上、右下、左上、坐下的鼠标形状
    switch (direction) {
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
        break;
    }
}

void FMainWindow::mouseReleaseEvent(QMouseEvent *e)
{
    if (e->button() & Qt::LeftButton) {
        titleBar->clearChecked();
    } else {
        QMainWindow::mouseReleaseEvent(e);
    }
}

void FMainWindow::mouseMoveEvent(QMouseEvent *e)
{
    if (!isMaximized() &&
        !(e->y() < titleBar->height() && e->x() > titleBar->width() - 120)) {
        if (titleBar->getFixedflag()) {
            move(e->globalPos() - dragPosition);
        }
    } else {
        QMainWindow::mouseMoveEvent(e);
    }
}

void FMainWindow::keyPressEvent(QKeyEvent *e)
{
    if (e->key() == Qt::Key_Escape) {
        close();
    } else if (e->key() == Qt::Key_F11) {
        titleBar->getMaxButton()->click();
    } else {
        QMainWindow::keyPressEvent(e);
    }
}

void FMainWindow::closeEvent(QCloseEvent *event)
{
    writeSettings();
    QMainWindow::closeEvent(event);
}

void FMainWindow::animationClose()
{
    QPropertyAnimation *animation = new QPropertyAnimation(this, "windowOpacity");
    connect(animation, SIGNAL(finished()), this, SLOT(close()));
    animation->setDuration(1500);
    animation->setStartValue(1);
    animation->setEndValue(0);
    animation->start();
}

void FMainWindow::onSystemTrayIconClicked(QSystemTrayIcon::ActivationReason reason)
{
    switch (reason) {
    case QSystemTrayIcon::Trigger:      //单击
    case QSystemTrayIcon::DoubleClick:  //双击
        if(isHidden()) {
            show(); //恢复窗口显示
            //一下两句缺一均不能有效将窗口置顶
            setWindowState(Qt::WindowActive);
            activateWindow();
        } else {
            hide();
        }
        break;
    case QSystemTrayIcon::Context:
    case QSystemTrayIcon::MiddleClick:
    case QSystemTrayIcon::Unknown:
        break;
    }
}

FMainWindow::~FMainWindow()
{
    qDebug("mainwindow deinit");
}
