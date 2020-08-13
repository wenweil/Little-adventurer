#include "event/event.h"
#define GLFW_INCLUDE_NONE
#include <glfw/glfw3.h>

namespace melodramatic{
    class keyPressedEvent : public event{
        public:
            keyPressedEvent(int inKey);
            eventType getEventType() override;
            void handle() override;
        private:
            eventType type = eventType::keyPressed;
            int key;

    };
    class keyReleasedEvent : public event{
        public:
            keyReleasedEvent(int inKey);
            eventType getEventType() override;
            void handle() override;
        private:
            eventType type = eventType::keyReleased;
            int key;
    };
    class keyRepeatedEvent :public event{
        public:
            keyRepeatedEvent(int inKey);
            eventType getEventType() override;
            void handle() override;
        private:
            eventType type = eventType::KeyRepeated;
            int key;

    };
}