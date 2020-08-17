#include "scene/layer.h"

namespace melodramatic{
    class scene{
        public:
            scene() = default;
            ~scene() = default;
            void addLayer(layer& l);
            std::vector<layer> getLayer(){return dataStore;};
            void setCamPos(float x, float y);
            void getCamPos(float& x ,float& y);
        private:
            std::vector<layer> dataStore;
            int tmp;
            float camX, camY;
    };
}