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

    void player::onDeath(){
        
    }

    void player::onRevive(){
        hp = hpMax;
    }

    void player::generateVertices(std::vector<float>& vData, std::vector<unsigned int>& iData){
        float id = textureManager::getTextureID(texturePath);
        int offset = 4*(iData.size()/6);
        std::vector<vertex> points = quad->generateVertices();
        int corner = 0;
        for(auto p: points){
            vData.push_back(p.getX());
            vData.push_back(p.getY());
            vData.push_back(p.getZ());
            if(texturePath == ""){
                vData.push_back(0.0f);
                vData.push_back(0.0f);
                vData.push_back(1.0f);
                vData.push_back(1.0f);
            }else{
                vData.push_back(1.0f);
                vData.push_back(1.0f);
                vData.push_back(1.0f);
                vData.push_back(1.0f);
            }
            vData.push_back(p.getTextureX());
            vData.push_back(p.getTextureY());
            vData.push_back(id);
        }
        iData.push_back(0+offset);
        iData.push_back(1+offset);
        iData.push_back(2+offset);
        iData.push_back(2+offset);
        iData.push_back(3+offset);
        iData.push_back(0+offset);

    }
    void player::getPos(float& x, float& y){
        x = xPos;
        y = yPos;
    }

}