#include "thememenu.h"
#include "QFramer/futil.h"
#include<QApplication>
ThemeMenu::ThemeMenu(QWidget *parent) :
    QMenu(parent)
{
    initData();
    initUI();
    initConnect();
}

void ThemeMenu::initData()
{
    actionNames<< tr("BW")<<tr("BB");
}

void ThemeMenu::initUI()
{
    for(int i=0; i< actionNames.length() ; ++i)
    {
        actions.append(new QAction(actionNames.at(i), this));
        actionMaps[actionNames.at(i)] = actions.at(i);
    }
    addActions(actions);
}

void ThemeMenu::initConnect()
{
    connect(actionMaps[tr("BW")], SIGNAL(triggered()), this, SLOT(changeTheme1()));
    connect(actionMaps[tr("BB")], SIGNAL(triggered()), this, SLOT(changeTheme2()));
}

void ThemeMenu::changeTheme1()
{
    setSkinForApp(*(QApplication*)QApplication::instance(), QString(":/qss/skin/qss/main.qss"));
}

void ThemeMenu::changeTheme2()
{
    setSkinForApp(*(QApplication*)QApplication::instance(), QString(":/qss/skin/qss/fblue.qss"));
}
