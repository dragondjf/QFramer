#ifndef MATHPLOT_H
#define MATHPLOT_H

#include <QWidget>
#include"qcustomplot/fcustomplot.h"
class MathPlot : public QWidget
{
    Q_OBJECT
public:

public:
    explicit MathPlot(QWidget *parent = 0);
    void setupQuadraticDemo(QCustomPlot *customPlot);
    void setupSimpleDemo(QCustomPlot *customPlot);
    void setupSincScatterDemo(QCustomPlot *customPlot);
    void setupScatterStyleDemo(QCustomPlot *customPlot);
    void setupLineStyleDemo(QCustomPlot *customPlot);
    void setupScatterPixmapDemo(QCustomPlot *customPlot);
    void setupDateDemo(QCustomPlot *customPlot);
    void setupTextureBrushDemo(QCustomPlot *customPlot);
    void setupMultiAxisDemo(QCustomPlot *customPlot);
signals:

public slots:

};

#endif // MATHPLOT_H
