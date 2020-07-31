#pragma once
namespace melodramatic {

    enum class eventType{
        windowClose, windowResize,
        keyPressed, keyReleased, KeyRepeated,
        mouseMove, mouseButtonPressed, mouseButtonReleased,
        gameTick,
    };

    class event{
        public:
            virtual ~event() = default;
            virtual eventType getEventType() = 0;
            virtual void handle() = 0;
    };
}