
#include "event/gameTickEvent.h"

namespace melodramatic{
    eventType gametTickEvent::getEventType(){
        return type;
    };

    void gametTickEvent::handle(){
    }
}