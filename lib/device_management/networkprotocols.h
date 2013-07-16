#ifndef NETWORKPROTOCOLS_H
#define NETWORKPROTOCOLS_H
#include <QObject>
namespace ONVIF {
    class NetworkProtocols : public QObject {
        Q_OBJECT
        Q_PROPERTY(QString networkProtocolsName READ networkProtocolsName WRITE setNetworkProtocolsName)
        Q_PROPERTY(QString networkProtocolsEnabled READ networkProtocolsEnabled WRITE setNetworkProtocolsEnabled)
        Q_PROPERTY(QString networkProtocolsPort READ networkProtocolsPort WRITE setNetworkProtocolsPort)

    public:
        explicit NetworkProtocols(QObject *parent = NULL);
        virtual ~NetworkProtocols();

        QString networkProtocolsName() const
        {
            return m_networkProtocolsName;
        }

        QString networkProtocolsEnabled() const
        {
            return m_networkProtocolsEnabled;
        }

        QString networkProtocolsPort() const
        {
            return m_networkProtocolsPort;
        }

    public slots:
        void setNetworkProtocolsName(QString arg)
        {
            m_networkProtocolsName = arg;
        }

        void setNetworkProtocolsEnabled(QString arg)
        {
            m_networkProtocolsEnabled = arg;
        }

        void setNetworkProtocolsPort(QString arg)
        {
            m_networkProtocolsPort = arg;
        }

    private:
        QString m_networkProtocolsEnabled;
        QString m_networkProtocolsPort;
        QString m_networkProtocolsName;
    };
}
#endif // NETWORKPROTOCOLS_H
