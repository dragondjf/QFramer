#ifndef FLYWIDGET_H
#define FLYWIDGET_H

#include <QWidget>
#include<QPixmap>
#include<QMouseEvent>
#include<QPainter>
<<<<<<< HEAD
#include<QMenu>
=======
#include"settingmenu.h"
>>>>>>> 93f3b82cf553ccbd90eec91b9860c38978134633

class FlyWidget : public QWidget
{
    Q_OBJECT
private:
    QWidget* p;

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseDoubleClickEvent(QMouseEvent * event);
    void paintEvent(QPaintEvent *event);
    void enterEvent(QEvent *event);
    void leaveEvent(QEvent *event);

private:
    QPoint m_CurrentPos;
    QPixmap m_Pixmap;
public:
<<<<<<< HEAD
    QMenu* settingmenu;

=======
    SettingMenu* menu;
>>>>>>> 93f3b82cf553ccbd90eec91b9860c38978134633
public:
    explicit FlyWidget(QWidget *parent = 0);
    void initData();
    void initUI();
    void initConnect();
    void setMenu(QMenu* menu);
signals:

public slots:

};

#endif // FLYWIDGET_H
