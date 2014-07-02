#include "fnavgationbar.h"
#include<QHBoxLayout>

FNavgationBar::FNavgationBar(QWidget *parent)
    :QFrame(parent)
{
    initData();
    initUI();
    initConnect();
}

void FNavgationBar::initData()
{
}

void FNavgationBar::initUI()
{
    setObjectName(QString("FNavgationBar"));
    setFixedHeight(66);
    mainlayout = new QHBoxLayout;
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

void FNavgationBar::initConnect()
{
    for(int i=0; i<buttons.length(); i++)
    {
        connect(buttons.at(i), SIGNAL(clicked()), this, SLOT(setButtonChecked()));
    }
}

void FNavgationBar::addNavgationTile(const QString &tile)
{
    buttonTitles  << tile;
    BaseToolButton* button = new BaseToolButton(tile);
    buttons.append(button);
    button->setObjectName(tile);
    mainlayout->insertWidget(mainlayout->count() - 1, button);

    connect(button, SIGNAL(clicked()), this, SLOT(setButtonChecked()));
}

void FNavgationBar::setButtonChecked()
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

