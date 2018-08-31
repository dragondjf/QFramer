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

#include "settingmenu.h"
#include "mainwindow.h"
#include "dialogs/settingdialog.h"
#include "dialogs/aboutdialog.h"
#include <QDesktopServices>
#include <QUrl>

SettingMenu::SettingMenu(QWidget *parent) :
    QMenu(parent)
{
    initData();
    initUI();
    initConnect();
}

void SettingMenu::initData()
{
    actionNames << tr("Show flyWindow")
                << tr("Settings")
                << tr("Show rightBar")
                << tr("Check update")
                << tr("Online help")
                << tr("Office site")
                << tr("About us")
                << tr("Quit");
}

void SettingMenu::initUI()
{
    for (int i = 0; i < actionNames.length(); ++i) {
        QAction *action = new QAction(actionNames.at(i), this);
        actionMaps[actionNames.at(i)] = action;
        addAction(action);
    }
}

void SettingMenu::initConnect()
{
    connect(actionMaps[tr("Show flyWindow")], SIGNAL(triggered()), this, SLOT(switchActionState()));
    connect(actionMaps[tr("Show rightBar")],  SIGNAL(triggered()), this, SLOT(switchFloatWindow()));
    connect(actionMaps[tr("Settings")],       SIGNAL(triggered()), this, SLOT(showSettingDialog()));
    connect(actionMaps[tr("Check update")],   SIGNAL(triggered()), this, SLOT(checkUpdate()));
    connect(actionMaps[tr("Online help")],    SIGNAL(triggered()), this, SLOT(onlineHelp()));
    connect(actionMaps[tr("Office site")],    SIGNAL(triggered()), this, SLOT(visitOfficialSite()));
    connect(actionMaps[tr("About us")],       SIGNAL(triggered()), this, SLOT(showAboutUs()));
    connect(actionMaps[tr("Quit")],           SIGNAL(triggered()), this, SLOT(closeMainWindow()));
}

QMap<QString, QAction*> SettingMenu::getActionMaps()
{
    return actionMaps;
}

void SettingMenu::switchActionState()
{
    FlyWidget * flyWidget = MainWindow::getInstance()->getFlyWidget();
    flyWidget->setVisible(!flyWidget->isVisible());
    if (flyWidget->isVisible()) {
        actionMaps[tr("Show flyWindow")]->setText(tr("Hide flyWindow"));
    } else {
        actionMaps[tr("Show flyWindow")]->setText(tr("Show flyWindow"));
    }
}

void SettingMenu::switchFloatWindow()
{
    RightFloatWindow* rightFloatWindow = MainWindow::getInstance()->getRightFloatWindow();
    rightFloatWindow->setVisible(!rightFloatWindow->isVisible());
}

void SettingMenu::showSettingDialog()
{
    MainWindow::getInstance()->show();
    SettingDialog* settingDialog = new SettingDialog;
    settingDialog->exec();
}

void SettingMenu::checkUpdate()
{
    QDesktopServices::openUrl(QUrl("https://github.com/dragondjf/QCFramer"));
}

void SettingMenu::onlineHelp()
{
    QDesktopServices::openUrl(QUrl("https://github.com/dragondjf/QCFramer"));
}

void SettingMenu::visitOfficialSite()
{
    QDesktopServices::openUrl(QUrl("https://github.com/dragondjf/QCFramer"));
}

void SettingMenu::showAboutUs()
{
    MainWindow::getInstance()->show();
    AboutDialog* aboutDialog = new AboutDialog;
    aboutDialog->exec();
}

void SettingMenu::closeMainWindow()
{
    MainWindow::getInstance()->animationClose();
}
