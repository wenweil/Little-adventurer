#include "render/renderer2d.h"
#include "scene/quadrilateral.h"
#include  <glm/glm/glm.hpp>

namespace melodramatic {

    int renderer2D::type = rendererAPI::type::OPENGL;
    rendererAPI* renderer2D::API = nullptr;

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
    }

    void renderer2D::draw(const scene& scene){
        
    }
}