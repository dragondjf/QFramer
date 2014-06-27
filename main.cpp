#include <QApplication>
#include "util.h"
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    qInstallMessageHandler(myMessageOutput);
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
