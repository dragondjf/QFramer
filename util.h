#ifndef UTIL_H
#define UTIL_H
#include <stdio.h>
#include <stdlib.h>
#include <QFile>
#include <QTextStream>
#include<QJsonObject>
#include<QJsonArray>
#include<QDebug>

void myMessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg);
QString getQssFromFile(QString filename);
QString readFile(const QString filename);


#endif // UTIL_H
