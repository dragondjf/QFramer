#ifndef WATERVIEW_H
#define WATERVIEW_H

#include <QGraphicsView>
#include <QResizeEvent>
#include <QGraphicsItem>
#include <QGraphicsEllipseItem>
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QWidget>


class FGraphicsEllipseItem: public QGraphicsEllipseItem, QObject
{
public:
    explicit FGraphicsEllipseItem(QGraphicsItem *parent = 0);
    explicit FGraphicsEllipseItem(const QRectF &rect, QGraphicsItem *parent = 0);
    explicit FGraphicsEllipseItem(qreal x, qreal y, qreal w, qreal h, QGraphicsItem *parent = 0);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};


class FGraphicsPixmapItem: public QGraphicsPixmapItem, QObject
{
public:
    explicit FGraphicsPixmapItem(QGraphicsItem *parent = 0);
    explicit FGraphicsPixmapItem(const QPixmap &pixmap, QGraphicsItem *parent = 0);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};


class WaterView : public QGraphicsView
{
    Q_OBJECT
private:
    void initData();
    void initUI();
    void initConnect();
protected:
    void resizeEvent(QResizeEvent * event);
public:
    explicit WaterView(QWidget *parent = 0);

signals:

public slots:

};

#endif // WATERVIEW_H
