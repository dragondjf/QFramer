#include "basedialog.h"
#include "util.h"
#include<QVBoxLayout>
BaseDialog::BaseDialog(QWidget *parent) :
    QDialog(parent)
{
    setWindowFlags(Qt::FramelessWindowHint);
    setFixedSize(400, 300);
    setAttribute(Qt::WA_DeleteOnClose);
//    setSizeGripEnabled(true);
    initData();
    initUI();
    initConnect();
    QString qss = getQssFromFile(QString(":/skin/qss/dialog.qss"));
    setStyleSheet(qss);
}

void BaseDialog::initData()
{

}

void BaseDialog::initUI()
{
    titlebar = new TitleBar;
    titlebar->settingButton->hide();
    titlebar->skinButton->hide();
    titlebar->minButton->hide();
    titlebar->maxButton->hide();

    QVBoxLayout* mainLayout = new QVBoxLayout;

    mainLayout->addWidget(titlebar);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);
    setLayout(mainLayout);

}

void BaseDialog::initConnect()
{
    connect(titlebar->closeButton, SIGNAL(clicked()), this, SLOT(close()));
}

void BaseDialog::mousePressEvent(QMouseEvent *e)
{
    if(e->button() & Qt::LeftButton)
    {
        dragPosition = e->globalPos() - frameGeometry().topLeft();
    }
    e->accept();
}

void BaseDialog::mouseReleaseEvent(QMouseEvent *e)
{
    e->accept();
}

void BaseDialog::mouseMoveEvent(QMouseEvent *e)
{
    if(e->y() < height() - 30){
        move(e->globalPos() - dragPosition);
        e->accept();
    }
    else{
        e->ignore();
    }

}
