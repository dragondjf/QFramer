#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QStatusBar>
#include "centerwindow.h"

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

    void mouseMoveEvent(QMouseEvent *e);
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
    void mouseDoubleClickEvent(QMouseEvent *e);
    void keyPressEvent(QKeyEvent *e);
    void SetCursorStyle(enum_Direction i);
public:
    CenterWindow *c;
    QStatusBar *pstatusbar;

    MainWindow(QWidget *parent = 0);
    void initData();
    void initUI();
    void initConnect();
    ~MainWindow();

public slots:
    void swithMaxNormal();
};

#endif // MAINWINDOW_H
