#include "settingmenu.h"
#include "mainwindow.h"
#include <QApplication>

SettingMenu::SettingMenu(QWidget *parent) :
    QMenu(parent)
{
    initData();
    initUI();
    initController();
    initConnect();

    QString qss = getQssFromFile(QString(":/qss/skin/qss/main.qss"));
    setStyleSheet(qss);
}

void SettingMenu::initData()
{
    actionNames<< tr("Show flyWindow")<<tr("Settings") << tr("Check update") << tr("Online help") << tr("Office site") << tr("About us")<< tr("Quit");
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
//    connect(actionMaps[tr("Settings")], &QAction::triggered, controller, &FSettingMenuController::showSettingDialog);
//    connect(actionMaps[tr("Check update")], &QAction::triggered, controller, &FSettingMenuController::checkUpdate);
//    connect(actionMaps[tr("Online help")], &QAction::triggered, controller, &FSettingMenuController::onlineHelp);
//    connect(actionMaps[tr("Office site")], &QAction::triggered, controller, &FSettingMenuController::visitOfficialSite);
//    connect(actionMaps[tr("About us")], &QAction::triggered, controller, &FSettingMenuController::showAboutUs);
//    connect(actionMaps[tr("Quit")], &QAction::triggered, controller, &FSettingMenuController::closeMainWindow);
    connect(actionMaps[tr("Show flyWindow")], SIGNAL(triggered()), this, SLOT(switchActionState()));
    connect(actionMaps[tr("Settings")], SIGNAL(triggered()), controller, SLOT(showSettingDialog()));
    connect(actionMaps[tr("Check update")], SIGNAL(triggered()), controller, SLOT(checkUpdate()));
    connect(actionMaps[tr("Online help")], SIGNAL(triggered()), controller, SLOT(onlineHelp()));
    connect(actionMaps[tr("Office site")], SIGNAL(triggered()), controller, SLOT(visitOfficialSite()));
    connect(actionMaps[tr("About us")], SIGNAL(triggered()), controller, SLOT(showAboutUs()));
    connect(actionMaps[tr("Quit")], SIGNAL(triggered()), controller, SLOT(closeMainWindow()));
}


void SettingMenu::switchActionState()
{
    MainWindow::getInstance()->flyWidget->setVisible(
                not MainWindow::getInstance()->flyWidget->isVisible());

    if(MainWindow::getInstance()->flyWidget->isVisible())
    {
        actionMaps[tr("Show flyWindow")]->setText(tr("Hide flyWindow"));
    }
    else
    {
        actionMaps[tr("Show flyWindow")]->setText(tr("Show flyWindow"));
    }
}
