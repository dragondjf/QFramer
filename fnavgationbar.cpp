#include "fnavgationbar.h"
#include<QBoxLayout>

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
    mainlayout = new QBoxLayout(QBoxLayout::LeftToRight);
    mainlayout->addSpacing(10);
    mainlayout->addStretch();
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

//    setAlignment(Qt::AlignRight);
//    setAlignment(Qt::AlignCenter);
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
    mainlayout->insertWidget(mainlayout->count(), button);
    connect(button, SIGNAL(clicked()), this, SLOT(setButtonChecked()));
}

void FNavgationBar::setAlignment(Qt::AlignmentFlag alignment)
{
    switch (alignment) {
    case Qt::AlignLeft:
        mainlayout->addStretch();
        break;
    case Qt::AlignRight:
        mainlayout->insertStretch(0);
        break;
    case Qt::AlignCenter:
        mainlayout->insertStretch(0);
        mainlayout->addStretch();
        break;
    default:
        break;
    }
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

