#ifndef LOCKMENU_H
#define LOCKMENU_H

#include <QMenu>
#include "lockcontroller.h"
class LockMenu : public QMenu
{
    Q_OBJECT
private:
    QList<QAction*> actions;
    QList<QString> actionNames;
    QList<QString> actionicons;
    QMap<QString, QAction*> actionMaps;
    QAction* lockMovableAction;
    QAction* lockUnMovableAction;
    QAction* unLockAction;
    LockController* controller;

public:
    explicit LockMenu(QWidget *parent = 0);
    void initData();
    void initUI();
    void initController();
    void initConnect();

signals:

public slots:

};

#endif // LOCKMENU_H
