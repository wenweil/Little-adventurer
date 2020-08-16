#include "scene/layer.h"

namespace melodramatic{
    class scene{
        public:
            scene() = default;
            ~scene() = default;
            void addLayer(layer& l);
            std::vector<layer> getLayer(){return dataStore;};
        private:
            std::vector<layer> dataStore;
            int tmp;
    };
}