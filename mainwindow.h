#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QStatusBar>
#include<QSystemTrayIcon>
#include<QCloseEvent>
#include "centerwindow.h"
#include"flywidget.h"
enum enum_Direction{
    eLeft,
    eTop,
    eRight,
    eBottom,
    eNormal
};

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    QPoint dragPosition;
    bool leftbuttonpressed;
    FlyWidget* flyWidget;

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
    CenterWindow *centerwindow;
    QStatusBar *pstatusbar;
    QSystemTrayIcon *trayicon;
    static MainWindow* instance;

    MainWindow(QWidget *parent = 0);
    void initData();
    void initUI();
    void initConnect();
    static MainWindow* getInstance();
    ~MainWindow();

public slots:
    void swithMaxNormal();
    void showFlyWidget();
    void onSystemTrayIconClicked(QSystemTrayIcon::ActivationReason reason);
};

#endif // MAINWINDOW_H
