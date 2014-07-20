#ifndef RIGHTFLOATWINDOW_H
#define RIGHTFLOATWINDOW_H

#include <QWidget>
#include <QResizeEvent>
#include <QShowEvent>
#include <QHideEvent>
#include "QFramer/fmovablewidget.h"
class RightFloatWindow : public FMovableWidget
{
    Q_OBJECT
private:
    int cwidth;
private:
    void initData();
    void initUI();
    void initConnect();
protected:
    void showEvent(QShowEvent * event);
    void mouseMoveEvent(QMouseEvent *event);
    void hideEvent(QHideEvent *event);
public:
    explicit RightFloatWindow(QWidget *parent = 0);

signals:

public slots:

}; 

#endif // RIGHTFLOATWINDOW_H
