#include "messageparser.h"
#include <QHashIterator>
#include <QDebug>

using namespace ONVIF;

MessageParser::MessageParser(const QString &data, QHash<QString, QString> &namespaces, QObject *parent) : QObject(parent) {
    mBuffer.setData(data.toUtf8());
    mBuffer.open(QIODevice::ReadOnly);
    mQuery.bindVariable("inputDocument", &mBuffer);
    QHashIterator<QString, QString> i(namespaces);
    mNamespaceQueryStr = "";
    while (i.hasNext()) {
        i.next();
        mNamespaceQueryStr.append("declare namespace " + i.key() + " = \"" + i.value() + "\";\n");
    }
}

MessageParser::~MessageParser() {
    mBuffer.close();
}

QString MessageParser::getValue(const QString &xpath) {
    QString str;
//    qDebug() << mNamespaceQueryStr + "doc($inputDocument)" + xpath + "/string()";
    mQuery.setQuery(mNamespaceQueryStr + "doc($inputDocument)" + xpath + "/string()");
    mQuery.evaluateTo(&str);
    return str.trimmed();
}
