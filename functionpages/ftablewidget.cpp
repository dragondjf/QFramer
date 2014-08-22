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

#include "ftablewidget.h"
#include <QHeaderView>
#include <QTableWidgetItem>


FTableWidget::FTableWidget(QWidget *parent) :
    QTableWidget(parent)
{
    setEditTriggers(FTableWidget::NoEditTriggers);
    setSelectionBehavior(FTableWidget::SelectRows);
    setSelectionMode(FTableWidget::SingleSelection);
    setFocusPolicy(Qt::NoFocus);
    verticalHeader()->setVisible(false);

    setColumnCount(4);
    QHeaderView* headview = new QHeaderView(Qt::Horizontal, this);
    setHorizontalHeader(headview);

    QStringList headLabels;
    headLabels << tr("RPC no") << tr("RPC type") << tr("RPC content") << tr("RPC mark");
    setHorizontalHeaderLabels(headLabels);
#if QT_VERSION >= QT_VERSION_CHECK(5, 0, 0)
    horizontalHeader()->setSectionResizeMode(0, QHeaderView::Fixed);
    horizontalHeader()->setSectionResizeMode(1, QHeaderView::Fixed);
    horizontalHeader()->setSectionResizeMode(2, QHeaderView::Fixed);
    horizontalHeader()->setSectionResizeMode(3, QHeaderView::Stretch);
#endif
    for(int row=0; row < 40; ++row)
    {
        insertRow(row);
        for(int column=0; column < 4; ++column)
        {
            QTableWidgetItem *newItem = new QTableWidgetItem(tr("%1").arg((row+1)*(column+1)));
            setItem(row, column, newItem);
        }
    }
}
