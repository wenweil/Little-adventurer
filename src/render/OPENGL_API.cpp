#include "render/renderAPI.h"

namespace melodramatic{
    OPENGL_API* OPENGL_API::instance = nullptr;
    OPENGL_API* OPENGL_API::getInstance(){
        if(!instance){
            instance = new OPENGL_API;
            instance->init();
        }
        return instance;
    }

    void OPENGL_API::init(){
        m_window = game::getInstance()->getWindow();
        assert(gladLoadGLLoader((GLADloadproc) glfwGetProcAddress));
        glGenBuffers(1,&vertexBuffer);
        glGenBuffers(1,&indexBuffer);
        glGenVertexArrays(1,&vertexArray);

        glBindVertexArray(vertexArray);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,indexBuffer);
        glBindBuffer(GL_ARRAY_BUFFER,vertexBuffer);
    }

    void OPENGL_API::setVertexBuffer(unsigned int count,std::vector<float> data){
        glBufferData(GL_ARRAY_BUFFER,sizeof(float) * data.size(),data.data(),GL_DYNAMIC_DRAW);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0,count,GL_FLOAT,GL_FALSE,3*sizeof(float),nullptr);
        
    }

    void OPENGL_API::setIndexBuffer(unsigned int count, std::vector<unsigned int> data){
        glBufferData(GL_ELEMENT_ARRAY_BUFFER,data.size()*sizeof(unsigned int),data.data(),GL_STATIC_DRAW);
        drawCount = count;
    }

    void OPENGL_API::draw(){
        glBindVertexArray(1);
        glDrawElements(GL_TRIANGLES,drawCount,GL_UNSIGNED_INT,nullptr);
    }

}