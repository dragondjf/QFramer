#ifndef GRADIENTSHOW_H
#define GRADIENTSHOW_H

#include <QWidget>
#include <QPaintEvent>
#include <QLinearGradient>
#include <QRadialGradient>
#include <QConicalGradient>

class GradientShow : public QWidget
{
    Q_OBJECT
protected:
     void paintEvent(QPaintEvent *e);

public:
    explicit GradientShow(QWidget *parent = 0);

signals:

public slots:

};

#endif // GRADIENTSHOW_H
