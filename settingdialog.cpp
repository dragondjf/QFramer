#include "settingdialog.h"
#include<QVBoxLayout>
SettingDialog::SettingDialog(QWidget *parent) :
    BaseDialog(parent)
{
    initUI();
}

void SettingDialog::initUI()
{
//    BaseDialog::initUI();
    QVBoxLayout* mainLayout = (QVBoxLayout*)layout();
    mainLayout->addStretch();
}
