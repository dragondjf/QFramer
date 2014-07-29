/****************************************************************************
**
** Copyright (C) 2014 dragondjf
**
** QFramer is a frame based on Qt5.3, you will be more efficient with it. 
** As an Qter，Qt give us a nice coding experience. With user interactive experience(UE) 
** become more and more important in modern software, deveployers should consider business and UE.
** So, QFramer is born. QFramer's goal is to be a mature solution 
** which you only need to be focus on your business but UE for all Qters.
**
** Version	: 0.2.2.0
** Author	: dragondjf
** Website	: https://github.com/dragondjf
** Project	: https://github.com/dragondjf/QCFramer
** Blog		: http://www.cnblogs.com/ldcsaa
** Wiki		: https://github.com/dragondjf/QCFramer
** Lincence: LGPL V2
** QQ: 465398889
** Email: dragondjf@gmail.com, ding465398889@163.com, 465398889@qq.com
** 
****************************************************************************/

#include "lockmenu.h"
LockMenu::LockMenu(QWidget *parent) :
    QMenu(parent)
{
    initData();
    initUI();
    initController();
    initConnect();
}

void LockMenu::initData()
{
    actionNames<< tr("Lock movable")<<tr("Lock unmoved")<< tr("Unlock");
}

void LockMenu::initUI()
{
    for(int i=0; i< actionNames.length() ; ++i)
    {
        actions.append(new QAction(actionNames.at(i), this));
        actionMaps[actionNames.at(i)] = actions.at(i);
    }
    addActions(actions);
}

void LockMenu::initController()
{
    controller = new LockController();
}

void LockMenu::initConnect()
{
    connect(actionMaps[tr("Lock movable")], SIGNAL(triggered()), controller, SLOT(lockMovable()));
    connect(actionMaps[tr("Lock unmoved")], SIGNAL(triggered()), controller, SLOT(lockUnmoved()));
    connect(actionMaps[tr("Unlock")], SIGNAL(triggered()), controller, SLOT(unLock()));
}
