#include "event/event.h"

namespace melodramatic{
    class gametTickEvent :public event
    {
    private:
        eventType type = eventType::gameTick;
    public:
        gametTickEvent() = default;
        eventType getEventType() override;
        void handle() override;
    };  
}