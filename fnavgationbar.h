#ifndef FNAVGATIONBAR_H
#define FNAVGATIONBAR_H

#include <QFrame>
#include<QList>
#include<QWidget>
#include<QBoxLayout>
#include "basetoolbutton.h"


class FNavgationBar : public QFrame
{
    Q_OBJECT
public:
    QBoxLayout* mainlayout;
    QList<BaseToolButton*> buttons;
    QList<QString> buttonTitles;
public:
    explicit FNavgationBar(QWidget *parent = 0);
    void initData();
    void initConnect();
    void initUI();
    void addNavgationTile(const QString& tile);
    void setAlignment(Qt::AlignmentFlag alignment);
signals:
    void indexChanged(int i);
private slots:
    void setButtonChecked();

};

#endif // FNAVGATIONBAR_H
