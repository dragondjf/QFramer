#ifndef FTITLEBAR_H
#define FTITLEBAR_H

#include <QFrame>
#include <QToolButton>
#include <QLabel>
#include <fsettingmenu.h>

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
    QToolButton* minButton;
    QToolButton* maxButton;
    QToolButton* closeButton;
    bool normal_max_flag;

private:
    void initData();
    void initConnect();
    void initUI();

public:
    QString title;
    FSettingMenu* settingMenu;

public:
    explicit FTitleBar(QWidget *parent = 0);

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

};

#endif // FTITLEBAR_H
