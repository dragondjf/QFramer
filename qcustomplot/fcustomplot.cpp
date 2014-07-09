#include "fcustomplot.h"
#include <QLinearGradient>
FCustomPlot::FCustomPlot(QWidget *parent) :
    QCustomPlot(parent)
{
    QLinearGradient linearGrad1(QPointF(0, 0), QPointF(200, 200));
    linearGrad1.setColorAt(0, QColor(33, 50, 70));
    linearGrad1.setColorAt(1, QColor(255, 255, 255));
    linearGrad1.setSpread(QGradient::PadSpread);
    setBackground(QBrush(linearGrad1));
}
