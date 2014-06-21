#ifndef NAVGATIONBAR_H
#define NAVGATIONBAR_H

#include <QFrame>
#include<QList>
#include "basetoolbutton.h"
#include<QWidget>

class NavgationBar : public QFrame
{
    Q_OBJECT
public:
    QList<BaseToolButton*> buttons;
    QList<QString> buttonTitles;
    BaseToolButton* homeButton;
    BaseToolButton* webkitButton;
    BaseToolButton* qmlviewerButton;
    BaseToolButton* aboutButton;
    BaseToolButton* photowallButton;
public:
    explicit NavgationBar(QWidget *parent = 0);
    void initData();
    void initConnect();
    void initUI();
signals:
    void indexChanged(int i);
private slots:
    void setButtonChecked();

};

#endif // NAVGATIONBAR_H
