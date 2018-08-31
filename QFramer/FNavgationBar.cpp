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

#include "FNavgationBar.h"
#include <QBoxLayout>

FNavgationBar::FNavgationBar(QWidget *parent)
    : QFrame(parent)
{
    initData();
    initUI();
    initConnect();
}

void FNavgationBar::initData()
{
    m_index = -1;
}

void FNavgationBar::initUI()
{
    setObjectName(QString("FNavgationBar"));
}

void FNavgationBar::initConnect()
{
    for (int i = 0; i < buttons.length(); i++) {
        connect(buttons.at(i), SIGNAL(clicked()), this, SLOT(setButtonChecked()));
    }
}

int  FNavgationBar::count()
{
    return buttons.size();
}

int  FNavgationBar::currentIndex()
{
    return m_index;
}

void FNavgationBar::setCurrentIndex(int index)
{
    if (index < buttons.size() && index >= 0) {
        buttons.at(index)->click();
    }
}

void FNavgationBar::addNavgationTile(const QString &tile, const QString &objectName)
{
    FCheckabelButton* button = new FCheckabelButton(tile);
    button->setObjectName(objectName.isEmpty() ? tile : objectName);
    connect(button, SIGNAL(clicked()), this, SLOT(setButtonChecked()));
    buttons.append(button);
}

void FNavgationBar::setAlignment(FNavgationBar::AlignmentDirection direction)
{
    delete this->layout();
    QBoxLayout *layout;
    switch(direction) {
    case TopLeft:       case TopCenter:     case TopRight:
    case BottomRight:   case BottomCenter:  case BottomLeft:
       layout = new QBoxLayout(QBoxLayout::LeftToRight, this);
        break;
    case LeftBottom:    case LeftCenter:    case LeftTop:
    case RightTop:      case RightCenter:   case RightBottom:
       layout = new QBoxLayout(QBoxLayout::TopToBottom, this);
        break;
    }
    switch(direction) {
    case TopLeft: case BottomLeft: case LeftTop: case RightTop:
        break;
    case TopRight: case BottomRight: case LeftBottom: case RightBottom:
    case TopCenter: case BottomCenter: case LeftCenter: case RightCenter:
        layout->addStretch();
        break;
    }
    for (int i = 0; i < buttons.size(); i++) {
        layout->addWidget(buttons.at(i));
    }
    switch(direction) {
    case TopRight: case BottomRight: case LeftBottom: case RightBottom:
        break;
    case TopLeft: case BottomLeft: case LeftTop: case RightTop:
    case TopCenter: case BottomCenter: case LeftCenter: case RightCenter:
        layout->addStretch();
        break;
    }
    layout->setContentsMargins(5, 5, 5, 5);
    layout->setSpacing(0);
}

void FNavgationBar::setButtonChecked()
{
    for (int i = 0; i < buttons.size(); ++i) {
        if (buttons.at(i) == sender()) {
            buttons.at(i)->setChecked(true);
            emit indexChanged(i);
            m_index = i;
        } else {
            buttons.at(i)->setChecked(false);
        }
    }
}
