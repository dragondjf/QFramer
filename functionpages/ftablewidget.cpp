#include "ftablewidget.h"
#include<QHeaderView>
#include<QTableWidgetItem>
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

    horizontalHeader()->setSectionResizeMode(0, QHeaderView::Fixed);
    horizontalHeader()->setSectionResizeMode(1, QHeaderView::Fixed);
    horizontalHeader()->setSectionResizeMode(2, QHeaderView::Fixed);
    horizontalHeader()->setSectionResizeMode(3, QHeaderView::Stretch);

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
