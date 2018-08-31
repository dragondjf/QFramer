#include "FSettingMenu.h"

FSettingMenu::FSettingMenu(QWidget *parent)
    : QMenu(parent)
{
    initUI();
}

void FSettingMenu::initUI()
{
    QString exitStr = tr("Exit");
    QAction *exitAction = new QAction(exitStr, this);
    actionMaps[exitStr] = exitAction;
    addAction(exitAction);
}

void FSettingMenu::addSetting(const QString &title)
{
    if (title.isEmpty())
        return;

    QAction *action = new QAction(title, this);
    actionMaps[title] = action;
    insertAction(actionMaps[tr("Exit")], action);
}

QMap<QString, QAction *> FSettingMenu::getActionMaps()
{
    return actionMaps;
}
