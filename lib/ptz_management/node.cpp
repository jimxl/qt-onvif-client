#include "node.h"
#include "libONVIF/message.h"
using namespace ONVIF;

Node::Node(QObject *parent):QObject(parent)
{

}

Node::~Node()
{

}

QDomElement Node::toxml()
{
    QDomElement getNode = newElement("wsdl:GetNode");
    QDomElement nodeToken = newElement("wsdl:NodeToken",this->ptzNodeToken());
    getNode.appendChild(nodeToken);
    return getNode;
}
