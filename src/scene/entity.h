#include <vector>
#include <string>

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
            player(float x, float y,int hitPoint):xPos(x),yPos(y){};
            void generateVertices(std::vector<float>& vData, std::vector<unsigned int>& iData) override;
            void setTexturePath(std::string& path);
            void moveUp();
            void moveDown();
            void moveLeft();
            void moveRight();
            void onHit(int damage);
            void onDeath();
            void onRevive();
            void onAttack();
        private:
            float xPos, yPos;
            int hp;
            std::string texturePath;
            direction facing = direction::RIGHT;
    };

    class friendly : public entity{
        public:
            friendly(float x, float y,int hitPoint): xPos(x),yPos(y){};
            void setTexturePath(std::string& path);
            void onHit(int damage);
            void onDeath();
            void onRevive();
            void onAttack();
            void move(float x, float y);
        private:
            float xPos, yPos;

            int hp;
            std::string texturePath;
            direction facing = direction::RIGHT;
    };

    class item : public entity{
        public:
            item(float x, float y):xPos(x),yPos(y){};
            void generateVertices(std::vector<float>& vData, std::vector<unsigned int>& iData) override;
            void setTexturePath(std::string& path);
        private:
            float xPos, yPos;
            std::string texturePath;
    };
    class enemy : public entity{
        public:
            enemy(float x, float y,int hitPoint):xPos(x),yPos(y){};
            void generateVertices(std::vector<float>& vData, std::vector<unsigned int>& iData) override;
            void setTexturePath(std::string& path);
            void onAttacK();
            void onDeath();
            void onHit(int damage);
            void move(float x, float y);
        private:
            float xPos, yPos;
            int hp;

            float moveXPos, moveYPos;
            std::string texturePath;
            direction facing = direction::LEFT;
    };
    class boss : public entity{
        public:
            boss(float x, float y,int hitPoint):xPos(x),yPos(y){};
            void generateVertices(std::vector<float>& vData, std::vector<unsigned int>& iData) override;
            void setTexturePath(std::string& path);
            void onAttacK();
            void onDeath();
            void onHit(int damage);
            void move(float x, float y);
        private:
            float xPos, yPos;
            int hp;
            std::string texturePath;
            direction facing = direction::LEFT;
    };
    class worldFeature : public entity{
        public:
            worldFeature(float x, float y,bool canStep):xPos(x),yPos(y),passable(canStep){};
            void generateVertices(std::vector<float>& vData, std::vector<unsigned int>& iData) override;
            void setTexturePath(std::string& path);
        private:
            float xPos, yPos;
            bool passable;
            std::string texturePath;
    };
}