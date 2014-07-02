#ifndef FSETTINGMENU_H
#define FSETTINGMENU_H
#include "util.h"
#include "fsettingmenucontroller.h"
#include <QMenu>
#include <QAction>
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
