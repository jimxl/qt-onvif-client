#include "testdevicemanagement.h"

#include <QTest>
#include <QDebug>

using namespace ONVIF;

TestDeviceManagement::TestDeviceManagement(QObject *parent) :
    QObject(parent)
{
}

void TestDeviceManagement::initTestCase() {
    mDeviceManagement = new DeviceManagement("http://192.168.2.113/onvif/device_service", "admin", "nvrnvr888");
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
    SystemDateAndTime *systemDateAndTime = new SystemDateAndTime();
    systemDateAndTime->setLocalTime(2010,5,5,5,5,5);
    systemDateAndTime->setDaylightSavings(false);
    systemDateAndTime->setTz("CST-8");
    mDeviceManagement->setSystemDateAndTime(systemDateAndTime);
    QCOMPARE(systemDateAndTime->result(),true);
}

void TestDeviceManagement::testSetSystemFactoryDefault(){
    SystemFactoryDefault *systemFactoryDefault = new SystemFactoryDefault();
    systemFactoryDefault->setFactoryDefault(SystemFactoryDefault::Hard);
    mDeviceManagement->setSystemFactoryDefault(systemFactoryDefault);
    QCOMPARE(systemFactoryDefault->result(),true);
}

void TestDeviceManagement::testSystemReboot(){
    SystemReboot *systemReboot = new SystemReboot();
  //  mDeviceManagement->systemReboot(systemReboot);
    QCOMPARE(systemReboot->result(),true);
}

void TestDeviceManagement::testGetUsers(){
    Users *user = mDeviceManagement->getUsers();
    QVERIFY(user != NULL);
    QCOMPARE(user->userName(),QString("admin"));
    QCOMPARE(user->passWord(),QString("admin"));
    QCOMPARE(user->userLevel(),Users::Administrator);
}

void TestDeviceManagement::testGetCapabilitiesPtz()
{
    Capabilities *cap = mDeviceManagement->getCapabilitiesPtz();
    QVERIFY(cap != NULL);
    QCOMPARE(cap->ptzXAddr(),QString("http://192.168.2.145:80/onvif/ptz_service"));
}

void TestDeviceManagement::testGetCapabilitiesImaging()
{
    Capabilities *cap = mDeviceManagement->getCapabilitiesImaging();
    QVERIFY(cap != NULL);
    QCOMPARE(cap->imagingXAddr(),QString("http://192.168.2.145:80//onvif/imaging_service"));
}

void TestDeviceManagement::testGetCapabilitiesMedia()
{
    Capabilities *cap = mDeviceManagement->getCapabilitiesMedia();
    QVERIFY(cap != NULL);
    QCOMPARE(cap->mediaXAddr(),QString("http://192.168.2.145:80/onvif/media_service"));
    QCOMPARE(cap->rtpMulticast(),true);
    QCOMPARE(cap->rtpRtspTcp(),true);
    QCOMPARE(cap->rtpTcp(),true);
}

void TestDeviceManagement::testGetCapabilitiesDevice()
{
    Capabilities *cap = mDeviceManagement->getCapabilitiesDevice();
    QVERIFY(cap != NULL);
    QCOMPARE(cap->deviceXAddr(),QString("http://192.168.2.145:80/onvif/device_service"));
    QCOMPARE(cap->iPFilter(),false);
    QCOMPARE(cap->zeroConfiguration(),false);
    QCOMPARE(cap->iPVersion6(),false);
    QCOMPARE(cap->dynDNS(),false);
    QCOMPARE(cap->disconveryResolve(),false);
    QCOMPARE(cap->discoveryBye(),false);
    QCOMPARE(cap->remoteDiscovery(),true);
    QCOMPARE(cap->systemBackup(),false);
    QCOMPARE(cap->systemLogging(),false);
    QCOMPARE(cap->firmwareUpgrade(),false);
    QCOMPARE(cap->major(),2);
    QCOMPARE(cap->minor(),0);
    QCOMPARE(cap->httpFirmwareUpgrade(),false);
    QCOMPARE(cap->httpSystemBackup(),false);
    QCOMPARE(cap->httpSystemLogging(),false);
    QCOMPARE(cap->httpSupportInformation(),false);
    QCOMPARE(cap->inputConnectors(),2);
    QCOMPARE(cap->relayOutputs(),2);
    QCOMPARE(cap->tls11(),false);
    QCOMPARE(cap->tls22(),false);
    QCOMPARE(cap->onboardKeyGeneration(),false);
    QCOMPARE(cap->accessPolicyConfig(),false);
    QCOMPARE(cap->x509Token(),false);
    QCOMPARE(cap->samlToken(),false);
    QCOMPARE(cap->kerberosToken(),false);
    QCOMPARE(cap->relToken(),false);
    QCOMPARE(cap->tls10(),false);
    QCOMPARE(cap->dot1x(),false);
    QCOMPARE(cap->remoteUserHanding(),false);
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
//    NetworkInterfaces *networkInterfaces = new NetworkInterfaces();
//    networkInterfaces->setNetworkInfacesEnabled(true);
//    networkInterfaces->setAutoNegotiation(true);
//    networkInterfaces->setSpeed(100);
//    networkInterfaces->setDuplex(NetworkInterfaces::Full);
//    networkInterfaces->setMtu(1500);
//    networkInterfaces->setIpv4Enabled(true);
//    networkInterfaces->setIpv4ManualAddress("192.168.2.145");
//    networkInterfaces->setIpv4ManualPrefixLength(24);
//    networkInterfaces->setIpv4DHCP(true);
//    mDeviceManagement->setNetworkInterfaces(networkInterfaces);
//    QCOMPARE(networkInterfaces->result(),true);
}

void TestDeviceManagement::testGetNetworkProtocols()
{
    NetworkProtocols *networkProtocols = mDeviceManagement->getNetworkProtocols();
    QVERIFY(networkProtocols != NULL);
    QCOMPARE(networkProtocols->getNetworkProtocolsName()[0],QString("RTSP"));
    QCOMPARE(networkProtocols->getNetworkProtocolsName()[1],QString("HTTP"));
    QCOMPARE(networkProtocols->getNetworkProtocolsEnabled()[0],true);
    QCOMPARE(networkProtocols->getNetworkProtocolsEnabled()[1],true);
    QCOMPARE(networkProtocols->getNetworkProtocolsPort()[0],554);
    QCOMPARE(networkProtocols->getNetworkProtocolsPort()[1],80);
}


void TestDeviceManagement::cleanupTestCase() {
    if(mDeviceManagement != NULL) {
        delete mDeviceManagement;
        mDeviceManagement = NULL;
    }
}
