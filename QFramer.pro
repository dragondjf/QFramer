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
    aboutdialog.cpp \
    settingdialog.cpp \
    bgskinpopup.cpp \
    gradientshow.cpp \
    webkitshow.cpp \
    basequickwidget.cpp \
    qmlviwer.cpp \
    flywidget.cpp \
    centerwindow.cpp \
    mainwindow.cpp \
    QFramer/fbasedialog.cpp \
    QFramer/fcenterwindow.cpp \
    QFramer/fnavgationbar.cpp \
    QFramer/ftitlebar.cpp \
    QFramer/fbasetoolbutton.cpp \
    settingmenu.cpp \
    settingmenucontroller.cpp \
    QFramer/fmainwindow.cpp \
    QFramer/futil.cpp

HEADERS  += \
    util.h \
    aboutdialog.h \
    settingdialog.h \
    bgskinpopup.h \
    gradientshow.h \
    webkitshow.h \
    basequickwidget.h \
    qmlviwer.h \
    flywidget.h \
    centerwindow.h \
    mainwindow.h \
    QFramer/fbasedialog.h \
    QFramer/fcenterwindow.h \
    QFramer/fnavgationbar.h \
    QFramer/ftitlebar.h \
    QFramer/fbasetoolbutton.h \
    settingmenu.h \
    settingmenucontroller.h \
    QFramer/fmainwindow.h \
    QFramer/futil.h

RESOURCES += \
    QFramer.qrc

RC_ICONS = "skin/images/QFramer.ico"
