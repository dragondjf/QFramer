#include "aboutpage.h"
#include "QFramer/fshadowlabel.h"
#include<QLabel>
#include<QVBoxLayout>
#include<QGraphicsDropShadowEffect>
#include<QLinearGradient>
#include<QPainter>
#include<QColor>
AboutPage::AboutPage(QWidget *parent) :
    QFrame(parent)
{
    initUI();
}

void AboutPage::initUI()
{

    FShadowLabel *logoLabel = new FShadowLabel(tr("QFramer"));
    logoLabel->setObjectName(QString("logoLabel"));
    logoLabel->setAlignment(Qt::AlignLeft);

    FShadowLabel *infoLabel = new FShadowLabel(tr("Faster Easier Stronger Prettier"));
    infoLabel->setObjectName(QString("content"));
    infoLabel->setAlignment(Qt::AlignLeft);

    FShadowLabel *authorLabel = new FShadowLabel(tr("author:dragondjf"));
    authorLabel->setObjectName(QString("content"));
    authorLabel->setAlignment(Qt::AlignLeft);

    FShadowLabel *versionLabel = new FShadowLabel(tr("version:0.2.0.0"), this);
    versionLabel->setObjectName(QString("version"));
    versionLabel->setAlignment(Qt::AlignLeft);

    FShadowLabel *lincenceLabel = new FShadowLabel(tr("lincence: LGPL v2"), this);
    lincenceLabel->setObjectName(QString("content"));
    lincenceLabel->setAlignment(Qt::AlignLeft);


    FShadowLabel *copyrightLabel = new FShadowLabel(tr("Copyright 2012-2014 DJF. All rights reserved"), this);
    copyrightLabel->setObjectName(QString("version"));
    copyrightLabel->setAlignment(Qt::AlignLeft);

    QHBoxLayout* versionLayout = new QHBoxLayout;
    versionLayout->addStretch();
    versionLayout->addWidget(versionLabel);
    versionLayout->addSpacing(20);

    QHBoxLayout* copyrightLayout = new QHBoxLayout;
    copyrightLayout->addStretch();
    copyrightLayout->addWidget(copyrightLabel);
    copyrightLayout->addSpacing(20);

    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout->addStretch();
    mainLayout->addWidget(logoLabel);
    mainLayout->addSpacing(10);
    mainLayout->addWidget(infoLabel);
    mainLayout->addSpacing(10);
    mainLayout->addWidget(lincenceLabel);
    mainLayout->addWidget(authorLabel);
    mainLayout->addStretch();
    mainLayout->addLayout(versionLayout);
    mainLayout->addLayout(copyrightLayout);
    mainLayout->addSpacing(10);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    setLayout(mainLayout);
}


void AboutPage::paintEvent(QPaintEvent *event)
{
//    QPainter painter(this);

//    QLinearGradient linearGrad1(geometry().topLeft(), geometry().bottomRight());
//    linearGrad1.setColorAt(0, QColor(33, 50, 70));
//    linearGrad1.setColorAt(0.5, Qt::white);
//    linearGrad1.setColorAt(1, QColor(33, 50, 70));
//    linearGrad1.setSpread(QGradient::PadSpread);
//    painter.fillRect(geometry(), linearGrad1);
}
