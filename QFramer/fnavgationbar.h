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

#ifndef FNAVGATIONBAR_H
#define FNAVGATIONBAR_H

#include <QFrame>
#include<QList>
#include<QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "fcheckablebutton.h"


class FNavgationBar : public QFrame
{
    Q_OBJECT
private:
    QHBoxLayout* mainlayout_topLeft;
    QHBoxLayout* mainlayout_topCenter;
    QHBoxLayout* mainlayout_topRight;
    QHBoxLayout* mainlayout_bottomLeft;
    QHBoxLayout* mainlayout_bottomCenter;
    QHBoxLayout* mainlayout_bottomRight;
    QVBoxLayout* mainlayout_leftTop;
    QVBoxLayout* mainlayout_leftCenter;
    QVBoxLayout* mainlayout_leftBottom;
    QVBoxLayout* mainlayout_rightTop;
    QVBoxLayout* mainlayout_rightCenter;
    QVBoxLayout* mainlayout_rightBottom;
    int cIndex;
public:

    QList<FCheckabelButton*> buttons;
    QList<QString> buttonTitles;
public:
    explicit FNavgationBar(QWidget *parent = 0);
    void initData();
    void initConnect();
    void initUI();
    int currentIndex();
    int count();
    void setCurrentIndex(int index);
    void addNavgationTile(const QString& tile, const QString &objectName);
    void setAlignment_topLeft();
    void setAlignment_topCenter();
    void setAlignment_topRight();
    void setAlignment_bottomLeft();
    void setAlignment_bottomCenter();
    void setAlignment_bottomRight();
    void setAlignment_leftTop();
    void setAlignment_leftCenter();
    void setAlignment_leftBottom();
    void setAlignment_rightTop();
    void setAlignment_rightCenter();
    void setAlignment_rightBottom();
signals:
    void indexChanged(int i);
private slots:
    void setButtonChecked();

};

#endif // FNAVGATIONBAR_H
