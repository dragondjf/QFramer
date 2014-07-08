#include "uielement.h"
#include "QFramer/ftabwidget.h"
#include <QGridLayout>
#include <QGroupBox>
#include<QLabel>
#include<QPushButton>
#include<QRadioButton>
#include<QCheckBox>

UIElement::UIElement(QWidget *parent) :
    FTabWidget(parent)
{
    initUI();
}


void UIElement::initUI()
{
    initBaseElements();
    addWidget(tr("Base UI Element"), QString("NavgationTab"), new QLabel(tr("898989")));
    addWidget(tr("Base UI Element"), QString("NavgationTab"), new QLabel(tr("898989")));
    addWidget(tr("Base UI Element"), QString("NavgationTab"), new QLabel(tr("898989")));
    addWidget(tr("Base UI Element"), QString("NavgationTab"), new QLabel(tr("898989")));
    addWidget(tr("Base UI Element"), QString("NavgationTab"), new QLabel(tr("898989")));
    addWidget(tr("Base UI Element"), QString("NavgationTab"), new QLabel(tr("898989")));
    addWidget(tr("Base UI Element"), QString("NavgationTab"), new QLabel(tr("898989")));
    addWidget(tr("Base UI Element"), QString("NavgationTab"), new QLabel(tr("898989")));
}

void UIElement::initBaseElements()
{
    QWidget* baseElement = new QWidget;
    QGridLayout* baseLayout = new QGridLayout;


    QGroupBox* buttonGroup = new QGroupBox(tr("Button"));
    QGridLayout *buttonlayout = new QGridLayout;
    for(int i=0; i< 4; i++)
    {
         for(int j=0; j <4; j++)
         {
             QPushButton *button = new QPushButton(tr("%1-2").arg(i, j));
             button->setFixedSize(100, 60);
             button->setObjectName(QString("normal"));
             buttonlayout->addWidget(button, i, j);
         }
    }
    buttonGroup->setLayout(buttonlayout);

    QGroupBox* labelGroup = new QGroupBox(tr("Label"));
    QGridLayout *labellayout = new QGridLayout;
    for(int i=0; i< 4; i++)
    {
         for(int j=0; j <4; j++)
         {
             QLabel *label = new QLabel(tr("%1-2").arg(i, j));
             label->setFixedSize(100, 60);
             label->setObjectName(QString("normal"));
             labellayout->addWidget(label, i, j);
         }
    }
    labelGroup->setLayout(labellayout);

    QGroupBox* raidoGroup = new QGroupBox(tr("RadioButton"));
    QGridLayout *raidolayout = new QGridLayout;
    for(int i=0; i< 4; i++)
    {
         for(int j=0; j <4; j++)
         {
             QRadioButton *raido = new QRadioButton(tr("%1-2").arg(i, j));
             raido->setFixedSize(100, 60);
             raido->setObjectName(QString("normal"));
             raidolayout->addWidget(raido, i, j);
         }
    }
    raidolayout->setContentsMargins(5, 5, 5, 5);
    raidoGroup->setLayout(raidolayout);

    QGroupBox* checkBoxGroup = new QGroupBox(tr("CheckBox"));
    QGridLayout *checklayout = new QGridLayout;
    for(int i=0; i< 4; i++)
    {
         for(int j=0; j <4; j++)
         {
             QCheckBox *check = new QCheckBox(tr("%1-2").arg(i, j));
             check->setFixedSize(100, 60);
             check->setObjectName(QString("normal"));
             checklayout->addWidget(check, i, j);
         }
    }
    checkBoxGroup->setLayout(checklayout);

    baseLayout->addWidget(buttonGroup, 0, 0);
    baseLayout->addWidget(labelGroup, 0, 1);
    baseLayout->addWidget(raidoGroup, 1, 0);
    baseLayout->addWidget(checkBoxGroup, 1, 1);
    baseLayout->setContentsMargins(50, 50, 50, 50);
    baseElement->setLayout(baseLayout);

    addWidget(tr("Base UI Element"), QString("NavgationTab"), baseElement);

}

void UIElement::initTableWidget()
{

}

void UIElement::initTreeWidget()
{

}

void UIElement::initComoBox()
{

}
