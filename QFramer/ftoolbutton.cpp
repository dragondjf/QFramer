#include "ftoolbutton.h"
#include<QCursor>
#include <QDebug>

FToolButton::FToolButton(QWidget* parent) :
   QToolButton(parent)
{

}

void FToolButton::setMenu(QMenu *menu){
    connect(menu, SIGNAL(aboutToHide()), this, SLOT(recover()));
    QToolButton::setMenu(menu);
}


void FToolButton::recover(){
    #ifdef Q_OS_LINUX
        bool flag = this->rect().contains(this->mapFromGlobal(QCursor::pos()));
        this->setAttribute(Qt::WA_UnderMouse, flag);
        this->update();
    #endif
}

FToolButton::~FToolButton()
{

}

