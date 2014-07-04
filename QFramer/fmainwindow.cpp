#include "fmainwindow.h"
#include "util.h"
#include"titlebar.h"
#include"centerwindow.h"
#include<QtCore>

#include<QMouseEvent>
#include<QKeyEvent>
#include <QDesktopWidget>
#include<QApplication>
#include<QDebug>
#include<QDir>

FMainWindow::FMainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    qDebug("mainwindow init");
    initData();
    initUI();
    initConnect();
}

void FMainWindow::initData()
{
    leftbuttonpressed = false;
}

void FMainWindow::initUI()
{
    titleBar = new FTitleBar;

    setObjectName(QString("FMainWindow"));
    QDesktopWidget* desktopWidget = QApplication::desktop();
    setMaximumSize(desktopWidget->availableGeometry().size());
    readSettings();

    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinimizeButtonHint);
    setWindowTitle("QFramer");

    pstatusbar = new QStatusBar;
    setStatusBar(pstatusbar);
    trayicon = new QSystemTrayIcon(QIcon(QString(":/skin/images/QFramer.ico")), this);
    trayicon->setObjectName(QString("trayicon"));
    trayicon->show();

    flyWidget = new FlyWidget(this);
    flyWidget->move(desktopWidget->availableGeometry().width() * 0.8, desktopWidget->availableGeometry().height() *0.2);

    QString qss = getQssFromFile(QString(":/skin/qss/main.qss"));
    setStyleSheet(qss);
}


void FMainWindow::initConnect( )
{
    connect(titleBar, SIGNAL(minimuned()), this, SLOT(hide()));
    connect(titleBar, SIGNAL(minimuned()), this, SLOT(showFlyWidget()));
    connect(titleBar, SIGNAL(maximumed()), this, SLOT(swithMaxNormal()));
    connect(titleBar, SIGNAL(closed()), this, SLOT(hide()));
    connect(titleBar, SIGNAL(closed()), this, SLOT(showFlyWidget()));
    connect(trayicon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)),
            this, SLOT(onSystemTrayIconClicked(QSystemTrayIcon::ActivationReason)));
}


void FMainWindow::readSettings()
{
   QDesktopWidget* desktopWidget = QApplication::desktop();
   int w = desktopWidget->availableGeometry().width();
   int h = desktopWidget->availableGeometry().height();
   QSettings settings(QDir::currentPath() + "/QFramer.ini", QSettings::IniFormat);
   settings.beginGroup("FMainWindow");
   resize(settings.value("size", QSize(w * 0.8, h * 0.8)).toSize());
   printf("%d\n" ,(settings.value("size", QSize(w * 0.8, h * 0.8)).toSize().height()));
   printf("%d\n" ,(settings.value("size", QSize(w * 0.8, h * 0.8)).toSize().width()));
   move(settings.value("pos", QPoint(w * 0.1, h * 0.1)).toPoint());
   settings.endGroup();
}

void FMainWindow::writeSettings()
{
    QSettings settings(QDir::currentPath() + "/QFramer.ini", QSettings::IniFormat);
    qDebug(qPrintable(QDir::currentPath() + "/QFramer.ini"));
    settings.beginGroup("FMainWindow");
    settings.setValue("size", size());
    settings.setValue("pos", pos());
    settings.endGroup();
}

void FMainWindow::swithMaxNormal()
{
    if(isMaximized())
    {
        showNormal();
    }else{
        showMaximized();
    }
}


void FMainWindow::showFlyWidget()
{
    flyWidget->show();
}

void FMainWindow::mousePressEvent(QMouseEvent *e)
{
    if(e->button() & Qt::LeftButton)
    {
        dragPosition = e->globalPos() - frameGeometry().topLeft();
        leftbuttonpressed = true;
    }
    e->accept();
}

void FMainWindow::mouseDoubleClickEvent(QMouseEvent *e)
{
    if(e->y() < titleBar->height() and e->x() < titleBar->width() - 120)
    {
        swithMaxNormal();
        e->accept();
    }else{
        e->ignore();
    }
}

void FMainWindow::SetCursorStyle(enum_Direction direction)
{
    //设置上下左右以及右上、右下、左上、坐下的鼠标形状
    switch(direction)
    {
    case eTop:
    case eBottom:
        setCursor(Qt::SizeVerCursor);
        break;
    case eRight:
    case eLeft:
        setCursor(Qt::SizeHorCursor);
        break;
    case eNormal:
        setCursor(Qt::ArrowCursor);
    default:
        setCursor(Qt::ArrowCursor);
        break;
    }
}

void FMainWindow::mouseReleaseEvent(QMouseEvent *e)
{
    leftbuttonpressed = false;
    e->accept();
}

void FMainWindow::mouseMoveEvent(QMouseEvent *e)
{
    if(isMaximized())
    {
        e->ignore();
    }
    else
    {

        if(e->y() < titleBar->height() and e->x() > titleBar->width() - 120)
        {
            e->ignore();
        }
        else{
            move(e->globalPos() - dragPosition);
            e->accept();
        }
    }

}

void FMainWindow::keyPressEvent(QKeyEvent *e)
{
    if(e->key() == Qt::Key_Escape){
        close();
    }
    else if (e->key() == Qt::Key_F11) {
        titleBar->getMaxButton()->click();
    }
    else if (e->key() == Qt::Key_F6) {
        CenterWindow::getInstance()->swicthLayout(QBoxLayout::LeftToRight);
    }
}

void FMainWindow::closeEvent(QCloseEvent *event)
{
    writeSettings();
    QMainWindow::closeEvent(event);
}

void FMainWindow::onSystemTrayIconClicked(QSystemTrayIcon::ActivationReason reason)
{
    switch(reason)
        {
        //单击
        case QSystemTrayIcon::Trigger:
            //双击
        case QSystemTrayIcon::DoubleClick:
            if(isHidden())
            {
                //恢复窗口显示
                show();
                //一下两句缺一均不能有效将窗口置顶
                setWindowState(Qt::WindowActive);
                activateWindow();
            }
            else
            {
                hide();
            }
            break;
        case QSystemTrayIcon::Context:
            break;
        default:
            break;
        }
}

FMainWindow::~FMainWindow()
{
    printf("111111\n");
}
