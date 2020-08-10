#include "render/renderAPI.h"
#include "scene/scene.h"
#include "scene/layer.h"

namespace melodramatic{
    class renderer2D{
        public:
            static void setAPIType(int type);
            static void init();
            static void draw(const melodramatic::scene& scene);
            static void draw(const melodramatic::layer& layer);
        private:
            static rendererAPI* API;
            static int type;
    };
}