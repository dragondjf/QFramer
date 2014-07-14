#include "aboutpage.h"
#include<QLabel>
#include<QVBoxLayout>
#include<QGraphicsDropShadowEffect>
AboutPage::AboutPage(QWidget *parent) :
    QWidget(parent)
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

    QHBoxLayout* versionLayout = new QHBoxLayout;
    versionLayout->addStretch();
    versionLayout->addWidget(versionLabel);
    versionLayout->addSpacing(20);


    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout->addStretch();
    mainLayout->addWidget(logoLabel);
    mainLayout->addSpacing(10);
    mainLayout->addWidget(infoLabel);
    mainLayout->addSpacing(30);
    mainLayout->addWidget(authorLabel);
    mainLayout->addStretch();
    mainLayout->addLayout(versionLayout);
    mainLayout->addSpacing(10);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    setLayout(mainLayout);
}
