#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include"fmainwindow.h"
#include"centerwindow.h"

class MainWindow : public FMainWindow
{
    Q_OBJECT
public:
    static MainWindow* instance;
    CenterWindow* centerWindow;
public:
    explicit MainWindow(QWidget *parent = 0);
    void initUI();
    static MainWindow* getInstance();
signals:

public slots:

};

#endif // MAINWINDOW_H
