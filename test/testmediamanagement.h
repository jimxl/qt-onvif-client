#ifndef TESTMEDIAMANAGEMENT_H
#define TESTMEDIAMANAGEMENT_H
#include <QObject>
#include "lib/mediamanagement.h"

class TestMediaManagement : public QObject {
    Q_OBJECT
public:
    explicit TestMediaManagement(QObject *parent = 0);

private slots:
    void initTestCase();
    void getVideoSourceConfigurations();
    void getVideoEncoderConfigurations();
    void getProfiles();
    void getProfile720P();
    void getProfileD1();
    void getAudioSourceConfigurations();
    void getAudioEncoderConfigurations();
    void getVideoSourceConfiguration();
    void getVideoEncoderConfiguration();
    void getAudioEncoderConfiguration();
    void getAudioEncoderConfigurationOptions();
    void getVideoEncoderConfigurationOptions();
    void getStreamUri();
    void cleanupTestCase();
private:
    ONVIF::MediaManagement *mMediaManagement;

};
#endif // TESTMEDIAMANAGEMENT_H
