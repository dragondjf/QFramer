#include "fbasepushbutton.h"
#include<QGraphicsDropShadowEffect>
FBasePushButton::FBasePushButton(QWidget *parent) :
    QPushButton(parent)
{
    setFixedSize(60, 30);
    QGraphicsDropShadowEffect *shadow_effect = new QGraphicsDropShadowEffect(this);
    shadow_effect->setOffset(-5, 5);
    shadow_effect->setColor(Qt::gray);
    shadow_effect->setBlurRadius(8);
    setGraphicsEffect(shadow_effect);
}
