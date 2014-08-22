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

#include "uielement.h"
#include "ftablewidget.h"
#include "QFramer/ftabwidget.h"
#include "QFramer/fnofocusdelegate.h"
#include "QFramer/futil.h"
#include <QGridLayout>
#include <QGroupBox>
#include <QLabel>
#include <QPushButton>
#include <QRadioButton>
#include <QCheckBox>
#include <QTreeWidget>
#include <QTabWidget>
#include <QSplitter>
#include <QHeaderView>
#include <QProgressBar>
#include <QTimer>
#include <QGraphicsScene>
UIElement::UIElement(QWidget *parent) :
    FTabWidget(parent)
{
    initUI();
}


void UIElement::initUI()
{
    initBaseElements();
    initTableWidget();
    initTreeWidget();
    initProgressBar();
    initAboutLabel();
    initWaterWidget();
    initWaterView();
    initAnimationLabel();
    getButtons().at(4)->click();
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
//             button->setObjectName(QString("normal"));
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
//             label->setObjectName(QString("normal"));
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
//             raido->setObjectName(QString("normal"));
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
//             check->setObjectName(QString("normal"));
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

    addWidget(tr("Base UI Element"), QString(""), baseElement);

}

void UIElement::initTableWidget()
{
    FTableWidget* table = new FTableWidget;
//    table->setItemDelegate(new FNoFocusDelegate);
//    table->setFocusPolicy(Qt::NoFocus);
    addWidget(tr("TabelWidget"), QString(""), table);
}

void UIElement::initTreeWidget()
{
    QTreeWidget *treeWidget = new QTreeWidget;
//    treeWidget->setItemDelegate(new FNoFocusDelegate);
    treeWidget->setFocusPolicy(Qt::NoFocus);
    treeWidget->setHeaderHidden(true);
    treeWidget->setColumnCount(3);
    QList<QTreeWidgetItem *> items;
    for (int i = 0; i < 10; ++i)
    {
        items.append(new QTreeWidgetItem(treeWidget, QStringList(QString("item: %1").arg(i))));
        for(int j=0; j <10; j++)
        {
            items.at(i)->addChild(new QTreeWidgetItem(treeWidget, QStringList(QString("child: %1").arg(j))));
        }
    }
    treeWidget->insertTopLevelItems(0, items);

    QTreeWidget *treeWidget2 = new QTreeWidget;
//    treeWidget2->setItemDelegate(new FNoFocusDelegate);
    treeWidget2->setFocusPolicy(Qt::NoFocus);
    QStringList labels;
    labels << tr("rpcID") << tr("rpcType") << tr("rpcDetail");
    treeWidget2->setHeaderLabels(labels);
    treeWidget2->setColumnCount(3);
#if QT_VERSION >= QT_VERSION_CHECK(5, 0, 0)
    treeWidget2->header()->setSectionResizeMode(0, QHeaderView::Fixed);
    treeWidget2->header()->setSectionResizeMode(1, QHeaderView::Fixed);
    treeWidget2->header()->setSectionResizeMode(2, QHeaderView::Stretch);
#endif
    QList<QTreeWidgetItem *> items2;
    for (int i = 0; i < 10; ++i)
    {
        items2.append(new QTreeWidgetItem(treeWidget2, QStringList(QString("item: %1").arg(i))));
        for(int j=0; j <10; j++)
        {
            QStringList childs;
            childs << tr("%1").arg(j) << tr("alert") << tr("show warning");
            items2.at(i)->addChild(new QTreeWidgetItem(items2.at(i), childs));
        }
    }
    treeWidget2->insertTopLevelItems(0, items2);


    QTreeWidget *treeWidget3 = new QTreeWidget;
//    treeWidget3->setItemDelegate(new FNoFocusDelegate);
    treeWidget3->setFocusPolicy(Qt::NoFocus);
    QStringList labels3;
    labels3 << tr("rpcID") << tr("rpcType") << tr("rpcDetail");
    treeWidget3->setHeaderLabels(labels3);
    treeWidget3->setColumnCount(3);

    #if QT_VERSION >= QT_VERSION_CHECK(5, 0, 0)
        treeWidget3->header()->setSectionResizeMode(0, QHeaderView::Fixed);
        treeWidget3->header()->setSectionResizeMode(1, QHeaderView::Fixed);
        treeWidget3->header()->setSectionResizeMode(2, QHeaderView::Stretch);
    #endif
    QList<QTreeWidgetItem *> items3;
    for (int i = 0; i < 10; ++i)
    {
        QTreeWidgetItem* fitem = new QTreeWidgetItem(treeWidget3, QStringList(QString("item: %1").arg(i)));
        fitem->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsSelectable |Qt::ItemIsEnabled);
        fitem->setCheckState(0, Qt::Checked);
        items3.append(fitem);
        for(int j=0; j <10; j++)
        {
            QStringList childs3;
            childs3 << tr("%1").arg(j) << tr("alert") << tr("show warning");
            QTreeWidgetItem* sitem = new QTreeWidgetItem(fitem, childs3);
            sitem->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsSelectable |Qt::ItemIsEnabled);
            sitem->setCheckState(0, Qt::Checked);
            items3.at(i)->addChild(sitem);
        }
    }
    treeWidget3->insertTopLevelItems(0, items3);



    QSplitter* splitter = new QSplitter(this);
    splitter->addWidget(treeWidget);
    splitter->addWidget(treeWidget2);

    QSplitter* vsplitter = new QSplitter(Qt::Vertical, this);
    vsplitter->addWidget(splitter);
    vsplitter->addWidget(treeWidget3);

    addWidget(tr("TreeWidget"), QString(""), vsplitter);
}

void UIElement::initProgressBar()
{
    QWidget* progressBarsWidget = new QWidget;
    QVBoxLayout* progressLayout = new QVBoxLayout;
    for(int i=1; i< 11; ++i)
    {
        QProgressBar* p = new QProgressBar;
        p->setRange(0, 100);
        p->setValue(i * 10);
        progressLayout->addWidget(p);
        progressBars.append(p);
    }
    progressBarsWidget->setLayout(progressLayout);
    addWidget(tr("ProgressBar"), QString(""), progressBarsWidget);
    QTimer * ptimer = new QTimer;
    ptimer->setInterval(20);
    connect(ptimer, SIGNAL(timeout()), this, SLOT(updateProgressBar()));
    ptimer->start();
}

void UIElement::updateProgressBar()
{
   for(int i=0; i< progressBars.size(); ++i)
   {
       int value = progressBars.at(i)->value();
       if(value < 100)
       {
           progressBars.at(i)->setValue(value + 1);
       }
       else
       {
           progressBars.at(i)->setValue(0);
       }
   }
}

void UIElement::initAboutLabel()
{
    QLabel* label = new QLabel();
    label->setObjectName("aboutLabel");
    label->setStyleSheet("\
                         QLabel#aboutLabel{\
                            border-image: url(:/images/skin/images/bear.jpg);\
                            }"\
                         );
    label->setAlignment(Qt::AlignBottom | Qt::AlignRight);

    QLabel* labelText = new QLabel(label);
    QString text;
    text = readFile(":/about/skin/html/about.html");
    labelText->setText(text);

    QHBoxLayout* layout = new QHBoxLayout();
    layout->addStretch();
    layout->addWidget(labelText);
    label->setLayout(layout);
    addWidget(tr("AboutLabel"), QString(""), label);
}


void UIElement::initWaterWidget()
{
    WaterWidget* waterWidget = new WaterWidget;
    addWidget(tr("Water"), QString(""), waterWidget);
}


void UIElement::initWaterView()
{

    WaterView* waterView = new WaterView;
    addWidget(tr("Waterview"), QString(""), waterView);
}


void UIElement::initAnimationLabel()
{
    AnimationGradientLabel* label = new AnimationGradientLabel;
    addWidget(tr("GradientLabel"), QString(""), label);
}
