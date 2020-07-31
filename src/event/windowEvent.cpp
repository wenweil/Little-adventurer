#include "event/windowEvent.h"
#include "application/game.h"

#include <iostream>

namespace melodramatic{
    windowResizeEvent::windowResizeEvent(int width, int height){
        thisWidth = width;
        thisHeight = height;
    }

    void windowResizeEvent::handle(){
        game::getInstance()->setNewWindowSize(thisWidth,thisHeight);
    }

    void windowCloseEvent::handle(){
        game::getInstance()->onClose();
    }
}