#-------------------------------------------------
#
# Project created by QtCreator 2014-06-06T21:53:56
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QFramer
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    centerwindow.cpp

HEADERS  += mainwindow.h \
    centerwindow.h \
    util.h

RESOURCES += \
    QFramer.qrc

RC_ICONS = "skin/images/QFramer.ico"
