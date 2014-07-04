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
<<<<<<< HEAD
    centerwindow.cpp \
    mainwindow.cpp \
    QFramer/fbasedialog.cpp \
    QFramer/fcenterwindow.cpp \
    QFramer/fnavgationbar.cpp \
    QFramer/ftitlebar.cpp \
    QFramer/fbasetoolbutton.cpp \
    settingmenu.cpp \
    settingmenucontroller.cpp \
    QFramer/fmainwindow.cpp

=======
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
>>>>>>> 93f3b82cf553ccbd90eec91b9860c38978134633

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
<<<<<<< HEAD
    centerwindow.h \
    mainwindow.h \
    QFramer/fbasedialog.h \
    QFramer/fcenterwindow.h \
    QFramer/fnavgationbar.h \
    QFramer/ftitlebar.h \
    QFramer/fbasetoolbutton.h \
    settingmenu.h \
    settingmenucontroller.h \
    QFramer/fmainwindow.h
=======
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

>>>>>>> 93f3b82cf553ccbd90eec91b9860c38978134633

RESOURCES += \
    QFramer.qrc

RC_ICONS = "skin/images/QFramer.ico"
