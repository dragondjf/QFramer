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
