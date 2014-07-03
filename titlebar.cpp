#include "titlebar.h"

TitleBar* TitleBar::instance = NULL;

TitleBar::TitleBar(QWidget *parent) :
    FTitleBar(parent)
{
}


TitleBar* TitleBar::getInstance()
{
    if(!instance)
    {
        instance = new TitleBar();
    }
    return instance;
}
