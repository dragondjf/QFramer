#include "flywidget.h"
#include<QBitmap>
#include<QApplication>
#include<QMainWindow>
#include<QCursor>
FlyWidget::FlyWidget(QWidget *parent) :
    QWidget(parent)
{
    p = parent;
    settingmenu = NULL;
    setWindowFlags(Qt::FramelessWindowHint);
    setWindowFlags(Qt::ToolTip);
    initData();
    initUI();
    initConnect();
}

void FlyWidget::initData()
{
    m_Pixmap.load(QString(":/images/skin/images/QFramer.png"));
}

void FlyWidget::initUI()
{
    resize(m_Pixmap.size());
    setMask(m_Pixmap.mask());
}

void FlyWidget::initConnect()
{

}

void FlyWidget::setMenu(QMenu *menu)
{
    settingmenu = menu;
}

void FlyWidget::mousePressEvent(QMouseEvent *event)
{
    //按住左键可以托动窗口，按下右键关闭程序
    if(event->button() == Qt::LeftButton)
    {
        m_CurrentPos = event->globalPos() - frameGeometry().topLeft();
        event->accept();
    }
    else if(event->button() == Qt::RightButton)
    {
        settingmenu->exec(QCursor::pos());
    }
}

void FlyWidget::mouseDoubleClickEvent(QMouseEvent *event)
{
    p->setVisible(not p->isVisible());
}

void FlyWidget::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() && Qt::LeftButton)
    {
        move(event->globalPos() - m_CurrentPos);
        event->accept();
    }
}

void FlyWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(0, 0, m_Pixmap);
}

void FlyWidget::leaveEvent(QEvent *event)
{
    //鼠标离开窗口时是普通的指针
    setCursor(Qt::ArrowCursor);
}

void FlyWidget::enterEvent(QEvent *event)
{
    //鼠标留在窗口上时是一个手指
    setCursor(Qt::PointingHandCursor);
}
