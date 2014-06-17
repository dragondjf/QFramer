#include<QPushButton>
#include "centerwindow.h"

CenterWindow::CenterWindow(QWidget *parent) :
    QWidget(parent)
{
    QPushButton *p = new QPushButton("1212121212", parent);
    p->move(100, 200);
    qDebug("init CenterWindow");
}
