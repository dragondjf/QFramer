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
#include "QFramer/futil.h"
#include "QFramer/fwigglywidget.h"


MainWindow* MainWindow::instance = NULL;

MainWindow* MainWindow::getInstance()
{
    if (!instance) {
        instance = new MainWindow();
    }
    return instance;
}

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
    uiElements = new UIElement;
    mathPlot = new MathPlot;
    qssBuilder = new QssBuilder;
    aboutPage = new AboutPage;

    getCenterWindow()->addWidget(uiElements, "Home");
    getCenterWindow()->addWidget(mathPlot, "MathPlot");
    getCenterWindow()->addWidget(qssBuilder, "QssBuilder");
    getCenterWindow()->addWidget(aboutPage, "About");
    getCenterWindow()->getNavgationBar()->setCurrentIndex(0);

    settingMenu = new SettingMenu;
    getTitleBar()->getSettingButton()->setMenu(settingMenu);
    getQSystemTrayIcon()->setContextMenu(settingMenu);
    getFlyWidget()->setMenu(settingMenu);

    getThemeMenu()->addTheme(tr("GBG"), QString(":/qss/skin/qss/GBG.qss"));
    getThemeMenu()->addTheme(tr("GGG"), QString(":/qss/skin/qss/GGG.qss"));
    getThemeMenu()->addTheme(tr("BW"),  QString(":/qss/skin/qss/BW.qss"));
    getThemeMenu()->addTheme(tr("BB"),  QString(":/qss/skin/qss/BB.qss"));
    getThemeMenu()->addTheme(tr("GB"),  QString(":/qss/skin/qss/GB.qss"));
    getThemeMenu()->addTheme(tr("GG"),  QString(":/qss/skin/qss/GG.qss"));
    getThemeMenu()->getActionMaps()[tr("GBG")]->trigger();

    rightfloatWindow = new RightFloatWindow;
}

void MainWindow::initConnect()
{
    connect(this, SIGNAL(Hidden()), rightfloatWindow, SLOT(hide()));
}

void MainWindow::addWiggleWiget()
{
    FWigglyWidget* wiggleWidget = new FWigglyWidget("Faster Easier Stronger Prettier", getCenterWindow()->getNavgationBar());
    wiggleWidget->move(40, 5);
    wiggleWidget->setFixedSize(400, 60);
    wiggleWidget->setStyleSheet("background-color: transparent; font-size: 20px;");
}

RightFloatWindow* MainWindow::getRightFloatWindow()
{
    return rightfloatWindow;
}

SettingMenu *MainWindow::getSettingMenu()
{
    return settingMenu;
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

void MainWindow::showEvent(QShowEvent *event)
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
    if (event->button() & Qt::RightButton && event->y() > getTitleBar()->height()) {
        rightfloatWindow->setVisible(not rightfloatWindow->isVisible());
    } else {
        FMainWindow::mouseDoubleClickEvent(event);
    }
}
