#include "futil.h"

void myMessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    QByteArray localMsg = msg.toLocal8Bit();
    QString outmsg;

    switch (type) {
        case QtDebugMsg:
            fprintf(stderr, "Debug: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
            outmsg = QString("Debug: %1 %2 %3 %4\r\n").arg(localMsg.constData(), context.file, QString(context.line), context.function);
            break;
        case QtWarningMsg:
            fprintf(stderr, "Warning: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
            outmsg = QString("Warning: %1 %2 %3 %4 \r\n").arg(localMsg.constData(), context.file, QString(context.line), context.function);
            break;
        case QtCriticalMsg:
            fprintf(stderr, "Critical: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
            outmsg = QString("Critical: %1 %2 %3 %4 \r\n").arg(localMsg.constData(), context.file, QString(context.line), context.function);
            break;
        case QtFatalMsg:
            fprintf(stderr, "Fatal: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
            outmsg = QString("Fatal: %1 %2 %3 %4 \r\n").arg(localMsg.constData(), context.file, QString(context.line), context.function);
            abort();
    }

    QFile outFile("debuglog.txt");
    outFile.open(QIODevice::WriteOnly | QIODevice::Append);
    QTextStream ts(&outFile);
    ts << outmsg <<endl;
}


QString getQssFromFile(QString filename)
{
    QFile f(filename);
    QString qss = "";
    if (f.open(QFile::ReadOnly))
    {
        qss = QLatin1String(f.readAll());
        f.close();
    }
    return qss;
};

QString readFile(const QString filename)
{
    QFile f(filename);
    if (!f.open(QFile::ReadOnly | QFile::Text)) {
        return QString();
    } else {
        QTextStream in(&f);
        return in.readAll();
    }
}


QString setSkinForApp(QApplication &app, QString filename)
{
    QString qss = getQssFromFile(filename);
    app.setStyleSheet(qss);
}
