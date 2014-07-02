#ifndef FCENTERWINDOW_H
#define FCENTERWINDOW_H

#include <QFrame>
#include<QWidget>
#include<QStackedWidget>
#include "fnavgationbar.h"
#include "ftitlebar.h"

class FCenterWindow : public QFrame
{
    Q_OBJECT
public:
    FTitleBar* titleBar;
    FNavgationBar* navagationBar;
    QStackedWidget* stackWidget;
    int currentIndex;
public:
    explicit FCenterWindow(QWidget *parent = 0);
    void initData();
    void initUI();
    void initConnect();
    void addWidget(const QString& tile, QWidget* widget);
signals:

public slots:
    void switchscreen(const int index);
    void switchscreen();
    virtual void cloudAntimation(const int index);
};

#endif // FCENTERWINDOW_H
