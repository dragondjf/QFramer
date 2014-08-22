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
