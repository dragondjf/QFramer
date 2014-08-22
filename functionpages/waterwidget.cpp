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

#include "waterwidget.h"
#include <QPixmap>
#include <QBitmap>
#include <QPropertyAnimation>


WaterWidget::WaterWidget(QWidget *parent) :
    QLabel(parent)
{
    initData();
    initUI();
    initConnect();
}

void WaterWidget::initData()
{
//    ballpaths << QString(":/ball/skin/ball/white.png");
    ballpaths << QString(":/ball/skin/ball/green.png");
    ballpaths << QString(":/ball/skin/ball/red.png");
    ballpaths << QString(":/ball/skin/ball/blue.png");
    ballpaths << QString(":/ball/skin/ball/yellow.png");
    ballpaths << QString(":/ball/skin/ball/black.png");
    count = 0;
    animationFlag = true;
    durations << 1000 << 2000 << 3000 << 4000 << 5000;
    parallelAnimationGroup = new QParallelAnimationGroup;
    sequentialAnimationGroup = new QSequentialAnimationGroup;
}

void WaterWidget::initUI()
{
    QString style;
    style = "QLabel{\
                    background-color:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, \
                                                     stop:0 rgba(63, 120, 137, 255), \
                                                     stop:0.5 rgba(61, 235, 188, 255),\
                                                     stop:1 rgba(63, 120, 137, 255));\
                }";
    setStyleSheet(style);

    switchButton = new QPushButton(tr("sequential"), this);
    switchButton->setFixedSize(100, 60);

    for(int i=0; i<10 ; i++)
    {
        QLabel * ball = new QLabel(this);
        labels.append(ball);
        QPixmap m_Pixmap;
        m_Pixmap.load(ballpaths[i % 5]);
        m_Pixmap = m_Pixmap.scaled(m_Pixmap.size() / 3);
        ball->setPixmap(m_Pixmap);
        ball->resize(m_Pixmap.size());
        ball->setMask(m_Pixmap.mask());
        ball->move(i*60, 0);
    }
    initAnimations();
    parallelAnimationGroup->start();

}

void WaterWidget::initConnect()
{
    connect(parallelAnimationGroup, SIGNAL(finished()), this, SLOT(updateCount()));
    connect(sequentialAnimationGroup, SIGNAL(finished()), this, SLOT(updateCount()));
    connect(switchButton, SIGNAL(clicked()), this, SLOT(swicthAnimationType()));
}

void WaterWidget::updateCount()
{
    count = count + 1;

    if (animationFlag){
        foreach (QPropertyAnimation* animation, sequentialAnimations) {
            animation->setDuration(durations[qrand() % 5]);
            animation->setEasingCurve(static_cast<QEasingCurve::Type>(qrand() % 41));
        }
        sequentialAnimationGroup->start();

    }else{
        foreach (QPropertyAnimation* animation, parallelAnimations) {
            animation->setDuration(durations[qrand() % 5]);
            animation->setEasingCurve(static_cast<QEasingCurve::Type>(qrand() % 41));
        }
        parallelAnimationGroup->start();
    }
}

void WaterWidget::swicthAnimationType()
{
    if(animationFlag){
        switchButton->setText(tr("parallel"));
        sequentialAnimationGroup->stop();
        parallelAnimationGroup->start();
    }else{
        switchButton->setText(tr("sequential"));
        parallelAnimationGroup->stop();
        sequentialAnimationGroup->start();
    }
    animationFlag = not animationFlag;
}

void WaterWidget::initAnimations()
{
    for(int i=0; i<labels.length(); i++)
    {
        QPropertyAnimation* animation_pos = new QPropertyAnimation(labels[i], "pos");
        animation_pos->setDuration(durations[qrand() % 5]);
        animation_pos->setStartValue(QPoint(labels[i]->x(),0));
        animation_pos->setEndValue(QPoint(labels[i]->x(), 600));
        animation_pos->setEasingCurve(QEasingCurve::OutBounce);
        parallelAnimationGroup->addAnimation(animation_pos);
        parallelAnimations.append(animation_pos);
    }

    for(int i=0; i<labels.length(); i++)
    {
        QPropertyAnimation* animation_pos = new QPropertyAnimation(labels[i], "pos");
        animation_pos->setDuration(durations[qrand() % 5]);
        animation_pos->setStartValue(QPoint(labels[i]->x(),0));
        animation_pos->setEndValue(QPoint(labels[i]->x(), 600));
        animation_pos->setEasingCurve(QEasingCurve::OutBounce);
        sequentialAnimationGroup->addAnimation(animation_pos);
        sequentialAnimations.append(animation_pos);
    }
}
