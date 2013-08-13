#include <QCoreApplication>
#include <QTest>
#include <test/testmesasge.h>
#include <lib/devicesearcher.h>
#include <lib/client.h>
#include <lib/devicemanagement.h>
#include <test/testdevicemanagement.h>
#include <test/testmediamanagement.h>
#include <test/testptzmanagement.h>

using namespace ONVIF;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QTest::qExec((new TestMesasge()));
    QTest::qExec((new TestDeviceManagement()));
    QTest::qExec((new TestMediaManagement()));
    QTest::qExec((new TestPtzManagement()));
    
//    DeviceSearcher::instance()->sendSearchMsg();
    
//    Client client("http://192.168.2.145/onvif/device_service");
//    qDebug() << "request 1" << client.sendData("<?xml version=\"1.0\"?><soap:Envelope xmlns:soap=\"http://www.w3.org/2003/05/soap-envelope\" xmlns:wsdl=\"http://www.onvif.org/ver10/device/wsdl\"><soap:Header><wsse:Security xmlns:wsse=\"http://docs.oasis-open.org/wss/2004/01/oasis-200401-wss-wssecurity-secext-1.0.xsd\" xmlns:wsu=\"http://docs.oasis-open.org/wss/2004/01/oasis-200401-wss-wssecurity-utility-1.0.xsd\" soap:mustUnderstand=\"true\"><wsse:UsernameToken wsu:Id=\"UsernameToken-3\"><wsse:Username>admin</wsse:Username><wsse:Password Type=\"http://docs.oasis-open.org/wss/2004/01/oasis-200401-wss-username-token-profile-1.0#PasswordDigest\">z/Plmh5pTS6BMUf1QP4hoAOJxis=</wsse:Password><wsse:Nonce EncodingType=\"http://docs.oasis-open.org/wss/2004/01/oasis-200401-wss-soap-message-security-1.0#Base64Binary\">uZtxMbSpL+Knbld3lDnX3Q==</wsse:Nonce><wsu:Created>2013-06-21T05:07:47.374Z</wsu:Created></wsse:UsernameToken></wsse:Security></soap:Header><soap:Body><wsdl:GetDeviceInformation/></soap:Body></soap:Envelope>");
    
//    qDebug() << "request 2" << client.sendData("<?xml version=\"1.0\"?><soap:Envelope xmlns:soap=\"http://www.w3.org/2003/05/soap-envelope\" xmlns:wsdl=\"http://www.onvif.org/ver10/device/wsdl\"><soap:Header><wsse:Security xmlns:wsse=\"http://docs.oasis-open.org/wss/2004/01/oasis-200401-wss-wssecurity-secext-1.0.xsd\" xmlns:wsu=\"http://docs.oasis-open.org/wss/2004/01/oasis-200401-wss-wssecurity-utility-1.0.xsd\" soap:mustUnderstand=\"true\"><wsse:UsernameToken wsu:Id=\"UsernameToken-3\"><wsse:Username>admin</wsse:Username><wsse:Password Type=\"http://docs.oasis-open.org/wss/2004/01/oasis-200401-wss-username-token-profile-1.0#PasswordDigest\">z/Plmh5pTS6BMUf1QP4hoAOJxis=</wsse:Password><wsse:Nonce EncodingType=\"http://docs.oasis-open.org/wss/2004/01/oasis-200401-wss-soap-message-security-1.0#Base64Binary\">uZtxMbSpL+Knbld3lDnX3Q==</wsse:Nonce><wsu:Created>2013-06-21T05:07:47.374Z</wsu:Created></wsse:UsernameToken></wsse:Security></soap:Header><soap:Body><wsdl:GetDeviceInformation/></soap:Body></soap:Envelope>");
    
//    DeviceManagement *dm = new DeviceManagement("http://192.168.2.145/onvif/device_service", "admin", "admin");
//    qDebug() << dm->getDeviceInformation();
    
    return a.exec();
}
