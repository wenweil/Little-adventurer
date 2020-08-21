#include "render/renderer2d.h"
#include "scene/quadrilateral.h"
#include  <glm/glm/glm.hpp>
#include "application/game.h"
#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>


namespace melodramatic {

    int renderer2D::type = rendererAPI::type::OPENGL;
    rendererAPI* renderer2D::API = nullptr;
    std::vector<float> renderer2D::vData;
    std::vector<unsigned int> renderer2D::iData;
    unsigned int renderer2D::count = 0;

    renderer2D::tmp renderer2D::dat = {
        0,
        0,
        false,
        false,
        false,
        false,
    };

    void renderer2D::setAPIType(int inType){
        type = inType;
    }

    void renderer2D::init(){
        switch(type){
            case rendererAPI::type::NONE:
                API = nullptr;
                break;
            case rendererAPI::type::OPENGL:
                API = OPENGL_API::getInstance();
                break;
            case rendererAPI::type::D3D:
                API = nullptr;
                break;
            case rendererAPI::type::VULKAN:
                API = nullptr;
                break;
        }
        assert(API);


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
"	texColor *= texture(u_Textures[int(v_TexIndex)], v_TexCoord );\n"
"	color = texColor;\n"
"}\n";

        API->setShader(fragShader,vertShader);

        game::windowData data = game::getInstance()->getData();

        dat.xPos = (float)data.width/2;
        dat.yPos = (float)data.height/2;
        dat.up = false;
        dat.down = false;
        dat.left = false;
        dat.right = false;
    }

    void renderer2D::draw(const scene& scene){
        matrix c;
        game::windowData data = game::getInstance()->getData();
        c[0][3] = -dat.xPos;
        c[1][3] = -dat.yPos;

        matrix s;
        s[0][0] = (float)2/data.width;
        s[1][1] = (float)2/data.height;

        matrix m;
        m = std::move(s * c);

        /* test quad locations
        960 540
        960 180    
        320 540
        320 180
        640 360
        */

        float width = 100.0f;
        float height = 100.0f;

        float vertexData [] = {
            dat.xPos-width, dat.yPos+height, 0.0f,  1.0f, 1.0f, 1.00f, 1.0f,  0.0f, 1.0f,  1.0f,
            dat.xPos-width, dat.yPos-height, 0.0f,  1.0f, 1.0f, 1.00f, 1.0f,  0.0f, 0.0f,  1.0f,
            dat.xPos+width, dat.yPos-height, 0.0f,  1.0f, 1.0f, 1.00f, 1.0f,  1.0f, 0.0f,  1.0f,
            dat.xPos+width, dat.yPos+height, 0.0f,  1.0f, 1.0f, 1.00f, 1.0f,  1.0f, 1.0f,  1.0f,
        };

        int w = 50;
        int h = 30;

        vData.reserve(w*h*4);
        iData.reserve(w*h*6);

        float gradient = 1.0f;

        int offset = 0;

        for(float i = 0;i < w;i += 1.0f){
            for(float j = 0;j < h;j += 1.0f){
                vData.push_back(i*30.0f);
                vData.push_back(j*30.0f+20.0f);
                vData.push_back(0.0f);
                vData.push_back(1.0f-gradient*i/w);
                vData.push_back(0.0f+gradient*i/w);
                vData.push_back(1.0f-gradient*j/h);
                vData.push_back(1.0f);
                vData.push_back(0.0f);
                vData.push_back(1.0f);
                vData.push_back(1.0f);

                vData.push_back(i*30.0f);
                vData.push_back(j*30.0f);
                vData.push_back(0.0f);
                vData.push_back(1.0f-gradient*j/h);
                vData.push_back(0.0f+gradient*i/w);
                vData.push_back(1.0f-gradient*j/h);
                vData.push_back(1.0f);
                vData.push_back(0.0f);
                vData.push_back(0.0f);
                vData.push_back(1.0f);

                vData.push_back(i*30.0f+20.0f);
                vData.push_back(j*30.0f);
                vData.push_back(0.0f);
                vData.push_back(1.0f-gradient*j/h);
                vData.push_back(0.0f+gradient*i/w);
                vData.push_back(1.0f-gradient*i/h);
                vData.push_back(1.0f);
                vData.push_back(1.0f);
                vData.push_back(0.0f);
                vData.push_back(1.0f);

                vData.push_back(i*30.0f+20.0f);
                vData.push_back(j*30.0f+20.0f);
                vData.push_back(0.0f);
                vData.push_back(1.0f-gradient*i/w);
                vData.push_back(0.0f+gradient*j/h);
                vData.push_back(1.0f-gradient*j/h);
                vData.push_back(1.0f);
                vData.push_back(1.0f);
                vData.push_back(1.0f);
                vData.push_back(1.0f);

                iData.push_back(0+offset);
                iData.push_back(1+offset);
                iData.push_back(2+offset);
                iData.push_back(2+offset);
                iData.push_back(3+offset);
                iData.push_back(0+offset);
                offset +=4;
            }
        }

        std::string path = "assets/nerd.png";

        stbi_set_flip_vertically_on_load(true);

        stbi_uc* textureData = nullptr;

        int imgWidth, imgHeight, channels;

        textureData = stbi_load(path.c_str(),&imgWidth,&imgHeight,&channels,0);

        assert(textureData);

        iData.push_back(0+offset);
        iData.push_back(1+offset);
        iData.push_back(2+offset);
        iData.push_back(2+offset);
        iData.push_back(3+offset);
        iData.push_back(0+offset);
        offset +=4;
        
        for(auto c:vertexData)
            vData.push_back(c);

        API->setVertexBuffer(vData);
        API->setIndexBuffer(iData);

        API->setTransformMatrix(m);

        unsigned int tid;

        API->bindTexture(tid,textureData,imgWidth,imgHeight);

        stbi_image_free(textureData);

        API->draw();

        count = 0;

        iData.clear();
        vData.clear();


    }
    void renderer2D::drawCurrent(){
            matrix c;
            game::windowData data = game::getInstance()->getData();
            c[0][3] = -dat.xPos;
            c[1][3] = -dat.yPos;

            matrix s;
            s[0][0] = (float)2/data.width;
            s[1][1] = (float)2/data.height;

            matrix m;
            m = std::move(s * c);
            API->setVertexBuffer(vData);
            API->setIndexBuffer(iData);

            API->setTransformMatrix(m);
            
            API->draw();

            count = 0;

            iData.clear();
            vData.clear();

    }
    float renderer2D::loadTexture(std::string& path){
        if (count == 15)
            drawCurrent();
        stbi_set_flip_vertically_on_load(true);

        stbi_uc* textureData = nullptr;

        int imgWidth, imgHeight, channels;

        textureData = stbi_load(path.c_str(),&imgWidth,&imgHeight,&channels,0);

        assert(textureData);

        unsigned int tid;

        API->bindTexture(tid,textureData,imgWidth,imgHeight);

        stbi_image_free(textureData);

        count++;
        return (float) count;
    }
}