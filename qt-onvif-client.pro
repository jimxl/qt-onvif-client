#-------------------------------------------------
#
# Project created by QtCreator 2013-07-08T17:08:39
#
#-------------------------------------------------

QT       += core testlib xml network xmlpatterns

QT       -= gui

TARGET = qt-onvif-client
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    lib/message.cpp \
    test/testmesasge.cpp \
    lib/devicesearcher.cpp \
    lib/messageparser.cpp

HEADERS += \
    lib/message.h \
    test/testmesasge.h \
    lib/devicesearcher.h \
    lib/messageparser.h
