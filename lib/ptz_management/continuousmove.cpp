#include "continuousmove.h"
#include "libONVIF/message.h"
using namespace ONVIF;

ContinuousMove::ContinuousMove(QObject *parent):QObject(parent)
{

}

ContinuousMove::~ContinuousMove()
{

}

QDomElement ContinuousMove::toxml()
{
    QDomElement continuousMove = newElement("tptz:ContinuousMove");
    QDomElement velocity = newElement("tptz:Velocity");
    QDomElement profileToken = newElement("tptz:ProfileToken",this->profileToken());
    QDomElement panTilt = newElement("tt:PanTilt");
    panTilt.setAttribute("x",this->panTiltX());
    panTilt.setAttribute("y",this->panTiltY());
    panTilt.setAttribute("space",this->panTiltSpace());
    QDomElement zoom = newElement("tt:Zoom");
    zoom.setAttribute("x",this->zoomX());
    zoom.setAttribute("space",this->zoomSpace());
    QDomElement timeout = newElement("tptz:Timeout",this->timeout());
    continuousMove.appendChild(profileToken);
    continuousMove.appendChild(velocity);
    continuousMove.appendChild(timeout);
    velocity.appendChild(panTilt);
    velocity.appendChild(zoom);
    return continuousMove;
}


