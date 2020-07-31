#pragma once
namespace melodramatic {

    enum class eventType{
        windowClose, windowResize,
        keyPressed, keyReleased, kKeyRepeated,
        mouseMove, mouseButtonPressed, mouseButtonReleased,
        gameTick,
    };

    class Event{
        public:
            virtual ~Event() = default;
            virtual eventType getEventType() = 0;
            virtual void handle() = 0;
    };
}