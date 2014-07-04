#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include"QFramer/fmainwindow.h"
#include"centerwindow.h"
#include"settingmenu.h"
class MainWindow : public FMainWindow
{
    Q_OBJECT
public:
    static MainWindow* instance;
    CenterWindow* centerWindow;
    SettingMenu* settingmenu;
public:
    explicit MainWindow(QWidget *parent = 0);
    void initUI();
    static MainWindow* getInstance();
signals:

public slots:

};

#endif // MAINWINDOW_H
