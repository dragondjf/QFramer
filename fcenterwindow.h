#ifndef FCENTERWINDOW_H
#define FCENTERWINDOW_H

#include <QFrame>
#include<QWidget>
#include<QStackedWidget>
#include "fnavgationbar.h"
#include "titlebar.h"

enum Layout_Direction{
    Left,
    Top,
    Right,
    Bottom
};

class FCenterWindow : public QFrame
{
    Q_OBJECT
public:
    TitleBar* titleBar;
    FNavgationBar* navagationBar;
    QStackedWidget* stackWidget;
    QBoxLayout* navlayout;
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
    void swicthLayout(QBoxLayout::Direction direction);
    virtual void cloudAntimation(const int index);
};

#endif // FCENTERWINDOW_H
