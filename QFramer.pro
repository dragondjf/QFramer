#-------------------------------------------------
#
# Project created by QtCreator 2014-06-06T21:53:56
#
#-------------------------------------------------

QT       += core gui quick widgets quickwidgets
QT += webkitwidgets network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QFramer
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    centerwindow.cpp \
    titlebar.cpp \
    navgationbar.cpp \
    basetoolbutton.cpp \
    util.cpp \
    settingmenu.cpp \
    settingmenucontroller.cpp \
    basedialog.cpp \
    aboutdialog.cpp \
    settingdialog.cpp

HEADERS  += mainwindow.h \
    centerwindow.h \
    titlebar.h \
    navgationbar.h \
    basetoolbutton.h \
    util.h \
    settingmenu.h \
    settingmenucontroller.h \
    basedialog.h \
    aboutdialog.h \
    settingdialog.h

RESOURCES += \
    QFramer.qrc

RC_ICONS = "skin/images/QFramer.ico"
