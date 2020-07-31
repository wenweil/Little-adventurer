#include "event/event.h"

namespace melodramatic{
    class windowResizeEvent : public Event{
        public:
            windowResizeEvent(int width, int height);
            eventType getEventType() override{ return type;};
            void handle() override;
        private:
            int thisWidth;
            int thisHeight;
            eventType type = eventType::windowResize;
    };
    class windowCloseEvent : public Event{
        public:
            eventType getEventType() override {return type;};
            void handle() override;
        private:
            eventType type = eventType::windowClose;
    };
}