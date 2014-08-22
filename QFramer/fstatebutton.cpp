/****************************************************************************
**
** Copyright (C) 2014 dragondjf
**
** QFramer is a frame based on Qt5.3, you will be more efficient with it. 
** As an Qter, Qt give us a nice coding experience. With user interactive experience(UE) 
** become more and more important in modern software, deveployers should consider business and UE.
** So, QFramer is born. QFramer's goal is to be a mature solution 
** which you only need to be focus on your business but UE for all Qters.
**
** Version	: 0.2.5.0
** Author	: dragondjf
** Website	: https://github.com/dragondjf
** Project	: https://github.com/dragondjf/QCFramer
** Blog		: http://my.oschina.net/dragondjf/home/?ft=atme
** Wiki		: https://github.com/dragondjf/QCFramer/wiki
** Lincence: LGPL V2
** QQ: 465398889
** Email: dragondjf@gmail.com, ding465398889@163.com, 465398889@qq.com
** 
****************************************************************************/

#include "fstatebutton.h"

#if QT_VERSION < QT_VERSION_CHECK(5, 0, 0)
    #include<QtCore/qmath.h>
#else
    #include <QtMath>
#endif

#include <QBitmap>


FStateButton::FStateButton(const QString &ficon, const QString &bicon, int buttonFlag, QWidget *parent):
    QPushButton(parent), fStateIcon(ficon), bStateIcon(bicon), bflag(buttonFlag)
{
    state = 0;
    if(bflag == 0)
    {
        setIcon(QIcon(fStateIcon));
        setIconSize(QPixmap(fStateIcon).size());
    }
    else if (bflag == 1)
    {
        setText(fStateIcon);;
    }
    connect(this, SIGNAL(clicked()), this, SLOT(changeState()));
}

void FStateButton::changeState()
{
    state = qAbs(1 - state);
    if(state == 0){
        if(bflag == 0){
            setIcon(QIcon(fStateIcon));
            setMask(QBitmap(fStateIcon).mask());
        }
        else if(bflag == 1)
        {
            setText(fStateIcon);
        }

    }
    else if(state == 1)
    {
        if(bflag == 0){
            setIcon(QIcon(bStateIcon));
            setMask(QBitmap(bStateIcon).mask());
        }
        else if(bflag == 1)
        {
            setText(bStateIcon);
        }
    }
    emit stateChanged();
}

int FStateButton::getState()
{
    return state;
}
