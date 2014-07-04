#ifndef FCENTERWINDOW_H
#define FCENTERWINDOW_H

#include <QFrame>
#include<QWidget>
#include<QStackedWidget>
#include<QResizeEvent>
#include "fnavgationbar.h"
#include"ftitlebar.h"
class FCenterWindow : public QFrame
{
    Q_OBJECT

public:
    enum Alignment_Direction{
        TopLeft,
        TopCenter,
        TopRight,
        RightTop,
        RightCenter,
        RightBottom,
        BottomRight,
        BottomCenter,
        BottomLeft,
        LeftBottom,
        LeftCenter,
        LeftTop,
    };

    FNavgationBar* navagationBar;
    QStackedWidget* stackWidget;
    QBoxLayout* navlayout;
    QVBoxLayout* mainLayout;
    int currentIndex;
public:
    explicit FCenterWindow(QWidget *parent = 0);
    void initData();
    void initUI();
    void initConnect();
    void setTitleBar(FTitleBar* ftitleBar);
    void addWidget(const QString& tile, QWidget* widget);
    void setAlignment(Alignment_Direction direction);
signals:

public slots:
    void switchscreen(const int index);
    void switchscreen();
    void swicthLayout(QBoxLayout::Direction direction);
    virtual void cloudAntimation(const int index);
};

#endif // FCENTERWINDOW_H
