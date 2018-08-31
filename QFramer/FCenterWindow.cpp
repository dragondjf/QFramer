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

#include "FCenterWindow.h"
#include <QStackedWidget>
#include <QVBoxLayout>
#include <QTime>
#include <QLabel>
#include <QPixmap>
#include <QEasingCurve>
#include <QPropertyAnimation>
#include <QParallelAnimationGroup>
#include "FTitleBar.h"

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
    preindex = 0;
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

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(FTitleBar::getInstace());
    mainLayout->addLayout(navlayout);
    mainLayout->setContentsMargins(0, 0 ,0 ,0);
    mainLayout->setSpacing(0);
}

void FCenterWindow::initConnect()
{
    connect(navagationBar, SIGNAL(indexChanged(int)), this, SLOT(switchscreen(int)));
}

void FCenterWindow::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left) {
        int count = navagationBar->count();
        int index = (navagationBar->currentIndex() + count - 1) % count;
        navagationBar->setCurrentIndex(index);
    } else if(event->key() == Qt::Key_Right) {
        int count = navagationBar->count();
        int index = (navagationBar->currentIndex() + 1) % count;
        navagationBar->setCurrentIndex(index);
    } else if (event->key() == Qt::Key_F1) {
        setAlignment(FNavgationBar::TopCenter);
    } else if (event->key() == Qt::Key_F2) {
        QTime time = QTime::currentTime();
        qsrand(static_cast<uint>(time.msec() + time.second() * 1000));
        setAlignment(static_cast<FNavgationBar::AlignmentDirection>(qrand() % 12));
    } else {
        QFrame::keyPressEvent(event);
    }
}

void FCenterWindow::setAlignment(FNavgationBar::AlignmentDirection direction)
{
    switch (direction) {
    case FNavgationBar::TopLeft:
    case FNavgationBar::TopCenter:
    case FNavgationBar::TopRight:
        navagationBar->setObjectName(QString("FNavgationBar_bottom"));
        navagationBar->setAlignment(direction);
        navagationBar->resize(QSize(stackWidget->width(), navagationBar->height()));
        navagationBar->adjustSize();
        navlayout->setDirection(QBoxLayout::TopToBottom);
        break;
    case FNavgationBar::RightTop:
    case FNavgationBar::RightCenter:
    case FNavgationBar::RightBottom:
        navagationBar->setObjectName(QString("FNavgationBar_left"));
        navagationBar->setAlignment(direction);
        navagationBar->resize(QSize(navagationBar->width(), stackWidget->height()));
        navagationBar->adjustSize();
        navlayout->setDirection(QBoxLayout::RightToLeft);
        break;
    case FNavgationBar::BottomRight:
    case FNavgationBar::BottomCenter:
    case FNavgationBar::BottomLeft:
        navagationBar->setObjectName(QString("FNavgationBar_top"));
        navagationBar->setAlignment(direction);
        navagationBar->resize(QSize(stackWidget->width(), navagationBar->height()));
        navagationBar->adjustSize();
        navlayout->setDirection(QBoxLayout::BottomToTop);
        break;
    case FNavgationBar::LeftBottom:
    case FNavgationBar::LeftCenter:
    case FNavgationBar::LeftTop:
        navagationBar->setObjectName(QString("FNavgationBar_right"));
        navagationBar->setAlignment(direction);
        navagationBar->resize(QSize(navagationBar->width(), stackWidget->height()));
        navagationBar->adjustSize();
        navlayout->setDirection(QBoxLayout::LeftToRight);
        break;
    }
}

void FCenterWindow::addWidget(QWidget *widget, const QString &tile, const QString &objectName)
{
    if (!widget) return;
    navagationBar->addNavgationTile(tile, objectName);
    widget->setObjectName(objectName.isEmpty() ? tile : objectName);
    stackWidget->addWidget(widget);
    setAlignment(FNavgationBar::TopCenter);
}

FNavgationBar* FCenterWindow::getNavgationBar()
{
    return navagationBar;
}

void FCenterWindow::switchscreen(const int index)
{
    AnimationDirection animation = animationTop;
    if (index == stackWidget->currentIndex()) {
        return;
    } else if (index > stackWidget->currentIndex()) {
        animation = FCenterWindow::animationRight;
    } else if (index < stackWidget->currentIndex()) {
        animation = FCenterWindow::animationLeft;
    }

    //  QTime time = QTime::currentTime();
    //  qsrand(static_cast<uint>(time.msec() + time.second() * 1000));
    //  int n = qrand() % 9;
    //  animation = static_cast<AnimationDirection>(n);

    stackWidget->setCurrentIndex(index);
    cloudAntimation(animation);
    preindex = index;
}

void FCenterWindow::swicthLayout(QBoxLayout::Direction direction)
{
    navlayout->setDirection(direction);
}

void FCenterWindow::cloudAntimation(AnimationDirection direction)
{
    // TODO : not read
    QLabel* circle = new QLabel(stackWidget->currentWidget());
    QLabel* line = new QLabel(this);
    line->setObjectName(QString("AntimationLine"));
    line->resize(0, 2);
    line->show();
    #if QT_VERSION < QT_VERSION_CHECK(5, 0, 0)
        circle->setPixmap(QPixmap::grabWidget(stackWidget->widget(preindex), stackWidget->widget(preindex)->geometry()));
    #else
        circle->setPixmap(stackWidget->widget(preindex)->grab());
    #endif

//  circle->setScaledContents(true);
    circle->show();
    circle->resize(stackWidget->currentWidget()->size());
    QPropertyAnimation *animation = new QPropertyAnimation(circle, "geometry");
    animation->setDuration(1000);
    animation->setStartValue(circle->geometry());

    QPropertyAnimation* animation_line = new QPropertyAnimation(line, "size");
    animation_line->setDuration(1000);
    animation_line->setEasingCurve(QEasingCurve::OutCubic);

    switch (direction) {
    case animationTop:
        animation->setEndValue(QRect(circle->x(), circle->y() - 10, circle->width(), 0));
        break;
    case animationTopRight:
        animation->setEndValue(QRect(circle->width(), 0, 0, 0));
        break;
    case animationRight:
        line->move(0, stackWidget->y() - 2);
        animation->setEndValue(QRect(circle->width() + 3, 0, 0, circle->height()));
        animation_line->setStartValue(QSize(0, 2));
        animation_line->setEndValue(QSize(stackWidget->width(), 2));
        break;
    case animationBottomRight:
        animation->setEndValue(QRect(circle->width(), circle->height(), 0, 0));
        break;
    case animationBottom:
        animation->setEndValue(QRect(0, circle->height() + 10, circle->width(), 0));
        break;
    case animationBottomLeft:
        animation->setEndValue(QRect(0, circle->height(), 0, 0));
        break;
    case animationLeft:
        animation->setEndValue(QRect(-3, 0, 0, circle->height()));
        line->move(stackWidget->x(), stackWidget->y() - 2);
        animation_line->setStartValue(QSize(0, 2));
        animation_line->setEndValue(QSize(stackWidget->width(), 2));
        break;
    case animationTopLeft:
        animation->setEndValue(QRect(0, 0, 0, 0));
        break;
    case animationCenter:
        animation->setEndValue(QRect(circle->width()/2, circle->height()/2, 0, 0));
        break;
    default:
        break;
    }
    animation->setEasingCurve(QEasingCurve::OutCubic);

    QPropertyAnimation* animation_opacity = new QPropertyAnimation(circle, "windowOpacity");
    animation_opacity->setDuration(1000);
    animation_opacity->setStartValue(1);
    animation_opacity->setEndValue(0);
    animation_opacity->setEasingCurve(QEasingCurve::OutCubic);

    QParallelAnimationGroup *group = new QParallelAnimationGroup;

    connect(group,SIGNAL(finished()), circle, SLOT(hide()));
    connect(group,SIGNAL(finished()), circle, SLOT(deleteLater()));
    connect(group,SIGNAL(finished()), line, SLOT(deleteLater()));
    connect(group,SIGNAL(finished()), group, SLOT(deleteLater()));
    connect(group,SIGNAL(finished()), animation, SLOT(deleteLater()));
    connect(group,SIGNAL(finished()), animation_opacity, SLOT(deleteLater()));
    connect(group,SIGNAL(finished()), animation_line, SLOT(deleteLater()));
    group->addAnimation(animation);
    group->addAnimation(animation_opacity);
    group->addAnimation(animation_line);
    group->start();
}
