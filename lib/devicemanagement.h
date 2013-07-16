#ifndef ONVIF_DEVICEMANAGEMENT_H
#define ONVIF_DEVICEMANAGEMENT_H

#include "service.h"
#include <QDateTime>
#include "device_management/systemdateandtime.h"
#include "device_management/user.h"
#include "device_management/systemfactorydefault.h"
#include "device_management/systemreboot.h"
#include "device_management/networkinterfaces.h"
#include "device_management/networkprotocols.h"

namespace ONVIF {
    class DeviceManagement : public Service {
        Q_OBJECT
    public:
        explicit DeviceManagement(const QString & wsdlUrl, const QString &username, const QString &password);
        QHash<QString, QString> getDeviceInformation();
        SystemDateAndTime *getSystemDateAndTime();
        void setSystemDateAndTime();
        void setSystemFactoryDefault();
        void setSystemReboot();
        Users *getUser();
        NetworkInterfaces *getNetworkInterfaces();
        NetworkProtocols *getNetworkProtocols();
        void setNetworkInterfaces();
    protected:
        Message *newMessage();
        QHash<QString, QString> namespaces(const QString &key);
    };
}



#endif // DEVICEMANAGEMENT_H
