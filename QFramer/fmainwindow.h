#ifndef FMAINWINDOW_H
#define FMAINWINDOW_H

#include <QMainWindow>
#include<QStatusBar>
#include<QSystemTrayIcon>
#include<QCloseEvent>
#include"flywidget.h"
#include"ftitlebar.h"
#include"fcenterwindow.h"
enum enum_Direction{
    eLeft,
    eTop,
    eRight,
    eBottom,
    eNormal
};

class FMainWindow : public QMainWindow
{
    Q_OBJECT
private:
    QPoint dragPosition;
    bool leftbuttonpressed;
    bool lockmoved;
    bool locked;

    void readSettings();
    void writeSettings();

    FTitleBar * titleBar;
    QStatusBar *pstatusbar;
    QSystemTrayIcon *trayicon;
    FlyWidget* flyWidget;

protected:
    void mouseMoveEvent(QMouseEvent *e);
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
    void mouseDoubleClickEvent(QMouseEvent *e);
    void keyPressEvent(QKeyEvent *e);
    void closeEvent(QCloseEvent * event);
    void SetCursorStyle(enum_Direction i);

public:
    FMainWindow(QWidget *parent = 0);
    void initData();
    void initUI();
    void initConnect();
    FTitleBar* getTitleBar();
    QStatusBar* getStatusBar();
    QSystemTrayIcon* getQSystemTrayIcon();
    FlyWidget* getFlyWidget();
    void animationClose();
    bool isMoved();
    bool isLocked();
    ~FMainWindow();

signals:
    void Hidden();
public slots:
    void swithMaxNormal();
    void showFlyWidget();
    void onSystemTrayIconClicked(QSystemTrayIcon::ActivationReason reason);
    void setLockMoved(bool flag);
    void setLocked(bool flag);
};

#endif // MAINWINDOW_H
