#include "videoencoderconfiguration.h"
#include "libONVIF/message.h"
#include <QDebug>

using namespace ONVIF;

VideoEncoderConfiguration::VideoEncoderConfiguration(QObject *parent):QObject(parent)
{

}

VideoEncoderConfiguration::~VideoEncoderConfiguration()
{

}

QDomElement VideoEncoderConfiguration::toxml()
{
    QDomElement SetVideoEncoderConfiguration = newElement("trt:SetVideoEncoderConfiguration");
    QDomElement Configuration = newElement("trt:Configuration");
    Configuration.setAttribute("token", this->token());
    QDomElement Name = newElement("tt:Name", this->name());
//    QDomElement UseCount = newElement("tt:UseCount", QString:: number(this->useCount()));
//    QDomElement Encoding = newElement("tt:Encoding", this->encoding());
    QDomElement Resolution = newElement("tt:Resolution");
   QDomElement Width = newElement("tt:Width", QString:: number(this->width()));
    QDomElement Height = newElement("tt:Height", QString:: number(this->height()));
//    QDomElement Quality = newElement("tt:Quality", QString:: number(this->quality()));
//    QDomElement RateControl = newElement("tt:RateControl");
//    QDomElement FrameRateLimit = newElement("tt:FrameRateLimit", QString:: number(this->frameRateLimit()));
//    QDomElement EncodingInterval = newElement("tt:EncodingInterval", QString:: number(this->encodingInterval()));
//    QDomElement BitrateLimit = newElement("tt:BitrateLimit", QString:: number(this->bitrateLimit()));
    //QDomElement H264 = newElement("tt:H264");
    //QDomElement GovLength = newElement("tt:GovLength", QString:: number(this->govLength()));
    //QDomElement H264Profile = newElement("tt:H264Profile", this->h264Profile());
//    QDomElement Multicast = newElement("tt:Multicast");
//    QDomElement Address = newElement("tt:Address");
//    QDomElement Type = newElement("tt:Type", this->type());
//    QDomElement IPv4Address = newElement("tt:IPv4Address", this->ipv4Address());
//    QDomElement IPv6Address = newElement("tt:IPv6Address", this->ipv6Address());
//    QDomElement Port = newElement("tt:Port", QString:: number(this->port()));
//    QDomElement TTL = newElement("tt:TTL", QString:: number(this->ttl()));
//    QDomElement AutoStart = newElement("tt:AutoStart", QString:: number(this->autoStart()));
//    QDomElement SessionTimeout = newElement("tt:SessionTimeout", this->sessionTimeout());
//    QDomElement ForcePersistence  = newElement("trt:ForcePersistence ", "true");

    SetVideoEncoderConfiguration.appendChild(Configuration);

    Configuration.appendChild(Name);
//    Configuration.appendChild(UseCount);
//    Configuration.appendChild(Encoding);
    Configuration.appendChild(Resolution);
    Resolution.appendChild(Width);
    Resolution.appendChild(Height);

//    Configuration.appendChild(Quality);
//    Configuration.appendChild(RateControl);
//    RateControl.appendChild(FrameRateLimit);
//    RateControl.appendChild(EncodingInterval);
//    RateControl.appendChild(BitrateLimit);

    //Configuration.appendChild(H264);
    //H264.appendChild(GovLength);
    //H264.appendChild(H264Profile);

//    Configuration.appendChild(Multicast);
//    Multicast.appendChild(Address);
//    Address.appendChild(Type);
//    Address.appendChild(IPv4Address);
//    Address.appendChild(IPv6Address);

//    Multicast.appendChild(Port);
//    Multicast.appendChild(TTL);
//    Multicast.appendChild(AutoStart);

//    Configuration.appendChild(SessionTimeout);
//    SetVideoEncoderConfiguration.appendChild(ForcePersistence);

    return SetVideoEncoderConfiguration;
}
