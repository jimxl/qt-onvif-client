#ifndef TESTMESASGE_H
#define TESTMESASGE_H

#include <QObject>

class TestMesasge : public QObject {
    Q_OBJECT
public:
    TestMesasge(QObject *parent = NULL);

private slots:
    void testNamespaceOptions();
    void testMessageToString();
    
};

#endif // TESTMESASGE_H
