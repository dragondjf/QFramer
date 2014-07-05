#ifndef CENTERWINDOW_H
#define CENTERWINDOW_H

#include"QFramer/fcenterwindow.h"
#include "functionpages/gradientshow.h"
#include "functionpages/webkitshow.h"
#include "functionpages/basequickwidget.h"
#include "functionpages/qmlviwer.h"
#include "functionpages/pdftool.h"
#include<QVBoxLayout>

class CenterWindow : public FCenterWindow
{
    Q_OBJECT

public:
    GradientShow* gradientShow;
    PDFTool* pdfTool;
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
