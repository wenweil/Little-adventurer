#include <vector>
#include <string>
#include "scene/quadrilateral.h"

namespace melodramatic{
    class entity{
        public:
            enum direction{
                UP,DOWN,LEFT,RIGHT
            };
            virtual void generateVertices(std::vector<float>& vData, std::vector<unsigned int>& iData) = 0;
    };

    class player : public entity{
        public:
            ~player(){delete quad;};
            player(float x, float y,int hitPoint):xPos(x),yPos(y){};
            void setTexturePath(std::string& path);
            void setSpeed(float speed);
            void createQuadAsRectangle(float width, float height);
            void createQuadAsDiamond(float xNegOffSet,float xPosOffset, float yNegOffset, float yPosOffset);

            void face(direction d);
            void moveUp();
            void moveDown();
            void moveLeft();
            void moveRight();
            void onHit(int damage);
            void onDeath();
            void onRevive();
            void onAttack();

            void getPos(float &x, float &y);
            void generateVertices(std::vector<float>& vData, std::vector<unsigned int>& iData) override;
        private:
            float xPos, yPos;
            int hp;
            float speed;
            std::string texturePath;
            direction facing = direction::RIGHT;
            quadrilateral* quad;
    };

    class friendly : public entity{
        public:
            friendly(float x, float y,int hitPoint): xPos(x),yPos(y){};
            ~friendly(){delete quad;};
            void setTexturePath(std::string& path);
            void setSpeed(float speed);
            void createQuadAsRectangle(float width, float height);
            void createQuadAsDiamond(float xNegOffSet,float xPosOffset, float yNegOffset, float yPosOffset);

            void face(direction d);
            void onHit(int damage);
            void onDeath();
            void onRevive();
            void onAttack();
            void move(float x, float y);

            void getPos(float &x, float &y);
            void generateVertices(std::vector<float>& vData, std::vector<unsigned int>& iData) override;
        private:
            float xPos, yPos;
            float speed;
            int hp;
            std::string texturePath;
            direction facing = direction::RIGHT;
            quadrilateral* quad;
    };

    class item : public entity{
        public:
            item(float x, float y):xPos(x),yPos(y){};
            ~item(){delete quad;};
            void setTexturePath(std::string& path);
            void createQuadAsRectangle(float width, float height);
            void createQuadAsDiamond(float xNegOffSet,float xPosOffset, float yNegOffset, float yPosOffset);

            void generateVertices(std::vector<float>& vData, std::vector<unsigned int>& iData) override;
        private:
            float xPos, yPos;
            std::string texturePath;
            quadrilateral* quad;
    };
    class enemy : public entity{
        public:
            enemy(float x, float y,int hitPoint):xPos(x),yPos(y){};
            ~enemy(){delete quad;};
            void createQuadAsRectangle(float width, float height);
            void createQuadAsDiamond(float xNegOffSet,float xPosOffset, float yNegOffset, float yPosOffset);

            void face(direction d);
            void setSpeed(float speed);
            void setTexturePath(std::string& path);
            void onAttacK();
            void onDeath();
            void onHit(int damage);
            void move(float x, float y);

            void getPos(float &x, float &y);
            void generateVertices(std::vector<float>& vData, std::vector<unsigned int>& iData) override;
        private:
            float xPos, yPos;
            int hp;
            float speed;
            float moveXPos, moveYPos;
            std::string texturePath;
            direction facing = direction::LEFT;
            quadrilateral* quad;
    };
    class boss : public entity{
        public:
            boss(float x, float y,int hitPoint):xPos(x),yPos(y){};
            ~boss(){delete quad;};
            void createQuadAsDiamond(float xNegOffSet,float xPosOffset, float yNegOffset, float yPosOffset);
            void setSpeed(float speed);
            void setTexturePath(std::string& path);

            void face(direction d);
            void onAttacK();
            void onDeath();
            void onHit(int damage);
            void move(float x, float y);

            void getPos(float &x, float &y);
            void generateVertices(std::vector<float>& vData, std::vector<unsigned int>& iData) override;
        private:
            float xPos, yPos;
            float speed;
            int hp;
            std::string texturePath;
            direction facing = direction::LEFT;
            quadrilateral* quad;
    };
    class worldFeature : public entity{
        public:
            worldFeature(float x, float y,bool canStep):xPos(x),yPos(y),passable(canStep){};
            ~worldFeature(){delete quad;};
            void generateVertices(std::vector<float>& vData, std::vector<unsigned int>& iData) override;
            void setTexturePath(std::string& path);
            void createQuadAsRectangle(float width, float height);
            void createQuadAsDiamond(float xNegOffSet,float xPosOffset, float yNegOffset, float yPosOffset);

            void generateVertices(std::vector<float>& vData, std::vector<unsigned int>& iData) override;
        private:
            float xPos, yPos;
            bool passable;
            std::string texturePath;
            quadrilateral* quad;
    };
}