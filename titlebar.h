#ifndef TITLEBAR_H
#define TITLEBAR_H

#include"QFramer/ftitlebar.h"
#include "settingmenu.h"

class TitleBar : public FTitleBar
{
    Q_OBJECT

public:
    static TitleBar* instance;
    SettingMenu* menu;
public:
    explicit TitleBar(QWidget *parent = 0);
    static TitleBar* getInstance();
signals:

public slots:

};

#endif // TITLEBAR_H
