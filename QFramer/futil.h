#ifndef UTIL_H
#define UTIL_H
#include <stdio.h>
#include <stdlib.h>
#include <QFile>
#include <QTextStream>
#include<QDebug>
#include <QApplication>
void myMessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg);
QString getQssFromFile(QString filename);
QString readFile(const QString filename);
QString setSkinForApp(QApplication &app, QString filename);

#endif // UTIL_H
