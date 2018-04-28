/****************************************************************************
**
** Copyright (C) 2014 dragondjf
**
** QFramer is a frame based on Qt5.3, you will be more efficient with it.
** As an Qter, Qt give us a nice coding experience. With user interactive experience(UE)
** become more and more important in modern software, deveployers should consider business and UE.
** So, QFramer is born. QFramer's goal is to be a mature solution
** which you only need to be focus on your business but UE for all Qters.
**
** Version	: 0.2.5.0
** Author	: dragondjf
** Website	: https://github.com/dragondjf
** Project	: https://github.com/dragondjf/QCFramer
** Blog		: http://my.oschina.net/dragondjf/home/?ft=atme
** Wiki		: https://github.com/dragondjf/QCFramer/wiki
** Lincence: LGPL V2
** QQ: 465398889
** Email: dragondjf@gmail.com, ding465398889@163.com, 465398889@qq.com
**
****************************************************************************/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "QFramer/fmainwindow.h"
#include "functionpages/rightfloatwindow.h"
#include <QResizeEvent>
#include <QMouseEvent>
#include <QHideEvent>

#include "settingmenu.h"
#include "functionpages/aboutpage.h"
#include "functionpages/mathplot.h"
#include "functionpages/uielement.h"
#include "functionpages/qssbuilder.h"

class MainWindow : public FMainWindow
{
    Q_OBJECT
private:
    SettingMenu *settingMenu;

    UIElement* uiElements;
    MathPlot* mathPlot;
    AboutPage* aboutPage;
    QssBuilder* qssBuilder;
    RightFloatWindow* rightfloatWindow;

    void initData();
    void initUI();
    void initConnect();
protected:
    void mouseMoveEvent(QMouseEvent *event);
    void resizeEvent(QResizeEvent * event);
    void hideEvent(QHideEvent * event);
    void showEvent(QShowEvent * event);
    void mouseDoubleClickEvent(QMouseEvent *event);
public:
public:
    static MainWindow* instance;
    static MainWindow* getInstance();
    explicit MainWindow(QWidget *parent = 0);

    void addWiggleWiget();

    SettingMenu* getSettingMenu();
    RightFloatWindow* getRightFloatWindow();
signals:

public slots:

};

#endif // MAINWINDOW_H
