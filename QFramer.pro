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
    navgationbar.cpp \
    basetoolbutton.cpp \
    util.cpp \
    basedialog.cpp \
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
    fsettingmenucontroller.cpp

HEADERS  += mainwindow.h \
    centerwindow.h \
    navgationbar.h \
    basetoolbutton.h \
    util.h \
    basedialog.h \
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
    fsettingmenucontroller.h

RESOURCES += \
    QFramer.qrc

RC_ICONS = "skin/images/QFramer.ico"
