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

#include "aboutdialog.h"
#include "QFramer/fbasepushbutton.h"
#include "QFramer/fshadowlabel.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QTextEdit>
#include <QGraphicsDropShadowEffect>
#include <QPropertyAnimation>
#include <QEasingCurve>
#include <QDesktopWidget>
#include <QApplication>


AboutDialog::AboutDialog(QWidget *parent) :
    FBaseDialog(parent)
{
    initUI();
    initConnect();
}

void AboutDialog::initUI()
{
    normalSize = QSize(400, 300);

    FShadowLabel *logoLabel = new FShadowLabel(tr("QFramer"));
    logoLabel->setObjectName(QString("logoLabel"));

    FShadowLabel *infoLabel = new FShadowLabel(tr("Faster Easier Stronger Prettier"));
    infoLabel->setObjectName(QString("content"));

    FShadowLabel *lincenceLabel = new FShadowLabel(tr("lincence: LGPL v3"), this);
    lincenceLabel->setObjectName(QString("content"));

    FShadowLabel *authorLabel = new FShadowLabel(tr("author:dragondjf"));
    authorLabel->setObjectName(QString("content"));


    FShadowLabel *versionLabel = new FShadowLabel(tr("version:0.2.5.0"));
    versionLabel->setObjectName(QString("content"));


    enterButton = new FBasePushButton();
    enterButton->setText(tr("Close"));
    QHBoxLayout* controlLayout = new QHBoxLayout;
    controlLayout->addStretch();
    controlLayout->addWidget(enterButton);
    controlLayout->addSpacing(10);

    QVBoxLayout* mainLayout = (QVBoxLayout*)layout();
    mainLayout->addSpacing(20);
    mainLayout->addWidget(logoLabel);
    mainLayout->addWidget(infoLabel);
    mainLayout->addSpacing(30);
    mainLayout->addWidget(lincenceLabel);
    mainLayout->addWidget(authorLabel);
    mainLayout->addWidget(versionLabel);
    mainLayout->addSpacing(10);
    mainLayout->addLayout(controlLayout);
    mainLayout->addSpacing(10);



}

void AboutDialog::initConnect()
{
//    BaseDialog::initConnect();
    connect(enterButton, SIGNAL(clicked()), this, SLOT(animationClose()));
}

void AboutDialog::showEvent(QShowEvent *event)
{
    QPropertyAnimation *animation = new QPropertyAnimation(this, "geometry");

    QDesktopWidget* desktopWidget = QApplication::desktop();
    int x = (desktopWidget->availableGeometry().width() - normalSize.width()) / 2;
    int y = (desktopWidget->availableGeometry().height() - normalSize.height()) / 2;

    connect(animation, SIGNAL(finished()), animation, SLOT(deleteLater()));
    animation->setDuration(1500);
    animation->setStartValue(QRect(x, 0, normalSize.width(), normalSize.height()));
    animation->setEndValue(QRect(x, y, normalSize.width(), normalSize.height()));
    animation->setEasingCurve(QEasingCurve::OutElastic);
    animation->start();
    QDialog::showEvent(event);
}

void AboutDialog::animationClose()
{
    QPropertyAnimation *animation = new QPropertyAnimation(this, "windowOpacity");
    connect(animation, SIGNAL(finished()), this, SLOT(deleteLater()));
    connect(animation, SIGNAL(finished()), this, SLOT(close()));
    animation->setDuration(1500);
    animation->setStartValue(1);
    animation->setEndValue(0);
    animation->start();
}
