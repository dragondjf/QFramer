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

    void readSettings();
    void writeSettings();

protected:
    void mouseMoveEvent(QMouseEvent *e);
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
    void mouseDoubleClickEvent(QMouseEvent *e);
    void keyPressEvent(QKeyEvent *e);
    void closeEvent(QCloseEvent * event);
    void SetCursorStyle(enum_Direction i);
public:
    FTitleBar * titleBar;
    QStatusBar *pstatusbar;
    QSystemTrayIcon *trayicon;
    FlyWidget* flyWidget;

public:
    FMainWindow(QWidget *parent = 0);
    void initData();
    void initUI();
    void initConnect();
//    void getTitleBar();
//    void setAlignment(FCenterWindow::Alignment_Direction direction);
    ~FMainWindow();

public slots:
    void swithMaxNormal();
    void showFlyWidget();
    void onSystemTrayIconClicked(QSystemTrayIcon::ActivationReason reason);
};

#endif // MAINWINDOW_H
