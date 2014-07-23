#ifndef CENTERWINDOW_H
#define CENTERWINDOW_H

#include"QFramer/fcenterwindow.h"
#include "functionpages/aboutpage.h"
#include "functionpages/mathplot.h"
#include"functionpages/uielement.h"
#include"functionpages/audiorecord/wavrecordmanager.h"
#include<QVBoxLayout>

class CenterWindow : public FCenterWindow
{
    Q_OBJECT

public:
    UIElement* uiElements;
    MathPlot* mathPlot;
    WavRecordManager* recordManger;
    AboutPage* aboutPage;

    static CenterWindow* instance;

public:
    explicit CenterWindow(QWidget *parent = 0);
    void initUI();
    static CenterWindow* getInstance();
    void addWiggleWiget();
signals:

public slots:
//    void cloudAntimation();
};

#endif // CENTERWINDOW_H
