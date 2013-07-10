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
    void cleanupTestCase();
private:
    ONVIF::DeviceManagement *mDeviceManagement;
    
};

#endif // TESTDEVICEMANAGEMENT_H
