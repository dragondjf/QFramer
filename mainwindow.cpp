#include "mainwindow.h"
#include "centerwindow.h"

MainWindow* MainWindow::instance = NULL;

MainWindow::MainWindow(QWidget *parent) :
    FMainWindow(parent)
{
    centerWindow = new CenterWindow;
    setCentralWidget(centerWindow);
<<<<<<< HEAD
    centerWindow->setTitleBar(titleBar);
    settingmenu = new SettingMenu;
    titleBar->setSettingMenu(settingmenu);
    trayicon->setContextMenu(settingmenu);
    flyWidget->setMenu(settingmenu);
=======
//    centerWindow->navagationBar->setFixedHeight(centerWindow->height());
>>>>>>> 93f3b82cf553ccbd90eec91b9860c38978134633

}

MainWindow* MainWindow::getInstance()
{
    if(!instance)
    {
        instance = new MainWindow();
    }
    return instance;
}
