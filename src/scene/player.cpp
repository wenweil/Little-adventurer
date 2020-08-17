#include "scene/entity.h"

namespace melodramatic{
    void player::setTexturePath(std::string& path){
        this->texturePath = path;
    }

    void player::setSpeed(float speed){
        this->speed = speed;
    }

    void player::createQuadAsRectangle(float width,float height){
        quad = new rectangle(width,(double)height);
        quad->move(xPos,yPos);
    }

    void player::createQuadAsDiamond(float xNegOffSet,float xPosOffset, float yNegOffset, float yPosOffset){
        quad = new diamond(xPosOffset,yPosOffset,xNegOffSet,yNegOffset);
        quad->move(xPos,yPos);
    }

    void player::generateVertices(std::vector<float>& vData, std::vector<unsigned int>& iData){

    }

}