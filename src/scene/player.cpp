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

    void player::moveUp(){
        yPos += speed;
        facing = direction::UP;
    }
    void player::moveDown(){
        yPos -= speed;
        facing = direction::DOWN;
    }
    void player::moveLeft(){
        xPos -= speed;
        facing = direction::LEFT;
    }
    void player::moveRight(){
        xPos +=speed;
        facing = direction::RIGHT;
    }

    void player::onHit(int damage){
        hp -= damage;
        if(hp <= 0)
            player::onDeath();
    }

    void player::onRevive(){
        hp = hpMax;
    }

    void player::generateVertices(std::vector<float>& vData, std::vector<unsigned int>& iData){

    }
    void player::getPos(float& x, float& y){
        x = xPos;
        y = yPos;
    }

}