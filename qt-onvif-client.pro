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
    lib/messageparser.cpp \
    lib/service.cpp \
    lib/client.cpp \
    lib/devicemanagement.cpp \
    lib/device_management/systemdateandtime.cpp \
    test/testdevicemanagement.cpp \
    lib/device_management/systemfactorydefault.cpp \
    lib/device_management/user.cpp \
    lib/device_management/systemreboot.cpp \
    lib/device_management/networkinterfaces.cpp \
    lib/device_management/networkprotocols.cpp \
    lib/device_management/capabilities.cpp

HEADERS += \
    lib/message.h \
    test/testmesasge.h \
    lib/devicesearcher.h \
    lib/messageparser.h \
    lib/service.h \
    lib/client.h \
    lib/devicemanagement.h \
    lib/device_management/systemdateandtime.h \
    test/testdevicemanagement.h \
    lib/device_management/user.h \
    lib/device_management/systemfactorydefault.h \
    lib/device_management/systemreboot.h \
    lib/device_management/networkinterfaces.h \
    lib/device_management/networkprotocols.h \
    lib/device_management/capabilities.h
