#include <QCoreApplication>
#include <QTest>
#include <test/testmesasge.h>
#include <lib/devicesearcher.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QTest::qExec((new TestMesasge()));
    
    ONVIF::DeviceSearcher::instance()->sendSearchMsg();
    
    return a.exec();
}
