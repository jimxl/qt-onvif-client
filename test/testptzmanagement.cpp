#include "testptzmanagement.h"

#include <QTest>
#include <QDebug>

using namespace ONVIF;

TestPtzManagement::TestPtzManagement(QObject *parent) : QObject(parent)
{
}

void TestPtzManagement::initTestCase() {
    mPtzManagement = new PtzManagement("http://192.168.2.113/onvif/ptz_service", "admin", "nvrnvr888");
}

void TestPtzManagement::cleanupTestCase() {
    if(mPtzManagement != NULL) {
        delete mPtzManagement;
        mPtzManagement = NULL;
    }
}

void TestPtzManagement::getConfigurations()
{
    Configurations *configurations = mPtzManagement->getConfigurations();
    QCOMPARE(configurations->getToken()[0],QString("profile_ptz_D1"));
    QCOMPARE(configurations->getName()[0],QString("profile_ptz_D1"));
    QCOMPARE(configurations->getUseCount()[0],2);
    QCOMPARE(configurations->getNodeToken()[0],QString("ptz_node_D1"));
    QCOMPARE(configurations->getDefaultAbsolutePantTiltPositionSpace()[0],QString("http://www.onvif.org/ver10/tptz/PanTiltSpaces/PositionGenericSpace"));
    QCOMPARE(configurations->getDefaultAbsoluteZoomPositionSpace()[0],QString("http://www.onvif.org/ver10/tptz/ZoomSpaces/PositionGenericSpace"));
    QCOMPARE(configurations->getDefaultRelativePanTiltTranslationSpace()[0],QString("http://www.onvif.org/ver10/tptz/PanTiltSpaces/TranslationGenericSpace"));
    QCOMPARE(configurations->getDefaultRelativeZoomTranslationSpace()[0],QString("http://www.onvif.org/ver10/tptz/ZoomSpaces/TranslationGenericSpace"));
    QCOMPARE(configurations->getDefaultContinuousPanTiltVelocitySpace()[0],QString("http://www.onvif.org/ver10/tptz/PanTiltSpaces/VelocityGenericSpace"));
    QCOMPARE(configurations->getDefaultContinuousZoomVelocitySpace()[0],QString("http://www.onvif.org/ver10/tptz/ZoomSpaces/VelocityGenericSpace"));
    QCOMPARE(configurations->getPanTiltSpace()[0],QString("http://www.onvif.org/ver10/tptz/PanTiltSpaces/GenericSpeedSpace"));
    QCOMPARE(configurations->getPanTiltX()[0],(float)0);
    QCOMPARE(configurations->getPanTiltY()[0],(float)0);
    QCOMPARE(configurations->getZoomSpace()[0],QString("http://www.onvif.org/ver10/tptz/ZoomSpaces/ZoomGenericSpeedSpace"));
    QCOMPARE(configurations->getZoomX()[0],(float)0);
    QCOMPARE(configurations->getPanTiltRangeUri()[0],QString("http://www.onvif.org/ver10/tptz/PanTiltSpaces/PositionGenericSpace"));
    QCOMPARE(configurations->getPanTiltXRangeMin()[0],(float)-1);
    QCOMPARE(configurations->getPanTiltXRangeMax()[0],(float)1);
    QCOMPARE(configurations->getPanTiltYRangeMin()[0],(float)-1);
    QCOMPARE(configurations->getPanTiltYRangeMax()[0],(float)1);
    QCOMPARE(configurations->getZoomRangeUri()[0],QString("http://www.onvif.org/ver10/tptz/ZoomSpaces/ZoomGenericSpace"));
    QCOMPARE(configurations->getZoomXRangeMin()[0],(float)0);
    QCOMPARE(configurations->getZoomXRangeMax()[0],(float)1);
}

void TestPtzManagement::getPresets()
{
    Presets *presets = mPtzManagement->getPresets();
    QCOMPARE(presets->getToken()[0],QString("1"));
    QCOMPARE(presets->getName()[0],QString("llp"));
    QCOMPARE(presets->getToken()[1],QString("2"));
    QCOMPARE(presets->getName()[1],QString("eebb"));
    QCOMPARE(presets->getToken()[2],QString("4"));
    QCOMPARE(presets->getName()[2],QString("eeee"));
}

void TestPtzManagement::removePreset()
{
    RemovePreset *removePreset = new RemovePreset();
    removePreset->setProfileToken("profile_CIF");
    removePreset->setPresetToken("2");
  //  mPtzManagement->removePreset(removePreset);
    QCOMPARE(removePreset->result(),true);
}

void TestPtzManagement::setPreset()
{
    Preset *preset = new Preset();
    preset->setProfileToken("profile_CIF");
    preset->setPresetName("test1");
    preset->setPresetToken("7");
    mPtzManagement->setPreset(preset);
    QCOMPARE(preset->result(),true);
}


void TestPtzManagement::continuousMove()
{
    ContinuousMove *continuousMove = new ContinuousMove();
    continuousMove->setProfileToken("profile_CIF");
    continuousMove->setPanTiltX(0);
    continuousMove->setPanTiltY(1);
    continuousMove->setZoomX(0);
    continuousMove->setTimeout("PT0H0M3.600S");
    mPtzManagement->continuousMove(continuousMove);
    QCOMPARE(continuousMove->result(),true);
}

void TestPtzManagement::absoluteMove()
{
    AbsoluteMove *absoluteMove = new AbsoluteMove();
    absoluteMove->setProfileToken("profile_CIF");
    absoluteMove->setPositionPanTiltX(0);
    absoluteMove->setPositionPanTiltY(1);
    absoluteMove->setPositionZoomX(0);
    absoluteMove->setSpeedPanTiltX(1);
    absoluteMove->setSpeedPanTiltY(0);
    absoluteMove->setSpeedZoomX(0);
    mPtzManagement->absoluteMove(absoluteMove);
    QCOMPARE(absoluteMove->result(),true);
}

void TestPtzManagement::relativeMove()
{
    RelativeMove *relativeMove = new RelativeMove();
    relativeMove->setProfileToken("profile_CIF");
    relativeMove->setTranslationPanTiltX(-1);
    relativeMove->setTranslationPanTiltY(1);
    relativeMove->setTranslationZoomX(0);
    relativeMove->setSpeedPanTiltX(1);
    relativeMove->setSpeedPanTiltY(0);
    relativeMove->setSpeedZoomX(0);
    mPtzManagement->relativeMove(relativeMove);
    QCOMPARE(relativeMove->result(),true);
}

void TestPtzManagement::stop()
{
    Stop *stop = new Stop();
    stop->setProfileToken("profile_CIF");
    stop->setPanTilt(true);
    stop->setZoom(false);
   // mPtzManagement->stop(stop);
  //  QCOMPARE(stop->result(),true);
}

void TestPtzManagement::getNodes()
{
    Nodes *nodes = mPtzManagement->getNodes();
    QCOMPARE(nodes->getPtzNodeToken()[0],QString("ptz_node_D1"));
    QCOMPARE(nodes->getName()[0],QString("profile_ptz_D1"));
    QCOMPARE(nodes->getAppsUri()[0],QString("http://www.onvif.org/ver10/tptz/PanTiltSpaces/PositionGenericSpace"));
    QCOMPARE(nodes->getAppsXRangeMin()[0],(float)0);
    QCOMPARE(nodes->getAppsXRangeMax()[0],(float)1);
    QCOMPARE(nodes->getAppsYRangeMin()[0],(float)0);
    QCOMPARE(nodes->getAppsYRangeMax()[0],(float)1);
    QCOMPARE(nodes->getAzpsUri()[0],QString("http://www.onvif.org/ver10/tptz/ZoomSpaces/PositionGenericSpace"));
    QCOMPARE(nodes->getAzpsXRangeMin()[0],(float)0);
    QCOMPARE(nodes->getAzpsXRangeMax()[0],(float)1);
    QCOMPARE(nodes->getRptsUri()[0],QString("http://www.onvif.org/ver10/tptz/PanTiltSpaces/TranslationGenericSpace"));
    QCOMPARE(nodes->getRptsXRangeMin()[0],(float)0);
    QCOMPARE(nodes->getRptsXRangeMax()[0],(float)1);
    QCOMPARE(nodes->getRptsYRangeMin()[0],(float)0);
    QCOMPARE(nodes->getRptsYRangeMax()[0],(float)1);
    QCOMPARE(nodes->getRztsUri()[0],QString("http://www.onvif.org/ver10/tptz/ZoomSpaces/TranslationGenericSpace"));
    QCOMPARE(nodes->getRztsXRangeMin()[0],(float)0);
    QCOMPARE(nodes->getRztsXRangeMax()[0],(float)1);
    QCOMPARE(nodes->getCpvsUri()[0],QString("http://www.onvif.org/ver10/tptz/PanTiltSpaces/VelocityGenericSpace"));
    QCOMPARE(nodes->getCpvsXRangeMin()[0],(float)0);
    QCOMPARE(nodes->getCpvsXRangeMax()[0],(float)1);
    QCOMPARE(nodes->getCpvsYRangeMin()[0],(float)0);
    QCOMPARE(nodes->getCpvsYRangeMax()[0],(float)1);
    QCOMPARE(nodes->getCzvsUri()[0],QString("http://www.onvif.org/ver10/tptz/ZoomSpaces/VelocityGenericSpace"));
    QCOMPARE(nodes->getCzvsXRangeMin()[0],(float)0);
    QCOMPARE(nodes->getCzvsXRangeMax()[0],(float)1);
    QCOMPARE(nodes->getPssUri()[0],QString("http://www.onvif.org/ver10/tptz/PanTiltSpaces/GenericSpeedSpace"));
    QCOMPARE(nodes->getPssXRangeMin()[0],(float)0);
    QCOMPARE(nodes->getPssXRangeMax()[0],(float)1);
    QCOMPARE(nodes->getZssUri()[0],QString("http://www.onvif.org/ver10/tptz/ZoomSpaces/ZoomGenericSpeedSpace"));
    QCOMPARE(nodes->getZssXRangeMin()[0],(float)0);
    QCOMPARE(nodes->getZssXRangeMax()[0],(float)1);
    QCOMPARE(nodes->getMaximumNumberOfPresets()[0],255);
    QCOMPARE(nodes->getHomeSupported()[0],true);
}

void TestPtzManagement::gotoPreset()
{
    GotoPreset *gotoPreset = new GotoPreset();
    gotoPreset->setProfileToken("profile_CIF");
    gotoPreset->setPresetToken("4");
    gotoPreset->setPanTiltX(1);
    gotoPreset->setPanTiltY(1);
    gotoPreset->setZoomX(0);
    mPtzManagement->gotoPreset(gotoPreset);
    QCOMPARE(gotoPreset->result(),true);
}

void TestPtzManagement::gotoHomePosition()
{
    GotoHomePosition *gotoHomePosition = new GotoHomePosition();
    gotoHomePosition->setProfileToken("profile_CIF");
    gotoHomePosition->setPanTiltX(1);
    gotoHomePosition->setPanTiltY(1);
    gotoHomePosition->setZoomX(0);
    mPtzManagement->gotoHomePosition(gotoHomePosition);
    QCOMPARE(gotoHomePosition->result(),true);
}

void TestPtzManagement::getConfiguration()
{
    Configuration *configuration = new Configuration();
    configuration->setPtzConfigurationToken("profile_ptz_D1");
    mPtzManagement->getConfiguration(configuration);
    QCOMPARE(configuration->ptzConfigurationToken(),QString("profile_ptz_D1"));
    QCOMPARE(configuration->name(),QString("profile_ptz_D1"));
    QCOMPARE(configuration->useCount(),2);
    QCOMPARE(configuration->nodeToken(),QString("ptz_node_D1"));
    QCOMPARE(configuration->defaultAbsolutePantTiltPositionSpace(),QString("http://www.onvif.org/ver10/tptz/PanTiltSpaces/PositionGenericSpace"));
    QCOMPARE(configuration->defaultAbsoluteZoomPositionSpace(),QString("http://www.onvif.org/ver10/tptz/ZoomSpaces/PositionGenericSpace"));
    QCOMPARE(configuration->defaultRelativePanTiltTranslationSpace(),QString("http://www.onvif.org/ver10/tptz/PanTiltSpaces/TranslationGenericSpace"));
}
