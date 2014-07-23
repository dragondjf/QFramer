#ifndef GRADIENTSHOW_H
#define GRADIENTSHOW_H

#include <QWidget>
#include <QPaintEvent>
#include <QLinearGradient>
#include <QRadialGradient>
#include <QConicalGradient>
#include <QMouseEvent>

class GradientShow : public QWidget
{
    Q_OBJECT
protected:
     void paintEvent(QPaintEvent *event);
     void mousePressEvent(QMouseEvent *event);
public:
    explicit GradientShow(QWidget *parent = 0);

signals:

public slots:
    void cloudAntimation();
};

#endif // GRADIENTSHOW_H
