#include <QCoreApplication>
#include <QTest>
#include <test/testmesasge.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QTest::qExec((new TestMesasge()));
    return a.exec();
}
