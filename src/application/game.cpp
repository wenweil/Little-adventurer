#include "application/game.h"
#include "render/renderer2d.h"
#define DEBUG

namespace melodramatic{

    game* game::s_instance = nullptr;


    game* game::getInstance(){
        if(!s_instance){
            s_instance = new game();
        }
        return s_instance;
    }

    game::game(){
        assert(!s_instance);
    }

    void game::onEvent(event& e){
        e.handle();
    }

    void game::setNewWindowSize(int width,int height){
        data.width = width;
        data.height = height;
    }

    void game::onClose(){
        ticker::getInstance()->stopTicking();
        OPENGL_API::getInstance()->onClose();
        m_running = false;
    }

    void game::init(){
        if(!initalized){
            bool state = glfwInit();
            assert(state);
        }

        m_window = glfwCreateWindow(1280, 720,"new game",NULL,NULL);

        data.height = 720;
        data.width = 1280;
        setEventCallback(std::bind(&onEvent, this, std::placeholders::_1));

        if(!m_window){
            glfwTerminate();
        }
        
        glfwMakeContextCurrent(m_window);


        glfwSetWindowUserPointer(m_window,&data);

        glfwSetWindowCloseCallback(m_window,[](GLFWwindow* window){
            windowData& data = *(windowData*)glfwGetWindowUserPointer(window);

            windowCloseEvent event;

            data.function(event);

        });

        glfwSetWindowSizeCallback(m_window,[](GLFWwindow* window, int width, int height){
            windowData& data = *(windowData*)glfwGetWindowUserPointer(window);

            windowResizeEvent event(width,height);

            data.function(event);
        });

        glfwSetKeyCallback(m_window,[](GLFWwindow* window, int key, int scancode, int action, int mods){
            windowData& data = *(windowData*)glfwGetWindowUserPointer(window);
            switch (action)
            {
                case GLFW_PRESS:
                {
                    keyPressedEvent event(key);
                    data.function(event);
                    break;
                }
                case GLFW_RELEASE:{
                    keyReleasedEvent event(key);
                    data.function(event);
                }
                    break;
                case GLFW_REPEAT:{
                    keyRepeatedEvent event(key);
                    data.function(event);
                    break;
                }
            }
        });

        glfwSetCursorPosCallback(m_window,[](GLFWwindow* window, double xpos, double ypos){
            windowData& data = *(windowData*)glfwGetWindowUserPointer(window);
            
            mouseMoveEvent event(xpos,(double)data.height-ypos);
            data.function(event);
        });

        glfwSetMouseButtonCallback(m_window,[](GLFWwindow* window, int button, int action, int mods){
            windowData& data = *(windowData*)glfwGetWindowUserPointer(window);
            switch (action)
            {
                case GLFW_PRESS:
                {
                    mouseButtonPressedEvent event(button);
                    data.function(event);
                    break;
                }
                case GLFW_RELEASE:{
                    mouseButtonReleasedEvent event(button);
                    data.function(event);
                }
                    break;
            }
        });
        ticker* ticker = ticker::getInstance();
        ticker->startTicking();

        m_running = true;

        renderer2D::init();

        std::cout<<"vendor :"<<glGetString(GL_VENDOR)<<std::endl;
        std::cout<<"renderer :"<<glGetString(GL_RENDERER)<<std::endl;
        std::cout<<"version :"<<glGetString(GL_VERSION)<<std::endl;
        
    }

    void game::run(){
        while(m_running){
            glfwSwapBuffers(m_window);

            glClearColor(0.2f,0.2f,0.2f,1.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            scene s;
            renderer2D::draw(s);

            glfwPollEvents();
        }
    }
}