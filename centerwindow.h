#ifndef CENTERWINDOW_H
#define CENTERWINDOW_H

#include"fcenterwindow.h"
#include "gradientshow.h"
#include "webkitshow.h"
#include "basequickwidget.h"
#include "qmlviwer.h"

class CenterWindow : public FCenterWindow
{
    Q_OBJECT

public:
    GradientShow* gradientShow;
    WebkitShow *webkitShow;
    BaseQuickWidget* qmlViwer2;
    QmlViwer* qmlViwer3;
    BaseQuickWidget* qmlViwer4;
    BaseQuickWidget* qmlViwer5;

public:
    explicit CenterWindow(QWidget *parent = 0);
    void initUI();
signals:

public slots:
    void cloudAntimation(const int index);
};

#endif // CENTERWINDOW_H
