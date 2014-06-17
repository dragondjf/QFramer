#ifndef UTIL_H
#define UTIL_H
#include <stdio.h>
#include <stdlib.h>
#include <QFile>
#include <QTextStream>

void myMessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    QByteArray localMsg = msg.toLocal8Bit();
    QString outmsg;

    switch (type) {
    case QtDebugMsg:
        fprintf(stderr, "Debug: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
        outmsg = QString("Debug: %1 %2 %3 %4\n").arg(localMsg.constData(), context.file, QString(context.line), context.function);
        break;
    case QtWarningMsg:
        fprintf(stderr, "Warning: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
        outmsg = QString("Warning: %1 %2 %3 %4 \n").arg(localMsg.constData(), context.file, QString(context.line), context.function);
        break;
    case QtCriticalMsg:
        fprintf(stderr, "Critical: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
        outmsg = QString("Critical: %1 %2 %3 %4 \n").arg(localMsg.constData(), context.file, QString(context.line), context.function);
        break;
    case QtFatalMsg:
        fprintf(stderr, "Fatal: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
        outmsg = QString("Fatal: %1 %2 %3 %4 \n").arg(localMsg.constData(), context.file, QString(context.line), context.function);
        abort();
    }

    QFile outFile("debuglog.txt");
    outFile.open(QIODevice::WriteOnly | QIODevice::Append);
    QTextStream ts(&outFile);
    ts << outmsg <<endl;
}
#endif // UTIL_H
