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

#ifndef FLYWIDGET_H
#define FLYWIDGET_H

#include <QWidget>
#include <QPoint>
#include <QPixmap>
#include <QMenu>

class QMouseEvent;
class QPaintEvent;
class QEvent;

class FlyWidget : public QWidget
{
    Q_OBJECT
private:
    QWidget *m_parent;
    QPixmap m_Pixmap;
    QPoint  m_CurrentPos;
    QMenu   *settingmenu;

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseDoubleClickEvent(QMouseEvent * event);
    void paintEvent(QPaintEvent *event);
    void enterEvent(QEvent *event);
    void leaveEvent(QEvent *event);

public:
    explicit FlyWidget(QWidget *parent = 0);
    void initData();
    void initUI();
    void initConnect();
    void setMenu(QMenu* menu);
    QMenu* getMenu();

signals:

public slots:

};

#endif // FLYWIDGET_H
