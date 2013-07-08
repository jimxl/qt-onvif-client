#-------------------------------------------------
#
# Project created by QtCreator 2013-07-08T17:08:39
#
#-------------------------------------------------

QT       += core testlib xml

QT       -= gui

TARGET = qt-onvif-client
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    lib/message.cpp \
    test/testmesasge.cpp

HEADERS += \
    lib/message.h \
    test/testmesasge.h
