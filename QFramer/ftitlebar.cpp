#include "ftitlebar.h"
#include<QHBoxLayout>

FTitleBar* FTitleBar::instance = NULL;

FTitleBar::FTitleBar(QWidget *parent) :
    QFrame(parent)
{
    initData();
    initUI();
    initConnect();
}

FTitleBar* FTitleBar::getInstace()
{
    if(!instance)
    {
        instance = new FTitleBar();
    }
    return instance;
}

void FTitleBar::initData()
{
    title = tr("");
    logoButton = new QToolButton;
    logoButton->setObjectName(QString("titleToolButton"));
    titleLabel = new QLabel;
    settingButton = new QToolButton;
    settingButton->setFocusPolicy(Qt::NoFocus);
    settingButton->setObjectName(QString("titleToolButton"));
    skinButton = new QToolButton;\
    skinButton->setFocusPolicy(Qt::NoFocus);
    skinButton->setObjectName(QString("titleToolButton"));
    fixButton = new QToolButton;
    fixButton->setObjectName(QString("titleToolButton"));
    minButton = new QToolButton;
    minButton->setObjectName(QString("titleToolButton"));
    maxButton = new QToolButton;
    maxButton->setObjectName(QString("titleToolButton"));
    closeButton = new QToolButton;
    closeButton->setObjectName(QString("titleToolButton"));
    normal_max_flag = true;
    fixflag = false;

    maxIcon =  new QIcon(QString(":/skin/icons/dark/appbar.fullscreen.box.png"));
    normalIcon =  new QIcon(QString(":/skin/icons/dark/appbar.app.png"));
}

void FTitleBar::initUI()
{
    setTitleBarHeight(Title_Height);
    setObjectName(QString("FTitleBar"));
    setLogoButton(":/skin/images/QFramer.png");
    setTitleLabel(tr("QFramer"), "FTitleLabel");
    setSettingButton(":/skin/icons/dark/appbar.control.down.png");
    setSkinButton(":/skin/icons/dark/appbar.clothes.shirt.png");
    setFixButton(":/skin/icons/dark/appbar.lock.png");
    setMinButton(":/skin/icons/dark/appbar.minus.png");
    setMaxButton(":/skin/icons/dark/appbar.app.png");
    setCloseButton(":/skin/icons/dark/appbar.close.png", "close");

    QHBoxLayout* mainlayout = new QHBoxLayout;
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
    setLayout(mainlayout);
}

void FTitleBar::initConnect()
{
    connect(settingButton, SIGNAL(clicked()), settingButton, SLOT(showMenu()));
    connect(skinButton, SIGNAL(clicked()), skinButton, SLOT(showMenu()));
    connect(fixButton, SIGNAL(clicked()), this, SLOT(changeFix()));
    connect(maxButton, SIGNAL(clicked()), this, SIGNAL(maximumed()));
    connect(minButton, SIGNAL(clicked()), this, SIGNAL(minimuned()));
    connect(closeButton, SIGNAL(clicked()), this, SIGNAL(closed()));
    connect(maxButton, SIGNAL(clicked()), this, SLOT(switchMaxMin()));
}

void FTitleBar::changeFix()
{
    if(fixflag)
    {
        fixButton->setIcon(QIcon(":/skin/icons/dark/appbar.lock.png"));
    }
    else{
        fixButton->setIcon(QIcon(":/skin/icons/dark/appbar.unlock.keyhole.png"));
    }
    fixflag = not fixflag;
}


bool FTitleBar::getFixedflag()
{
    return fixflag;
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

void FTitleBar::setSettingMenu(QMenu *menu)
{
    settingButton->setMenu(menu);
}

void FTitleBar::switchMaxMin()
{
    if(normal_max_flag)
    {
        maxButton->setIcon(*maxIcon);
        normal_max_flag = false;
    }
    else{
        maxButton->setIcon(*normalIcon);
        normal_max_flag = true;
    }
}

void FTitleBar::changeSkin()
{
//    BgSkinPopup* skinPopup = new BgSkinPopup;
//    skinPopup->move(QWidget::mapToGlobal(skinButton->geometry().bottomLeft()));
//    skinPopup->show();
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

void FTitleBar::setLogoButton(const char *str, const char *objectName)
{

    logoButton->setIcon(QIcon(QString(str)));
    logoButton->setIconSize(QSize(height(), height()));
    if(objectName)
        logoButton->setObjectName(QString(objectName));
}

QToolButton* FTitleBar::getLogoButton()
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


void FTitleBar::setTitleLabel(QString str, const char *objectName)
{
    titleLabel->setText(str);
    titleLabel->setFixedHeight(height());
    if (objectName)
    {
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

void FTitleBar::setSettingButton(const char *str, const char *objectName)
{

    settingButton->setIcon(QIcon(QString(str)));
    settingButton->setIconSize(QSize(height(), height()));
    if (objectName)
    {
        settingButton->setObjectName(QString(objectName));
    }
}


QToolButton* FTitleBar::getSettingButton()
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


void FTitleBar::setSkinButton(const char *str, const char *objectName)
{

    skinButton->setIcon(QIcon(QString(str)));
    skinButton->setIconSize(QSize(height(), height()));
    if(objectName)
    {
        skinButton->setObjectName(QString(objectName));
    }
}

QToolButton* FTitleBar::getSkinButton()
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


void FTitleBar::setFixButton(const char *str, const char *objectName)
{

    fixButton->setIcon(QIcon(QString(str)));
    fixButton->setIconSize(QSize(height(), height()));
    if(objectName)
    {
        fixButton->setObjectName(QString(objectName));
    }
}

QToolButton* FTitleBar::getFixButton()
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

void FTitleBar::setMinButton(const char *str, const char *objectName)
{
    minButton->setIcon(QIcon(QString(str)));
    minButton->setIconSize(QSize(height(), height()));
    if (objectName)
    {
        minButton->setObjectName(QString(objectName));

    }
}

QToolButton* FTitleBar::getMinButton()
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


void FTitleBar::setMaxButton(const char *str, const char *objectName)
{

    maxButton->setIcon(QIcon(QString(str)));
    maxButton->setIconSize(QSize(height(), height()));
    if (objectName)
    {
        maxButton->setObjectName(QString(objectName));

    }
}


QToolButton* FTitleBar::getMaxButton()
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


void FTitleBar::setCloseButton(const char *str, const char *objectName)
{
    closeButton->setIcon(QIcon(QString(str)));
    closeButton->setIconSize(QSize(height(), height()));
    if (objectName)
    {

        closeButton->setObjectName(QString(objectName));

    }
}

QToolButton* FTitleBar::getCloseButton()
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
