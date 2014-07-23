#include <QApplication>
#include "QFramer/futil.h"
#include "mainwindow/mainwindow.h"
int main(int argc, char *argv[])
{
    qInstallMessageHandler(myMessageOutput);
    QApplication app(argc, argv);
    QApplication::setOrganizationName("DJF");
    QApplication::setOrganizationDomain("https://github.com/dragondjf");
    QApplication::setApplicationName("QFramer");

    MainWindow *main = MainWindow::getInstance();
    setSkinForApp(QString(":/qss/skin/qss/main.qss"));
    main->setAttribute(Qt::WA_DeleteOnClose);
    main->show();
    return app.exec();
}
