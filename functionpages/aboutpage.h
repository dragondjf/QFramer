#ifndef ABOUTPAGE_H
#define ABOUTPAGE_H

#include <QWidget>

class AboutPage : public QWidget
{
    Q_OBJECT
private:
    void initUI();
public:
    explicit AboutPage(QWidget *parent = 0);

signals:

public slots:

};

#endif // ABOUTPAGE_H
