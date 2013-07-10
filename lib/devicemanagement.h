#ifndef ONVIF_DEVICEMANAGEMENT_H
#define ONVIF_DEVICEMANAGEMENT_H

#include "service.h"
#include <QDateTime>
#include "device_management/systemdateandtime.h"

namespace ONVIF {
    class DeviceManagement : public Service {
        Q_OBJECT
    public:
        explicit DeviceManagement(const QString & wsdlUrl, const QString &username, const QString &password);
        QHash<QString, QString> getDeviceInformation();
        SystemDateAndTime *getSystemDateAndTime();
    protected:
        Message *newMessage();
        QHash<QString, QString> namespaces(const QString &key);
    };
}



#endif // DEVICEMANAGEMENT_H
