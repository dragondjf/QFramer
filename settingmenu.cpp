#include "settingmenu.h"

SettingMenu::SettingMenu(QWidget *parent) :
    QMenu(parent)
{
    initData();
    initUI();
    initConnect();
//    setObjectName(QString("SettingMenu"));
    QString qss = getQssFromFile(QString(":/skin/qss/main.qss"));
    setStyleSheet(qss);
}

void SettingMenu::initData()
{
    actionNames<< tr("设置") << tr("检测更新") << tr("在线帮助") << tr("官方网站") << tr("帮助");
}

void SettingMenu::initUI()
{
    for(int i=0; i< actionNames.length() ; ++i)
    {
        actions.append(new QAction(actionNames.at(i), this));
    }
    addActions(actions);
}

void SettingMenu::initConnect()
{

}
