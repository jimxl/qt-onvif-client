#include "testdevicemanagement.h"

#include <QTest>
#include <QDebug>

using namespace ONVIF;

TestDeviceManagement::TestDeviceManagement(QObject *parent) :
    QObject(parent)
{
}

void TestDeviceManagement::initTestCase() {
    mDeviceManagement = new DeviceManagement("http://192.168.2.145/onvif/device_service", "admin", "admin");
}

void TestDeviceManagement::testGetDeviceInformation() {
    QHash<QString, QString> device_info = mDeviceManagement->getDeviceInformation();
    QCOMPARE(device_info["mf"], QString("CNJABSCO"));
    QCOMPARE(device_info["model"], QString("jimxl-ipc"));
    QCOMPARE(device_info["firmware_version"], QString("V2.4.0010-20130524-V"));
    QCOMPARE(device_info["serial_number"], QString("83919274"));
    QCOMPARE(device_info["hardware_id"], QString("0000510203A1"));
}

void TestDeviceManagement::testGetSystemDateAndTime() {
    SystemDateAndTime *dt = mDeviceManagement->getSystemDateAndTime();
    QVERIFY(dt != NULL);
    QCOMPARE(dt->dateTimeType(), SystemDateAndTime::Manual);
    QCOMPARE(dt->daylightSavings(), false);
    QVERIFY(dt->utcTime().isValid());
}

void TestDeviceManagement::cleanupTestCase() {
    if(mDeviceManagement != NULL) {
        delete mDeviceManagement;
        mDeviceManagement = NULL;
    }
}
