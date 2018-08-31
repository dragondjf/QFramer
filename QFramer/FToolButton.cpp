#include "FToolButton.h"

FToolButton::FToolButton(QWidget* parent) :
    QToolButton(parent)
{

}

FToolButton::~FToolButton()
{

}

#ifdef Q_OS_LINUX
#include <QCursor>
void FToolButton::setMenu(QMenu *menu)
{
    connect(menu, SIGNAL(aboutToHide()), this, SLOT(recover()));
    QToolButton::setMenu(menu);
}
void FToolButton::recover()
{
    bool flag = this->rect().contains(this->mapFromGlobal(QCursor::pos()));
    this->setAttribute(Qt::WA_UnderMouse, flag);
    this->update();
}
#endif

