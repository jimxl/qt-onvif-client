#ifndef ONVIF_MESSAGE_H
#define ONVIF_MESSAGE_H

#include <QObject>
#include <QHash>
#include <QDomElement>

namespace ONVIF {
    class Message : public QObject {
        Q_OBJECT
    public:
        explicit Message(const QHash<QString, QString> &namespaces, const QString &username, const QString &password, QObject *parent = NULL);
        
        void addBody();
        QString toXmlStr();
    private:
        QHash<QString, QString> mNamespaces;
        QString mUsername;
        QString mPassword;
        QDomElement mBody;
    };

    #endif // MESSAGE_H
}

