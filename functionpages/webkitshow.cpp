#include "webkitshow.h"
#include<QWebPage>
#include<QWebSettings>
#include<QShortcut>
#include<QSplitter>
#include<QVBoxLayout>
#include <QtNetwork>
#include <QtWebKitWidgets>
WebkitShow::WebkitShow(QWidget *parent) :
    QWidget(parent)
{

    QNetworkProxyFactory::setUseSystemConfiguration(true);
    initData();
    initUI();
    initConnect();
}


void WebkitShow::initData()
{

}

void WebkitShow::initUI()
{
    view = new QWebView(this);
    QUrl url = QUrl(QString("file:///%1/echarts-1.4.1/test/allchart/all.html").arg(QDir::currentPath()));
    qDebug(qPrintable(QString("file:///%1/echarts-1.4.1/test/allchart/all.html").arg(QDir::currentPath())));
    view->load(url);
//    setupInspector();
    QSplitter* splitter = new QSplitter;
    splitter->setOrientation(Qt::Vertical);
    splitter->addWidget(view);
//    splitter->addWidget(webInspector);

    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout->addWidget(splitter);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);
    setLayout(mainLayout);
}

void WebkitShow::initConnect()
{
    connect(view, SIGNAL(loadProgress(int)), SLOT(setProgress(int)));
    connect(view, SIGNAL(loadFinished(bool)), SLOT(finishLoading(bool)));
}

void WebkitShow::setupInspector()
{
    QWebPage* webpage = view->page();
    webpage->settings()->setAttribute(QWebSettings::DeveloperExtrasEnabled, true);
    webInspector->setPage(webpage);

    QShortcut* shortCut = new QShortcut(this);
    shortCut->setKey(Qt::Key_F12);
    connect(shortCut, SIGNAL(activated()), this, SLOT(toggleInspector()));
}

void WebkitShow::toggleInspector()
{
    webInspector->setVisible(not webInspector->isVisible());
}


void WebkitShow::setProgress(int p)
{
    progress = p;
}

void WebkitShow::finishLoading(bool)
{
    progress = 100;
}
