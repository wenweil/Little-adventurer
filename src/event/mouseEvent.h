#include "event/event.h"

namespace melodramatic{
    class mouseMoveEvent : public event{
        public:
            mouseMoveEvent(double inXPos, double inYPos);
            eventType getEventType() override;
            void handle() override;
        private:
            eventType type = eventType::mouseMove;
            double xPos;
            double yPos;
    };
    class mouseButtonPressedEvent :public event{
        public:
            mouseButtonPressedEvent(int inButton);
            eventType getEventType() override;
            void handle() override;
        private:
            eventType type = eventType::mouseButtonPressed;
            int button;
    };
    class mouseButtonReleasedEvent : public event{
        public:
            mouseButtonReleasedEvent(int inButton);
            eventType getEventType() override;
            void handle() override;
        private:
            eventType type = eventType::mouseButtonReleased;
            int button;
    };
}