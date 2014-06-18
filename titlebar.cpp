#include "titlebar.h"
#include<QHBoxLayout>
#include<QLabel>
TitleBar::TitleBar(QWidget *parent)
{
    setFixedHeight(Title_Height);
    setObjectName(QString("TitleBar"));
    logoIcon = QIcon(QString(":/skin/images/QFramer.png"));
    settingsIcon =  QIcon(QString(":/skin/icons/dark/appbar.control.down.png"));
    skinIcon =  QIcon(QString(":/skin/icons/dark/appbar.clothes.shirt.png"));
    minIcon =  QIcon(QString(":/skin/icons/dark/appbar.minus.png"));
    maxIcon =  QIcon(QString(":/skin/icons/dark/appbar.fullscreen.box.png"));
    normalIcon =  QIcon(QString(":/skin/icons/dark/appbar.app.png"));
    closeIcon =  QIcon(QString(":/skin/icons/dark/appbar.close.png"));
    titleLabel = new QLabel;
    logoButton = new QToolButton;
    settingButton = new QToolButton;
    skinButton = new QToolButton;
    minButton = new QToolButton;
    maxButton = new QToolButton;
    closeButton = new QToolButton;
    normal_max_flag = true;

    logoButton->setIcon(logoIcon);
    logoButton->setIconSize(QSize(Title_Height, Title_Height));
    logoButton->setObjectName(QString("logo"));
    titleLabel->setText(tr("QFramer"));
    titleLabel->setObjectName(QString("TitleLabel"));
    settingButton->setIcon(settingsIcon);
    settingButton->setIconSize(QSize(Title_Height, Title_Height));
    skinButton->setIcon(skinIcon);
    skinButton->setIconSize(QSize(Title_Height, Title_Height));
    minButton->setIcon(minIcon);
    minButton->setIconSize(QSize(Title_Height, Title_Height));
    maxButton->setIcon(normalIcon);
    maxButton->setIconSize(QSize(Title_Height, Title_Height));
    closeButton->setIcon(closeIcon);
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

    connect(maxButton, SIGNAL(clicked()), this, SIGNAL(maximumed()));
    connect(minButton, SIGNAL(clicked()), this, SIGNAL(minimuned()));
    connect(closeButton, SIGNAL(clicked()), this, SIGNAL(closed()));
    connect(maxButton, SIGNAL(clicked()), this, SLOT(switchMaxMin()));
}

void TitleBar::switchMaxMin()
{
    if(normal_max_flag)
    {
        maxButton->setIcon(maxIcon);
        normal_max_flag = false;
    }
    else{
        maxButton->setIcon(normalIcon);
        normal_max_flag = true;
    }
}
