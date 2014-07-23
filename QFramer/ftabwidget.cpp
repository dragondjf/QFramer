#include "ftabwidget.h"
#include<QVBoxLayout>
#include<QHBoxLayout>
#include<QBoxLayout>
#include<QStackedLayout>
FTabWidget::FTabWidget(QWidget *parent) :
    QWidget(parent)
{
    initUI();
    initConnect();
}

void FTabWidget::initUI()
{
    tabTile = new QWidget;
    tabTile->setObjectName(QString("FTabTile"));

    stackLayout = new QStackedLayout;
    tabLayout = new QVBoxLayout;
    tabLayout->addStretch();
    tabLayout->setContentsMargins(0, 0, 0, 0);
    tabLayout->setSpacing(0);
    tabTile->setLayout(tabLayout);

    mainLayout = new QHBoxLayout;
    mainLayout->addWidget(tabTile);
    mainLayout->addLayout(stackLayout);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);
    setLayout(mainLayout);
}

void FTabWidget::initConnect()
{


}

void FTabWidget::addWidget(const QString &tile, const QString &objectName, QWidget *widget)
{
    buttonTitles  << tile;
    FCheckabelButton* button = new FCheckabelButton(tile);
    buttons.append(button);
//    button->setObjectName(objectName);
    button->setFixedSize(200, 60);
    tabLayout->insertWidget(tabLayout->count() - 1, button);
    connect(button, SIGNAL(clicked()), this, SLOT(setButtonChecked()));
//    widget->setObjectName(objectName);
    stackLayout->addWidget(widget);
}

QList<FCheckabelButton*> FTabWidget::getButtons()
{
    return buttons;
}

void FTabWidget::setButtonChecked()
{
    for (int i = 0; i < buttons.size(); ++i) {
        if (buttons.at(i) == sender())
        {
            buttons.at(i)->setChecked(true);
            stackLayout->setCurrentIndex(i);
            emit indexChanged(i);
        }
        else{
            buttons.at(i)->setChecked(false);
        }
    }
}
