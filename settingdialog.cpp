#include "settingdialog.h"
#include<QVBoxLayout>
SettingDialog::SettingDialog(QWidget *parent) :
    BaseDialog(parent)
{
    initUI();
}

void SettingDialog::initUI()
{
    normalSize = QSize(450, 300);
    QVBoxLayout* mainLayout = (QVBoxLayout*)layout();
    mainLayout->addStretch();
}
