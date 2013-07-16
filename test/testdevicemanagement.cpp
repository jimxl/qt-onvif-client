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

void TestDeviceManagement::testSetSystemDateAndTime(){
    mDeviceManagement->setSystemDateAndTime();
}

void TestDeviceManagement::testSetSystemFactoryDefault(){
    mDeviceManagement->setSystemFactoryDefault();
}

void TestDeviceManagement::testSetSystemReboot(){
    mDeviceManagement->setSystemReboot();
}

void TestDeviceManagement::testGetUser(){
    Users *user = mDeviceManagement->getUser();
    QVERIFY(user != NULL);
    QCOMPARE(user->userName(),QString("admin"));
    QCOMPARE(user->passWord(),QString("admin"));
    QCOMPARE(user->userLevel(),Users::Administrator);
}

void TestDeviceManagement::testGetNetworkInterfaces()
{
    NetworkInterfaces *networkInterfaces = mDeviceManagement->getNetworkInterfaces();
    QVERIFY(networkInterfaces != NULL);
    QCOMPARE(networkInterfaces->networkInfacesEnabled(),true);
    QCOMPARE(networkInterfaces->networkInfacesName(),QString("NetworkInterfaces_Info_1"));
    QCOMPARE(networkInterfaces->hwAaddress(),QString("0000510203A1"));
    QCOMPARE(networkInterfaces->mtu(),1500);
    QCOMPARE(networkInterfaces->ipv4ManualAddress(),QString("192.168.2.145"));
    QCOMPARE(networkInterfaces->ipv4ManualPrefixLength(),24);
    QCOMPARE(networkInterfaces->ipv4LinkLocalAddress(),QString("192.168.2.145"));
    QCOMPARE(networkInterfaces->ipvLinkLocalPrefixLength(),24);
    QCOMPARE(networkInterfaces->ipv4FromDHCPAddress(),QString("192.168.2.145"));
    QCOMPARE(networkInterfaces->ipv4FromDHCPPrefixLength(),24);
    QCOMPARE(networkInterfaces->ipv4Enabled(),true);
}

void TestDeviceManagement::testSetNetworkInterfaces()
{
    mDeviceManagement->setNetworkInterfaces();
}

void TestDeviceManagement::testGetNetworkProtocols()
{
    NetworkProtocols *networkProtocols = mDeviceManagement->getNetworkProtocols();
    QVERIFY(networkProtocols != NULL);
    QCOMPARE(networkProtocols->networkProtocolsName(),QString("RTSP HTTP"));
    QCOMPARE(networkProtocols->networkProtocolsEnabled(),QString("true true"));
    QCOMPARE(networkProtocols->networkProtocolsPort(),QString("554 80"));
}


void TestDeviceManagement::cleanupTestCase() {
    if(mDeviceManagement != NULL) {
        delete mDeviceManagement;
        mDeviceManagement = NULL;
    }
}
