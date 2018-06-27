#-------------------------------------------------
#
# Project created by QtCreator 2018-06-25T12:20:33
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SuperQTKalk
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    datamanager.cpp \
    drawbox.cpp \
    leftbox.cpp \
    rightbox.cpp \
    bottombox.cpp

HEADERS  += mainwindow.h \
    datamanager.h \
    drawbox.h \
    leftbox.h \
    rightbox.h \
    bottombox.h

FORMS    += mainwindow.ui
