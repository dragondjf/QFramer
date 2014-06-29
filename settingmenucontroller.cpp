#include "settingmenucontroller.h"
#include "settingdialog.h"
#include "aboutdialog.h"
#include<QDesktopServices>
#include<QUrl>
#include<QApplication>

SettingMenuController::SettingMenuController(QObject *parent) :
    QObject(parent)
{

}

void SettingMenuController::showSettingDialog()
{
    foreach (QWidget *widget, QApplication::topLevelWidgets()) {
        if (widget->isHidden())
            widget->show();
    }
    SettingDialog* settingDialog = new SettingDialog;
    settingDialog->exec();
}

void SettingMenuController::checkUpdate()
{
    QDesktopServices::openUrl(QUrl("https://github.com/dragondjf/QCFramer"));
}

void SettingMenuController::onlineHelp()
{
    QDesktopServices::openUrl(QUrl("https://github.com/dragondjf/QCFramer"));
}

void SettingMenuController::visitOfficialSite()
{
    QDesktopServices::openUrl(QUrl("https://github.com/dragondjf/QCFramer"));
}

void SettingMenuController::showAboutUs()
{
    foreach (QWidget *widget, QApplication::topLevelWidgets()) {
        if (widget->isHidden())
            widget->show();
    }
    AboutDialog* aboutDialog = new AboutDialog;
    aboutDialog->exec();

}
