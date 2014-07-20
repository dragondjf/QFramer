#include "fstatebutton.h"
#include<QtMath>
#include<QBitmap>
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
