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

#include "fnavgationbar.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QDebug>


FNavgationBar::FNavgationBar(QWidget *parent)
    :QFrame(parent)
{
    initData();
    initUI();
    initConnect();
}

void FNavgationBar::initData()
{
    cIndex = 0;
}

void FNavgationBar::initUI()
{
    setObjectName(QString("FNavgationBar"));
}

void FNavgationBar::initConnect()
{
    for(int i=0; i<buttons.length(); i++)
    {
        connect(buttons.at(i), SIGNAL(clicked()), this, SLOT(setButtonChecked()));
    }
}

void FNavgationBar::addNavgationTile(const QString &tile, const QString &objectName)
{
    buttonTitles  << tile;
    FCheckabelButton* button = new FCheckabelButton(tile);
    buttons.append(button);
    button->setObjectName(objectName);
    connect(button, SIGNAL(clicked()), this, SLOT(setButtonChecked()));
}

void FNavgationBar::setAlignment_topLeft()
{
    mainlayout_topLeft = new QHBoxLayout;
    for(int i=0; i < buttons.length(); i++)
    {
        mainlayout_topLeft->addWidget(buttons.at(i));
    }
    mainlayout_topLeft->addStretch();
    mainlayout_topLeft->setContentsMargins(5, 5, 5, 5);
    mainlayout_topLeft->setSpacing(0);
    setLayout(mainlayout_topLeft);
}

void FNavgationBar::setAlignment_topCenter()
{
    mainlayout_topCenter = new QHBoxLayout;
    mainlayout_topCenter->addStretch();
    for(int i=0; i < buttons.length(); i++)
    {
        mainlayout_topCenter->addWidget(buttons.at(i));
    }
    mainlayout_topCenter->addStretch();
    mainlayout_topCenter->setContentsMargins(5, 5, 5, 5);
    mainlayout_topCenter->setSpacing(0);
    setLayout(mainlayout_topCenter);
}

void FNavgationBar::setAlignment_topRight()
{
    mainlayout_topRight = new QHBoxLayout;
    mainlayout_topRight->addStretch();
    for(int i=0; i < buttons.length(); i++)
    {
        mainlayout_topRight->addWidget(buttons.at(i));
    }
    mainlayout_topRight->setContentsMargins(5, 5, 5, 5);
    mainlayout_topRight->setSpacing(0);
    setLayout(mainlayout_topRight);
}


void FNavgationBar::setAlignment_bottomLeft()
{
    mainlayout_bottomLeft = new QHBoxLayout;
    for(int i=0; i < buttons.length(); i++)
    {
        mainlayout_bottomLeft->addWidget(buttons.at(i));
    }
    mainlayout_bottomLeft->addStretch();
    mainlayout_bottomLeft->setContentsMargins(5, 5, 5, 5);
    mainlayout_bottomLeft->setSpacing(0);
    setLayout(mainlayout_bottomLeft);
}


void FNavgationBar::setAlignment_bottomCenter()
{
    mainlayout_bottomCenter = new QHBoxLayout;
    mainlayout_bottomCenter->addStretch();
    for(int i=0; i < buttons.length(); i++)
    {
        mainlayout_bottomCenter->addWidget(buttons.at(i));
    }
    mainlayout_bottomCenter->addStretch();
    mainlayout_bottomCenter->setContentsMargins(5, 5, 5, 5);
    mainlayout_bottomCenter->setSpacing(0);
    setLayout(mainlayout_bottomCenter);

}

void FNavgationBar::setAlignment_bottomRight()
{
    mainlayout_bottomRight = new QHBoxLayout;
    mainlayout_bottomRight->addStretch();
    for(int i=0; i < buttons.length(); i++)
    {
        mainlayout_bottomRight->addWidget(buttons.at(i));
    }
    mainlayout_bottomRight->setContentsMargins(5, 5, 5, 5);
    mainlayout_bottomRight->setSpacing(0);
    setLayout(mainlayout_bottomRight);
}

void FNavgationBar::setAlignment_leftTop()
{
    mainlayout_leftTop = new QVBoxLayout;
    for(int i=0; i < buttons.length(); i++)
    {
        mainlayout_leftTop->addWidget(buttons.at(i));
    }
    mainlayout_leftTop->addStretch();
    mainlayout_leftTop->setContentsMargins(5, 5, 5, 5);
    mainlayout_leftTop->setSpacing(0);
    setLayout(mainlayout_leftTop);
}

void FNavgationBar::setAlignment_leftCenter()
{
    mainlayout_leftCenter = new QVBoxLayout;
    mainlayout_leftCenter->addStretch();
    for(int i=0; i < buttons.length(); i++)
    {
        mainlayout_leftCenter->addWidget(buttons.at(i));
    }
    mainlayout_leftCenter->addStretch();
    mainlayout_leftCenter->setContentsMargins(5, 5, 5, 5);
    mainlayout_leftCenter->setSpacing(0);
    setLayout(mainlayout_leftCenter);
}

void FNavgationBar::setAlignment_leftBottom()
{
    mainlayout_leftBottom = new QVBoxLayout;
    mainlayout_leftBottom->addStretch();
    for(int i=0; i < buttons.length(); i++)
    {
        mainlayout_leftBottom->addWidget(buttons.at(i));
    }
    mainlayout_leftBottom->setContentsMargins(5, 5, 5, 5);
    mainlayout_leftBottom->setSpacing(0);
    setLayout(mainlayout_leftBottom);
}

void FNavgationBar::setAlignment_rightTop()
{
    mainlayout_rightTop = new QVBoxLayout;
    for(int i=0; i < buttons.length(); i++)
    {
        mainlayout_rightTop->addWidget(buttons.at(i));
    }
    mainlayout_rightTop->addStretch();
    mainlayout_rightTop->setContentsMargins(5, 5, 5, 5);
    mainlayout_rightTop->setSpacing(0);
    setLayout(mainlayout_rightTop);
}

void FNavgationBar::setAlignment_rightCenter()
{
    mainlayout_rightCenter = new QVBoxLayout;
    mainlayout_rightCenter->addStretch();
    for(int i=0; i < buttons.length(); i++)
    {
        mainlayout_rightCenter->addWidget(buttons.at(i));
    }
    mainlayout_rightCenter->addStretch();
    mainlayout_rightCenter->setContentsMargins(5, 5, 5, 5);
    mainlayout_rightCenter->setSpacing(0);
    setLayout(mainlayout_rightCenter);
}

void FNavgationBar::setAlignment_rightBottom()
{
    mainlayout_rightBottom = new QVBoxLayout;
    mainlayout_rightBottom->addStretch();
    for(int i=0; i < buttons.length(); i++)
    {
        mainlayout_rightBottom->addWidget(buttons.at(i));
    }
    mainlayout_rightBottom->setContentsMargins(5, 5, 5, 5);
    mainlayout_rightBottom->setSpacing(0);
    setLayout(mainlayout_rightBottom);
}

int FNavgationBar::currentIndex()
{
    return cIndex;
}

void FNavgationBar::setCurrentIndex(int index)
{
    buttons.at(index)->click();
}

int FNavgationBar::count()
{
    return buttons.size();
}

void FNavgationBar::setButtonChecked()
{
    for (int i = 0; i < buttons.size(); ++i) {
        if (buttons.at(i) == sender())
        {
            buttons.at(i)->setChecked(true);
            emit indexChanged(i);
            cIndex = i;
        }
        else{
            buttons.at(i)->setChecked(false);
        }
    }
}

