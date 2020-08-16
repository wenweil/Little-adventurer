
#include "scene/entity.h"
#include <vector>
namespace melodramatic{
    class layer{
        public:
            void addEntity(entity& e);
            std::vector<entity> getEntities(){return dataStore;};
        private:
            std::vector<entity> dataStore;
    };

}