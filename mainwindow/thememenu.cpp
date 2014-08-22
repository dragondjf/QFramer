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

#include "thememenu.h"
#include "QFramer/futil.h"
#include <QApplication>
#include <QFileDialog>
#include <QDir>
ThemeMenu::ThemeMenu(QWidget *parent) :
    QMenu(parent)
{
    initData();
    initUI();
    initConnect();
    actionMaps[tr("GBG")]->trigger();
}

void ThemeMenu::initData()
{
    actionNames<< tr("BW")<<tr("BB") << tr("GB")<< tr("GG")<< tr("GBG") << tr("GGG") \
               <<tr("Custom theme")<<tr("Blank");
}

void ThemeMenu::initUI()
{
    for(int i=0; i< actionNames.length() ; ++i)
    {
        actions.append(new QAction(actionNames.at(i), this));
        actions.at(i)->setCheckable(true);
        actionMaps[actionNames.at(i)] = actions.at(i);
    }
    addActions(actions);
}

void ThemeMenu::initConnect()
{
    connect(actionMaps[tr("BW")], SIGNAL(triggered()), this, SLOT(changeTheme1()));
    connect(actionMaps[tr("BB")], SIGNAL(triggered()), this, SLOT(changeTheme2()));
    connect(actionMaps[tr("GB")], SIGNAL(triggered()), this, SLOT(changeTheme3()));
    connect(actionMaps[tr("GG")], SIGNAL(triggered()), this, SLOT(changeTheme4()));
    connect(actionMaps[tr("GBG")], SIGNAL(triggered()), this, SLOT(changeTheme5()));
    connect(actionMaps[tr("GGG")], SIGNAL(triggered()), this, SLOT(changeTheme6()));
    connect(actionMaps[tr("Custom theme")], SIGNAL(triggered()), this, SLOT(changeThemeFromFile()));
    connect(actionMaps[tr("Blank")], SIGNAL(triggered()), this, SLOT(changeTheme_blank()));
    connect(this, SIGNAL(triggered(QAction*)), this, SLOT(updateCheckedAction(QAction*)));
}

void ThemeMenu::changeTheme1()
{
    setSkinForApp(QString(":/qss/skin/qss/BW.qss"));
}

void ThemeMenu::changeTheme2()
{
    setSkinForApp(QString(":/qss/skin/qss/BB.qss"));
}

void ThemeMenu::changeTheme3()
{
    setSkinForApp(QString(":/qss/skin/qss/GB.qss"));
}

void ThemeMenu::changeTheme4()
{
    setSkinForApp(QString(":/qss/skin/qss/GG.qss"));
}

void ThemeMenu::changeTheme5()
{
    setSkinForApp(QString(":/qss/skin/qss/GBG.qss"));
}

void ThemeMenu::changeTheme6()
{
    setSkinForApp(QString(":/qss/skin/qss/GGG.qss"));
}

void ThemeMenu::changeTheme_blank()
{
    setSkinForApp(QString(""));
}

void ThemeMenu::changeThemeFromFile()
{
    QString fileName;
    fileName = QFileDialog::getOpenFileName(this,
        tr("Laod qss"), QDir::currentPath(), tr("Qss Files (*.qss)"));
    if (fileName != ""){
        setSkinForApp(fileName);
    }
}

void ThemeMenu::updateCheckedAction(QAction *action)
{
    foreach (QAction* actionItem, actions) {
        if(actionItem == action){
            action->setChecked(true);
        }else {
            actionItem->setChecked(false);
        }
    }
}
