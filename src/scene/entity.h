#include <vector>

namespace melodramatic{
    class entity{
        public:
            virtual void generateVertices(std::vector<float>& vData, std::vector<unsigned int>& iData) = 0;
    };

    class player : public entity{
        public:
            player(float x, float y,int hitPoint):xPos(x),yPos(y){};
            void generateVertices(std::vector<float>& vData, std::vector<unsigned int>& iData) override;
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
    };

    class friendly : public entity{
        public:
            friendly(float x, float y,int hitPoint): xPos(x),yPos(y){};
        private:
            float xPos, yPos;

    };

    class item : public entity{
        public:
            item(float x, float y):xPos(x),yPos(y){};
            void generateVertices(std::vector<float>& vData, std::vector<unsigned int>& iData) override;
        private:
            float xPos, yPos;

    };
    class enemy : public entity{
        public:
            enemy(float x, float y,int hitPoint):xPos(x),yPos(y){};
            void generateVertices(std::vector<float>& vData, std::vector<unsigned int>& iData) override;
            void onAttacK();
            void onDeath();
            void onHit(int damage);
        private:
            float xPos, yPos;
            int hp;

            float moveXPos, moveYPos;

    };
    class boss : public entity{
        public:
            boss(float x, float y,int hitPoint):xPos(x),yPos(y){};
            void generateVertices(std::vector<float>& vData, std::vector<unsigned int>& iData) override;
            void onAttacK();
            void onDeath();
            void onHit(int damage);
        private:
            float xPos, yPos;
            int hp;

    };
    class worldFeature : public entity{
        public:
            worldFeature(float x, float y,bool canStep):xPos(x),yPos(y),passable(canStep){};
            void generateVertices(std::vector<float>& vData, std::vector<unsigned int>& iData) override;
        private:
            float xPos, yPos;
            bool passable;

    };
}