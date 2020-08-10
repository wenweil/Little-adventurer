#include "render/renderAPI.h"
#include "vertex.h"

#define GLFW_INCLUDE_NONE
#include <glad/glad.h>
#include <GLFW/glfw3.h>


namespace melodramatic{
    OPENGL_API* OPENGL_API::instance = nullptr;
    OPENGL_API* OPENGL_API::getInstance(){
        if(!instance){
            instance = new OPENGL_API;
            instance->init();
        }
        return instance;
    }

    void OPENGL_API::onClose(){
        delete[] samplers;
    }

    void OPENGL_API::init(){
        assert(gladLoadGLLoader((GLADloadproc) glfwGetProcAddress));
        glGenBuffers(1,&vertexBuffer);
        glGenBuffers(1,&indexBuffer);
        glGenVertexArrays(1,&vertexArray);

        glBindVertexArray(vertexArray);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,indexBuffer);
        glBindBuffer(GL_ARRAY_BUFFER,vertexBuffer);

        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);

        glActiveTexture(GL_TEXTURE0);
        uint8_t blankTexture [4] = {255, 255, 255, 255};
        unsigned int tid;
        glGenTextures(1,&tid);
        glBindTexture(GL_TEXTURE_2D,tid);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA8,1,1,0,GL_RGBA,GL_UNSIGNED_BYTE,blankTexture);

        glGetIntegerv(GL_MAX_TEXTURE_IMAGE_UNITS,&textureMax);

        samplers = new int[textureMax];

        for(int i = 0; i < textureMax;i++){
            samplers[i] = i;
        }

        textureCount = 0;
    }

    void OPENGL_API::setVertexBuffer(std::vector<float> data){
        glBufferData(GL_ARRAY_BUFFER,sizeof(float) * data.size(),data.data(),GL_DYNAMIC_DRAW);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,sizeof(melodramatic::vertex),(const void*)(0*sizeof(float))); //vert pos
        glEnableVertexAttribArray(1);
        glVertexAttribPointer(1,4,GL_FLOAT,GL_FALSE,sizeof(melodramatic::vertex),(const void*)(3*sizeof(float))); //vert color
        glEnableVertexAttribArray(2);
        glVertexAttribPointer(2,2,GL_FLOAT,GL_FALSE,sizeof(melodramatic::vertex),(const void*)(7*sizeof(float))); //vert tex coord
        glEnableVertexAttribArray(3);
        glVertexAttribPointer(3,1,GL_FLOAT,GL_FALSE,sizeof(melodramatic::vertex),(const void*)(9*sizeof(float))); //vert tex id
        int err = glGetError();

    }

    void OPENGL_API::setIndexBuffer(std::vector<unsigned int> data){
        glBufferData(GL_ELEMENT_ARRAY_BUFFER,data.size()*sizeof(unsigned int),data.data(),GL_STATIC_DRAW);
        int err = glGetError();
        drawCount = data.size();
    }

    void OPENGL_API::draw(){
        glBindVertexArray(vertexArray);
        glDrawElements(GL_TRIANGLES,drawCount,GL_UNSIGNED_INT,nullptr);
        int err = glGetError();
        
        textureCount = 0;
        //drawCount = 0;
    }

    void OPENGL_API::setShader(const std::string& fragmentShaderSource, const std::string& vertexShaderSource){
        //todo:implement
        vertexShader = glCreateShader(GL_VERTEX_SHADER);
        const char* vSrc = vertexShaderSource.c_str();
        glShaderSource(vertexShader,1,&vSrc,NULL);
        fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        const char* fSrc = fragmentShaderSource.c_str();
        glShaderSource(fragmentShader,1,&fSrc,NULL);

        glCompileShader(vertexShader);
        glCompileShader(fragmentShader);

        shaderProgram = glCreateProgram();
        glAttachShader(shaderProgram,vertexShader);
        glAttachShader(shaderProgram,fragmentShader);
        glLinkProgram(shaderProgram);
        glUseProgram(shaderProgram);

        auto location = glGetUniformLocation(shaderProgram,"u_Textures");
        glUniform1iv(location,textureMax,samplers);
    };

    void OPENGL_API::setTransformMatrix(const glm::mat4& mat){
        auto location = glGetUniformLocation(shaderProgram,"u_Matrix");
        glUniformMatrix4fv(location,1,GL_FALSE,&mat[0][0]);
    }

    void OPENGL_API::bindTexture(unsigned int &tid, void* data,unsigned int width, unsigned int height){
        //todo: implement
        glActiveTexture(GL_TEXTURE1+textureCount);
        glGenTextures(1, &tid);
        glBindTexture(GL_TEXTURE_2D,tid);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA8,width,height,0,GL_RGBA,GL_UNSIGNED_BYTE,data);
        textureCount++;
    }

}