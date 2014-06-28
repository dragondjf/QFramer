#include "settingdialog.h"
#include<QVBoxLayout>
SettingDialog::SettingDialog(QWidget *parent) :
    BaseDialog(parent)
{
    initUI();
}

void SettingDialog::initUI()
{
    setFixedSize(450, 300);
    QVBoxLayout* mainLayout = (QVBoxLayout*)layout();
    mainLayout->addStretch();
}
