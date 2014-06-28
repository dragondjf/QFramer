#include "aboutdialog.h"
#include<QVBoxLayout>
#include<QLabel>
#include<QPushButton>
#include<QTextEdit>
AboutDialog::AboutDialog(QWidget *parent) :
    BaseDialog(parent)
{
    initUI();
    initConnect();
}

void AboutDialog::initUI()
{
//    BaseDialog::initUI();

    QTextEdit* infoEdit = new QTextEdit;
    infoEdit->setObjectName(QString("info"));
    infoEdit->setText(QString("<h1>QFramer</h1><p>Github: https://github.com/dragondjf/QCFramer</p><p>Email: ding4656398889@163.com</p>"));
    infoEdit->setReadOnly(true);

    enterButton = new QPushButton(QString("Close"));
    QHBoxLayout* controlLayout = new QHBoxLayout;
    controlLayout->addStretch();
    controlLayout->addWidget(enterButton);
    controlLayout->addSpacing(10);

    QVBoxLayout* mainLayout = (QVBoxLayout*)layout();
    mainLayout->addSpacing(20);
    mainLayout->addWidget(infoEdit);
    mainLayout->addSpacing(10);
    mainLayout->addLayout(controlLayout);
    mainLayout->addSpacing(10);

}

void AboutDialog::initConnect()
{
//    BaseDialog::initConnect();
    connect(enterButton, &QPushButton::clicked, this, &BaseDialog::close);
}
