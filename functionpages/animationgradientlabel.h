#ifndef ANIMATIONGRADIENTLABEL_H
#define ANIMATIONGRADIENTLABEL_H

#include <QLabel>
#include <QTimerEvent>

class AnimationGradientLabel : public QLabel
{
    Q_OBJECT
private:
    void initData();
    void initUI();
    void initConnect();
protected:
    void timerEvent(QTimerEvent *event);
public:
    explicit AnimationGradientLabel(QWidget *parent = 0);

signals:

public slots:

};

#endif // ANIMATIONGRADIENTLABEL_H
