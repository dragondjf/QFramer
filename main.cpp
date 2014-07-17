#include <QApplication>
#include "QFramer/futil.h"
#include "mainwindow/mainwindow.h"
#include "QFramer/futil.h"
int main(int argc, char *argv[])
{
    qInstallMessageHandler(myMessageOutput);
    QApplication app(argc, argv);
    QApplication::setOrganizationName("DJF");
    QApplication::setOrganizationDomain("https://github.com/dragondjf");
    QApplication::setApplicationName("QFramer");
    setSkinForApp(app, QString(":/qss/skin/qss/main.qss"));

    MainWindow *main = MainWindow::getInstance();
    main->setAttribute(Qt::WA_DeleteOnClose);
    main->show();
    return app.exec();
}
