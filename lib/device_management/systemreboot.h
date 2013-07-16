#ifndef SYSTEMREBOOT_H
#define SYSTEMREBOOT_H
#include <QObject>
#include <QDomElement>
namespace ONVIF {
    class SystemReboot : public QObject {
        Q_OBJECT
    public:
        explicit SystemReboot(QObject *parent = NULL);
        virtual ~SystemReboot();
        QDomElement toxml();
    };
}
#endif // SYSTEMREBOOT_H
