#ifndef ONVIF_ACTION_H
#define ONVIF_ACTION_H

#include <QObject>

namespace ONVIF {
    class Action : public QObject
    {
        Q_OBJECT
    public:
        explicit Action();
        explicit Action(const Action &action);
        ~Action();
    
    };
}



#endif // ONVIF_ACTION_H
