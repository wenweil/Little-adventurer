#pragma once
#include <assert.h>
#include <GLFW/glfw3.h>
#include <functional>
#include "event/event.h"


namespace melodramatic {
    class game {

        private:

            using EventCallBackFn = std::function<void(event&)>;

            static game* s_instance;
            GLFWwindow* m_window;
            bool initalized = false;
            bool m_running = false;
            typedef struct{
                int height;
                int width;
                EventCallBackFn function;
            }windowData;
            windowData data;
    
        public:
            static game* getInstance();
            void init();
            void run();
            game();
            void onClose();
            void onResize(int width, int height);
            void setNewWindowSize(int width, int height);
            void onEvent(event& e);
            void setEventCallback(const EventCallBackFn& callback) {data.function = callback;};

    };
}
