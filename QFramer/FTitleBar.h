/****************************************************************************
**
** Copyright (C) 2014 dragondjf
**
** QFramer is a frame based on Qt5.3, you will be more efficient with it.
** As an Qter, Qt give us a nice coding experience. With user interactive experience(UE)
** become more and more important in modern software, deveployers should consider business and UE.
** So, QFramer is born. QFramer's goal is to be a mature solution
** which you only need to be focus on your business but UE for all Qters.
**
** Version	: 0.2.5.0
** Author	: dragondjf
** Website	: https://github.com/dragondjf
** Project	: https://github.com/dragondjf/QCFramer
** Blog		: http://my.oschina.net/dragondjf/home/?ft=atme
** Wiki		: https://github.com/dragondjf/QCFramer/wiki
** Lincence: LGPL V2
** QQ: 465398889
** Email: dragondjf@gmail.com, ding465398889@163.com, 465398889@qq.com
**
****************************************************************************/

#ifndef FTITLEBAR_H
#define FTITLEBAR_H

#include <QFrame>
#include <QMenu>
#include <QLabel>
#include <QString>
#include "FToolButton.h"
class QIcon;

const int TitleHeight = 25;

class FTitleBar : public QFrame
{
    Q_OBJECT
private:
    QLabel *titleLabel;
    FToolButton *logoButton;
    FToolButton *settingButton;
    FToolButton *skinButton;
    FToolButton *fixButton;
    FToolButton *minButton;
    FToolButton *maxButton;
    FToolButton *closeButton;

    bool normal_max_flag;
    bool fixflag;

    void initData();
    void initConnect();
    void initUI();

public:
    static FTitleBar* instance;
    static FTitleBar* getInstace();
    explicit FTitleBar(QWidget *parent = 0);

    void setTitleBarHeight(int height = TitleHeight);
    void setSettingMenu(QMenu* menu);
    bool getFixedflag();

    void setLogoButton(const QString &str, const char *objectName = nullptr);
    FToolButton* getLogoButton();
    void setLogoButtonVisible(bool visible);
    bool isLogoButtonVisible();

    void setTitleLabel(const QString &str, const char *objectName = nullptr);
    QLabel* getTitleLabel();
    void setTitleLabelVisible(bool visible);
    bool isTitleLabelVisible();

    void setSettingButton(const QString &str, const char *objectName = nullptr);
    FToolButton* getSettingButton();
    void setSettingButtonVisible(bool visible);
    bool isSettingButtonVisible();

    void setSkinButton(const QString &str, const char *objectName = nullptr);
    FToolButton* getSkinButton();
    void setSkinButtonVisible(bool visible);
    bool isSkinButtonVisible();

    void setFixButton(const QString &str, const char *objectName = nullptr);
    FToolButton* getFixButton();
    void setFixButtonVisible(bool visible);
    bool isFixButtonVisible();

    void setMinButton(const QString &str, const char *objectName = nullptr);
    FToolButton* getMinButton();
    void setMinButtonVisible(bool visible);
    bool isMinButtonVisible();

    void setMaxButton(const QString &str, const char *objectName = nullptr);
    FToolButton* getMaxButton();
    void setMaxButtonVisible(bool visible);
    bool isMaxButtonVisible();

    void setCloseButton(const QString &str, const char *objectName = nullptr);
    FToolButton* getCloseButton();
    void setCloseButtonVisible(bool visible);
    bool isCloseButtonVisible();

signals:
    void maximumed();
    void minimuned();
    void normaled();
    void closed();

public slots:
    void changeFix();
    void switchMaxMin();
    void changeSkin();
    void clearChecked();
};

#endif // FTITLEBAR_H
