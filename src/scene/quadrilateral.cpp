#include "scene/quadrilateral.h"

namespace melodramatic{
    void diamond::move(float inXPos, float inYPos){
        xPos = inXPos;
        yPos = inYPos;
    }

    std::vector<vertex> diamond::generateVertices(){
        std::vector<vertex> retval;
        retval.push_back(vertex(xPos,yPos+yPosOffset,0));
        retval.push_back(vertex(xPos+xPosOffset,yPos,0));
        retval.push_back(vertex(xPos,yPos-yNegOffset,0));
        retval.push_back(vertex(xPos-xNegOffset,yPos,0));
        return retval;
    }

    void rectangle::move(float inXPos, float inYPos){
        xPos = inXPos;
        yPos = inYPos;
    }

    std::vector<vertex> rectangle::generateVertices(){
        std::vector<vertex> retval;
        float halfWidth = width / 2;
        float halfHeight = height /2;
        retval.push_back(vertex(xPos+halfWidth,yPos-halfHeight,0));
        retval.push_back(vertex(xPos-halfWidth,yPos-halfHeight,0));
        retval.push_back(vertex(xPos+halfWidth,yPos+halfHeight,0));
        retval.push_back(vertex(xPos-halfWidth,yPos+halfHeight,0));
        return retval;
    }
}