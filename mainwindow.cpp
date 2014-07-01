#include "mainwindow.h"
#include "util.h"
#include<QtCore>

#include<QMouseEvent>
#include<QKeyEvent>
#include <QDesktopWidget>
#include<QApplication>
#include<QDebug>
#include<QDir>

MainWindow* MainWindow::instance = NULL;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    qDebug("mainwindow init");
    initData();
    initUI();
    initConnect();
}

void MainWindow::initData()
{
    leftbuttonpressed = false;
}

void MainWindow::initUI()
{
    QDesktopWidget* desktopWidget = QApplication::desktop();
    setMaximumSize(desktopWidget->availableGeometry().size());
    readSettings();

    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinimizeButtonHint);
    setWindowTitle("QFramer");

    centerwindow = new CenterWindow();
    pstatusbar = new QStatusBar;
    setCentralWidget(centerwindow);
    setStatusBar(pstatusbar);

    trayicon = new QSystemTrayIcon(QIcon(QString(":/skin/images/QFramer.ico")), this);
    trayicon->setContextMenu(centerwindow->titleBar->settingMenu);
    trayicon->show();

    flyWidget = new FlyWidget(this);
    flyWidget->menu = centerwindow->titleBar->settingMenu;
    flyWidget->move(desktopWidget->availableGeometry().width() * 0.8, desktopWidget->availableGeometry().height() *0.2);

    QString qss = getQssFromFile(QString(":/skin/qss/main.qss"));
    setStyleSheet(qss);
}

void MainWindow::initConnect()
{
    connect(centerwindow->titleBar, SIGNAL(minimuned()), this, SLOT(hide()));
    connect(centerwindow->titleBar, SIGNAL(minimuned()), this, SLOT(showFlyWidget()));
    connect(centerwindow->titleBar, SIGNAL(maximumed()), this, SLOT(swithMaxNormal()));
    connect(centerwindow->titleBar, SIGNAL(closed()), this, SLOT(hide()));
    connect(centerwindow->titleBar, SIGNAL(closed()), this, SLOT(showFlyWidget()));
    connect(trayicon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)),
            this, SLOT(onSystemTrayIconClicked(QSystemTrayIcon::ActivationReason)));

}

MainWindow* MainWindow::getInstance()
{
    if(!instance)
    {
        instance = new MainWindow();
    }
    return instance;
}

void MainWindow::readSettings()
{
   QDesktopWidget* desktopWidget = QApplication::desktop();
   int w = desktopWidget->availableGeometry().width();
   int h = desktopWidget->availableGeometry().height();
   QSettings settings(QDir::currentPath() + "/QFramer.ini", QSettings::IniFormat);
   settings.beginGroup("MainWindow");
   resize(settings.value("size", QSize(w * 0.8, h * 0.8)).toSize());
   printf("%d\n" ,(settings.value("size", QSize(w * 0.8, h * 0.8)).toSize().height()));
   printf("%d\n" ,(settings.value("size", QSize(w * 0.8, h * 0.8)).toSize().width()));
   move(settings.value("pos", QPoint(w * 0.1, h * 0.1)).toPoint());
   settings.endGroup();

}

void MainWindow::writeSettings()
{
    QSettings settings(QDir::currentPath() + "/QFramer.ini", QSettings::IniFormat);
    qDebug(qPrintable(QDir::currentPath() + "/QFramer.ini"));
    settings.beginGroup("MainWindow");
    settings.setValue("size", size());
    settings.setValue("pos", pos());
    settings.endGroup();
}

void MainWindow::swithMaxNormal()
{
    if(isMaximized())
    {
        showNormal();
    }else{
        showMaximized();
    }
}


void MainWindow::showFlyWidget()
{
    flyWidget->show();
}

void MainWindow::mousePressEvent(QMouseEvent *e)
{
    if(e->button() & Qt::LeftButton)
    {
        dragPosition = e->globalPos() - frameGeometry().topLeft();
        leftbuttonpressed = true;
    }
    e->accept();
}

void MainWindow::mouseDoubleClickEvent(QMouseEvent *e)
{
    if(e->y() < Title_Height and e->x() < centerwindow->titleBar->width() - 120)
    {
        swithMaxNormal();
        e->accept();
    }else{
        e->ignore();
    }
}

void MainWindow::SetCursorStyle(enum_Direction direction)
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

void MainWindow::mouseReleaseEvent(QMouseEvent *e)
{
    leftbuttonpressed = false;
    e->accept();
}

void MainWindow::mouseMoveEvent(QMouseEvent *e)
{
    if(isMaximized())
    {
        e->ignore();
    }
    else
    {

        if(e->y() < Title_Height and e->x() > centerwindow->titleBar->width() - 120)
        {
            e->ignore();
        }
        else{
            move(e->globalPos() - dragPosition);
            e->accept();
        }
    }

}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
    if(e->key() == Qt::Key_Escape){
        close();
    }
    else if (e->key() == Qt::Key_F11) {
        centerwindow->titleBar->maxButton->click();
    }
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    printf("=========");
    writeSettings();
    QMainWindow::closeEvent(event);
}

void MainWindow::onSystemTrayIconClicked(QSystemTrayIcon::ActivationReason reason)
{
    switch(reason)
        {
        //单击
        case QSystemTrayIcon::Trigger:
            //双击
        case QSystemTrayIcon::DoubleClick:
            if(this->isHidden())
            {
                //恢复窗口显示
                this->show();
                //一下两句缺一均不能有效将窗口置顶
                this->setWindowState(Qt::WindowActive);
                this->activateWindow();
            }
            else
            {
                this->hide();
            }
            break;
        case QSystemTrayIcon::Context:
            break;
        default:
            break;
        }
}

MainWindow::~MainWindow()
{
    printf("111111\n");
}
