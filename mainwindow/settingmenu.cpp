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
#include "functionpages/rightfloatwindow.h"
#include <QApplication>


SettingMenu::SettingMenu(QWidget *parent) :
    QMenu(parent)
{
    initData();
    initUI();
    initController();
    initConnect();
}

void SettingMenu::initData()
{
    actionNames<< tr("Show flyWindow")<<tr("Settings")\
              << tr("Show rightBar")\
              << tr("Check update") << tr("Online help") \
              << tr("Office site") << tr("About us")<< tr("Quit");
}

void SettingMenu::initUI()
{
    for(int i=0; i< actionNames.length() ; ++i)
    {
        actions.append(new QAction(actionNames.at(i), this));
        actionMaps[actionNames.at(i)] = actions.at(i);
    }
    addActions(actions);
}

void SettingMenu::initController()
{
    controller = new SettingMenuController();
}

void SettingMenu::initConnect()
{
    connect(actionMaps[tr("Show flyWindow")], SIGNAL(triggered()), this, SLOT(switchActionState()));
    connect(actionMaps[tr("Show rightBar")], SIGNAL(triggered()), this, SLOT(switchFloatWindow()));
    connect(actionMaps[tr("Settings")], SIGNAL(triggered()), controller, SLOT(showSettingDialog()));
    connect(actionMaps[tr("Check update")], SIGNAL(triggered()), controller, SLOT(checkUpdate()));
    connect(actionMaps[tr("Online help")], SIGNAL(triggered()), controller, SLOT(onlineHelp()));
    connect(actionMaps[tr("Office site")], SIGNAL(triggered()), controller, SLOT(visitOfficialSite()));
    connect(actionMaps[tr("About us")], SIGNAL(triggered()), controller, SLOT(showAboutUs()));
    connect(actionMaps[tr("Quit")], SIGNAL(triggered()), controller, SLOT(closeMainWindow()));
}

QMap<QString, QAction*> SettingMenu::getActionMaps()
{
    return actionMaps;
}


void SettingMenu::switchActionState()
{
    MainWindow::getInstance()->getFlyWidget()->setVisible(
                not MainWindow::getInstance()->getFlyWidget()->isVisible());

    if(MainWindow::getInstance()->getFlyWidget()->isVisible())
    {
        actionMaps[tr("Show flyWindow")]->setText(tr("Hide flyWindow"));
    }
    else
    {
        actionMaps[tr("Show flyWindow")]->setText(tr("Show flyWindow"));
    }
}

void SettingMenu::switchFloatWindow()
{
    MainWindow::getInstance()->getRightFloatWindow()->setVisible(\
        not MainWindow::getInstance()->getRightFloatWindow()->isVisible());
}
