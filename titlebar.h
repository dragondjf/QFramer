#ifndef TITLEBAR_H
#define TITLEBAR_H
#include<QWidget>
#include <QFrame>
#include<QIcon>
#include<QLabel>
#include<QToolButton>
#include"settingmenu.h"
#include"bgskinpopup.h"
#define Title_Height 25

class TitleBar : public QFrame
{
    Q_OBJECT
public:
    QIcon* logoIcon;
    QIcon* settingsIcon;
    QIcon* skinIcon;
    QIcon* minIcon;
    QIcon* maxIcon;
    QIcon* normalIcon;
    QIcon* closeIcon;
    QLabel* titleLabel;
    QToolButton* logoButton;
    QToolButton* settingButton;
    QToolButton* skinButton;
    QToolButton* minButton;
    QToolButton* maxButton;
    QToolButton* closeButton;
    bool normal_max_flag;

    SettingMenu* settingMenu;
public:
    explicit TitleBar(QWidget *parent = 0);
    void initData();
    void initUI();
    void initConnect();
signals:
    void maximumed();
    void minimuned();
    void normaled();
    void closed();

public slots:
    void switchMaxMin();
    void changeSkin();
};

#endif // TITLEBAR_H
