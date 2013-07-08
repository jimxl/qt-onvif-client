#include "message.h"

using namespace ONVIF;

Message::Message(const QHash<QString, QString> &namespaces, const QString &username, const QString &password, QObject *parent) : QObject(parent) {
    this->mUsername = username;
    this->mPassword = password;
    this->mNamespaces = namespaces;
}

QString Message::toXmlStr() {
    QDomDocument doc;
    doc.appendChild(doc.createProcessingInstruction("xml", "version=\"1.0\" encoding=\"UTF-8\""));
    QDomElement env = doc.createElementNS("http://www.w3.org/2003/05/soap-envelope", "soap:Envelope");
    QDomElement header = doc.createElement("soap:Header");
    QDomElement body = doc.createElement("soap:Body");
    QHashIterator<QString, QString> i(mNamespaces);
    while (i.hasNext()) {
        i.next();
        env.setAttribute("xmlns:" + i.key(), i.value());
    }
    env.appendChild(header);
    env.appendChild(body);
    doc.appendChild(env);
    return doc.toString(-1);
}
