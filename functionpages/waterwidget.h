#ifndef WATERWIDGET_H
#define WATERWIDGET_H

#include <QLabel>
#include <QPropertyAnimation>
#include <QParallelAnimationGroup>
#include <QSequentialAnimationGroup>
#include <QPushButton>
class WaterWidget : public QLabel
{
    Q_OBJECT
private:
    QList<QLabel* > labels;
    QList<QPropertyAnimation *> parallelAnimations;
    QList<QPropertyAnimation *> sequentialAnimations;
    QStringList ballpaths;
    QParallelAnimationGroup *parallelAnimationGroup;
    QSequentialAnimationGroup *sequentialAnimationGroup;
    QList<int> durations;
    QPushButton* switchButton;
    int count;
    bool animationFlag;
private:
    void initData();
    void initUI();
    void initConnect();
    void initAnimations();

public:
    explicit WaterWidget(QWidget *parent = 0);

signals:

public slots:
    void updateCount();
    void swicthAnimationType();
};

#endif // WATERWIDGET_H
