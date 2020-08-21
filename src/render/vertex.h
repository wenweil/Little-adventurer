#pragma once
namespace melodramatic {
    class vertex{
        public:
            vertex() : x(0),y(0),z(0){};
            vertex(float inX, float inY, float inZ, float texX, float texY)
            :x(inX),y(inY),z(inZ),textureX(texX),textureY(texY){};
            ~vertex() = default;
            void getPos(float& x, float& y, float& z){
                x = this->x;
                y = this->y;
                z = this->z;
            }
            float getX() const {return x;};
            float getY() const {return y;};
            float getZ() const {return z;};
            float getTextureX() const {return textureX;};
            float getTextureY() const {return textureY;};
        private:
            float x,y,z;
            float r,g,b,a;
            float textureX, textureY;
            float textureID;
    };
}