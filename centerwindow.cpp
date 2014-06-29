#include<QPushButton>
#include<QVBoxLayout>
#include<QQuickWidget>
#include<QWebView>
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

    WebkitShow *webkitShow = new WebkitShow(this);

    BaseQuickWidget* qmlViwer2 = new BaseQuickWidget;

    QmlViwer* qmlViwer3 = new QmlViwer;

    BaseQuickWidget* qmlViwer4 = new BaseQuickWidget;

    BaseQuickWidget* qmlViwer5 = new BaseQuickWidget;


    qmlViwer2->setSource(QUrl(QString("qrc:/home/welcom.qml")));
//    qmlViwer3->setSource(QUrl(QString("qrc:/quickwindow/application/appquick.qml")));
    qmlViwer4->setSource(QUrl(QString("qrc:/about/photowall.qml")));
    qmlViwer5->setSource(QUrl(QString("qrc:/about/about.qml")));
    stackWidget->addWidget(gradientShow);
    stackWidget->addWidget(webkitShow);
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
    connect(navagationBar, SIGNAL(indexChanged(int)), this, SLOT(switchscreen(int)));
}

void CenterWindow::switchscreen(const int index)
{
    stackWidget->setCurrentIndex(index);
}
