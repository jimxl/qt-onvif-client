#include "testmesasge.h"
#include "lib/message.h"
#include <QHash>
#include <QTest>
#include <QDebug>

using namespace ONVIF;


TestMesasge::TestMesasge(QObject *parent) : QObject(parent) {
    
}

void TestMesasge::testNamespaceOptions() {
//    QHash<QString, QString> namespaces;
//    namespaces.insert("soap", "http://www.w3.org/2003/05/soap-envelope");
//    Message *message = new Message(namespaces, "admin", "admin");
    
}

void TestMesasge::testMessageToString() {
    QHash<QString, QString> namespaces;
    Message *message = new Message(namespaces, "admin", "admin");
    QString message_result =
"<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n\
<soap:Envelope xmlns:soap=\"http://www.w3.org/2003/05/soap-envelope\">\
<soap:Header/>\
<soap:Body/>\
</soap:Envelope>";
    QCOMPARE(message->toXmlStr(), message_result);
}
