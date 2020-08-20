#include <unordered_map>
namespace melodramatic{

    class textureManager{
        public:
            static float getTextureID(std::string& path);
        private:
            static unsigned int count;
            static std::unordered_map<std::string,float> textureIndex;
    };
}