#-------------------------------------------------
#
# Project created by QtCreator 2015-04-20T22:03:18
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtImageDetector
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    imagehandler.cpp

HEADERS  += mainwindow.h \
    imagehandler.h

FORMS    += mainwindow.ui

DISTFILES += \
    bwb.jpg

RESOURCES += \
    resources.qrc
