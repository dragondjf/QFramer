#include "lockcontroller.h"
#include "mainwindow.h"
LockController::LockController(QObject *parent) :
    QObject(parent)
{

}

void LockController::lockMovable()
{
    MainWindow::getInstance()->setLockMoved(true);
    MainWindow::getInstance()->setLocked(true);
}

void LockController::lockUnmoved()
{
    MainWindow::getInstance()->setLockMoved(false);
    MainWindow::getInstance()->setLocked(true);
}

void LockController::unLock()
{
    MainWindow::getInstance()->setLocked(false);
}
