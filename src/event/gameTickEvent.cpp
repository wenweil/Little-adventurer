#include "event/gameTickEvent.h"
#include "render/renderer2d.h"

namespace melodramatic{
    eventType gametTickEvent::getEventType(){
        return type;
    };

    void gametTickEvent::handle(){
        if(renderer2D::dat.up)
            renderer2D::dat.yPos += 5.0f;
        if(renderer2D::dat.down)
            renderer2D::dat.yPos -= 5.0f;
        if(renderer2D::dat.left)
            renderer2D::dat.xPos -= 5.0f;
        if(renderer2D::dat.right)
            renderer2D::dat.xPos += 5.0f;

    }
}