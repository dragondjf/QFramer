#include "aboutpage.h"
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
    QGraphicsDropShadowEffect *shadow_effect1 = new QGraphicsDropShadowEffect(this);
    shadow_effect1->setOffset(-5, 5);
    shadow_effect1->setColor(Qt::darkGreen);
    shadow_effect1->setBlurRadius(8);

    QGraphicsDropShadowEffect *shadow_effect2 = new QGraphicsDropShadowEffect(this);
    shadow_effect2->setOffset(-5, 5);
    shadow_effect2->setColor(Qt::darkGreen);
    shadow_effect2->setBlurRadius(8);

    QGraphicsDropShadowEffect *shadow_effect3 = new QGraphicsDropShadowEffect(this);
    shadow_effect3->setOffset(-5, 5);
    shadow_effect3->setColor(Qt::darkGreen);
    shadow_effect3->setBlurRadius(8);

    QGraphicsDropShadowEffect *shadow_effect4 = new QGraphicsDropShadowEffect(this);
    shadow_effect4->setOffset(-5, 5);
    shadow_effect4->setColor(Qt::darkGreen);
    shadow_effect4->setBlurRadius(8);

    QGraphicsDropShadowEffect *shadow_effect5 = new QGraphicsDropShadowEffect(this);
    shadow_effect5->setOffset(-5, 5);
    shadow_effect5->setColor(Qt::darkGreen);
    shadow_effect5->setBlurRadius(8);

    QGraphicsDropShadowEffect *shadow_effect6 = new QGraphicsDropShadowEffect(this);
    shadow_effect6->setOffset(-5, 5);
    shadow_effect6->setColor(Qt::darkGreen);
    shadow_effect6->setBlurRadius(8);


    QLabel *logoLabel = new QLabel(tr("QFramer"));
    logoLabel->setObjectName(QString("logoLabel"));
    logoLabel->setGraphicsEffect(shadow_effect1);
    logoLabel->setAlignment(Qt::AlignLeft);

    QLabel *infoLabel = new QLabel(tr("Faster Easier Stronger Prettier"));
    infoLabel->setObjectName(QString("content"));
    infoLabel->setGraphicsEffect(shadow_effect2);
    infoLabel->setAlignment(Qt::AlignLeft);

    QLabel *authorLabel = new QLabel(tr("author:dragondjf"));
    authorLabel->setObjectName(QString("content"));
    authorLabel->setGraphicsEffect(shadow_effect3);
    authorLabel->setAlignment(Qt::AlignLeft);

    QLabel *versionLabel = new QLabel(tr("version:0.2.0.0"), this);
    versionLabel->setObjectName(QString("version"));
    versionLabel->setGraphicsEffect(shadow_effect4);
    versionLabel->setAlignment(Qt::AlignLeft);

    QLabel *lincenceLabel = new QLabel(tr("lincence: LGPL v2"), this);
    lincenceLabel->setObjectName(QString("content"));
    lincenceLabel->setGraphicsEffect(shadow_effect5);
    lincenceLabel->setAlignment(Qt::AlignLeft);


    QLabel *copyrightLabel = new QLabel(tr("Copyright 2012-2014 DJF. All rights reserved"), this);
    copyrightLabel->setObjectName(QString("version"));
    copyrightLabel->setGraphicsEffect(shadow_effect6);
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
