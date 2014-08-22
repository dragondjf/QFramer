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

#include "qmlviwer.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include<QFileDialog>
QmlViwer::QmlViwer(QWidget *parent) :
    QWidget(parent)
{
    initData();
    initUI();
    initConnect();
}

void QmlViwer::initData()
{

}

void QmlViwer::initUI()
{
    loadQmlButton = new QToolButton;
    loadQmlButton->setIcon(QIcon(":/skin/icons/dark/appbar.upload.png"));
    loadQmlButton->setIconSize(QSize(20, 20));
    loadQmlButton->setToolTip(QString("Load QML"));

    qmlUrlEdit = new QLineEdit;
    qmlUrlEdit->setFixedHeight(25);
    QHBoxLayout* loadLayout = new QHBoxLayout;
    loadLayout->addWidget(loadQmlButton);
    loadLayout->addWidget(qmlUrlEdit);

    viewer = new BaseQuickWidget;
    viewer->setSource(QUrl(QString("qrc:/home/qml/home.qml")));
    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout->addLayout(loadLayout);
    mainLayout->addWidget(viewer);

    setLayout(mainLayout);


}

void QmlViwer::initConnect()
{
    connect(loadQmlButton, SIGNAL(clicked()), this, SLOT(getQmlUrl()));
    connect(qmlUrlEdit, SIGNAL(editingFinished()), this, SLOT(loadQml()));
    connect(qmlUrlEdit, SIGNAL(returnPressed()), this, SLOT(loadQml()));
    connect(qmlUrlEdit, SIGNAL(textChanged()), this, SLOT(loadQml()));
}

void QmlViwer::getQmlUrl()
{
    QString qmlurl = QFileDialog::getOpenFileName(this, tr("Open QML"), QDir::currentPath(), tr("QML Files(*.qml)"));
    if(qmlurl != QString(""))
    {
        qmlUrlEdit->setText(QString("file:///%1").arg(qmlurl));
    }
    else
    {
        viewer->setSource(QUrl(QString("qrc:/home/welcom.qml")));
        qmlUrlEdit->setText("");
    }

}

void QmlViwer::loadQml()
{
    viewer->setSource(QUrl(qmlUrlEdit->text()));
}





