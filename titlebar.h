#ifndef TITLEBAR_H
#define TITLEBAR_H

#include"ftitlebar.h"

class TitleBar : public FTitleBar
{
    Q_OBJECT

public:
    static TitleBar* instance;
public:
    explicit TitleBar(QWidget *parent = 0);
    static TitleBar* getInstance();
signals:

public slots:

};

#endif // TITLEBAR_H
