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

#ifndef WATERWIDGET_H
#define WATERWIDGET_H

#include <QLabel>
#include <QPropertyAnimation>
#include <QParallelAnimationGroup>
#include <QSequentialAnimationGroup>
#include <QPushButton>


class WaterWidget : public QLabel
{
    Q_OBJECT
private:
    QList<QLabel* > labels;
    QList<QPropertyAnimation *> parallelAnimations;
    QList<QPropertyAnimation *> sequentialAnimations;
    QStringList ballpaths;
    QParallelAnimationGroup *parallelAnimationGroup;
    QSequentialAnimationGroup *sequentialAnimationGroup;
    QList<int> durations;
    QPushButton* switchButton;
    int count;
    bool animationFlag;
private:
    void initData();
    void initUI();
    void initConnect();
    void initAnimations();

public:
    explicit WaterWidget(QWidget *parent = 0);

signals:

public slots:
    void updateCount();
    void swicthAnimationType();
};

#endif // WATERWIDGET_H
