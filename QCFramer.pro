#-------------------------------------------------
#
# Project created by QtCreator 2014-07-23T11:28:16
#
#-------------------------------------------------

QT       += core gui
QT += multimedia
QT += printsupport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QCFramer
TEMPLATE = app

SOURCES += \
    dialogs/aboutdialog.cpp \
    dialogs/bgskinpopup.cpp \
    dialogs/settingdialog.cpp \
    functionpages/audiorecord/qaudiolevel.cpp \
    functionpages/audiorecord/wavrecordmanager.cpp \
    functionpages/audiorecord/wavrecordwidget.cpp \
    functionpages/audiorecord/wavutil.cpp \
    functionpages/aboutpage.cpp \
    functionpages/ftablewidget.cpp \
    functionpages/gradientshow.cpp \
    functionpages/mathplot.cpp \
    functionpages/pdftool.cpp \
    functionpages/recordmanager.cpp \
    functionpages/rightfloatwindow.cpp \
    functionpages/uielement.cpp \
    mainwindow/centerwindow.cpp \
    mainwindow/lockcontroller.cpp \
    mainwindow/lockmenu.cpp \
    mainwindow/mainwindow.cpp \
    mainwindow/settingmenu.cpp \
    mainwindow/settingmenucontroller.cpp \
    mainwindow/thememenu.cpp \
    qcustomplot/fcustomplot.cpp \
    qcustomplot/qcustomplot.cpp \
    QFramer/fbasedialog.cpp \
    QFramer/fbasepushbutton.cpp \
    QFramer/fcenterwindow.cpp \
    QFramer/fcheckablebutton.cpp \
    QFramer/flywidget.cpp \
    QFramer/fmainwindow.cpp \
    QFramer/fmovablewidget.cpp \
    QFramer/fnavgationbar.cpp \
    QFramer/fnofocusdelegate.cpp \
    QFramer/fshadowlabel.cpp \
    QFramer/fstatebutton.cpp \
    QFramer/ftabwidget.cpp \
    QFramer/ftitlebar.cpp \
    QFramer/futil.cpp \
    QFramer/fwigglywidget.cpp \
    main.cpp

HEADERS  += \
    dialogs/aboutdialog.h \
    dialogs/bgskinpopup.h \
    dialogs/settingdialog.h \
    functionpages/audiorecord/qaudiolevel.h \
    functionpages/audiorecord/wavrecordmanager.h \
    functionpages/audiorecord/wavrecordwidget.h \
    functionpages/audiorecord/wavutil.h \
    functionpages/aboutpage.h \
    functionpages/ftablewidget.h \
    functionpages/gradientshow.h \
    functionpages/mathplot.h \
    functionpages/pdftool.h \
    functionpages/recordmanager.h \
    functionpages/rightfloatwindow.h \
    functionpages/uielement.h \
    mainwindow/centerwindow.h \
    mainwindow/lockcontroller.h \
    mainwindow/lockmenu.h \
    mainwindow/mainwindow.h \
    mainwindow/settingmenu.h \
    mainwindow/settingmenucontroller.h \
    mainwindow/thememenu.h \
    qcustomplot/fcustomplot.h \
    qcustomplot/qcustomplot.h \
    QFramer/fbasedialog.h \
    QFramer/fbasepushbutton.h \
    QFramer/fcenterwindow.h \
    QFramer/fcheckablebutton.h \
    QFramer/flywidget.h \
    QFramer/fmainwindow.h \
    QFramer/fmovablewidget.h \
    QFramer/fnavgationbar.h \
    QFramer/fnofocusdelegate.h \
    QFramer/fshadowlabel.h \
    QFramer/fstatebutton.h \
    QFramer/ftabwidget.h \
    QFramer/ftitlebar.h \
    QFramer/futil.h \
    QFramer/fwigglywidget.h

RESOURCES += \
    QCFramer.qrc

RC_ICONS = "skin/images/QFramer.ico"
