/****************************************************************************
**
** Copyright (C) 2014 dragondjf
**
** QFramer is a frame based on Qt5.3, you will be more efficient with it. 
** As an Qter, Qt give us a nice coding experience. With user interactive experience(UE) 
** become more and more important in modern software, deveployers should consider business and UE.
** So, QFramer is born. QFramer's goal is to be a mature solution 
** which you only need to be focus on your business but UE for all Qters.
**
** Version	: 0.2.5.0
** Author	: dragondjf
** Website	: https://github.com/dragondjf
** Project	: https://github.com/dragondjf/QCFramer
** Blog		: http://my.oschina.net/dragondjf/home/?ft=atme
** Wiki		: https://github.com/dragondjf/QCFramer/wiki
** Lincence: LGPL V2
** QQ: 465398889
** Email: dragondjf@gmail.com, ding465398889@163.com, 465398889@qq.com
** 
****************************************************************************/

#include "futil.h"

#if QT_VERSION >= QT_VERSION_CHECK(5, 0, 0)
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

void loadFonts(QApplication& app) {
    QFontDatabase database;
    QStringList fontlist = database.families();

    QStringList preferList;
//    preferList.append("Microsoft YaHei UI");
//    preferList.append("微软雅黑");
    preferList.append("SimSong");
    preferList.append("宋体");
    preferList.append("WenQuanYi Micro Hei");
    preferList.append("文泉驿微米黑");

    foreach (QString font, preferList) {
        if (fontlist.contains(font)) {
            app.setFont(QFont(font));
            qDebug()<<&app<<" set font: "<<font;
            return;
        }
    }
}
#endif



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


void setSkinForApp(QString filename)
{
    QString qss = getQssFromFile(filename);
    qApp->setStyleSheet(qss);
}
