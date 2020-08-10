#include "application/game.h"
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

       // assert(gladLoadGLLoader((GLADloadproc) glfwGetProcAddress));
    

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
            mouseMoveEvent event(xpos,ypos);
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

        OPENGL_API::getInstance();

        std::cout<<"vendor :"<<glGetString(GL_VENDOR)<<std::endl;
        std::cout<<"renderer :"<<glGetString(GL_RENDERER)<<std::endl;
        std::cout<<"version :"<<glGetString(GL_VERSION)<<std::endl;

        float data [] = {
            -0.4f, -0.4f , 0.0f , 0.8f, 0.1f, 0.6f, 1.0f, 0.0f, 0.0f, 0.0f,
            -0.4f, -0.1f , 0.0f , 0.8f, 0.1f, 0.6f, 1.0f, 0.0f, 1.0f, 0.0f,
            -0.1f, -0.4f , 0.0f , 0.8f, 0.1f, 0.6f, 1.0f, 1.0f, 0.0f, 0.0f,
            -0.1f, -0.1f , 0.0f , 0.8f, 0.1f, 0.6f, 1.0f, 1.0f, 1.0f, 0.0f,

            0.1f, -0.4f , 0.0f , 0.8f, 0.1f, 0.6f, 1.0f, 0.0f, 0.0f, 0.0f,
            0.1f, -0.1f , 0.0f , 0.8f, 0.1f, 0.6f, 1.0f, 0.0f, 1.0f, 0.0f,
            0.4f, -0.4f , 0.0f , 0.8f, 0.1f, 0.6f, 1.0f, 1.0f, 0.0f, 0.0f,
            0.4f, -0.1f , 0.0f , 0.8f, 0.1f, 0.6f, 1.0f, 1.0f, 1.0f, 0.0f,

            -0.4f, 0.1f , 0.0f , 0.8f, 0.1f, 0.6f, 1.0f, 0.0f, 0.0f, 0.0f,
            -0.4f, 0.4f , 0.0f , 0.8f, 0.1f, 0.6f, 1.0f, 0.0f, 1.0f, 0.0f,
            -0.1f, 0.1f , 0.0f , 0.8f, 0.1f, 0.6f, 1.0f, 1.0f, 0.0f, 0.0f,
            -0.1f, 0.4f , 0.0f , 0.8f, 0.1f, 0.6f, 1.0f, 1.0f, 1.0f, 0.0f,

            0.1f, 0.1f , 0.0f , 0.8f, 0.1f, 0.6f, 1.0f, 0.0f, 0.0f, 0.0f,
            0.1f, 0.4f , 0.0f , 0.8f, 0.1f, 0.6f, 1.0f, 0.0f, 1.0f, 0.0f,
            0.4f, 0.1f , 0.0f , 0.8f, 0.1f, 0.6f, 1.0f, 1.0f, 0.0f, 0.0f,
            0.4f, 0.4f , 0.0f , 0.8f, 0.1f, 0.6f, 1.0f, 1.0f, 1.0f, 0.0f,
        };

        unsigned int indices [] {
            2,3,1, 1,0,2,
            6,7,5, 5,4,6,
            10,11,9, 9,8,10,
            14,15,13, 13,12,14,
        };

        std::string vertShader = 
"#version 330 core\n"
"\n"
"layout(location = 0) in vec3 a_Position;\n"
"layout(location = 1) in vec4 a_Color;\n"
"layout(location = 2) in vec2 a_TexCoord;\n"
"layout(location = 3) in float a_TexIndex;\n"
"\n"
"out vec4 v_Color;\n"
"out vec2 v_TexCoord;\n"
"out float v_TexIndex;\n"
"\n"
"uniform mat4 u_Matrix;\n"
"\n"
"void main()\n"
"{\n"
"	v_Color = a_Color;\n"
"	v_TexCoord = a_TexCoord;\n"
"	v_TexIndex = a_TexIndex;\n"
"	gl_Position = u_Matrix * vec4(a_Position, 1.0);\n"
"}\n";

        std::string fragShader = 
"#version 330 core\n"
"\n"
"layout(location = 0) out vec4 color;\n"
"\n"
"in vec4 v_Color;\n"
"in vec2 v_TexCoord;\n"
"in float v_TexIndex;\n"
"\n"
"uniform sampler2D u_Textures[16];\n"
"\n"
"void main()\n"
"{\n"
"	vec4 texColor = v_Color;\n"
"	switch(int(v_TexIndex))\n"
"	{\n"
"		case 0: texColor *= texture(u_Textures[0], v_TexCoord ); break;\n"
"		case 1: texColor *= texture(u_Textures[1], v_TexCoord ); break;\n"
"		case 2: texColor *= texture(u_Textures[2], v_TexCoord ); break;\n"
"		case 3: texColor *= texture(u_Textures[3], v_TexCoord ); break;\n"
"		case 4: texColor *= texture(u_Textures[4], v_TexCoord ); break;\n"
"		case 5: texColor *= texture(u_Textures[5], v_TexCoord ); break;\n"
"		case 6: texColor *= texture(u_Textures[6], v_TexCoord ); break;\n"
"		case 7: texColor *= texture(u_Textures[7], v_TexCoord ); break;\n"
"		case 8: texColor *= texture(u_Textures[8], v_TexCoord ); break;\n"
"		case 9: texColor *= texture(u_Textures[9], v_TexCoord ); break;\n"
"		case 10: texColor *= texture(u_Textures[10], v_TexCoord ); break;\n"
"		case 11: texColor *= texture(u_Textures[11], v_TexCoord ); break;\n"
"		case 12: texColor *= texture(u_Textures[12], v_TexCoord ); break;\n"
"		case 13: texColor *= texture(u_Textures[13], v_TexCoord ); break;\n"
"		case 14: texColor *= texture(u_Textures[14], v_TexCoord ); break;\n"
"		case 15: texColor *= texture(u_Textures[15], v_TexCoord ); break;\n"
"	}\n"
"	color = texColor;\n"
"}\n";

        std::vector<float> vData;
        for(auto c:data)
            vData.push_back(c);
        std::vector<unsigned int> iData;
        for(auto c:indices)
            iData.push_back(c);

        OPENGL_API::getInstance()->setVertexBuffer(vData);
        OPENGL_API::getInstance()->setIndexBuffer(iData);

        OPENGL_API::getInstance()->setShader(fragShader,vertShader);

        m_running = true;
    }

    void game::run(){
        while(m_running){
            glfwSwapBuffers(m_window);

            glClearColor(0.2f,0.2f,0.2f,1.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            glm::mat4 m(1.0f);

            OPENGL_API::getInstance()->setTransformMatrix(m);

            OPENGL_API::getInstance()->draw();

            glfwPollEvents();
        }
    }
}