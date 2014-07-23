#include "centerwindow.h"
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
    uiElements = new UIElement;
    mathPlot = new MathPlot;
    recordManger = new WavRecordManager;
    aboutPage = new AboutPage;

    addWidget(tr("Home"), tr("Home"), uiElements);
    addWidget(tr("MathPlot"),tr("MathPlot"), mathPlot);
    addWidget(tr("Voice"), tr("Voice"), recordManger);
    addWidget(tr("About"),tr("About"), aboutPage);
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
