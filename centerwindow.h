#ifndef CENTERWINDOW_H
#define CENTERWINDOW_H

#include <QFrame>
#include<QWidget>
#include<titlebar.h>

class CenterWindow : public QFrame
{
    Q_OBJECT
public:
    TitleBar* titleBar;
public:
    explicit CenterWindow(QWidget *parent = 0);

signals:

public slots:

};

#endif // CENTERWINDOW_H
