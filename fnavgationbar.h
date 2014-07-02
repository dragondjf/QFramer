#ifndef FNAVGATIONBAR_H
#define FNAVGATIONBAR_H

#include <QFrame>
#include<QList>
#include<QWidget>
#include<QHBoxLayout>
#include "basetoolbutton.h"


class FNavgationBar : public QFrame
{
    Q_OBJECT
private:
    QHBoxLayout* mainlayout;

public:
    QList<BaseToolButton*> buttons;
    QList<QString> buttonTitles;
public:
    explicit FNavgationBar(QWidget *parent = 0);
    void initData();
    void initConnect();
    void initUI();
    void addNavgationTile(const QString& tile);
signals:
    void indexChanged(int i);
private slots:
    void setButtonChecked();

};

#endif // FNAVGATIONBAR_H
