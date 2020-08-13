#include "render/renderer2d.h"
#include "scene/quadrilateral.h"
#include  <glm/glm/glm.hpp>
#include "application/game.h"


namespace melodramatic {

    int renderer2D::type = rendererAPI::type::OPENGL;
    rendererAPI* renderer2D::API = nullptr;

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
        m = s * c;

        s[3][3] = 2.0f;

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
            960.0f-width, 540.0f+height, 0.0f,  0.3f, 0.0f, 0.8f, 1.0f,  0.0f, 1.0f,  0.0f,
            960.0f-width, 540.0f-height, 0.0f,  0.3f, 0.0f, 0.8f, 1.0f,  0.0f, 0.0f,  0.0f,
            960.0f+width, 540.0f-height, 0.0f,  0.3f, 0.0f, 0.8f, 1.0f,  1.0f, 0.0f,  0.0f,
            960.0f+width, 540.0f+height, 0.0f,  0.3f, 0.0f, 0.8f, 1.0f,  1.0f, 1.0f,  0.0f,

            960.0f-width, 180.0f+height, 0.0f,  0.3f, 0.0f, 0.8f, 1.0f,  0.0f, 1.0f,  0.0f,
            960.0f-width, 180.0f-height, 0.0f,  0.3f, 0.0f, 0.8f, 1.0f,  0.0f, 0.0f,  0.0f,
            960.0f+width, 180.0f-height, 0.0f,  0.3f, 0.0f, 0.8f, 1.0f,  1.0f, 0.0f,  0.0f,
            960.0f+width, 180.0f+height, 0.0f,  0.3f, 0.0f, 0.8f, 1.0f,  1.0f, 1.0f,  0.0f,

            320.0f-width, 540.0f+height, 0.0f,  0.3f, 1.0f, 0.0f, 1.0f,  0.0f, 1.0f,  0.0f,
            320.0f-width, 540.0f-height, 0.0f,  0.3f, 1.0f, 0.0f, 1.0f,  0.0f, 0.0f,  0.0f,
            320.0f+width, 540.0f-height, 0.0f,  0.3f, 1.0f, 0.0f, 1.0f,  1.0f, 0.0f,  0.0f,
            320.0f+width, 540.0f+height, 0.0f,  0.3f, 1.0f, 0.0f, 1.0f,  1.0f, 1.0f,  0.0f,

            320.0f-width, 180.0f+height, 0.0f,  0.3f, 1.0f, 0.0f, 1.0f,  0.0f, 1.0f,  0.0f,
            320.0f-width, 180.0f-height, 0.0f,  0.3f, 1.0f, 0.0f, 1.0f,  0.0f, 0.0f,  0.0f,
            320.0f+width, 180.0f-height, 0.0f,  0.3f, 1.0f, 0.0f, 1.0f,  1.0f, 0.0f,  0.0f,
            320.0f+width, 180.0f+height, 0.0f,  0.3f, 1.0f, 0.0f, 1.0f,  1.0f, 1.0f,  0.0f,

            dat.xPos-width, dat.yPos+height, 0.0f,  0.1f, 0.5f, 0.05f, 1.0f,  0.0f, 1.0f,  0.0f,
            dat.xPos-width, dat.yPos-height, 0.0f,  0.1f, 0.5f, 0.05f, 1.0f,  0.0f, 0.0f,  0.0f,
            dat.xPos+width, dat.yPos-height, 0.0f,  0.1f, 0.5f, 0.05f, 1.0f,  1.0f, 0.0f,  0.0f,
            dat.xPos+width, dat.yPos+height, 0.0f,  0.1f, 0.5f, 0.05f, 1.0f,  1.0f, 1.0f,  0.0f,
        };

        unsigned int indices [] = {
            0,1,2,  2,3,0,
            4,5,6,  6,7,4,
            8,9,10, 10,11,8,
            12,13,14,  14,15,12,
            16,17,18,  18,19,16 
        };

        std::vector<float> vData;
        for(auto c:vertexData)
            vData.push_back(c);
        std::vector<unsigned int> iData;
        for(auto c:indices)
            iData.push_back(c);

        API->setVertexBuffer(vData);
        API->setIndexBuffer(iData);

        API->setTransformMatrix(m);

        API->draw();


    }
}