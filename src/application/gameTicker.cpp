#include "application/gameTicker.h"
#include "application/game.h"
#include <windows.h>
#include "event/gametTickEvent.h"

namespace melodramatic{
    ticker* ticker::instance = nullptr;
    ticker* ticker::getInstance(){
        if(!instance){
            instance = new ticker();
        }
        return instance;
    }

    void ticker::startTicking(){
        ticking = true;
        one = std::thread(&ticker::tick, this);
    }

    void ticker::startTicking(int timePerTick){
        tickSpeed = timePerTick;
        startTicking();
    }

    void ticker::stopTicking(){
        ticking = false;
        one.join();
        std::cout<<"ticker stopped"<<std::endl;
    }

    void ticker::tick(){
        while(ticking){
            gametTickEvent event;
            game::getInstance()->onEvent(event);
            Sleep(tickSpeed);
        }
    }
}