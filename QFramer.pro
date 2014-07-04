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
    util.cpp \
    aboutdialog.cpp \
    settingdialog.cpp \
    bgskinpopup.cpp \
    gradientshow.cpp \
    webkitshow.cpp \
    basequickwidget.cpp \
    qmlviwer.cpp \
    flywidget.cpp \
    QFramer/ftitlebar.cpp\
    centerwindow.cpp \
    fmainwindow.cpp \
    mainwindow.cpp \
    titlebar.cpp \
    qcustomplot.cpp \
    QFramer/fnavgationbar.cpp \
    QFramer/fbasetoolbutton.cpp \
    QFramer/fcenterwindow.cpp \
    QFramer/fbasedialog.cpp \
    settingmenu.cpp \
    settingmenucontroller.cpp

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
    QFramer/ftitlebar.h\
    centerwindow.h \
    fmainwindow.h \
    mainwindow.h \
    titlebar.h \
    qcustomplot.h \
    QFramer/fnavgationbar.h \
    QFramer/fbasetoolbutton.h \
    QFramer/fcenterwindow.h \
    QFramer/fbasedialog.h \
    settingmenu.h \
    settingmenucontroller.h


RESOURCES += \
    QFramer.qrc

RC_ICONS = "skin/images/QFramer.ico"
