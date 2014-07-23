#include "settingdialog.h"
#include<QVBoxLayout>
#include<QTabWidget>
SettingDialog::SettingDialog(QWidget *parent) :
    FBaseDialog(parent)
{
    initUI();
}

void SettingDialog::initUI()
{
    normalSize = QSize(680, 475);
    getTitleBar()->getTitleLabel()->setText(tr("Settings"));
    QVBoxLayout* mainLayout = (QVBoxLayout*)layout();


    QWidget* tab1 = new QWidget;
    QWidget* tab2 = new QWidget;
    QWidget* tab3 = new QWidget;

    QTabWidget* tabwidget = new QTabWidget;
    tabwidget->addTab(tab1, tr("Home"));
    tabwidget->addTab(tab2, tr("Plot"));
    tabwidget->addTab(tab3, tr("About"));
    mainLayout->addSpacing(5);
    mainLayout->addWidget(tabwidget);
}
