#-------------------------------------------------
#
# Project created by QtCreator 2018-04-18T17:22:28
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Cliente
TEMPLATE = app


SOURCES += main.cpp\
        cliente.cpp \
    observer.cpp \
    node_rr.cpp \
    ram_remoto.cpp

HEADERS  += cliente.h

FORMS    += cliente.ui

RESOURCES += \
    image.qrc
