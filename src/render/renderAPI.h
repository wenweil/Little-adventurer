#pragma once
#include <vector>
#include <assert.h>
#include <string>
#include <glm/glm/glm.hpp>

namespace melodramatic{

    class rendererAPI{
        public:
            enum type{
                NONE = 0, OPENGL = 1, D3D = 2, VULKAN = 3
            };
            virtual void draw() = 0;
            virtual void setVertexBuffer(std::vector<float> data) = 0;
            virtual void setIndexBuffer(std::vector<unsigned int> data) =0 ;
            virtual void setShader(const std::string& fragmentShaderSource, const std::string& vertexShaderSource) = 0;
            virtual void bindTexture(unsigned int &tid, void* data,unsigned int width, unsigned int height) = 0;
            virtual void onClose() = 0;
            virtual void setTransformMatrix(const glm::mat4& mat) = 0;
    };

    class OPENGL_API : public rendererAPI{
        public:
            static OPENGL_API* getInstance();
            OPENGL_API(){assert(!instance);};
            void setVertexBuffer(std::vector<float>data) override;
            void draw() override;
            void setIndexBuffer(std::vector<unsigned int> data) override ;
            void setShader(const std::string& fragmentShaderSource, const std::string& vertexShaderSource) override;
            void bindTexture(unsigned int &tid, void* data,unsigned int width, unsigned int height) override;
            void onClose() override;
            void setTransformMatrix(const glm::mat4& mat) override;
        private:
            void init();
            static OPENGL_API* instance;
            unsigned int drawCount;
            unsigned int vertexBuffer, vertexArray, indexBuffer;
            int textureCount, textureMax;
            unsigned int vertexShader, fragmentShader, shaderProgram;
            int* samplers;
    };
    
}