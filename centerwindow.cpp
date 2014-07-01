#include<QPushButton>
#include<QVBoxLayout>
#include<QQuickWidget>
#include<QWebView>
#include<QEasingCurve>
#include "centerwindow.h"
#include "gradientshow.h"
#include "webkitshow.h"
#include "basequickwidget.h"
#include "qmlviwer.h"
CenterWindow::CenterWindow(QWidget *parent)
    :QFrame(parent)
{
    qDebug("centerwindow init");
    initData();
    initUI();
    initConnect();
}

void CenterWindow::initData()
{

}

void CenterWindow::initUI()
{
    setObjectName(QString("CenterWindow"));
    titleBar = new TitleBar();
    navagationBar = new NavgationBar();

    stackWidget = new QStackedWidget();

    GradientShow* gradientShow = new GradientShow;

    WebkitShow *webkitShow = new WebkitShow();

    BaseQuickWidget* qmlViwer2 = new BaseQuickWidget;

    QmlViwer* qmlViwer3 = new QmlViwer;

    BaseQuickWidget* qmlViwer4 = new BaseQuickWidget;

    BaseQuickWidget* qmlViwer5 = new BaseQuickWidget;


    qmlViwer2->setSource(QUrl(QString("qrc:/home/welcom.qml")));
//    qmlViwer3->setSource(QUrl(QString("qrc:/quickwindow/application/appquick.qml")));
    qmlViwer4->setSource(QUrl(QString("qrc:/about/photowall.qml")));
    qmlViwer5->setSource(QUrl(QString("qrc:/about/about.qml")));
    stackWidget->addWidget(webkitShow);
    stackWidget->addWidget(gradientShow);
//    stackWidget->addWidget(webkitShow);
    stackWidget->addWidget(qmlViwer2);
    stackWidget->addWidget(qmlViwer3);
    stackWidget->addWidget(qmlViwer4);
    stackWidget->addWidget(qmlViwer5);
    QVBoxLayout* mainlayout = new QVBoxLayout;
    mainlayout->addWidget(titleBar);
    mainlayout->addWidget(navagationBar);
    mainlayout->addWidget(stackWidget);
    mainlayout->setContentsMargins(0, 0 ,0 ,0);
    mainlayout->setSpacing(0);
    setLayout(mainlayout);
}

void CenterWindow::initConnect()
{
    connect(navagationBar, SIGNAL(indexChanged(int)), this, SLOT(cloudAntimation(int)));
}

void CenterWindow::switchscreen(const int index)
{
    stackWidget->setCurrentIndex(index);
//    cloudAntimation();
}


void CenterWindow::switchscreen()
{
    stackWidget->setCurrentIndex(currentIndex);
}

void CenterWindow::cloudAntimation(const int index)
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
