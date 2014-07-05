#include <QApplication>
#include "QFramer/futil.h"
#include "mainwindow/mainwindow.h"
int main(int argc, char *argv[])
{
    qInstallMessageHandler(myMessageOutput);
    QApplication a(argc, argv);
    QApplication::setOrganizationName("DJF");
    QApplication::setOrganizationDomain("https://github.com/dragondjf");
    QApplication::setApplicationName("QFramer");

    MainWindow *main = MainWindow::getInstance();
    main->setAttribute(Qt::WA_DeleteOnClose);
    main->show();
    return a.exec();
}
