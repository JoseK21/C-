#-------------------------------------------------
#
# Project created by QtCreator 2018-03-24T14:04:18
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
greaterThan(QT_MAJOR_VERSION, 4): QT += network

TARGET = Proyecto1_C
TEMPLATE = app


SOURCES += main.cpp\
    interface.cpp \
    observer.cpp \
    listasimple.cpp \
    nodos.cpp


HEADERS  += interface.h \
    tcp_client.h \
    rmlib.h \
    rmnode.h


FORMS    += interface.ui \


RESOURCES += \
    pics.qrc

DISTFILES +=


