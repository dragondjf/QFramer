#include "mainwindow.h"
#include "centerwindow.h"
#include "QFramer/futil.h"
MainWindow* MainWindow::instance = NULL;

MainWindow::MainWindow(QWidget *parent) :
    FMainWindow(parent)
{
    centerWindow = new CenterWindow;
    setCentralWidget(centerWindow);

    settingmenu = new SettingMenu;
    getTitleBar()->setSettingMenu(settingmenu);
    getQSystemTrayIcon()->setContextMenu(settingmenu);
    getFlyWidget()->setMenu(settingmenu);

    QString qss = getQssFromFile(QString(":/qss/skin/qss/main.qss"));
    setStyleSheet(qss);
}

MainWindow* MainWindow::getInstance()
{
    if(!instance)
    {
        instance = new MainWindow();
    }
    return instance;
}
