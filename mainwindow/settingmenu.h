#ifndef SETTINGMENU_H
#define SETTINGMENU_H
#include <QMenu>
#include <QAction>
#include "QFramer/futil.h"
#include "settingmenucontroller.h"

class SettingMenu : public QMenu
{
    Q_OBJECT
private:
    QList<QAction*> actions;
    QList<QString> actionNames;
    QList<QString> actionicons;
    QMap<QString, QAction*> actionMaps;
    QAction* settingAction;
    QAction* checkUpdateAction;
    QAction* onlineHelpAction;
    QAction* officialSiteAction;
    QAction* aboutAction;
    SettingMenuController* controller;
private:
    void initData();
    void initUI();
    void initController();
    void initConnect();
public:
    explicit SettingMenu(QWidget *parent = 0);

    QMap<QString, QAction*> getActionMaps();
signals:

public slots:
    void switchActionState();
    void switchFloatWindow();
};

#endif // SETTINGMENU_H
