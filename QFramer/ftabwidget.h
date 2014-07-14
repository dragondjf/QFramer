#ifndef FTABWIDGET_H
#define FTABWIDGET_H

#include <QWidget>
#include<QStackedLayout>
#include"fbasetoolbutton.h"
#include"QBoxLayout"

class FTabWidget : public QWidget
{
    Q_OBJECT

private:
    QList<FBaseToolButton*> buttons;
    QList<QString> buttonTitles;

private:
    void initUI();
    void initConnect();

public:
    QWidget* tabTile;
    QBoxLayout* mainLayout;
    QStackedLayout* stackLayout;
    QVBoxLayout* tabLayout;
public:
    explicit FTabWidget(QWidget *parent = 0);
    QList<FBaseToolButton*> getButtons();

signals:
        void indexChanged(int i);
public slots:
    void addWidget(const QString &tile, const QString &objectName, QWidget *widget);
    void setButtonChecked();
};

#endif // FTABWIDGET_H
