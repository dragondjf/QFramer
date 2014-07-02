#include "fsettingmenucontroller.h"
#include "settingdialog.h"
#include "aboutdialog.h"
#include<QDesktopServices>
#include<QUrl>
#include<QApplication>
#include"mainwindow.h"

FSettingMenuController::FSettingMenuController(QObject *parent) :
    QObject(parent)
{

}

void FSettingMenuController::showSettingDialog()
{
    MainWindow::getInstance()->show();
    SettingDialog* settingDialog = new SettingDialog;
    settingDialog->exec();
}

void FSettingMenuController::checkUpdate()
{
    QDesktopServices::openUrl(QUrl("https://github.com/dragondjf/QCFramer"));
}

void FSettingMenuController::onlineHelp()
{
    QDesktopServices::openUrl(QUrl("https://github.com/dragondjf/QCFramer"));
}

void FSettingMenuController::visitOfficialSite()
{
    QDesktopServices::openUrl(QUrl("https://github.com/dragondjf/QCFramer"));
}

void FSettingMenuController::showAboutUs()
{
    MainWindow::getInstance()->show();
    AboutDialog* aboutDialog = new AboutDialog;
    aboutDialog->exec();

}

void FSettingMenuController::closeMainWindow()
{
    MainWindow* p = MainWindow::getInstance();
    p->close();
}
