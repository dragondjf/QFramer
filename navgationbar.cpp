#include "navgationbar.h"
#include<QHBoxLayout>

NavgationBar::NavgationBar(QWidget *parent)
    :QFrame(parent)
{
    setObjectName(QString("NavgationBar"));
    setFixedHeight(66);
    homeButton = new BaseToolButton(tr("Home"));
    homeButton->setObjectName(QString("Home"));
    buttons.append(homeButton);
    webkitButton = new BaseToolButton(tr("QtWebkit"));
    webkitButton->setObjectName(QString("QtWebkit"));
    buttons.append(webkitButton);
    qmlviewerButton = new BaseToolButton(tr("QmlViewer"));
    qmlviewerButton->setObjectName(QString("QmlViewer"));
    buttons.append(qmlviewerButton);
    aboutButton = new BaseToolButton(tr("About"));
    aboutButton->setObjectName(QString("About"));
    buttons.append(aboutButton);

    QHBoxLayout* mainlayout = new QHBoxLayout;
    mainlayout->addSpacing(10);
    mainlayout->addWidget(homeButton);
    mainlayout->addWidget(webkitButton);
    mainlayout->addWidget(qmlviewerButton);
    mainlayout->addWidget(aboutButton);
    mainlayout->addStretch();
    mainlayout->setContentsMargins(0, 0, 0, 0);
    mainlayout->setSpacing(0);
    setLayout(mainlayout);

    initConnect();
}

void NavgationBar::initConnect()
{
    connect(homeButton, SIGNAL(clicked()), this, SLOT(setButtonChecked()));
    connect(webkitButton, SIGNAL(clicked()), this, SLOT(setButtonChecked()));
    connect(qmlviewerButton, SIGNAL(clicked()), this, SLOT(setButtonChecked()));
    connect(aboutButton, SIGNAL(clicked()), this, SLOT(setButtonChecked()));
}

void NavgationBar::setButtonChecked()
{
    for (int i = 0; i < buttons.size(); ++i) {
        if (buttons.at(i) == sender())
        {
            buttons.at(i)->setChecked(true);
            emit indexChanged(i);
        }
        else{
            buttons.at(i)->setChecked(false);
        }
    }
}

