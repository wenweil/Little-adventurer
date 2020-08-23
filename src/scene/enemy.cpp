#include "scene/entity.h"

namespace melodramatic{
    void enemy::createQuadAsDiamond(float xNegOffSet,float xPosOffset, float yNegOffset, float yPosOffset){
        quad = new diamond(xPosOffset,yPosOffset,xNegOffSet,yNegOffset);
        quad->move(xPos,yPos);
    }

    void enemy::createQuadAsRectangle(float width, float height){
        quad = new rectangle(width,(double)height);
        quad->move(xPos,yPos);
    }

    void enemy::setTexturePath(std::string& path){
        texturePath = path;
    }

    void enemy::setSpeed(float speed){
        this->speed = speed;
    }

    void enemy::face(direction d){
        facing = d;
    }

    void enemy::onAttacK(){

    }

    void enemy::onHit(int dmg){
        hp-=dmg;
        if(hp <= 0){
            onDeath();
        }
    }

    void enemy::onDeath(){

    }

    void enemy::move(float x, float y){
        float max = (abs(x - xPos) / speed) > (abs(y - yPos)/speed) ? (abs(x - xPos) / speed) : (abs(x - xPos) / speed);
        xPos += (x-xPos) / max;
        yPos += (y-yPos) / max;
    }

    void enemy::getPos(float& x, float& y){
        x = xPos;
        y = yPos;
    }

    void enemy::generateVertices(std::vector<float>& vData, std::vector<unsigned int>& iData){
        float id = textureManager::getTextureID(texturePath);
        int offset = 4 * iData.size() / 6;
        std::vector<vertex> vertices = quad->generateVertices();
        for(auto v:vertices){
            vData.push_back(v.getX());
            vData.push_back(v.getY());
            vData.push_back(v.getZ());
            if(id == 0.0f){
                vData.push_back(0.5f);
                vData.push_back(0.0f);
                vData.push_back(0.0f);
                vData.push_back(1.0f);
            }else{
                vData.push_back(1.0f);
                vData.push_back(1.0f);
                vData.push_back(1.0f);
                vData.push_back(1.0f);
            }
            vData.push_back(v.getTextureX());
            vData.push_back(v.getTextureY());
            vData.push_back(id);
        }
        iData.push_back(0+offset);
        iData.push_back(+offset);
        iData.push_back(2+offset);
        iData.push_back(2+offset);
        iData.push_back(3+offset);
        iData.push_back(0+offset);
    }
}