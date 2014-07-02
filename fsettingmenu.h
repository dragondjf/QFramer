#ifndef FSETTINGMENU_H
#define FSETTINGMENU_H
#include <QMenu>
#include <QAction>
#include "util.h"
#include "fsettingmenucontroller.h"

class FSettingMenu : public QMenu
{
    Q_OBJECT
public:
    QList<QAction*> actions;
    QList<QString> actionNames;
    QList<QString> actionicons;
    QMap<QString, QAction*> actionMaps;
    QAction* settingAction;
    QAction* checkUpdateAction;
    QAction* onlineHelpAction;
    QAction* officialSiteAction;
    QAction* aboutAction;
    FSettingMenuController* controller;
public:
    explicit FSettingMenu(QWidget *parent = 0);
    void initData();
    void initUI();
    void initController();
    void initConnect();

signals:

public slots:
    void switchActionState();
};

#endif // FSETTINGMENU_H
