#include "render/renderAPI.h"
#include "scene/scene.h"


namespace melodramatic{
    class renderer2D{
        public:
            typedef struct{
                float xPos;
                float yPos;
                bool up;
                bool down;
                bool left;
                bool right;
            }tmp;
            static void setAPIType(int type);
            static void init();
            static float loadTexture(std::string& path);
            static void draw(const melodramatic::scene& scene);
            static void draw(const melodramatic::layer& layer);
            static tmp dat;
        private:
            static void drawCurrent();
            static rendererAPI* API;
            static int type;
            static unsigned int count;
            static std::vector<float> vData;
            static std::vector<unsigned int> iData;
    };
}