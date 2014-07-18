#include "centerwindow.h"
#include "functionpages/webkitshow.h"
#include "functionpages/basequickwidget.h"
#include "functionpages/qmlviwer.h"
#include "QFramer/fcenterwindow.h"
#include "functionpages/mathplot.h"
#include"functionpages/uielement.h"
#include"functionpages/aboutpage.h"
#include"QFramer/fwigglywidget.h"
#include<QHBoxLayout>
CenterWindow* CenterWindow::instance = NULL;

CenterWindow::CenterWindow(QWidget *parent) :
    FCenterWindow(parent)
{
    initUI();
}

void CenterWindow::initUI()
{
    uiElements = new UIElement(this);
//    pdfTool = new PDFTool;
    MathPlot* p1 = new MathPlot;
//    webkitShow = new WebkitShow();
//    qmlViwer2 = new BaseQuickWidget;
//    qmlViwer3 = new QmlViwer;
//    qmlViwer4 = new BaseQuickWidget;
//    qmlViwer5 = new BaseQuickWidget;
//    qmlViwer2->setSource(QUrl(QString("qrc:/home/qml/home.qml")));
//    qmlViwer4->setSource(QUrl(QString("qrc:/home/qml/photowall.qml")));
//    qmlViwer5->setSource(QUrl(QString("qrc:/home/qml/about.qml")));
    AboutPage* aboutPage = new AboutPage;

    addWidget(tr("Home"), tr("Home"), uiElements);
    addWidget(tr("MathPlot"),tr("MathPlot"),p1);
    addWidget(tr("About"),tr("About"), aboutPage);
//    addWidget(tr("QtWebkit"), webkitShow);
//    addWidget(tr("QQuickWidget"), qmlViwer2);
//    addWidget(tr("QmlViewer"), qmlViwer3);
//    addWidget(tr("PhotoWall"), qmlViwer4);
//    addWidget(tr("About"),tr("About"), qmlViwer5);
    addWiggleWiget();
    setAlignment(TopCenter);
}

CenterWindow* CenterWindow::getInstance()
{
    if(!instance)
    {
        instance = new CenterWindow();
    }
    return instance;
}


void CenterWindow::addWiggleWiget()
{
    FWigglyWidget* wiggleWidget = new FWigglyWidget("Faster Easier Stronger Prettier", getNavgationBar());
    wiggleWidget->move(40, 5);
    wiggleWidget->setFixedSize(400, 60);
    wiggleWidget->setStyleSheet("background-color: transparent;\
                                 font-size: 20px;");

}
