#include "uielement.h"
#include "ftablewidget.h"
#include "QFramer/ftabwidget.h"
#include <QGridLayout>
#include <QGroupBox>
#include<QLabel>
#include<QPushButton>
#include<QRadioButton>
#include<QCheckBox>
#include<QTreeWidget>
#include<QSplitter>
#include<QHeaderView>
#include<QProgressBar>
#include<QTimer>
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
    for(int i = 1; i< 8; ++i)
    {
        QLabel* label = new QLabel(QString::number(i));
        addWidget(tr("Base UI Element %1").arg(QString::number(i)), QString("NavgationTab"), label);
    }
    getButtons().at(0)->click();
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
    FTableWidget* table = new FTableWidget;
    addWidget(tr("TabelWidget"), QString("NavgationTab"), table);
}

void UIElement::initTreeWidget()
{
    QTreeWidget *treeWidget = new QTreeWidget();
    treeWidget->setHeaderHidden(true);
    treeWidget->setColumnCount(1);
    QList<QTreeWidgetItem *> items;
    for (int i = 0; i < 10; ++i)
    {
        items.append(new QTreeWidgetItem((QTreeWidget*)0, QStringList(QString("item: %1").arg(i))));
        for(int j=0; j <10; j++)
        {
            items.at(i)->addChild(new QTreeWidgetItem((QTreeWidget*)0, QStringList(QString("child: %1").arg(j))));
        }
    }
    treeWidget->insertTopLevelItems(0, items);

    QTreeWidget *treeWidget2 = new QTreeWidget();

    QStringList labels;
    labels << tr("rpcID") << tr("rpcType") << tr("rpcDetail");
    treeWidget2->setHeaderLabels(labels);
    treeWidget2->setColumnCount(3);
    treeWidget2->header()->setSectionResizeMode(0, QHeaderView::Fixed);
    treeWidget2->header()->setSectionResizeMode(1, QHeaderView::Fixed);
    treeWidget2->header()->setSectionResizeMode(2, QHeaderView::Stretch);
    QList<QTreeWidgetItem *> items2;
    for (int i = 0; i < 10; ++i)
    {
        items2.append(new QTreeWidgetItem((QTreeWidget*)0, QStringList(QString("item: %1").arg(i))));
        for(int j=0; j <10; j++)
        {
            QStringList childs;
            childs << tr("%1").arg(j) << tr("alert") << tr("show warning");
            items2.at(i)->addChild(new QTreeWidgetItem((QTreeWidget*)0, childs));
        }
    }
    treeWidget2->insertTopLevelItems(0, items2);


    QTreeWidget *treeWidget3 = new QTreeWidget();
    QStringList labels3;
    labels3 << tr("rpcID") << tr("rpcType") << tr("rpcDetail");
    treeWidget3->setHeaderLabels(labels3);
    treeWidget3->setColumnCount(3);
    treeWidget3->header()->setSectionResizeMode(0, QHeaderView::Fixed);
    treeWidget3->header()->setSectionResizeMode(1, QHeaderView::Fixed);
    treeWidget3->header()->setSectionResizeMode(2, QHeaderView::Stretch);
    QList<QTreeWidgetItem *> items3;
    for (int i = 0; i < 10; ++i)
    {
        QTreeWidgetItem* fitem = new QTreeWidgetItem((QTreeWidget*)0, QStringList(QString("item: %1").arg(i)));
        fitem->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsSelectable |Qt::ItemIsEnabled);
        fitem->setCheckState(0, Qt::Checked);
        items3.append(fitem);
        for(int j=0; j <10; j++)
        {
            QStringList childs3;
            childs3 << tr("%1").arg(j) << tr("alert") << tr("show warning");
            QTreeWidgetItem* sitem = new QTreeWidgetItem((QTreeWidget*)0, childs3);
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

    addWidget(tr("TreeWidget"), QString("NavgationTab"), vsplitter);
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
    addWidget(tr("ProgressBar"), QString("NavgationTab"), progressBarsWidget);
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
