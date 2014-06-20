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
    BaseToolButton* homeButton;
    BaseToolButton* webkitButton;
    BaseToolButton* qmlviewerButton;
    BaseToolButton* aboutButton;
public:
    explicit NavgationBar(QWidget *parent = 0);
    void initConnect();
signals:
    void indexChanged(int i);
private slots:
    void setButtonChecked();

};

#endif // NAVGATIONBAR_H
