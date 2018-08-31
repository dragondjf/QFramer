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

FMainWindow::~FMainWindow()
{
    qDebug("mainwindow deinit");
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

    trayicon = new QSystemTrayIcon(this);
    trayicon->setIcon(QIcon(QString(":/skin/images/QFramer.ico")));
    trayicon->setObjectName(QString("trayicon"));
    trayicon->setToolTip(QString(qApp->applicationName()));
    trayicon->show();

    flyWidget = new FlyWidget(this);
    flyWidget->move(desktopWidgetRect.width() * 4 / 5, desktopWidgetRect.height() / 5);

    titleBar = FTitleBar::getInstace();

    themeMenu = new FThemeMenu(this);
    titleBar->getSkinButton()->setMenu(themeMenu);

    settingMenu = new FSettingMenu(this);
    titleBar->getSettingButton()->setMenu(settingMenu);
    trayicon->setContextMenu(settingMenu);
    flyWidget->setMenu(settingMenu);
    connect(settingMenu->getActionMaps()[tr("Exit")], &QAction::triggered, this, &FMainWindow::animationClose);

    pstatusbar = new QStatusBar;
    pstatusbar->setFixedHeight(35);
    setStatusBar(pstatusbar);

    centerWindow = new FCenterWindow(this);
    setCentralWidget(centerWindow);
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

FlyWidget* FMainWindow::getFlyWidget()
{
    return flyWidget;
}

FCenterWindow *FMainWindow::getCenterWindow()
{
    return centerWindow;
}

void FMainWindow::setCenterWindow(FCenterWindow *center)
{
    if (center) {
        setCentralWidget(center);
        centerWindow = center;
    }
}

QStatusBar* FMainWindow::getStatusBar()
{
    return pstatusbar;
}

QSystemTrayIcon* FMainWindow::getQSystemTrayIcon()
{
    return trayicon;
}

FThemeMenu* FMainWindow::getThemeMenu()
{
    return themeMenu;
}

FSettingMenu *FMainWindow::getSettingMenu()
{
    return settingMenu;
}

void FMainWindow::setSystemIcon(const QString &icon_path)
{
    trayicon->setIcon(QIcon(icon_path));
}

void FMainWindow::setCursorStyle(FMainWindow::CursorDirection direction)
{
    switch (direction) {
    case Top:
    case Bottom:
        setCursor(Qt::SizeVerCursor);
        break;
    case Right:
    case Left:
        setCursor(Qt::SizeHorCursor);
        break;
    case Normal:
        setCursor(Qt::ArrowCursor);
        break;
    }
}

void FMainWindow::animationClose()
{
    // TODO : not read
    QPropertyAnimation *animation = new QPropertyAnimation(this, "windowOpacity");
    connect(animation, SIGNAL(finished()), this, SLOT(close()));
    animation->setDuration(1500);
    animation->setStartValue(1);
    animation->setEndValue(0);
    animation->start();
}

void FMainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if (!isMaximized() && !(event->y() < titleBar->height() && event->x() > titleBar->width() - 120)) {
        if (titleBar->getFixedflag()) {
            move(event->globalPos() - dragPosition);
        }
    } else {
        QMainWindow::mouseMoveEvent(event);
    }
}

void FMainWindow::mousePressEvent(QMouseEvent *event)
{
    if (event->button() & Qt::LeftButton) {
        dragPosition = event->globalPos() - frameGeometry().topLeft();
    } else {
        QMainWindow::mousePressEvent(event);
    }
}

void FMainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() & Qt::LeftButton) {
        titleBar->clearChecked();
    } else {
        QMainWindow::mouseReleaseEvent(event);
    }
}

void FMainWindow::mouseDoubleClickEvent(QMouseEvent *event)
{
    if (event->button() & Qt::LeftButton && !(event->y() < titleBar->height() && event->x() > titleBar->width() - 120)) {
        swithMaxNormal();
    } else {
        QMainWindow::mouseDoubleClickEvent(event);
    }
}

void FMainWindow::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left || event->key() == Qt::Key_Right ||
        event->key() == Qt::Key_F1 || event->key() == Qt::Key_F2) {
        QApplication::sendEvent(centerWindow, event);
    } else if (event->key() == Qt::Key_Escape) {
        titleBar->getCloseButton()->click();
    } else if (event->key() == Qt::Key_F11) {
        titleBar->getMaxButton()->click();
    } else {
        QMainWindow::keyPressEvent(event);
    }
}

void FMainWindow::closeEvent(QCloseEvent *event)
{
    writeSettings();
    QMainWindow::closeEvent(event);
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

void FMainWindow::onSystemTrayIconClicked(QSystemTrayIcon::ActivationReason reason)
{
    switch (reason) {
    case QSystemTrayIcon::Trigger:     // click
    case QSystemTrayIcon::DoubleClick:
        if (isHidden()) {
            show();
            flyWidget->hide();

            // These two codes put the window to the top
            setWindowState(Qt::WindowActive);
            activateWindow();
        } else {
            hide();
            flyWidget->show();
        }
        break;
    case QSystemTrayIcon::Context:
    case QSystemTrayIcon::MiddleClick:
    case QSystemTrayIcon::Unknown:
        break;
    }
}
