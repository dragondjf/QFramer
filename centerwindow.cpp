#include<QPushButton>
#include<QVBoxLayout>
#include<QQuickWidget>
#include<QWebView>
#include "centerwindow.h"
#include "gradientshow.h"
#include "webkitshow.h"
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

    QQuickWidget* qmlViwer1 = new QQuickWidget;
    qmlViwer1->setResizeMode(qmlViwer1->SizeRootObjectToView);

    GradientShow* gradientShow = new GradientShow;

    WebkitShow *webkitShow = new WebkitShow(this);
//    webkitShow->view->load(QUrl("http://qt.nokia.com/"));

    QQuickWidget* qmlViwer2 = new QQuickWidget;
    qmlViwer2->setResizeMode(qmlViwer2->SizeRootObjectToView);
    QQuickWidget* qmlViwer3 = new QQuickWidget;
    qmlViwer3->setResizeMode(qmlViwer3->SizeRootObjectToView);
    QQuickWidget* qmlViwer4 = new QQuickWidget;
    qmlViwer4->setResizeMode(qmlViwer4->SizeRootObjectToView);
    QQuickWidget* qmlViwer5 = new QQuickWidget;
    qmlViwer5->setResizeMode(qmlViwer4->SizeRootObjectToView);

//    webkit->load(QUrl("wen.lu"));
    qmlViwer1->setSource(QUrl(QString("qrc:/home/home.qml")));
    qmlViwer2->setSource(QUrl(QString("qrc:/home/webkit.qml")));
    qmlViwer3->setSource(QUrl(QString("qrc:/quickwindow/application/appquick.qml")));
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
