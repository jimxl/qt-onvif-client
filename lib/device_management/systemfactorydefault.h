#ifndef SYSTEMFACTORYDEFAULT_H
#define SYSTEMFACTORYDEFAULT_H
#include <QObject>
#include <QDomElement>
namespace ONVIF {
    class SystemFactoryDefault : public QObject {
        Q_OBJECT
        Q_ENUMS(FactoryDefault)
        Q_PROPERTY(FactoryDefault factoryDefault READ factoryDefault WRITE setFactoryDefault)
    public:
        explicit SystemFactoryDefault(QObject *parent = NULL);
        virtual ~SystemFactoryDefault();
        enum FactoryDefault {Hard,Soft};
        QDomElement toxml();
        FactoryDefault factoryDefault() const
        {
            return m_factoryDefault;
        }

    public slots:
        void setFactoryDefault(FactoryDefault arg)
        {
            m_factoryDefault = arg;
        }

    private:
        FactoryDefault m_factoryDefault;
    };
}
#endif // SYSTEMFACTORYDEFAULT_H
