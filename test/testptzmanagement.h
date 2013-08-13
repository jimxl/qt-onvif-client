#ifndef TESTPTZMANAGEMENT_H
#define TESTPTZMANAGEMENT_H
#include <QObject>
#include "lib/ptzmanagement.h"

class TestPtzManagement : public QObject {
    Q_OBJECT
public:
    explicit TestPtzManagement(QObject *parent = 0);

private slots:
    void initTestCase();
    void cleanupTestCase();
    void getConfigurations();
    void getPresets();
    void removePreset();
    void setPreset();
    void continuousMove();
    void absoluteMove();
    void relativeMove();
    void stop();
    void getNodes();
    void gotoPreset();
    void gotoHomePosition();
    void getConfiguration();
private:
    ONVIF::PtzManagement *mPtzManagement;

};
#endif // TESTPTZMANAGEMENT_H
