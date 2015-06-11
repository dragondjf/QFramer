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

#include "animationgradientlabel.h"


AnimationGradientLabel::AnimationGradientLabel(QWidget *parent) :
    QLabel(parent)
{
    startTimer(1000);
}

void AnimationGradientLabel::initData()
{

}

void AnimationGradientLabel::initUI()
{

}

void AnimationGradientLabel::initConnect()
{

}

void AnimationGradientLabel::timerEvent(QTimerEvent *event)
{
    Q_UNUSED(event)
    QString style;
    QString pos;
    QString startColor;
    QString middleColor;
    QString stopColor;
    pos = QString("x1:%1, y1:%2, x2:%3, y2:%4");
    pos = pos.arg(QString::number((qrand() % 2)), QString::number((qrand() % 2)), QString::number((qrand() % 2)), QString::number((qrand() % 2)));
    startColor = QString("0 rgba(%1, %2, %3, %4)");
    startColor = startColor.arg(QString::number(qrand() % 256), QString::number(qrand() % 256), QString::number(qrand() % 256), QString::number(qrand() % 256));

    middleColor = QString("0.5 rgba(%1, %2, %3, %4)");
    middleColor = middleColor.arg(QString::number(qrand() % 256), QString::number(qrand() % 256), QString::number(qrand() % 256), QString::number(qrand() % 256));

    stopColor = QString("1 rgba(%1, %2, %3, %4)");
    stopColor = stopColor.arg(QString::number(qrand() % 256), QString::number(qrand() % 256), QString::number(qrand() % 256), QString::number(qrand() % 256));


    style = QString("QLabel{\
                    background-color:qlineargradient(spread:pad, %1 ,\
                                                     stop: %2,\
                                                     stop: %3,\
                                                     stop: %4);\
                }");

    style = style.arg(pos, startColor, middleColor, stopColor);
    setStyleSheet(style);
}
