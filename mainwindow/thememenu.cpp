#include "thememenu.h"
#include "QFramer/futil.h"
#include<QApplication>
#include<QFileDialog>
#include<QDir>
ThemeMenu::ThemeMenu(QWidget *parent) :
    QMenu(parent)
{
    initData();
    initUI();
    initConnect();
}

void ThemeMenu::initData()
{
    actionNames<< tr("BW")<<tr("BB") << tr("Custom Skin");
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
    connect(actionMaps[tr("Custom Skin")], SIGNAL(triggered()), this, SLOT(changeThemeFromFile()));
}

void ThemeMenu::changeTheme1()
{
    setSkinForApp(QString(":/qss/skin/qss/main.qss"));
}

void ThemeMenu::changeTheme2()
{
    setSkinForApp(QString(":/qss/skin/qss/fblue.qss"));
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
