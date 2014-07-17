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
