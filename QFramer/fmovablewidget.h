#ifndef FMOVABLEWIDGET_H
#define FMOVABLEWIDGET_H

#include <QFrame>
#include<QMouseEvent>
class FMovableWidget : public QFrame
{
    Q_OBJECT
private:
    QPoint dragPosition;
    bool leftbuttonpressed;
protected:
    void mouseMoveEvent(QMouseEvent *e);
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);

public:
    explicit FMovableWidget(QWidget *parent = 0);

signals:

public slots:

};

#endif // FMOVABLEWIDGET_H
