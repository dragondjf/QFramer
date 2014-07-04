#include "mainwindow.h"
#include "centerwindow.h"

MainWindow* MainWindow::instance = NULL;

MainWindow::MainWindow(QWidget *parent) :
    FMainWindow(parent)
{
    centerWindow = new CenterWindow;
    setCentralWidget(centerWindow);
    centerWindow->setTitleBar(titleBar);
    settingmenu = new SettingMenu;
    titleBar->setSettingMenu(settingmenu);
    trayicon->setContextMenu(settingmenu);
    flyWidget->setMenu(settingmenu);

}

MainWindow* MainWindow::getInstance()
{
    if(!instance)
    {
        instance = new MainWindow();
    }
    return instance;
}
