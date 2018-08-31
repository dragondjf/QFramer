#ifndef FSETTINGMENU_H
#define FSETTINGMENU_H

#include <QMenu>
#include <QMap>

class FSettingMenu : public QMenu
{
    Q_OBJECT
private:
    QMap<QString, QAction*> actionMaps;

    void initUI();

public:
    explicit FSettingMenu(QWidget *parent = nullptr);

    void addSetting(const QString &title);

    QMap<QString, QAction*> getActionMaps();

signals:

public slots:

};

#endif // FSETTINGMENU_H
