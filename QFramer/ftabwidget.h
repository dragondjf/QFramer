#ifndef FTABWIDGET_H
#define FTABWIDGET_H

#include <QWidget>
#include<QStackedLayout>
#include"fnavgationbar.h"
#include"QBoxLayout"

class FTabWidget : public QWidget
{
    Q_OBJECT
private:
    void initUI();
    void initConnect();
    void swicthLayout(QBoxLayout::Direction direction);

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
    QBoxLayout* mainLayout;
    QStackedLayout* stackLayout;
public:
    explicit FTabWidget(QWidget *parent = 0);
    void setAlignment(Alignment_Direction direction);
signals:

public slots:
    void addWidget(const QString &tile, const QString &objectName, QWidget *widget);
    void setCurrentIndex(int index);
};

#endif // FTABWIDGET_H
