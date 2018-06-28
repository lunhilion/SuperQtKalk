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
    bottombox.cpp \
    Model/colore.cpp \
    rgb.cpp \
    Model/rgb.cpp \
    Model/poligono.cpp \
    Model/latifiniti.cpp \
    Model/punto.cpp \
    Model/triangolo.cpp \
    Model/circonferenza.cpp \
    Model/quadrilatero.cpp \
    Model/cmyk.cpp

HEADERS  += mainwindow.h \
    datamanager.h \
    drawbox.h \
    leftbox.h \
    rightbox.h \
    bottombox.h \
    Model/colore.h \
    rgb.h \
    Model/rgb.h \
    Model/poligono.h \
    Model/latifiniti.h \
    Model/punto.h \
    Model/triangolo.h \
    Model/circonferenza.h \
    Model/cmyk.h \
    Model/quadrilatero.h

FORMS    += mainwindow.ui
