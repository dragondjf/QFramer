#-------------------------------------------------
#
# Project created by QtCreator 2014-06-06T21:53:56
#
#-------------------------------------------------

QT       += core gui  widgets
QT += network
QT += printsupport
QT += multimedia
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QFramer
TEMPLATE = app
#CONFIG += console

SOURCES += main.cpp\
    QFramer/fbasedialog.cpp \
    QFramer/fcenterwindow.cpp \
    QFramer/fnavgationbar.cpp \
    QFramer/ftitlebar.cpp \
    QFramer/fbasetoolbutton.cpp \
    QFramer/fmainwindow.cpp \
    QFramer/futil.cpp \
    QFramer/flywidget.cpp \
    functionpages/gradientshow.cpp \
    mainwindow/centerwindow.cpp \
    mainwindow/mainwindow.cpp \
    mainwindow/settingmenu.cpp \
    mainwindow/settingmenucontroller.cpp \
    dialogs/aboutdialog.cpp \
    dialogs/bgskinpopup.cpp \
    dialogs/settingdialog.cpp \
    functionpages/pdftool.cpp \
    qcustomplot/qcustomplot.cpp \
    functionpages/mathplot.cpp \
    qcustomplot/fcustomplot.cpp \
    QFramer/fbasepushbutton.cpp \
    functionpages/uielement.cpp \
    QFramer/ftabwidget.cpp \
    functionpages/rightfloatwindow.cpp \
    QFramer/fmovablewidget.cpp \
    mainwindow/lockmenu.cpp \
    mainwindow/lockcontroller.cpp \
    functionpages/ftablewidget.cpp \
    functionpages/aboutpage.cpp \
    QFramer/fshadowlabel.cpp \
    mainwindow/thememenu.cpp \
    QFramer/fwigglywidget.cpp \
    QFramer/fnofocusdelegate.cpp \
    functionpages/recordmanager.cpp \
    QFramer/fstatebutton.cpp \
    functionpages/audiorecord/qaudiolevel.cpp

HEADERS  += \
    QFramer/fbasedialog.h \
    QFramer/fcenterwindow.h \
    QFramer/fnavgationbar.h \
    QFramer/ftitlebar.h \
    QFramer/fbasetoolbutton.h \
    QFramer/fmainwindow.h \
    QFramer/futil.h \
    QFramer/flywidget.h \
    functionpages/gradientshow.h \
    mainwindow/centerwindow.h \
    mainwindow/mainwindow.h \
    mainwindow/settingmenu.h \
    mainwindow/settingmenucontroller.h \
    dialogs/aboutdialog.h \
    dialogs/bgskinpopup.h \
    dialogs/settingdialog.h \
    functionpages/pdftool.h \
    qcustomplot/qcustomplot.h \
    functionpages/mathplot.h \
    qcustomplot/fcustomplot.h \
    QFramer/fbasepushbutton.h \
    functionpages/uielement.h \
    QFramer/ftabwidget.h \
    functionpages/rightfloatwindow.h \
    QFramer/fmovablewidget.h \
    mainwindow/lockmenu.h \
    mainwindow/lockcontroller.h \
    functionpages/ftablewidget.h \
    functionpages/aboutpage.h \
    QFramer/fshadowlabel.h \
    mainwindow/thememenu.h \
    QFramer/fwigglywidget.h \
    QFramer/fnofocusdelegate.h \
    functionpages/recordmanager.h \
    QFramer/fstatebutton.h \
    functionpages/audiorecord/qaudiolevel.h

RESOURCES += \
    QFramer.qrc

RC_ICONS = "skin/images/QFramer.ico"
