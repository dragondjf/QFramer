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
#include <QWidget>
#include <QList>
#include "FCheckableButton.h"


class FNavgationBar : public QFrame
{
    Q_OBJECT
private:
    int m_index;
    QList<QString> buttonTitles;
    QList<FCheckabelButton*> buttons;

    void initData();
    void initConnect();
    void initUI();

public:
    enum AlignmentDirection{
        TopLeft,
        TopCenter,
        TopRight,
        RightTop,
        RightCenter,
        RightBottom,
        BottomRight,
        BottomCenter,
        BottomLeft,
        LeftBottom,
        LeftCenter,
        LeftTop,
    };

    explicit FNavgationBar(QWidget *parent = 0);

    int  count();
    int  currentIndex();
    void setCurrentIndex(int index);
    void addNavgationTile(const QString& tile, const QString &objectName = QString());
    void setAlignment(FNavgationBar::AlignmentDirection direction);

signals:
    void indexChanged(int index);

private slots:
    void setButtonChecked();

};

#endif // FNAVGATIONBAR_H
