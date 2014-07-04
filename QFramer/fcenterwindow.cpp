#include "fcenterwindow.h"
#include<QPushButton>
#include<QVBoxLayout>
#include<QQuickWidget>
#include<QWebView>
#include<QPropertyAnimation>
#include<QEasingCurve>
#include<QLabel>


FCenterWindow::FCenterWindow(QWidget *parent)
    :QFrame(parent)
{
    qDebug("FCenterWindow init");
    initData();
    initUI();
    initConnect();
}

void FCenterWindow::initData()
{

}

void FCenterWindow::initUI()
{

    setObjectName(QString("FCenterWindow"));
    navagationBar = new FNavgationBar();
    stackWidget = new QStackedWidget();

    navlayout = new QBoxLayout(QBoxLayout::TopToBottom);
    navlayout->addWidget(navagationBar);
    navlayout->addWidget(stackWidget);
    navlayout->setContentsMargins(0, 0 ,0 ,0);
    navlayout->setSpacing(0);

    mainLayout = new QVBoxLayout;
    mainLayout->addLayout(navlayout);
    mainLayout->setContentsMargins(0, 0 ,0 ,0);
    mainLayout->setSpacing(0);
    setLayout(mainLayout);
}

void FCenterWindow::swicthLayout(QBoxLayout::Direction direction)
{
    navlayout->setDirection(direction);
}


void FCenterWindow::setAlignment(Alignment_Direction direction)
{
    switch (direction) {
    case TopLeft:
        navagationBar->setObjectName(QString("FNavgationBar_bottom"));
        navagationBar->setAlignment_topLeft();
        navagationBar->resize(QSize(stackWidget->width(), navagationBar->height()));
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
        navagationBar->resize(QSize(navagationBar->width(), stackWidget->height()));
        break;
    case RightCenter:
        navagationBar->setObjectName(QString("FNavgationBar_left"));
        navagationBar->setAlignment_rightCenter();
        swicthLayout(QBoxLayout::RightToLeft);
        navagationBar->resize(QSize(navagationBar->width(), stackWidget->height()));
        break;
    case RightBottom:
        navagationBar->setObjectName(QString("FNavgationBar_left"));
        navagationBar->setAlignment_rightBottom();
        swicthLayout(QBoxLayout::RightToLeft);
        navagationBar->resize(QSize(navagationBar->width(), stackWidget->height()));
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


void FCenterWindow::initConnect()
{
    connect(navagationBar, SIGNAL(indexChanged(int)), this, SLOT(cloudAntimation(int)));
}

void FCenterWindow::setTitleBar(FTitleBar *ftitleBar)
{
    mainLayout->insertWidget(0, ftitleBar);
}

void FCenterWindow::addWidget(const QString &tile, QWidget *widget)
{
    navagationBar->addNavgationTile(tile);
    stackWidget->addWidget(widget);
}

void FCenterWindow::switchscreen(const int index)
{
    stackWidget->setCurrentIndex(index);
}


void FCenterWindow::switchscreen()
{
    stackWidget->setCurrentIndex(currentIndex);
}

void FCenterWindow::cloudAntimation(const int index)
{
    currentIndex = index;
    QLabel* circle = new QLabel(stackWidget);
    circle->setStyleSheet(QString("\
         QLabel{background-color: qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 rgba(1, 255, 255, 255), stop:0.511364 rgba(255, 255, 0, 255), stop:1 rgba(0, 137, 0, 238));}"\
                                  ));
    circle->show();
    QPropertyAnimation *animation = new QPropertyAnimation(circle, "size");
    connect(animation,SIGNAL(finished()), this, SLOT(switchscreen()));
    connect(animation,SIGNAL(finished()), circle, SLOT(deleteLater()));
    animation->setDuration(1000);
    animation->setStartValue(QSize(0, 0));
    animation->setEndValue(stackWidget->size());
    animation->setEasingCurve(QEasingCurve::OutCubic);
    animation->start();
}
