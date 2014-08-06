#include "waterwidget.h"

WaterWidget::WaterWidget(QWidget *parent) :
    QLabel(parent)
{
    initData();
    initUI();
    initConnect();
}

void WaterWidget::initData()
{

}

void WaterWidget::initUI()
{
    QString style;
    style = "QLabel{\
                    background-color:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, \
                                                     stop:0 rgba(63, 120, 137, 255), \
                                                     stop:0.5 rgba(61, 235, 188, 255),\
                                                     stop:1 rgba(63, 120, 137, 255));\
                }";
    setStyleSheet(style);
}

void WaterWidget::initConnect()\
{

}
