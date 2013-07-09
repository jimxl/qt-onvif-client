#ifndef ONVIF_MESSAGEPARSER_H
#define ONVIF_MESSAGEPARSER_H

#include <QObject>
#include <QXmlQuery>
#include <QBuffer>

namespace ONVIF {
    class MessageParser : public QObject
    {
        Q_OBJECT
    public:
        explicit MessageParser(const QString &data, QHash<QString, QString> &namespaces, QObject *parent = 0);
        ~MessageParser();
        QString getValue(const QString &xpath);
    private:
        QXmlQuery mQuery;
        QString mNamespaceQueryStr;
        QBuffer mBuffer;
    };
}


#endif // ONVIF_MESSAGEPARSER_H
