#include "testmediamanagement.h"

#include <QTest>
#include <QDebug>

using namespace ONVIF;

TestMediaManagement::TestMediaManagement(QObject *parent) :
    QObject(parent)
{
}

void TestMediaManagement::initTestCase() {
    mMediaManagement = new MediaManagement("http://192.168.2.113/onvif/media_service", "admin", "nvrnvr888");
}

void TestMediaManagement::cleanupTestCase() {
    if(mMediaManagement != NULL) {
        delete mMediaManagement;
        mMediaManagement = NULL;
    }
}

void TestMediaManagement::getVideoSourceConfigurations()
{
     VideoSourceConfigurations *videoSourceConfigurations = mMediaManagement->getVideoSourceConfigurations();
     QCOMPARE(videoSourceConfigurations->getName()[0],QString("profile_VideoSource_1"));
     QCOMPARE(videoSourceConfigurations->getUseCount()[0],2);
     QCOMPARE(videoSourceConfigurations->getSourceToken()[0],QString("VideoSource_1"));
     QRect rect(0,0,352,288);
     QCOMPARE(videoSourceConfigurations->getBounds()[0],rect);
}

void TestMediaManagement::getVideoEncoderConfigurations()
{
    VideoEncoderConfigurations *videoEncoderConfigurations = mMediaManagement->getVideoEncoderConfigurations();
    QCOMPARE(videoEncoderConfigurations->getToken()[0],QString("profile_video_stream_CIF"));
    QCOMPARE(videoEncoderConfigurations->getName()[0],QString("profile_video_stream_CIF"));
    QCOMPARE(videoEncoderConfigurations->getUseCount()[0],1);
    QCOMPARE(videoEncoderConfigurations->getEncoding()[0],QString("H264"));
    QCOMPARE(videoEncoderConfigurations->getWidth()[0],352);
    QCOMPARE(videoEncoderConfigurations->getHeight()[0],288);
    QCOMPARE(videoEncoderConfigurations->getQuality()[0],100);
    QCOMPARE(videoEncoderConfigurations->getFrameRateLimit()[0],10);
    QCOMPARE(videoEncoderConfigurations->getEncodingInterval()[0],15);
    QCOMPARE(videoEncoderConfigurations->getBitrateLimit()[0],120);
    QCOMPARE(videoEncoderConfigurations->getGovLength()[0],30);
    QCOMPARE(videoEncoderConfigurations->getH264Profile()[0],QString("Main"));
    QCOMPARE(videoEncoderConfigurations->getType()[0],QString("IPv4"));
    QCOMPARE(videoEncoderConfigurations->getIpv4Address()[0],QString("239.255.0.0"));
    QCOMPARE(videoEncoderConfigurations->getIpv6Address()[0],QString("0000:0000:0000:0000:0000:0000:0000:0000"));
    QCOMPARE(videoEncoderConfigurations->getPort()[0],1024);
    QCOMPARE(videoEncoderConfigurations->getTtl()[0],1);
    QCOMPARE(videoEncoderConfigurations->getAutoStart()[0],false);
}

void TestMediaManagement::getProfiles()
{
//    Profiles *profiles = mMediaManagement->getProfiles();
//    QCOMPARE(profiles->m_toKenPro[0],QString("profile_720P"));
//    QCOMPARE(profiles->m_toKenPro[1],QString("profile_D1"));
//    QCOMPARE(profiles->m_fixed[0],true);
//    QCOMPARE(profiles->m_fixed[1],true);
//    QCOMPARE(profiles->m_namePro[0],QString("profile_720P"));
//    QCOMPARE(profiles->m_namePro[1],QString("profile_D1"));
//    QCOMPARE(profiles->m_useCountVsc[0],2);
//    QCOMPARE(profiles->m_useCountVsc[1],2);
//    QCOMPARE(profiles->m_sourceTokenVsc[0],QString("VideoSource_1"));
//    QCOMPARE(profiles->m_sourceTokenVsc[1],QString("VideoSource_1"));
//    QRect rect(0,0,1280,720);
//    QRect rect1(0,0,720,576);
//    QCOMPARE(profiles->m_boundsVsc[0],rect);
//    QCOMPARE(profiles->m_boundsVsc[1],rect1);
//    QCOMPARE(profiles->m_nameVec[0],QString("profile_video_stream_720P"));
//    QCOMPARE(profiles->m_nameVec[1],QString("profile_video_stream_D1"));
//    QCOMPARE(profiles->m_useCountVec[0],1);
//    QCOMPARE(profiles->m_useCountVec[1],1);
//    QCOMPARE(profiles->m_encodingVec[0],QString("H264"));
//    QCOMPARE(profiles->m_encodingVec[1],QString("H264"));
//    QCOMPARE(profiles->m_widthVec[0],1280);
//    QCOMPARE(profiles->m_widthVec[1],720);
//    QCOMPARE(profiles->m_heightVec[0],720);
//    QCOMPARE(profiles->m_heightVec[1],576);
//    QCOMPARE(profiles->m_qualityVec[0],100);
//    QCOMPARE(profiles->m_qualityVec[1],100);
//    QCOMPARE(profiles->m_frameRateLimitVec[0],25);
//    QCOMPARE(profiles->m_frameRateLimitVec[1],25);
//    QCOMPARE(profiles->m_encodingIntervalVec[0],25);
//    QCOMPARE(profiles->m_encodingIntervalVec[1],40);
//    QCOMPARE(profiles->m_bitrateLimitVec[0],4096);
//    QCOMPARE(profiles->m_bitrateLimitVec[1],2048);
//    QCOMPARE(profiles->m_govLengthVec[0],30);
//    QCOMPARE(profiles->m_govLengthVec[1],30);
//    QCOMPARE(profiles->m_h264ProfileVec[0],QString("Main"));
//    QCOMPARE(profiles->m_h264ProfileVec[1],QString("Main"));
//    QCOMPARE(profiles->m_typeVec[0],QString("IPv4"));
//    QCOMPARE(profiles->m_typeVec[1],QString("IPv4"));
//    QCOMPARE(profiles->m_ipv4AddressVec[0],QString("239.255.0.0"));
//    QCOMPARE(profiles->m_ipv4AddressVec[1],QString("239.255.0.0"));
//    QCOMPARE(profiles->m_ipv6AddressVec[0],QString("0000:0000:0000:0000:0000:0000:0000:0000"));
//    QCOMPARE(profiles->m_ipv6AddressVec[1],QString("0000:0000:0000:0000:0000:0000:0000:0000"));
//    QCOMPARE(profiles->m_portVec[0],1024);
//    QCOMPARE(profiles->m_portVec[1],1024);
//    QCOMPARE(profiles->m_ttlVec[0],1);
//    QCOMPARE(profiles->m_ttlVec[1],1);
//    QCOMPARE(profiles->m_autoStartVec[0],false);
//    QCOMPARE(profiles->m_autoStartVec[1],false);
//    QCOMPARE(profiles->m_sessionTimeoutVec[0],QString("PT0H1M26.400S"));
//    QCOMPARE(profiles->m_sessionTimeoutVec[1],QString("PT0H1M26.400S"));
//    QCOMPARE(profiles->m_namePtz[0],QString("profile_ptz_720P"));
//    QCOMPARE(profiles->m_namePtz[1],QString("profile_ptz_D1"));
//    QCOMPARE(profiles->m_useCountPtz[0],2);
//    QCOMPARE(profiles->m_useCountPtz[1],2);
//    QCOMPARE(profiles->m_nodeToken[0],QString("ptz_node_720P"));
//    QCOMPARE(profiles->m_nodeToken[1],QString("ptz_node_D1"));
//    QCOMPARE(profiles->m_defaultAbsolutePantTiltPositionSpace[0],QString("http://www.onvif.org/ver10/tptz/PanTiltSpaces/PositionGenericSpace"));
//    QCOMPARE(profiles->m_defaultAbsolutePantTiltPositionSpace[1],QString("http://www.onvif.org/ver10/tptz/PanTiltSpaces/PositionGenericSpace"));
//    QCOMPARE(profiles->m_defaultAbsoluteZoomPositionSpace[0],QString("http://www.onvif.org/ver10/tptz/ZoomSpaces/PositionGenericSpace"));
//    QCOMPARE(profiles->m_defaultAbsoluteZoomPositionSpace[1],QString("http://www.onvif.org/ver10/tptz/ZoomSpaces/PositionGenericSpace"));
//    QCOMPARE(profiles->m_defaultRelativePantTiltTranslationSpace[0],QString("http://www.onvif.org/ver10/tptz/PanTiltSpaces/TranslationGenericSpace"));
//    QCOMPARE(profiles->m_defaultRelativePantTiltTranslationSpace[1],QString("http://www.onvif.org/ver10/tptz/PanTiltSpaces/TranslationGenericSpace"));
//    QCOMPARE(profiles->m_defaultRelativeZoomTranslationSpace[0],QString("http://www.onvif.org/ver10/tptz/ZoomSpaces/TranslationGenericSpace"));
//    QCOMPARE(profiles->m_defaultRelativeZoomTranslationSpace[1],QString("http://www.onvif.org/ver10/tptz/ZoomSpaces/TranslationGenericSpace"));
//    QCOMPARE(profiles->m_defaultContinuousPantTiltVelocitySpace[0],QString("http://www.onvif.org/ver10/tptz/PanTiltSpaces/VelocityGenericSpace"));
//    QCOMPARE(profiles->m_defaultContinuousPantTiltVelocitySpace[1],QString("http://www.onvif.org/ver10/tptz/PanTiltSpaces/VelocityGenericSpace"));
//    QCOMPARE(profiles->m_defaultContinuousZoomVelocitySpace[0],QString("http://www.onvif.org/ver10/tptz/ZoomSpaces/VelocityGenericSpace"));
//    QCOMPARE(profiles->m_defaultContinuousZoomVelocitySpace[1],QString("http://www.onvif.org/ver10/tptz/ZoomSpaces/VelocityGenericSpace"));
//    QCOMPARE(profiles->m_panTiltSpace[0],QString("http://www.onvif.org/ver10/tptz/PanTiltSpaces/GenericSpeedSpace"));
//    QCOMPARE(profiles->m_panTiltSpace[1],QString("http://www.onvif.org/ver10/tptz/PanTiltSpaces/GenericSpeedSpace"));
//    QCOMPARE(profiles->m_zoomSpace[0],QString("http://www.onvif.org/ver10/tptz/ZoomSpaces/ZoomGenericSpeedSpace"));
//    QCOMPARE(profiles->m_zoomSpace[1],QString("http://www.onvif.org/ver10/tptz/ZoomSpaces/ZoomGenericSpeedSpace"));
//    QCOMPARE(profiles->m_defaultPTZTimeout[0],QString("PT0H0M3.600S"));
//    QCOMPARE(profiles->m_defaultPTZTimeout[1],QString("PT0H0M3.600S"));
//    QCOMPARE(profiles->m_panTiltUri[0],QString("http://www.onvif.org/ver10/tptz/PanTiltSpaces/PositionGenericSpace"));
//    QCOMPARE(profiles->m_panTiltUri[1],QString("http://www.onvif.org/ver10/tptz/PanTiltSpaces/PositionGenericSpace"));
//    QCOMPARE(profiles->m_panTiltSpace[0],QString("http://www.onvif.org/ver10/tptz/PanTiltSpaces/GenericSpeedSpace"));
//    QCOMPARE(profiles->m_panTiltSpace[1],QString("http://www.onvif.org/ver10/tptz/PanTiltSpaces/GenericSpeedSpace"));
//    QCOMPARE(profiles->m_xRangeMinPt[0],-1);
//    QCOMPARE(profiles->m_xRangeMinPt[1],-1);
//    QCOMPARE(profiles->m_xRangeMaxPt[0],1);
//    QCOMPARE(profiles->m_xRangeMaxPt[1],1);
//    QCOMPARE(profiles->m_yRangeMinPt[0],-1);
//    QCOMPARE(profiles->m_yRangeMinPt[1],-1);
//    QCOMPARE(profiles->m_yRangeMaxPt[0],1);
//    QCOMPARE(profiles->m_yRangeMaxPt[1],1);
//    QCOMPARE(profiles->m_zoomSpace[0],QString("http://www.onvif.org/ver10/tptz/ZoomSpaces/ZoomGenericSpeedSpace"));
//    QCOMPARE(profiles->m_zoomSpace[1],QString("http://www.onvif.org/ver10/tptz/ZoomSpaces/ZoomGenericSpeedSpace"));
//    QCOMPARE(profiles->m_xRangeMinZm[0],0);
//    QCOMPARE(profiles->m_xRangeMinZm[1],0);
//    QCOMPARE(profiles->m_xRangeMaxZm[0],1);
//    QCOMPARE(profiles->m_xRangeMaxZm[1],1);
//    QCOMPARE(profiles->m_nameMc[0],QString("profile_metadata_720P"));
//    QCOMPARE(profiles->m_nameMc[1],QString("profile_metadata_D1"));
//    QCOMPARE(profiles->m_useCountMc[0],0);
//    QCOMPARE(profiles->m_useCountMc[1],0);
//    QCOMPARE(profiles->m_status[0],false);
//    QCOMPARE(profiles->m_status[1],false);
//    QCOMPARE(profiles->m_position[0],true);
//    QCOMPARE(profiles->m_position[1],true);
//    QCOMPARE(profiles->m_filter[0],QString("Dialect=http://www.onvif.org/ver10/tev/topicExpression/ConcreteSet"));
//    QCOMPARE(profiles->m_filter[1],QString("Dialect=http://www.onvif.org/ver10/tev/topicExpression/ConcreteSet"));
//    QCOMPARE(profiles->m_subscriptionPolicy[0],QString("Dialect=http://www.onvif.org/ver10/tev/messageContentFilter/ItemFilter"));
//    QCOMPARE(profiles->m_subscriptionPolicy[1],QString("Dialect=http://www.onvif.org/ver10/tev/messageContentFilter/ItemFilter"));
//    QCOMPARE(profiles->m_analytics[0],false);
//    QCOMPARE(profiles->m_analytics[1],false);
//    QCOMPARE(profiles->m_typeMc[0],QString("IPv4"));
//    QCOMPARE(profiles->m_typeMc[1],QString("IPv4"));
//    QCOMPARE(profiles->m_ipv4AddressMc[0],QString("239.255.0.0"));
//    QCOMPARE(profiles->m_ipv4AddressMc[1],QString("239.255.0.0"));
//    QCOMPARE(profiles->m_ipv6AddressMc[0],QString("0000:0000:0000:0000:0000:0000:0000:0000"));
//    QCOMPARE(profiles->m_ipv6AddressMc[1],QString("0000:0000:0000:0000:0000:0000:0000:0000"));
//    QCOMPARE(profiles->m_portMc[0],60000);
//    QCOMPARE(profiles->m_portMc[1],60000);
//    QCOMPARE(profiles->m_ttlMc[0],64);
//    QCOMPARE(profiles->m_ttlMc[1],64);
//    QCOMPARE(profiles->m_autoStartMc[0],false);
//    QCOMPARE(profiles->m_autoStartMc[1],false);
//    QCOMPARE(profiles->m_sessionTimeoutMc[0],QString("PT0H1M26.400S"));
//    QCOMPARE(profiles->m_sessionTimeoutMc[1],QString("PT0H1M26.400S"));
}

void TestMediaManagement::getProfile720P()
{
    Profile *profiles = mMediaManagement->getProfile720P();
//    QCOMPARE(profiles->m_toKenPro[0],QString("profile_720P"));
//    QCOMPARE(profiles->m_fixed[0],true);
//    QCOMPARE(profiles->m_namePro[0],QString("profile_720P"));
//    QCOMPARE(profiles->m_useCountVsc[0],2);
//    QCOMPARE(profiles->m_sourceTokenVsc[0],QString("VideoSource_1"));
//    QRect rect(0,0,1280,720);
//    QCOMPARE(profiles->m_boundsVsc[0],rect);
//    QCOMPARE(profiles->m_nameVec[0],QString("profile_video_stream_720P"));
//    QCOMPARE(profiles->m_useCountVec[0],1);
//    QCOMPARE(profiles->m_encodingVec[0],QString("H264"));
//    QCOMPARE(profiles->m_widthVec[0],1280);
//    QCOMPARE(profiles->m_heightVec[0],720);
//    QCOMPARE(profiles->m_qualityVec[0],100);
//    QCOMPARE(profiles->m_frameRateLimitVec[0],25);
//    QCOMPARE(profiles->m_encodingIntervalVec[0],25);
//    QCOMPARE(profiles->m_bitrateLimitVec[0],4096);
//    QCOMPARE(profiles->m_govLengthVec[0],30);
//    QCOMPARE(profiles->m_h264ProfileVec[0],QString("Main"));
//    QCOMPARE(profiles->m_typeVec[0],QString("IPv4"));
//    QCOMPARE(profiles->m_ipv4AddressVec[0],QString("239.255.0.0"));
//    QCOMPARE(profiles->m_ipv6AddressVec[0],QString("0000:0000:0000:0000:0000:0000:0000:0000"));
//    QCOMPARE(profiles->m_portVec[0],1024);
//    QCOMPARE(profiles->m_ttlVec[0],1);
//    QCOMPARE(profiles->m_autoStartVec[0],false);
//    QCOMPARE(profiles->m_sessionTimeoutVec[0],QString("PT0H1M26.400S"));
//    QCOMPARE(profiles->m_namePtz[0],QString("profile_ptz_720P"));
//    QCOMPARE(profiles->m_useCountPtz[0],2);
//    QCOMPARE(profiles->m_nodeToken[0],QString("ptz_node_720P"));
//    QCOMPARE(profiles->m_defaultAbsolutePantTiltPositionSpace[0],QString("http://www.onvif.org/ver10/tptz/PanTiltSpaces/PositionGenericSpace"));
//    QCOMPARE(profiles->m_defaultAbsoluteZoomPositionSpace[0],QString("http://www.onvif.org/ver10/tptz/ZoomSpaces/PositionGenericSpace"));
//    QCOMPARE(profiles->m_defaultRelativePantTiltTranslationSpace[0],QString("http://www.onvif.org/ver10/tptz/PanTiltSpaces/TranslationGenericSpace"));
//    QCOMPARE(profiles->m_defaultRelativeZoomTranslationSpace[0],QString("http://www.onvif.org/ver10/tptz/ZoomSpaces/TranslationGenericSpace"));
//    QCOMPARE(profiles->m_defaultContinuousPantTiltVelocitySpace[0],QString("http://www.onvif.org/ver10/tptz/PanTiltSpaces/VelocityGenericSpace"));
//    QCOMPARE(profiles->m_defaultContinuousZoomVelocitySpace[0],QString("http://www.onvif.org/ver10/tptz/ZoomSpaces/VelocityGenericSpace"));
//    QCOMPARE(profiles->m_panTiltSpace[0],QString("http://www.onvif.org/ver10/tptz/PanTiltSpaces/GenericSpeedSpace"));
//    QCOMPARE(profiles->m_zoomSpace[0],QString("http://www.onvif.org/ver10/tptz/ZoomSpaces/ZoomGenericSpeedSpace"));
//    QCOMPARE(profiles->m_defaultPTZTimeout[0],QString("PT0H0M3.600S"));
//    QCOMPARE(profiles->m_panTiltUri[0],QString("http://www.onvif.org/ver10/tptz/PanTiltSpaces/PositionGenericSpace"));
//    QCOMPARE(profiles->m_panTiltSpace[0],QString("http://www.onvif.org/ver10/tptz/PanTiltSpaces/GenericSpeedSpace"));
//    QCOMPARE(profiles->m_xRangeMinPt[0],-1);
//    QCOMPARE(profiles->m_xRangeMaxPt[0],1);
//    QCOMPARE(profiles->m_yRangeMinPt[0],-1);
//    QCOMPARE(profiles->m_yRangeMaxPt[0],1);
//    QCOMPARE(profiles->m_zoomSpace[0],QString("http://www.onvif.org/ver10/tptz/ZoomSpaces/ZoomGenericSpeedSpace"));
//    QCOMPARE(profiles->m_xRangeMinZm[0],0);
//    QCOMPARE(profiles->m_xRangeMaxZm[0],1);
//    QCOMPARE(profiles->m_nameMc[0],QString("profile_metadata_720P"));
//    QCOMPARE(profiles->m_useCountMc[0],0);
//    QCOMPARE(profiles->m_status[0],false);
//    QCOMPARE(profiles->m_position[0],true);
//    QCOMPARE(profiles->m_filter[0],QString("Dialect=http://www.onvif.org/ver10/tev/topicExpression/ConcreteSet"));
//    QCOMPARE(profiles->m_subscriptionPolicy[0],QString("Dialect=http://www.onvif.org/ver10/tev/messageContentFilter/ItemFilter"));
//    QCOMPARE(profiles->m_analytics[0],false);
//    QCOMPARE(profiles->m_typeMc[0],QString("IPv4"));
//    QCOMPARE(profiles->m_ipv4AddressMc[0],QString("239.255.0.0"));
//    QCOMPARE(profiles->m_ipv6AddressMc[0],QString("0000:0000:0000:0000:0000:0000:0000:0000"));
//    QCOMPARE(profiles->m_portMc[0],60000);
//    QCOMPARE(profiles->m_ttlMc[0],64);
//    QCOMPARE(profiles->m_autoStartMc[0],false);
//    QCOMPARE(profiles->m_sessionTimeoutMc[0],QString("PT0H1M26.400S"));
}

void TestMediaManagement::getProfileD1()
{

}

void TestMediaManagement::getAudioSourceConfigurations()
{
    AudioSourceConfigurations *audioSourceConfigurations = mMediaManagement->getAudioSourceConfigurations();
    QCOMPARE(audioSourceConfigurations->getToken()[0],QString("profile_AudioSource_1"));
    QCOMPARE(audioSourceConfigurations->getName()[0],QString("profile_AudioSource_1"));
    QCOMPARE(audioSourceConfigurations->getUseCount()[0],2);
    QCOMPARE(audioSourceConfigurations->getSourceToken()[0],QString("AudioSource_1"));
}

void TestMediaManagement::getAudioEncoderConfigurations()
{
    AudioEncoderConfigurations *audioEncoderConfigurations = mMediaManagement->getAudioEncoderConfigurations();
    QCOMPARE(audioEncoderConfigurations->getToken()[0],QString("profile_audio_stream_1"));
    QCOMPARE(audioEncoderConfigurations->getName()[0],QString("profile_audio_stream_1"));
    QCOMPARE(audioEncoderConfigurations->getUseCount()[0],1);
    QCOMPARE(audioEncoderConfigurations->getEncoding()[0],QString("G711"));
    QCOMPARE(audioEncoderConfigurations->getBitrate()[0],32);
    QCOMPARE(audioEncoderConfigurations->getType()[0],QString("IPv4"));
    QCOMPARE(audioEncoderConfigurations->getIpv4Address()[0],QString("239.255.0.0"));
    QCOMPARE(audioEncoderConfigurations->getIpv6Address()[0],QString("0000:0000:0000:0000:0000:0000:0000:0000"));
    QCOMPARE(audioEncoderConfigurations->getPort()[0],1024);
    QCOMPARE(audioEncoderConfigurations->getTtl()[0],1);
    QCOMPARE(audioEncoderConfigurations->getAutoStart()[0],false);
    QCOMPARE(audioEncoderConfigurations->getSessionTimeout()[0],QString("PT0H1M26.400S"));
}

void TestMediaManagement::getVideoSourceConfiguration()
{
    VideoSourceConfiguration *videoSourceConfiguration = mMediaManagement->getVideoSourceConfiguration();
    QCOMPARE(videoSourceConfiguration->token(),QString("profile_VideoSource_1"));
    QCOMPARE(videoSourceConfiguration->name(),QString("profile_VideoSource_1"));
    QCOMPARE(videoSourceConfiguration->useCount(),2);
    QCOMPARE(videoSourceConfiguration->sourceToken(),QString("VideoSource_1"));
    QCOMPARE(videoSourceConfiguration->bounds(),QRect(0,0,352,288));
}

void TestMediaManagement::getVideoEncoderConfiguration()
{
    VideoEncoderConfiguration *videoEncoderConfiguration = mMediaManagement->getVideoEncoderConfiguration();
    QCOMPARE(videoEncoderConfiguration->token(),QString("profile_video_stream_D1"));
    QCOMPARE(videoEncoderConfiguration->name(),QString("profile_video_stream_D1"));
    QCOMPARE(videoEncoderConfiguration->useCount(),1);
    QCOMPARE(videoEncoderConfiguration->encoding(),QString("H264"));
    QCOMPARE(videoEncoderConfiguration->width(),720);
    QCOMPARE(videoEncoderConfiguration->height(),576);
    QCOMPARE(videoEncoderConfiguration->quality(),100);
    QCOMPARE(videoEncoderConfiguration->frameRateLimit(),25);
    QCOMPARE(videoEncoderConfiguration->encodingInterval(),25);
    QCOMPARE(videoEncoderConfiguration->bitrateLimit(),2048);
    QCOMPARE(videoEncoderConfiguration->type(),QString("IPv4"));
    QCOMPARE(videoEncoderConfiguration->ipv4Address(),QString("239.255.0.0"));
    QCOMPARE(videoEncoderConfiguration->ipv6Address(),QString("0000:0000:0000:0000:0000:0000:0000:0000"));
    QCOMPARE(videoEncoderConfiguration->port(),1024);
    QCOMPARE(videoEncoderConfiguration->ttl(),1);
    QCOMPARE(videoEncoderConfiguration->autoStart(),false);
    QCOMPARE(videoEncoderConfiguration->sessionTimeout(),QString("PT0H1M26.400S"));
}

void TestMediaManagement::getAudioEncoderConfiguration()
{
    AudioEncoderConfiguration *audioEncoderConfiguration = mMediaManagement->getAudioEncoderConfiguration();
    QCOMPARE(audioEncoderConfiguration->token(),QString("profile_audio_stream_1"));
    QCOMPARE(audioEncoderConfiguration->name(),QString("profile_audio_stream_1"));
    QCOMPARE(audioEncoderConfiguration->useCount(),1);
    QCOMPARE(audioEncoderConfiguration->encoding(),QString("G711"));
    QCOMPARE(audioEncoderConfiguration->bitrate(),32);
    QCOMPARE(audioEncoderConfiguration->sampleRate(),8);
    QCOMPARE(audioEncoderConfiguration->type(),QString("IPv4"));
    QCOMPARE(audioEncoderConfiguration->ipv4Address(),QString("239.255.0.0"));
    QCOMPARE(audioEncoderConfiguration->ipv6Address(),QString("0000:0000:0000:0000:0000:0000:0000:0000"));
    QCOMPARE(audioEncoderConfiguration->port(),1024);
    QCOMPARE(audioEncoderConfiguration->ttl(),1);
    QCOMPARE(audioEncoderConfiguration->autoStart(),false);
    QCOMPARE(audioEncoderConfiguration->sessionTimeout(),QString("PT0H1M26.400S"));
}

void TestMediaManagement::getAudioEncoderConfigurationOptions()
{
    AudioEncoderConfigurationOptions *audioEncoderConfigurationOptions = mMediaManagement->getAudioEncoderConfigurationOptions();
    QCOMPARE(audioEncoderConfigurationOptions->getEncoding()[0],AudioEncoderConfigurationOptions::G711);
    QCOMPARE(audioEncoderConfigurationOptions->getBitrateList()[0][0],32);
    QCOMPARE(audioEncoderConfigurationOptions->getSampleRateList()[0][0],8);
}

void TestMediaManagement::getVideoEncoderConfigurationOptions()
{
    VideoEncoderConfigurationOptions *videoEncoderConfigurationOptions = mMediaManagement->getVideoEncoderConfigurationOptions();
    QCOMPARE(videoEncoderConfigurationOptions->qualityRangeMin(),1);
    QCOMPARE(videoEncoderConfigurationOptions->qulityRangeMax(),100);
    QCOMPARE(videoEncoderConfigurationOptions->getResAvailableWidth()[0],352);
    QCOMPARE(videoEncoderConfigurationOptions->getResAvailableHeight()[0],288);
    QCOMPARE(videoEncoderConfigurationOptions->govLengthRangeMin(),1);
    QCOMPARE(videoEncoderConfigurationOptions->govLengthRangeMax(),100);
    QCOMPARE(videoEncoderConfigurationOptions->frameRateRangeMin(),1);
    QCOMPARE(videoEncoderConfigurationOptions->frameRateRangeMax(),25);
    QCOMPARE(videoEncoderConfigurationOptions->encodingIntervalRangeMin(),1);
    QCOMPARE(videoEncoderConfigurationOptions->encodingIntervalRangeMax(),15);
    QCOMPARE(videoEncoderConfigurationOptions->getH264ProfilesSupported()[0],VideoEncoderConfigurationOptions::Main);
    QCOMPARE(videoEncoderConfigurationOptions->getH264ProfilesSupported()[1],VideoEncoderConfigurationOptions::Baseline);
    QCOMPARE(videoEncoderConfigurationOptions->getH264ProfilesSupported()[2],VideoEncoderConfigurationOptions::Extended);
    QCOMPARE(videoEncoderConfigurationOptions->getH264ProfilesSupported()[3],VideoEncoderConfigurationOptions::High);
}

void TestMediaManagement::getStreamUri()
{
    StreamUri *streamUri = mMediaManagement->getStreamUri();
    QCOMPARE(streamUri->uri(),QString("rtsp://192.168.2.113:554/1/cif"));
    QCOMPARE(streamUri->invalidAfterConnect(),true);
    QCOMPARE(streamUri->invalidAfterReboot(),true);
    QCOMPARE(streamUri->timeout(),QString("PT0H0M3.600S"));
}
