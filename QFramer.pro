#-------------------------------------------------
#
# Project created by QtCreator 2014-07-23T11:28:16
#
#-------------------------------------------------

QT       += core gui printsupport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

# application name
TARGET = QFramer

# type
TEMPLATE = app

DEPENDPATH += .
INCLUDEPATH += .

include(./QFramer/QFramer.pri)

# build dir
BuildDir =build_$$QT_VERSION

CONFIG(debug, debug|release) {
    DESTDIR = $$PWD/$$BuildDir/debug
    OBJECTS_DIR = $$PWD/$$BuildDir/debug/.obj
    MOC_DIR = $$PWD/$$BuildDir/debug/.moc
    RCC_DIR = $$PWD/$$BuildDir/debug/.rcc
    UI_DIR = $$PWD/$$BuildDir/debug/.ui
} else {
    DESTDIR = $$PWD/$$BuildDir/release
    OBJECTS_DIR = $$PWD/$$BuildDir/release/.obj
    MOC_DIR = $$PWD/$$BuildDir/release/.moc
    RCC_DIR = $$PWD/$$BuildDir/release/.rcc
    UI_DIR = $$PWD/$$BuildDir/release/.ui
}

# source
SOURCES += \
    dialogs/aboutdialog.cpp \
    dialogs/bgskinpopup.cpp \
    dialogs/settingdialog.cpp \
    functionpages/aboutpage.cpp \
    functionpages/ftablewidget.cpp \
    functionpages/gradientshow.cpp \
    functionpages/mathplot.cpp \
    functionpages/rightfloatwindow.cpp \
    functionpages/uielement.cpp \
    mainwindow/centerwindow.cpp \
    mainwindow/mainwindow.cpp \
    mainwindow/settingmenu.cpp \
    mainwindow/settingmenucontroller.cpp \
    mainwindow/thememenu.cpp \
    qcustomplot/fcustomplot.cpp \
    qcustomplot/qcustomplot.cpp \
    main.cpp \
    functionpages/waterwidget.cpp \
    functionpages/waterview.cpp \
    functionpages/animationgradientlabel.cpp \
    functionpages/qssbuilder.cpp

# header
HEADERS  += \
    dialogs/aboutdialog.h \
    dialogs/bgskinpopup.h \
    dialogs/settingdialog.h \
    functionpages/aboutpage.h \
    functionpages/ftablewidget.h \
    functionpages/gradientshow.h \
    functionpages/mathplot.h \
    functionpages/rightfloatwindow.h \
    functionpages/uielement.h \
    mainwindow/centerwindow.h \
    mainwindow/mainwindow.h \
    mainwindow/settingmenu.h \
    mainwindow/settingmenucontroller.h \
    mainwindow/thememenu.h \
    qcustomplot/fcustomplot.h \
    qcustomplot/qcustomplot.h \
    functionpages/waterwidget.h \
    functionpages/waterview.h \
    functionpages/animationgradientlabel.h \
    functionpages/qssbuilder.h

# resources
RESOURCES += \
    QFramer.qrc

FORMS += \
    skin/ui/form.ui

# QT4.8 applciation icon
contains(QT_MAJOR_VERSION, 4){
    win32{
        RC_FILE = QFramer.rc
    }
}

# QT5 applciation icon
contains(QT_MAJOR_VERSION, 5){
    RC_ICONS = "skin/images/QFramer.ico"
}
