#include "keyEvent.h"
#include <iostream>

namespace melodramatic{
    keyPressedEvent::keyPressedEvent(int inKey){
        key = inKey;
    }
    eventType keyPressedEvent::getEventType(){
        return type;
    }
    void keyPressedEvent::handle(){
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
        if(key >= 32 && key <= 96){
            char a = key;
            std::cout<<"released key "<<a<<std::endl;
        }
    }
}