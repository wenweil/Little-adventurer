#include <vector>

namespace melodramatic {
    class quadrilaterial {
        public:
            virtual ~quadrilaterial() = default;
    };

    class diamond : public quadrilaterial{
        public:
            diamond() : xPos(0),yPos(0),xPosOffset(0),xNegOffset(0),yPosOffset(0),yNegOffset(0){};
            diamond(float inXPosOffset, float inYPosOffset) 
              : xPos(0), yPos(0) , xPosOffset(inXPosOffset), yPosOffset(inYPosOffset),xNegOffset(inXPosOffset), yNegOffset(inYPosOffset){};
            diamond(float inXPosOffset, float inYPosOffset,float inXNegOffset, float inYNegOffset) 
              : xPosOffset(inXPosOffset), yPosOffset(inYPosOffset),xNegOffset(inXNegOffset), yNegOffset(inYNegOffset){};
            void move(float inXPos, float inYPos);
            std::vector<float> generateVertices();
        private:
            float xPos,yPos,xPosOffset,xNegOffset,yPosOffset,yNegOffset;
    };

    class rectangle: public quadrilaterial{
        public:
            rectangle() : xPos(0), yPos(0) , width(0), height(0){};
            rectangle(float inWidth, float inHeight) : xPos(0), yPos(0) , width(inWidth), height(inHeight){};
            rectangle(float inXPos, float inYPos) : xPos(inXPos), yPos(inYPos) , width(0), height(0){};
            void move(float inXPos, float inYPos);
            std::vector<float> generateVertices();
        private:
            float xPos, yPos, width, height;
    };
}