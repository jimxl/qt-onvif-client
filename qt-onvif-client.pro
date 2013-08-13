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
    lib/device_management/capabilities.cpp \
    lib/media_management/videosourceconfigurations.cpp \
    lib/mediamanagement.cpp \
    test/testmediamanagement.cpp \
    lib/media_management/videoencoderconfigurations.cpp \
    lib/media_management/profiles.cpp \
    lib/media_management/profile.cpp \
    lib/media_management/audiosourceconfiigurations.cpp \
    lib/media_management/audioencoderconfigurations.cpp \
    lib/media_management/videosourceconfiguration.cpp \
    lib/media_management/videoencoderconfiguration.cpp \
    lib/media_management/audioencoderconfiguration.cpp \
    lib/ptzmanagement.cpp \
    lib/ptz_management/configurations.cpp \
    test/testptzmanagement.cpp \
    lib/media_management/audioencoderconfigurationoptions.cpp \
    lib/media_management/videoencoderconfigurationoptions.cpp \
    lib/media_management/streamuri.cpp \
    lib/ptz_management/presets.cpp \
    lib/ptz_management/removepreset.cpp \
    lib/ptz_management/preset.cpp \
    lib/ptz_management/continuousmove.cpp \
    lib/ptz_management/absolutemove.cpp \
    lib/ptz_management/relativemove.cpp \
    lib/ptz_management/stop.cpp \
    lib/ptz_management/nodes.cpp \
    lib/ptz_management/gotopreset.cpp \
    lib/ptz_management/gotohomeposition.cpp \
    lib/ptz_management/configuration.cpp \
    lib/ptz_management/node.cpp

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
    lib/device_management/capabilities.h \
    lib/media_management/videosourceconfigurations.h \
    lib/mediamanagement.h \
    test/testmediamanagement.h \
    lib/media_management/videoencoderconfigurations.h \
    lib/media_management/audiosourceconfigurations.h \
    lib/media_management/profiles.h \
    lib/media_management/profile.h \
    lib/media_management/audioencoderconfigurations.h \
    lib/media_management/videosourceconfiguration.h \
    lib/media_management/videoencoderconfiguration.h \
    lib/media_management/audioencoderconfiguration.h \
    lib/ptz_management/configurations.h \
    lib/ptzmanagement.h \
    test/testptzmanagement.h \
    lib/media_management/audioencoderconfigurationoptions.h \
    lib/media_management/videoencoderconfigurationoptions.h \
    lib/media_management/streamuri.h \
    lib/ptz_management/presets.h \
    lib/ptz_management/removepreset.h \
    lib/ptz_management/preset.h \
    lib/ptz_management/continuousmove.h \
    lib/ptz_management/absolutemove.h \
    lib/ptz_management/relativemove.h \
    lib/ptz_management/stop.h \
    lib/ptz_management/nodes.h \
    lib/ptz_management/gotopreset.h \
    lib/ptz_management/gotohomeposition.h \
    lib/ptz_management/configuration.h \
    lib/ptz_management/node.h
