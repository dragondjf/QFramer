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

#include "FTabWidget.h"
#include <QHBoxLayout>

FTabWidget::FTabWidget(QWidget *parent) :
    QWidget(parent)
{
    initUI();
}

void FTabWidget::initUI()
{
    tabLayout = new QVBoxLayout();
    tabLayout->addStretch();
    tabLayout->setContentsMargins(0, 0, 0, 0);
    tabLayout->setSpacing(0);

    QWidget* tabTile = new QWidget();
    tabTile->setObjectName(QString("FTabTile"));
    tabTile->setLayout(tabLayout);

    stackLayout = new QStackedLayout;

    QHBoxLayout* mainLayout = new QHBoxLayout(this);
    mainLayout->addWidget(tabTile);
    mainLayout->addLayout(stackLayout);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);
}

void FTabWidget::addWidget(const QString &tile, const QString &objectName, QWidget *widget)
{
    Q_UNUSED(objectName);
    FCheckabelButton* button = new FCheckabelButton(tile);
    button->setFixedSize(200, 60);
    buttons.append(button);
    tabLayout->insertWidget(tabLayout->count() - 1, button);
    connect(button, SIGNAL(clicked()), this, SLOT(setButtonChecked()));
    stackLayout->addWidget(widget);
}

int  FTabWidget::currentIndex()
{
    return m_index;
}

void FTabWidget::setCurrentIndex(int index)
{
    if (index < buttons.size() && index >= 0) {
        buttons.at(index)->click();
    }
}

QList<FCheckabelButton*> FTabWidget::getButtons()
{
    return buttons;
}

void FTabWidget::setButtonChecked()
{
    for (int i = 0; i < buttons.size(); ++i) {
        if (buttons.at(i) == sender()) {
            buttons.at(i)->setChecked(true);
            stackLayout->setCurrentIndex(i);
            emit indexChanged(i);
        } else {
            buttons.at(i)->setChecked(false);
        }
    }
}
