#ifndef FNAVGATIONBAR_H
#define FNAVGATIONBAR_H

#include <QFrame>
#include<QList>
#include<QWidget>
#include<QHBoxLayout>
#include<QVBoxLayout>
#include "fcheckablebutton.h"

class FNavgationBar : public QFrame
{
    Q_OBJECT
private:
    QHBoxLayout* mainlayout_topLeft;
    QHBoxLayout* mainlayout_topCenter;
    QHBoxLayout* mainlayout_topRight;
    QHBoxLayout* mainlayout_bottomLeft;
    QHBoxLayout* mainlayout_bottomCenter;
    QHBoxLayout* mainlayout_bottomRight;
    QVBoxLayout* mainlayout_leftTop;
    QVBoxLayout* mainlayout_leftCenter;
    QVBoxLayout* mainlayout_leftBottom;
    QVBoxLayout* mainlayout_rightTop;
    QVBoxLayout* mainlayout_rightCenter;
    QVBoxLayout* mainlayout_rightBottom;
    bool cIndex;
public:

    QList<FCheckabelButton*> buttons;
    QList<QString> buttonTitles;
public:
    explicit FNavgationBar(QWidget *parent = 0);
    void initData();
    void initConnect();
    void initUI();
    int currentIndex();
    int count();
    void setCurrentIndex(int index);
    void addNavgationTile(const QString& tile, const QString &objectName);
    void setAlignment_topLeft();
    void setAlignment_topCenter();
    void setAlignment_topRight();
    void setAlignment_bottomLeft();
    void setAlignment_bottomCenter();
    void setAlignment_bottomRight();
    void setAlignment_leftTop();
    void setAlignment_leftCenter();
    void setAlignment_leftBottom();
    void setAlignment_rightTop();
    void setAlignment_rightCenter();
    void setAlignment_rightBottom();
signals:
    void indexChanged(int i);
private slots:
    void setButtonChecked();

};

#endif // FNAVGATIONBAR_H
