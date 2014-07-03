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
    basetoolbutton.cpp \
    util.cpp \
    aboutdialog.cpp \
    settingdialog.cpp \
    bgskinpopup.cpp \
    gradientshow.cpp \
    webkitshow.cpp \
    basequickwidget.cpp \
    qmlviwer.cpp \
    flywidget.cpp \
    ftitlebar.cpp \
    fsettingmenu.cpp \
    fsettingmenucontroller.cpp \
    fnavgationbar.cpp \
    fcenterwindow.cpp \
    centerwindow.cpp \
    fbasedialog.cpp \
    fmainwindow.cpp \
    mainwindow.cpp \
    titlebar.cpp

HEADERS  += \
    basetoolbutton.h \
    util.h \
    aboutdialog.h \
    settingdialog.h \
    bgskinpopup.h \
    gradientshow.h \
    webkitshow.h \
    basequickwidget.h \
    qmlviwer.h \
    flywidget.h \
    ftitlebar.h \
    fsettingmenu.h \
    fsettingmenucontroller.h \
    fnavgationbar.h \
    fcenterwindow.h \
    centerwindow.h \
    fbasedialog.h \
    fmainwindow.h \
    mainwindow.h \
    titlebar.h

RESOURCES += \
    QFramer.qrc

RC_ICONS = "skin/images/QFramer.ico"
