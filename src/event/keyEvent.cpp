#include "keyEvent.h"
#include <iostream>
#include "render/renderer2d.h"

namespace melodramatic{
    keyPressedEvent::keyPressedEvent(int inKey){
        key = inKey;
    }
    eventType keyPressedEvent::getEventType(){
        return type;
    }
    void keyPressedEvent::handle(){
        if(key == GLFW_KEY_W)
            renderer2D::dat.up = true;
        if(key == GLFW_KEY_S)
            renderer2D::dat.down = true;
        if(key == GLFW_KEY_A)
            renderer2D::dat.left = true;
        if(key == GLFW_KEY_D)
            renderer2D::dat.right = true;
        if(key >= 32 && key <= 96){
            char a = key;
            std::cout<<"pressed key "<<a<<std::endl;
        }
    }
    keyRepeatedEvent::keyRepeatedEvent(int inKey){
        key = inKey;
    }
    eventType keyRepeatedEvent::getEventType(){
        return type;
    }
    void keyRepeatedEvent::handle(){
        if(key >= 32 && key <= 96){
            char a = key;
            std::cout<<"repeated key "<<a<<std::endl;
        }
    }
    keyReleasedEvent::keyReleasedEvent(int inKey){
        key = inKey;
    }
    eventType keyReleasedEvent::getEventType(){
        return type;
    }
    void keyReleasedEvent::handle(){
        if(key == GLFW_KEY_W)
            renderer2D::dat.up = false;
        if(key == GLFW_KEY_S)
            renderer2D::dat.down = false;
        if(key == GLFW_KEY_A)
            renderer2D::dat.left = false;
        if(key == GLFW_KEY_D)
            renderer2D::dat.right = false;



        if(key >= 32 && key <= 96){
            char a = key;
            std::cout<<"released key "<<a<<std::endl;
        }
    }
}