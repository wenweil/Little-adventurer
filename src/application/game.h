#pragma once
#define GLFW_INCLUDE_NONE
#include <assert.h>
#include <glad/glad.h>
#include <functional>
#include <vector>
#include "event/event.h"
#include "event/windowEvent.h"
#include "event/keyEvent.h"
#include "event/mouseEvent.h"
#include "application/gameTicker.h"
#include <GLFW/glfw3.h>


namespace melodramatic {
    class game {
        private:
            using EventCallBackFn = std::function<void(event&)>;
        public:
            typedef struct{
                int height;
                int width;
                EventCallBackFn function;
            }windowData;
            static game* getInstance();
            void init();
            void run();
            game();
            GLFWwindow* getWindow(){return m_window;};
            void onClose();
            void onResize(int width, int height);
            void setNewWindowSize(int width, int height);
            void onEvent(event& e);
            void setEventCallback(const EventCallBackFn& callback) {data.function = callback;};
            windowData getData() {return data;};

        private:
            static game* s_instance;
            GLFWwindow* m_window;
            bool initalized = false;
            bool m_running = false;
            windowData data;
        
    };
}
