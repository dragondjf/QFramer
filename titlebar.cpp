#include "titlebar.h"
#include "QFramer/ftitlebar.h"

TitleBar* TitleBar::instance = NULL;

TitleBar::TitleBar(QWidget *parent) :
    FTitleBar(parent)
{
    menu = new SettingMenu;
    setSettingMenu(menu);
}


TitleBar* TitleBar::getInstance()
{
    if(!instance)
    {
        instance = new TitleBar();
    }
    return instance;
}
