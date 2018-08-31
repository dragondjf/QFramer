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

#ifndef FMAINWINDOW_H
#define FMAINWINDOW_H

#include <QMainWindow>
#include <QStatusBar>
#include <QSystemTrayIcon>
#include <QMenu>
#include "FlyWidget.h"
#include "FTitleBar.h"
#include "FThemeMenu.h"
#include "FSettingMenu.h"
#include "FCenterWindow.h"

class QPoint;
class QMouseEvent;
class QKeyEvent;
class QCloseEvent;

class FMainWindow : public QMainWindow
{
    Q_OBJECT
private:
    QPoint dragPosition;

    void initData();
    void initUI();
    void initConnect();
    void readSettings();
    void writeSettings();

    FlyWidget  *flyWidget;
    FTitleBar  *titleBar;
    FThemeMenu *themeMenu;
    FSettingMenu  *settingMenu;
    FCenterWindow *centerWindow;
    QStatusBar *pstatusbar;
    QSystemTrayIcon *trayicon;

protected:
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseDoubleClickEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void closeEvent(QCloseEvent * event);

public:
    FMainWindow(QWidget *parent = 0);
    ~FMainWindow();

    FTitleBar* getTitleBar();
    FlyWidget* getFlyWidget();
    FThemeMenu *getThemeMenu();
    FSettingMenu  *getSettingMenu();
    FCenterWindow* getCenterWindow();
    void setCenterWindow(FCenterWindow* center);
    QStatusBar* getStatusBar();
    QSystemTrayIcon* getQSystemTrayIcon();

    void setSystemIcon(const QString &icon_path);
    // 设置上下左右以及右上、右下、左上、坐下的鼠标形状
    enum CursorDirection {
        Left,
        Top,
        Right,
        Bottom,
        Normal
    };
    void setCursorStyle(CursorDirection direction);

signals:
    void Hidden();
public slots:
    void animationClose();
    void swithMaxNormal();
    void showFlyWidget();
    void onSystemTrayIconClicked(QSystemTrayIcon::ActivationReason reason);
};

#endif // MAINWINDOW_H
