
#include "event/gametTickEvent.h"

namespace melodramatic{
    eventType gametTickEvent::getEventType(){
        return type;
    };

    void gametTickEvent::handle(){
        std::cout<<"game ticked"<<std::endl;
    }
}