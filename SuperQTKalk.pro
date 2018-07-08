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
    Controller/datamanager.cpp \
    Model/circonferenza.cpp \
    Model/cmyk.cpp \
    Model/colore.cpp \
    Model/latifiniti.cpp \
    Model/poligono.cpp \
    Model/punto.cpp \
    Model/quadrilatero.cpp \
    Model/rgb.cpp \
    Model/triangolo.cpp \
    View/bottombox.cpp \
    View/leftbox.cpp \
    View/mainwindow.cpp \
    View/rightbox.cpp \
    View/valueselector.cpp \
    View/drawbox.cpp \
    View/colorbox.cpp \
    Exception/kalkexception.cpp

HEADERS  +=  Controller/datamanager.h \
    Model/circonferenza.h \
    Model/cmyk.h \
    Model/colore.h \
    Model/latifiniti.h \
    Model/poligono.h \
    Model/punto.h \
    Model/quadrilatero.h \
    Model/rgb.h \
    Model/triangolo.h \
    View/bottombox.h \
    View/drawbox.h \
    View/leftbox.h \
    View/mainwindow.h \
    View/rightbox.h \
    View/valueselector.h \
    View/colorbox.h \
    Exception/kalkexception.h
