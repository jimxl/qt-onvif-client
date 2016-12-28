#ifndef ONVIF_CLIENT_H
#define ONVIF_CLIENT_H

#include <QObject>
#include <QtNetwork>

namespace ONVIF {
    class Client : public QObject {
        Q_OBJECT
    public:
        explicit Client(const QString &url);
        QNetworkReply *reply;
        QString sendData(const QString &data);

    private:
        void waitForFinished(const QNetworkReply* reply);
        QString mUrl;
    };
}

#endif // ONVIF_CLIENT_H

