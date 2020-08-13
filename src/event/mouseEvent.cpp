#include "event/mouseEvent.h"
#include <iostream>

namespace melodramatic{
    mouseMoveEvent::mouseMoveEvent(double inXPos, double inYPos){
        xPos = inXPos;
        yPos = inYPos;
    }

    eventType mouseMoveEvent::getEventType(){
        return type;
    }

    void mouseMoveEvent::handle(){
       // std::cout<<"Mouse moved: xpos "<<xPos<<" ypos "<<yPos<<std::endl;
    }

    mouseButtonPressedEvent::mouseButtonPressedEvent(int inButton){
        button = inButton;
    }

    eventType mouseButtonPressedEvent::getEventType(){
        return type;
    }

    void mouseButtonPressedEvent::handle(){
        std::cout<<"Mouse button pressed: "<<button<<std::endl;
    }

    mouseButtonReleasedEvent::mouseButtonReleasedEvent(int inButton){
        button = inButton;
    }

    eventType mouseButtonReleasedEvent::getEventType(){
        return type;
    }

    void mouseButtonReleasedEvent::handle(){
        std::cout<<"Mouse button released: "<<button<<std::endl;

    }

}