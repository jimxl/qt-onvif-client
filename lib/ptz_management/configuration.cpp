#include "configuration.h"
#include "libONVIF/message.h"
using namespace ONVIF;

Configuration::Configuration(QObject *parent):QObject(parent)
{

}

Configuration::~Configuration()
{

}

QDomElement Configuration::toxml()
{
    QDomElement getConfiguration = newElement("wsdl:GetConfiguration");
    QDomElement ptzConfigurationToken = newElement("wsdl:PTZConfigurationToken",this->ptzConfigurationToken());
    getConfiguration.appendChild(ptzConfigurationToken);
    return getConfiguration;
}
