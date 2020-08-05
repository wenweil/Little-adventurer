#include "render/renderAPI.h"

namespace melodramatic {
    renderAPI* renderAPI::instance = nullptr;
    renderAPI* renderAPI::init(int type){
        if(!instance){
            switch(type){
                case NONE:{
                    return nullptr;
                }
                case OPENGL:{
                    instance = OPENGL_API::getInstance();
                    return instance;
                }
                case D3D:{
                    return nullptr; //not implemented
                }
                case VULKAN:{
                    return nullptr; //not implemented
                }
            }
        }
        return instance;
    }
}