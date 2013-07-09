#ifndef ONVIF_SERVICE_H
#define ONVIF_SERVICE_H

#include <QObject>

namespace ONVIF {
    class Service : public QObject {
        Q_OBJECT
    public:
        explicit Service(const QString & wsdlUrl, const QString &username, const QString &password);
        
        ~Service();
        
    };
}


#endif // ONVIF_SERVICE_H
