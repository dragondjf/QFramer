#include "fcustomplot.h"
#include <QLinearGradient>
FCustomPlot::FCustomPlot(QWidget *parent) :
    QCustomPlot(parent)
{
    QLinearGradient linearGrad1(QPointF(0, 0), QPointF(200, 200));
    linearGrad1.setColorAt(0, Qt::white);
    linearGrad1.setColorAt(0.5, Qt::green);
    linearGrad1.setColorAt(1, Qt::yellow);
    linearGrad1.setSpread(QGradient::PadSpread);
    setBackground(QBrush(linearGrad1));
}
