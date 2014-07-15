#ifndef ABOUTPAGE_H
#define ABOUTPAGE_H

#include <QFrame>
#include <QPaintEvent>
class AboutPage : public QFrame
{
    Q_OBJECT
private:
    void initUI();
protected:
    void paintEvent(QPaintEvent *event);
public:
    explicit AboutPage(QWidget *parent = 0);

signals:

public slots:

};

#endif // ABOUTPAGE_H
