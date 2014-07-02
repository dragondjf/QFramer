#ifndef FSETTINGMENUCONTROLLER_H
#define FSETTINGMENUCONTROLLER_H

#include <QObject>

class FSettingMenuController : public QObject
{
    Q_OBJECT
public:
    explicit FSettingMenuController(QObject *parent = 0);

signals:

public slots:
    void showSettingDialog();
    void checkUpdate();
    void onlineHelp();
    void visitOfficialSite();
    void showAboutUs();
    void closeMainWindow();
};

#endif // FSETTINGMENUCONTROLLER_H
