#include "titlebar.h"
#include"bgskinpopup.h"
#include<QHBoxLayout>
#include<QLabel>


TitleBar::TitleBar(QWidget *parent)
    :QFrame(parent)
{
    initData();
    initUI();
    initConnect();
}


void TitleBar::initData()
{
    logoIcon = new QIcon(QString(":/skin/images/QFramer.png"));
    settingsIcon = new QIcon(QString(":/skin/icons/dark/appbar.control.down.png"));
    skinIcon =  new QIcon(QString(":/skin/icons/dark/appbar.clothes.shirt.png"));
    minIcon =  new QIcon(QString(":/skin/icons/dark/appbar.minus.png"));
    maxIcon =  new QIcon(QString(":/skin/icons/dark/appbar.fullscreen.box.png"));
    normalIcon =  new QIcon(QString(":/skin/icons/dark/appbar.app.png"));
    closeIcon =  new QIcon(QString(":/skin/icons/dark/appbar.close.png"));
    normal_max_flag = true;
}

void TitleBar::initUI()
{
    setFixedHeight(Title_Height);
    setObjectName(QString("TitleBar"));

    titleLabel = new QLabel;
    logoButton = new QToolButton;
    settingButton = new QToolButton;
    skinButton = new QToolButton;
    minButton = new QToolButton;
    maxButton = new QToolButton;
    closeButton = new QToolButton;

    settingMenu = new SettingMenu;
    settingButton->setMenu(settingMenu);

    logoButton->setIcon(*logoIcon);
    logoButton->setIconSize(QSize(Title_Height, Title_Height));
    logoButton->setObjectName(QString("logo"));
    titleLabel->setText(tr("QFramer"));
    titleLabel->setObjectName(QString("TitleLabel"));
    settingButton->setIcon(*settingsIcon);
    settingButton->setIconSize(QSize(Title_Height, Title_Height));
    skinButton->setIcon(*skinIcon);
    skinButton->setIconSize(QSize(Title_Height, Title_Height));
    minButton->setIcon(*minIcon);
    minButton->setIconSize(QSize(Title_Height, Title_Height));
    maxButton->setIcon(*normalIcon);
    maxButton->setIconSize(QSize(Title_Height, Title_Height));
    closeButton->setIcon(*closeIcon);
    closeButton->setIconSize(QSize(Title_Height, Title_Height));
    closeButton->setObjectName(tr("close"));
    QHBoxLayout* mainlayout = new QHBoxLayout;
    mainlayout->addWidget(logoButton);
    mainlayout->addWidget(titleLabel);
    mainlayout->addStretch();
    mainlayout->addWidget(settingButton);
    mainlayout->addWidget(skinButton);
    mainlayout->addWidget(minButton);
    mainlayout->addWidget(maxButton);
    mainlayout->addWidget(closeButton);
    mainlayout->setContentsMargins(0, 0, 5, 0);
    mainlayout->setSpacing(0);
    setLayout(mainlayout);
}

void TitleBar::initConnect()
{
    connect(settingButton, &QToolButton::clicked, settingButton, &QToolButton::showMenu);
    connect(skinButton, &QToolButton::clicked, this, &TitleBar::changeSkin);
    connect(maxButton, SIGNAL(clicked()), this, SIGNAL(maximumed()));
    connect(minButton, SIGNAL(clicked()), this, SIGNAL(minimuned()));
    connect(closeButton, SIGNAL(clicked()), this, SIGNAL(closed()));
    connect(maxButton, SIGNAL(clicked()), this, SLOT(switchMaxMin()));
}

void TitleBar::switchMaxMin()
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


void TitleBar::changeSkin()
{
    BgSkinPopup* skinPopup = new BgSkinPopup;
    skinPopup->move(QWidget::mapToGlobal(skinButton->geometry().bottomLeft()));
    skinPopup->show();
}
