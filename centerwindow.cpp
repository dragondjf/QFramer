#include<QPushButton>
#include<QVBoxLayout>
#include "centerwindow.h"
#include "titlebar.h"
CenterWindow::CenterWindow(QWidget *parent)
{
    titleBar = new TitleBar();
    QVBoxLayout* mainlayout = new QVBoxLayout;
    mainlayout->addWidget(titleBar);
    mainlayout->addStretch();
    mainlayout->setContentsMargins(0, 0 ,0 ,0);
    mainlayout->setSpacing(0);
    setLayout(mainlayout);
}
