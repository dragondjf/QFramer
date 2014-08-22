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
#include <QToolButton>
#include <QLabel>


#define Title_Height 25

class FTitleBar : public QFrame
{
    Q_OBJECT
private:
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
    QToolButton* fixButton;
    QToolButton* minButton;
    QToolButton* maxButton;
    QToolButton* closeButton;
    bool normal_max_flag;
    bool fixflag;

private:
    void initData();
    void initConnect();
    void initUI();

public:
    QString title;
    static FTitleBar* instance;

public:
    explicit FTitleBar(QWidget *parent = 0);
    static FTitleBar* getInstace();

    bool getFixedflag();

    void setTitleBarHeight(int height);
    void setSettingMenu(QMenu* menu);

    void setLogoButton(const char * str, const char *objectName=NULL);
    QToolButton* getLogoButton();
    void setLogoButtonVisible(bool visible);
    bool isLogoButtonVisible();

    void setTitleLabel(QString str , const char *objectName=NULL);
    QLabel* getTitleLabel();
    void setTitleLabelVisible(bool visible);
    bool isTitleLabelVisible();

    void setSettingButton(const char * str, const char *objectName=NULL);
    QToolButton* getSettingButton();
    void setSettingButtonVisible(bool visible);
    bool isSettingButtonVisible();

    void setSkinButton(const char * str, const char *objectName=NULL);
    QToolButton* getSkinButton();
    void setSkinButtonVisible(bool visible);
    bool isSkinButtonVisible();

    void setFixButton(const char * str, const char *objectName=NULL);
    QToolButton* getFixButton();
    void setFixButtonVisible(bool visible);
    bool isFixButtonVisible();

    void setMinButton(const char * str, const char *objectName=NULL);
    QToolButton* getMinButton();
    void setMinButtonVisible(bool visible);
    bool isMinButtonVisible();

    void setMaxButton(const char * str, const char *objectName=NULL);
    QToolButton* getMaxButton();
    void setMaxButtonVisible(bool visible);
    bool isMaxButtonVisible();

    void setCloseButton(const char * str, const char *objectName=NULL);
    QToolButton* getCloseButton();
    void setCloseButtonVisible(bool visible);
    bool isCloseButtonVisible();

signals:
    void maximumed();
    void minimuned();
    void normaled();
    void closed();

public slots:
    void switchMaxMin();
    void changeSkin();
    void clearChecked();
    void changeFix();

};

#endif // FTITLEBAR_H
