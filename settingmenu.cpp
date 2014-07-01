#include "settingmenu.h"
#include <QApplication>
SettingMenu::SettingMenu(QWidget *parent) :
    QMenu(parent)
{
    initData();
    initUI();
    initController();
    initConnect();
//    setObjectName(QString("SettingMenu"));
    QString qss = getQssFromFile(QString(":/skin/qss/main.qss"));
    setStyleSheet(qss);
}

void SettingMenu::initData()
{
    actionNames<< tr("Settings") << tr("Check update") << tr("Online help") << tr("Office site") << tr("About us")<< tr("Quit");
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
    connect(actionMaps[tr("Settings")], &QAction::triggered, controller, &SettingMenuController::showSettingDialog);
    connect(actionMaps[tr("Check update")], &QAction::triggered, controller, &SettingMenuController::checkUpdate);
    connect(actionMaps[tr("Online help")], &QAction::triggered, controller, &SettingMenuController::onlineHelp);
    connect(actionMaps[tr("Office site")], &QAction::triggered, controller, &SettingMenuController::visitOfficialSite);
    connect(actionMaps[tr("About us")], &QAction::triggered, controller, &SettingMenuController::showAboutUs);
    connect(actionMaps[tr("Quit")], &QAction::triggered, controller, &SettingMenuController::closeMainWindow);
}
