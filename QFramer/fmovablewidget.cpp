#include "fmovablewidget.h"

FMovableWidget::FMovableWidget(QWidget *parent) :
    QFrame(parent)
{
}


void FMovableWidget::mousePressEvent(QMouseEvent *e)
{
    if(e->button() & Qt::LeftButton)
    {
            dragPosition = e->globalPos() - frameGeometry().topLeft();
            leftbuttonpressed = true;
    }
    e->accept();
}


void FMovableWidget::mouseReleaseEvent(QMouseEvent *e)
{
    leftbuttonpressed = false;
    e->accept();
}

void FMovableWidget::mouseMoveEvent(QMouseEvent *e)
{
    if(leftbuttonpressed)
    {
        move(e->globalPos() - dragPosition);
    }
    e->accept();
}
