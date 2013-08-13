#ifndef TESTDEVICEMANAGEMENT_H
#define TESTDEVICEMANAGEMENT_H

#include <QObject>
#include "lib/devicemanagement.h"

class TestDeviceManagement : public QObject {
    Q_OBJECT
public:
    explicit TestDeviceManagement(QObject *parent = 0);
    
private slots:
    void initTestCase();
    void testGetDeviceInformation();
    void testGetSystemDateAndTime();
    void testSetSystemDateAndTime();
    void testSetSystemFactoryDefault();
    void testSystemReboot();
    void testGetUsers();
    void testGetNetworkInterfaces();
    void testGetNetworkProtocols();
    void testSetNetworkInterfaces();
    void testGetCapabilitiesPtz();
    void testGetCapabilitiesImaging();
    void testGetCapabilitiesMedia();
    void testGetCapabilitiesDevice();
    void cleanupTestCase();
private:
    ONVIF::DeviceManagement *mDeviceManagement;
    
};

#endif // TESTDEVICEMANAGEMENT_H
