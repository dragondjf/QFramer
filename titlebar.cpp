#include "titlebar.h"
#include<QHBoxLayout>
#include<QLabel>

TitleBar::TitleBar(QWidget *parent)
{
    setFixedHeight(30);
    setObjectName(QString("TitleBar"));
    settingsIcon =  QIcon(QString(":/skin/icons/dark/appbar.control.down.png"));
    skinIcon =  QIcon(QString(":/skin/icons/dark/appbar.clothes.shirt.png"));
    minIcon =  QIcon(QString(":/skin/icons/dark/appbar.minus.png"));
    maxIcon =  QIcon(QString(":/skin/icons/dark/appbar.fullscreen.box.png"));
    normalIcon =  QIcon(QString(":/skin/icons/dark/appbar.app.png"));
    closeIcon =  QIcon(QString(":/skin/icons/dark/appbar.close.png"));
    titleLabel = new QLabel;
    settingButton = new QToolButton;
    skinButton = new QToolButton;
    minButton = new QToolButton;
    maxButton = new QToolButton;
    closeButton = new QToolButton;

    titleLabel->setText(QString("QFramer"));
    titleLabel->setObjectName(QString("TitleLabel"));
    settingButton->setIcon(settingsIcon);
    settingButton->setIconSize(QSize(20, 20));
    skinButton->setIcon(skinIcon);
    skinButton->setIconSize(QSize(20, 20));
    minButton->setIcon(minIcon);
    minButton->setIconSize(QSize(20, 20));
    maxButton->setIcon(maxIcon);
    maxButton->setIconSize(QSize(20, 20));
    closeButton->setIcon(closeIcon);
    closeButton->setIconSize(QSize(20, 20));
    QHBoxLayout* mainlayout = new QHBoxLayout;
    mainlayout->addWidget(titleLabel);
    mainlayout->addStretch();
    mainlayout->addWidget(settingButton);
    mainlayout->addWidget(skinButton);
    mainlayout->addWidget(minButton);
    mainlayout->addWidget(normalButton);
    mainlayout->addWidget(closeButton);
    mainlayout->setContentsMargins(0, 0, 5, 0);
    mainlayout->setSpacing(0);
    setLayout(mainlayout);


}
