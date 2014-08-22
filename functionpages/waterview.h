/****************************************************************************
**
** Copyright (C) 2014 dragondjf
**
** QFramer is a frame based on Qt5.3, you will be more efficient with it. 
** As an Qter, Qt give us a nice coding experience. With user interactive experience(UE) 
** become more and more important in modern software, deveployers should consider business and UE.
** So, QFramer is born. QFramer's goal is to be a mature solution 
** which you only need to be focus on your business but UE for all Qters.
**
** Version	: 0.2.5.0
** Author	: dragondjf
** Website	: https://github.com/dragondjf
** Project	: https://github.com/dragondjf/QCFramer
** Blog		: http://my.oschina.net/dragondjf/home/?ft=atme
** Wiki		: https://github.com/dragondjf/QCFramer/wiki
** Lincence: LGPL V2
** QQ: 465398889
** Email: dragondjf@gmail.com, ding465398889@163.com, 465398889@qq.com
** 
****************************************************************************/

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
