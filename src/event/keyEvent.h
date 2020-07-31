#include "event/event.h"

namespace melodramatic{
    class keyPressedEvent : public Event{
        public:
            keyPressedEvent(int inKey);
            eventType getEventType() override;
            void handle() override;
        private:
            eventType type = eventType::keyPressed;
            int key;

    };
    class keyReleasedEvent : public Event{
        public:
            keyReleasedEvent(int inKey);
            eventType getEventType() override;
            void handle() override;
        private:
            eventType type = eventType::keyReleased;
            int key;
    };
    class keyRepeatedEvent :public Event{
        public:
            keyRepeatedEvent(int inKey);
            eventType getEventType() override;
            void handle() override;
        private:
            eventType type = eventType::KeyRepeated;
            int key;

    };
}