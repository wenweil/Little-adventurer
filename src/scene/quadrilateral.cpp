#include "scene/quadrilateral.h"

namespace melodramatic{
    void diamond::move(float inXPos, float inYPos){
        xPos = inXPos;
        yPos = inYPos;
    }

    std::vector<vertex> diamond::generateVertices(){
        std::vector<vertex> retval;
        retval.emplace_back(xPos,yPos+yPosOffset,0.0f,0.5f,1.0f);
        retval.emplace_back(xPos-xNegOffset,yPos,0.0f,0.0f,0.5f);
        retval.emplace_back(xPos,yPos-yNegOffset,0.0f,0.5f,0.0f);
        retval.emplace_back(xPos+xPosOffset,yPos,0.0f,1.0f,0.5f);
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
        retval.emplace_back(xPos-halfWidth,yPos+halfHeight,0.0f,0.0f,1.0f);
        retval.emplace_back(xPos-halfWidth,yPos-halfHeight,0.0f,0.0f,0.0f);
        retval.emplace_back(xPos+halfWidth,yPos-halfHeight,0.0f,1.0f,0.0f);
        retval.emplace_back(xPos+halfWidth,yPos+halfHeight,0.0f,1.0f,1.0f);
        return retval;
    }
}