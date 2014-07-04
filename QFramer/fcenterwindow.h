#ifndef FCENTERWINDOW_H
#define FCENTERWINDOW_H

#include <QFrame>
#include<QWidget>
#include<QStackedWidget>
#include<QResizeEvent>
<<<<<<< HEAD:QFramer/fcenterwindow.h
#include "fnavgationbar.h"
#include"ftitlebar.h"
=======
#include "QFramer/fnavgationbar.h"


>>>>>>> 93f3b82cf553ccbd90eec91b9860c38978134633:QFramer/fcenterwindow.h
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
<<<<<<< HEAD:QFramer/fcenterwindow.h

    QVBoxLayout* mainLayout;
=======
    QVBoxLayout* mainlayout;
>>>>>>> 93f3b82cf553ccbd90eec91b9860c38978134633:QFramer/fcenterwindow.h
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
