#-------------------------------------------------
#
# Project created by QtCreator 2014-06-06T21:53:56
#
#-------------------------------------------------

QT       += core gui quick widgets quickwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QFramer
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    centerwindow.cpp \
    titlebar.cpp \
    navgationbar.cpp \
    basetoolbutton.cpp

HEADERS  += mainwindow.h \
    centerwindow.h \
    util.h \
    titlebar.h \
    navgationbar.h \
    basetoolbutton.h

RESOURCES += \
    QFramer.qrc

RC_ICONS = "skin/images/QFramer.ico"
