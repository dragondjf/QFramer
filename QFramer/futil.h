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

#ifndef UTIL_H
#define UTIL_H
#include <stdio.h>
#include <stdlib.h>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QApplication>
#include <QFontDatabase>


#if QT_VERSION >= QT_VERSION_CHECK(5, 0, 0)
    void myMessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg);
    void loadFonts(QApplication& app);
#endif


QString getQssFromFile(QString filename);
QString readFile(const QString filename);
void setSkinForApp(QString filename);

#endif // UTIL_H
