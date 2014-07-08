#include "ftabwidget.h"
#include<QVBoxLayout>
#include<QHBoxLayout>
#include<QBoxLayout>
#include<QStackedLayout>
FTabWidget::FTabWidget(QWidget *parent) :
    QWidget(parent)
{
    initUI();
}

void FTabWidget::initUI()
{
    setObjectName(QString("FCenterWindow"));
    navagationBar = new FNavgationBar();
    stackLayout = new QStackedLayout;

    mainLayout = new QBoxLayout(QBoxLayout::TopToBottom);
    mainLayout->addWidget(navagationBar);
    mainLayout->addLayout(stackLayout);
    mainLayout->setContentsMargins(0, 0 ,0 ,0);
    mainLayout->setSpacing(0);
}


void FTabWidget::swicthLayout(QBoxLayout::Direction direction)
{
    mainLayout->setDirection(direction);
}


void FTabWidget::setAlignment(Alignment_Direction direction)
{
    switch (direction) {
    case TopLeft:
        navagationBar->setObjectName(QString("FNavgationBar_bottom"));
        navagationBar->setAlignment_topLeft();
        swicthLayout(QBoxLayout::TopToBottom);
        break;
    case TopCenter:
        navagationBar->setObjectName(QString("FNavgationBar_bottom"));
        navagationBar->setAlignment_topCenter();
        swicthLayout(QBoxLayout::TopToBottom);
        break;
    case TopRight:
        navagationBar->setObjectName(QString("FNavgationBar_bottom"));
        navagationBar->setAlignment_topRight();
        swicthLayout(QBoxLayout::TopToBottom);
        break;
    case RightTop:
        navagationBar->setObjectName(QString("FNavgationBar_left"));
        navagationBar->setAlignment_rightTop();
        swicthLayout(QBoxLayout::RightToLeft);
        break;
    case RightCenter:
        navagationBar->setObjectName(QString("FNavgationBar_left"));
        navagationBar->setAlignment_rightCenter();
        swicthLayout(QBoxLayout::RightToLeft);
        break;
    case RightBottom:
        navagationBar->setObjectName(QString("FNavgationBar_left"));
        navagationBar->setAlignment_rightBottom();
        swicthLayout(QBoxLayout::RightToLeft);
        break;
    case BottomRight:
        navagationBar->setObjectName(QString("FNavgationBar_top"));
        navagationBar->setAlignment_bottomRight();
        swicthLayout(QBoxLayout::BottomToTop);
        break;
    case BottomCenter:
        navagationBar->setObjectName(QString("FNavgationBar_top"));
        navagationBar->setAlignment_bottomCenter();
        swicthLayout(QBoxLayout::BottomToTop);
        break;
    case BottomLeft:
        navagationBar->setObjectName(QString("FNavgationBar_top"));
        navagationBar->setAlignment_bottomLeft();
        swicthLayout(QBoxLayout::BottomToTop);
        break;
    case LeftBottom:
        navagationBar->setObjectName(QString("FNavgationBar_right"));
        navagationBar->setAlignment_leftBottom();
        swicthLayout(QBoxLayout::LeftToRight);
        break;
    case LeftCenter:
        navagationBar->setObjectName(QString("FNavgationBar_right"));
        navagationBar->setAlignment_leftCenter();
        swicthLayout(QBoxLayout::LeftToRight);
        break;
    case LeftTop:
        navagationBar->setObjectName(QString("FNavgationBar_right"));
        navagationBar->setAlignment_leftTop();
        swicthLayout(QBoxLayout::LeftToRight);
        break;
    default:
        break;
    }
}


void FTabWidget::initConnect()
{
    connect(navagationBar, SIGNAL(indexChanged(int)), this, SLOT(switchscreen(int)));
}


void FTabWidget::addWidget(const QString &tile, const QString &objectName, QWidget *widget)
{
    navagationBar->addNavgationTile(tile, objectName);
    widget->setObjectName(objectName);
    stackLayout->addWidget(widget);
}

void FTabWidget::setCurrentIndex(const int index)
{
    stackLayout->setCurrentIndex(index);
}
