#ifndef FWIGGLYWIDGET_H
#define FWIGGLYWIDGET_H

#include <QBasicTimer>
#include <QWidget>
#include <QLabel>

//! [0]
class FWigglyWidget : public QLabel
{
    Q_OBJECT

public:
    FWigglyWidget(const QString &text, QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *event);
    void timerEvent(QTimerEvent *event);

private:
    QBasicTimer timer;
    QString text;
    int step;
};
//! [0]

#endif // FWIGGLYWIDGET_H
