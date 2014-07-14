#include "aboutdialog.h"
#include"QFramer/fbasepushbutton.h"
#include<QVBoxLayout>
#include<QLabel>
#include<QPushButton>
#include<QTextEdit>
#include<QGraphicsDropShadowEffect>
#include<QPropertyAnimation>
AboutDialog::AboutDialog(QWidget *parent) :
    FBaseDialog(parent)
{
    initUI();
    initConnect();
}

void AboutDialog::initUI()
{
    normalSize = QSize(400, 300);

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


    QLabel *logoLabel = new QLabel(tr("    QFramer"));
    logoLabel->setObjectName(QString("logoLabel"));
    logoLabel->setGraphicsEffect(shadow_effect1);

    QLabel *infoLabel = new QLabel(tr("            Faster Easier Stronger Prettier"));
    infoLabel->setObjectName(QString("content"));
    infoLabel->setGraphicsEffect(shadow_effect2);

    QLabel *authorLabel = new QLabel(tr("     author:dragondjf"));
    authorLabel->setObjectName(QString("content"));
    authorLabel->setGraphicsEffect(shadow_effect3);


    QLabel *versionLabel = new QLabel(tr("     version:0.2.0.0"));
    versionLabel->setObjectName(QString("content"));
    versionLabel->setGraphicsEffect(shadow_effect4);


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
    mainLayout->addWidget(authorLabel);
    mainLayout->addWidget(versionLabel);
    mainLayout->addSpacing(10);
    mainLayout->addLayout(controlLayout);
    mainLayout->addSpacing(10);



}

void AboutDialog::initConnect()
{
//    BaseDialog::initConnect();
    connect(enterButton, &QPushButton::clicked, this, &AboutDialog::animationClose);
}


void AboutDialog::animationClose()
{
    QPropertyAnimation *animation = new QPropertyAnimation(this, "windowOpacity");
    connect(animation, &QPropertyAnimation::finished, this, &AboutDialog::close);
    animation->setDuration(1500);
    animation->setStartValue(1);
    animation->setEndValue(0);
    animation->start();
}
