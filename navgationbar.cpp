#include "navgationbar.h"
#include<QHBoxLayout>

NavgationBar::NavgationBar(QWidget *parent)
    :QFrame(parent)
{
    initData();
    initUI();
    initConnect();
}

void NavgationBar::initData()
{
    buttonTitles << tr("Home") << tr("QtWebkit") << tr("QQuickWidget")<<tr("QmlViewer") << tr("PhotoWall") << tr("About");
}

void NavgationBar::initUI()
{
    setObjectName(QString("NavgationBar"));
    setFixedHeight(66);
    QHBoxLayout* mainlayout = new QHBoxLayout;
    mainlayout->addSpacing(10);
    for(int i=0; i < buttonTitles.length(); i++)
    {
        buttons.append(new BaseToolButton(buttonTitles.at((i))));
        buttons.at(i)->setObjectName(QString(buttonTitles.at(i)));
        mainlayout->addWidget(buttons.at(i));
    }
    mainlayout->addStretch();
    mainlayout->setContentsMargins(0, 0, 0, 0);
    mainlayout->setSpacing(0);
    setLayout(mainlayout);
}

void NavgationBar::initConnect()
{
    for(int i=0; i<buttons.length(); i++)
    {
        connect(buttons.at(i), SIGNAL(clicked()), this, SLOT(setButtonChecked()));
    }
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

