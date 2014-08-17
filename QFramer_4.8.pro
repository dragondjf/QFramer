#-------------------------------------------------
#
# Project created by QtCreator 2014-08-13T09:26:14
#
#-------------------------------------------------

QT       += core gui printsupport

TARGET = QFramer_4.8
TEMPLATE = app

DEPENDPATH += .
INCLUDEPATH += .

CONFIG(debug, debug|release) {
    DESTDIR = ../QFramer_4.8_build/debug
    OBJECTS_DIR = ../QFramer_4.8_build/debug/.obj
    MOC_DIR = ../QFramer_4.8_build/debug/.moc
    RCC_DIR = ../QFramer_4.8_build/debug/.rcc
    UI_DIR = ../QFramer_4.8_build/debug/.ui
} else {
    DESTDIR = ../QFramer_4.8_build/release
    OBJECTS_DIR = ../QFramer_4.8_build/release/.obj
    MOC_DIR = ../QFramer_4.8_build/release/.moc
    RCC_DIR = ../QFramer_4.8_build/release/.rcc
    UI_DIR = ../QFramer_4.8_build/release/.ui
}

SOURCES += main.cpp\
    dialogs/aboutdialog.cpp \
    dialogs/bgskinpopup.cpp \
    dialogs/settingdialog.cpp \
    functionpages/aboutpage.cpp \
    functionpages/animationgradientlabel.cpp \
    functionpages/ftablewidget.cpp \
    functionpages/gradientshow.cpp \
    functionpages/mathplot.cpp \
    functionpages/qssbuilder.cpp \
    functionpages/rightfloatwindow.cpp \
    functionpages/uielement.cpp \
    functionpages/waterview.cpp \
    functionpages/waterwidget.cpp \
    mainwindow/centerwindow.cpp \
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
    mainwindow/mainwindow.cpp

HEADERS  +=\
    dialogs/aboutdialog.h \
    dialogs/bgskinpopup.h \
    dialogs/settingdialog.h \
    functionpages/aboutpage.h \
    functionpages/animationgradientlabel.h \
    functionpages/ftablewidget.h \
    functionpages/gradientshow.h \
    functionpages/mathplot.h \
    functionpages/qssbuilder.h \
    functionpages/rightfloatwindow.h \
    functionpages/uielement.h \
    functionpages/waterview.h \
    functionpages/waterwidget.h \
    mainwindow/centerwindow.h \
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
    QFramer/fwigglywidget.h \
    mainwindow/mainwindow.h

RESOURCES += \
    QCFramer.qrc

win32{
    RC_FILE = QFramer.rc
}
