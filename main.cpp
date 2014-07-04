#include <QApplication>
#include "util.h"
#include "mainwindow.h"
#include "webkitshow.h"
int main(int argc, char *argv[])
{
    qInstallMessageHandler(myMessageOutput);
    QApplication a(argc, argv);
    QApplication::setOrganizationName("DJF");
    QApplication::setOrganizationDomain("https://github.com/dragondjf");
    QApplication::setApplicationName("QFramer");

    MainWindow *main = MainWindow::getInstance();
    main->show();

//    WebkitShow w;
//    w.show();
    return a.exec();
    delete main;
}
