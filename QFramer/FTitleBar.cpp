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

#include "FTitleBar.h"
#include <QHBoxLayout>
#include <QApplication>

FTitleBar* FTitleBar::instance = NULL;

FTitleBar* FTitleBar::getInstace()
{
    if (!instance) {
        instance = new FTitleBar();
    }
    return instance;
}

FTitleBar::FTitleBar(QWidget *parent) :
    QFrame(parent)
{
    initData();
    initUI();
    initConnect();
}

void FTitleBar::initData()
{
    logoButton = new FToolButton();
    logoButton->setFocusPolicy(Qt::NoFocus);
    logoButton->setObjectName(QString("titleToolButton"));
    titleLabel = new QLabel();
    settingButton = new FToolButton();
    settingButton->setFocusPolicy(Qt::NoFocus);
    settingButton->setObjectName(QString("titleToolButton"));
    skinButton = new FToolButton();\
    skinButton->setFocusPolicy(Qt::NoFocus);
    skinButton->setObjectName(QString("titleToolButton"));
    fixButton = new FToolButton();
    fixButton->setFocusPolicy(Qt::NoFocus);
    fixButton->setObjectName(QString("titleToolButton"));
    minButton = new FToolButton();
    minButton->setFocusPolicy(Qt::NoFocus);
    minButton->setObjectName(QString("titleToolButton"));
    maxButton = new FToolButton();
    maxButton->setFocusPolicy(Qt::NoFocus);
    maxButton->setObjectName(QString("titleToolButton"));
    closeButton = new FToolButton();
    closeButton->setFocusPolicy(Qt::NoFocus);
    closeButton->setObjectName(QString("titleToolButton"));

    normal_max_flag = true;
    fixflag = true;
}

void FTitleBar::initUI()
{
    setObjectName(QString("FTitleBar"));
    setTitleBarHeight(TitleHeight);
    setLogoButton(":/skin/images/QFramer.png");
    setTitleLabel(qApp->applicationName(), "FTitleLabel");
    setSettingButton(":/skin/icons/dark/appbar.control.down.png");
    setSkinButton(":/skin/icons/dark/appbar.clothes.shirt.png");
    setFixButton(":/skin/icons/dark/appbar.unlock.keyhole.png");
    setMinButton(":/skin/icons/dark/appbar.minus.png");
    setMaxButton(":/skin/icons/dark/appbar.app.png");
    setCloseButton(":/skin/icons/dark/appbar.close.png", "close");

    QHBoxLayout* mainlayout = new QHBoxLayout(this);
    mainlayout->addWidget(logoButton);
    mainlayout->addWidget(titleLabel);
    mainlayout->addStretch();
    mainlayout->addWidget(settingButton);
    mainlayout->addWidget(skinButton);
    mainlayout->addWidget(fixButton);
    mainlayout->addWidget(minButton);
    mainlayout->addWidget(maxButton);
    mainlayout->addWidget(closeButton);
    mainlayout->setContentsMargins(0, 0, 5, 0);
    mainlayout->setSpacing(0);
}

void FTitleBar::initConnect()
{
    connect(settingButton, SIGNAL(clicked()), settingButton, SLOT(showMenu()));
    connect(skinButton, SIGNAL(clicked()), skinButton, SLOT(showMenu()));
    connect(fixButton, SIGNAL(clicked()), this, SLOT(changeFix()));
    connect(minButton, SIGNAL(clicked()), this, SIGNAL(minimuned()));
    connect(maxButton, SIGNAL(clicked()), this, SIGNAL(maximumed()));
    connect(maxButton, SIGNAL(clicked()), this, SLOT(switchMaxMin()));
    connect(closeButton, SIGNAL(clicked()), this, SIGNAL(closed()));
}

void FTitleBar::setTitleBarHeight(int height)
{
    setFixedHeight(height);
    logoButton->setIconSize(QSize(height, height));
    titleLabel->setFixedHeight(height);
    settingButton->setIconSize(QSize(height, height));
    skinButton->setIconSize(QSize(height, height));
    minButton->setIconSize(QSize(height, height));
    maxButton->setIconSize(QSize(height, height));
    closeButton->setIconSize(QSize(height, height));
}

void FTitleBar::setSettingMenu(QMenu *menu)
{
    settingButton->setMenu(menu);
}

bool FTitleBar::getFixedflag()
{
    return fixflag;
}

void FTitleBar::changeFix()
{
    if (fixflag) {
        fixButton->setIcon(QIcon(":/skin/icons/dark/appbar.lock.png"));
        fixflag = false;
    } else {
        fixButton->setIcon(QIcon(":/skin/icons/dark/appbar.unlock.keyhole.png"));
        fixflag = true;
    }
}

void FTitleBar::switchMaxMin()
{
    if(normal_max_flag) {
        maxButton->setIcon(QIcon(":/skin/icons/dark/appbar.fullscreen.box.png"));
        normal_max_flag = false;
    } else {
        maxButton->setIcon(QIcon(":/skin/icons/dark/appbar.app.png"));
        normal_max_flag = true;
    }
}

void FTitleBar::changeSkin()
{
//    BgSkinPopup* skinPopup = new BgSkinPopup;
//    skinPopup->move(QWidget::mapToGlobal(skinButton->geometry().bottomLeft()));
//    skinPopup->show();
}

void FTitleBar::clearChecked()
{
    settingButton->setChecked(false);
    skinButton->setChecked(false);
    fixButton->setChecked(false);
    minButton->setChecked(false);
    maxButton->setChecked(false);
    closeButton->setChecked(false);
}

void FTitleBar::setLogoButton(const QString &str, const char *objectName)
{
    logoButton->setIcon(QIcon(str));
    logoButton->setIconSize(QSize(height(), height()));
    if (objectName) {
        logoButton->setObjectName(QString(objectName));
    }
}

FToolButton* FTitleBar::getLogoButton()
{
    return logoButton;
}

void FTitleBar::setLogoButtonVisible(bool visible)
{
    logoButton->setVisible(visible);
}

bool FTitleBar::isLogoButtonVisible()
{
    return logoButton->isVisible();
}

void FTitleBar::setTitleLabel(const QString &str, const char *objectName)
{
    titleLabel->setText(str);
    titleLabel->setFixedHeight(height());
    if (objectName) {
        titleLabel->setObjectName(QString(objectName));
    }
}

QLabel* FTitleBar::getTitleLabel()
{
    return titleLabel;
}

void FTitleBar::setTitleLabelVisible(bool visible)
{
    titleLabel->setVisible(visible);
}

bool FTitleBar::isTitleLabelVisible()
{
    return titleLabel->isVisible();
}

void FTitleBar::setSettingButton(const QString &str, const char *objectName)
{
    settingButton->setIcon(QIcon(str));
    settingButton->setIconSize(QSize(height(), height()));
    if (objectName) {
        settingButton->setObjectName(QString(objectName));
    }
}

FToolButton* FTitleBar::getSettingButton()
{
    return settingButton;
}

void FTitleBar::setSettingButtonVisible(bool visible)
{
    settingButton->setVisible(visible);
}

bool FTitleBar::isSettingButtonVisible()
{
    return settingButton->isVisible();
}

void FTitleBar::setSkinButton(const QString &str, const char *objectName)
{
    skinButton->setIcon(QIcon(str));
    skinButton->setIconSize(QSize(height(), height()));
    if (objectName) {
        skinButton->setObjectName(QString(objectName));
    }
}

FToolButton* FTitleBar::getSkinButton()
{
    return skinButton;
}

void FTitleBar::setSkinButtonVisible(bool visible)
{
    skinButton->setVisible(visible);
}

bool FTitleBar::isSkinButtonVisible()
{
    return skinButton->isVisible();
}

void FTitleBar::setFixButton(const QString &str, const char *objectName)
{
    fixButton->setIcon(QIcon(str));
    fixButton->setIconSize(QSize(height(), height()));
    if (objectName) {
        fixButton->setObjectName(QString(objectName));
    }
}

FToolButton* FTitleBar::getFixButton()
{
    return fixButton;
}

void FTitleBar::setFixButtonVisible(bool visible)
{
    fixButton->setVisible(visible);
}

bool FTitleBar::isFixButtonVisible()
{
    return fixButton->isVisible();
}

void FTitleBar::setMinButton(const QString &str, const char *objectName)
{
    minButton->setIcon(QIcon(str));
    minButton->setIconSize(QSize(height(), height()));
    if (objectName) {
        minButton->setObjectName(QString(objectName));
    }
}

FToolButton* FTitleBar::getMinButton()
{
    return minButton;
}

void FTitleBar::setMinButtonVisible(bool visible)
{
    minButton->setVisible(visible);
}

bool FTitleBar::isMinButtonVisible()
{
    return minButton->isVisible();
}

void FTitleBar::setMaxButton(const QString &str, const char *objectName)
{
    maxButton->setIcon(QIcon(str));
    maxButton->setIconSize(QSize(height(), height()));
    if (objectName) {
        maxButton->setObjectName(QString(objectName));
    }
}

FToolButton* FTitleBar::getMaxButton()
{
    return maxButton;
}

void FTitleBar::setMaxButtonVisible(bool visible)
{
    maxButton->setVisible(visible);
}

bool FTitleBar::isMaxButtonVisible()
{
    return maxButton->isVisible();
}

void FTitleBar::setCloseButton(const QString &str, const char *objectName)
{
    closeButton->setIcon(QIcon(str));
    closeButton->setIconSize(QSize(height(), height()));
    if (objectName) {
        closeButton->setObjectName(QString(objectName));
    }
}

FToolButton* FTitleBar::getCloseButton()
{
    return closeButton;
}

void FTitleBar::setCloseButtonVisible(bool visible)
{
    closeButton->setVisible(visible);
}

bool FTitleBar::isCloseButtonVisible()
{
    return closeButton->isVisible();
}
