#ifndef FCENTERWINDOW_H
#define FCENTERWINDOW_H

#include <QFrame>
#include<QWidget>
#include<QStackedWidget>
#include<QResizeEvent>
#include<QPixmap>
#include "fnavgationbar.h"

class FCenterWindow : public QFrame
{
    Q_OBJECT
private:
    FNavgationBar* navagationBar;
    QStackedWidget* stackWidget;
    QBoxLayout* navlayout;
    QVBoxLayout* mainLayout;
    int currentIndex;
    int preindex;
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

    enum animation_Direction{
        animationTop,
        animationRight,
        animationBottom,
        animationLeft,
        animationTopLeft,
        animationTopRight,
        animationBottomRight,
        animationBottomLeft,
        animationCenter
    };

public:
    explicit FCenterWindow(QWidget *parent = 0);
    void initData();
    void initUI();
    void initConnect();
    void addWidget(const QString& tile, const QString &obejctName, QWidget* widget);
    void setAlignment(Alignment_Direction direction);
    FNavgationBar* getNavgationBar();
signals:

public slots:
    void switchscreen(const int index);
    void switchscreen();
    void swicthLayout(QBoxLayout::Direction direction);
    virtual void cloudAntimation(animation_Direction direction);
};

#endif // FCENTERWINDOW_H
