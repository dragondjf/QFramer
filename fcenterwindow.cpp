#include "fcenterwindow.h"
#include<QPushButton>
#include<QVBoxLayout>
#include<QQuickWidget>
#include<QWebView>
#include<QPropertyAnimation>
#include<QEasingCurve>




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
    titleBar = new FTitleBar();
    navagationBar = new FNavgationBar();

    stackWidget = new QStackedWidget();

    QVBoxLayout* mainlayout = new QVBoxLayout;
    mainlayout->addWidget(titleBar);
    mainlayout->addWidget(navagationBar);
    mainlayout->addWidget(stackWidget);
    mainlayout->setContentsMargins(0, 0 ,0 ,0);
    mainlayout->setSpacing(0);
    setLayout(mainlayout);
}

void FCenterWindow::initConnect()
{
    connect(navagationBar, SIGNAL(indexChanged(int)), this, SLOT(cloudAntimation(int)));
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
