#include "scene/textureManager.h"
#include "render/renderer2D.h"
namespace melodramatic{
    std::unordered_map<std::string,float> textureManager::textureIndex;
    unsigned int textureManager::count = 0;

    float textureManager::getTextureID(std::string& path){

        if(path == ""){
            return 0.0f;
        }

        auto search = textureIndex.find(path);
        if(search != textureIndex.end()){
            return search->second;
        }
        if(count == 15){
            textureIndex.clear();
            count = 0;
        }
        float res = renderer2D::loadTexture(path);
        textureIndex.emplace(path,res);
        count++;
        return res;
    }
}