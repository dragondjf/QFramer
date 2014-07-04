#ifndef CENTERWINDOW_H
#define CENTERWINDOW_H

#include"QFramer/fcenterwindow.h"
#include"titlebar.h"
#include "gradientshow.h"
#include "webkitshow.h"
#include "basequickwidget.h"
#include "qmlviwer.h"
#include<QVBoxLayout>

class CenterWindow : public FCenterWindow
{
    Q_OBJECT

public:
    TitleBar* titleBar;
    GradientShow* gradientShow;
    WebkitShow *webkitShow;
    BaseQuickWidget* qmlViwer2;
    QmlViwer* qmlViwer3;
    BaseQuickWidget* qmlViwer4;
    BaseQuickWidget* qmlViwer5;

    static CenterWindow* instance;

public:
    explicit CenterWindow(QWidget *parent = 0);
    void initUI();
    static CenterWindow* getInstance();
signals:

public slots:
    void cloudAntimation(const int index);
};

#endif // CENTERWINDOW_H
