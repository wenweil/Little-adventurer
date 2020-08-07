#include "application/game.h"

namespace melodramatic{

    class renderAPI{
        public:
            enum type{
                NONE = 0, OPENGL = 1, D3D = 2, VULKAN = 3
            };
            virtual void draw() = 0;
            virtual void setVertexBuffer(std::vector<float> data) = 0;
            virtual void setIndexBuffer(std::vector<unsigned int> data) =0 ;
            virtual void setShader(const char* fragmentShader, const char* vertexShader) = 0;
            virtual void bindTexture(unsigned int &tid, void* data,unsigned int width, unsigned int height) = 0;

    };

    class OPENGL_API : public renderAPI{
        public:
            static OPENGL_API* getInstance();
            OPENGL_API(){assert(!instance);};
            void setVertexBuffer(std::vector<float>data) override;
            void draw() override;
            void setIndexBuffer(std::vector<unsigned int> data) override ;
            void setShader(const char* fragmentShader, const char* vertexShader) override;
            void bindTexture(unsigned int &tid, void* data,unsigned int width, unsigned int height) override;
        private:
            void init();
            static OPENGL_API* instance;
            GLFWwindow* m_window;
            unsigned int drawCount;
            unsigned int vertexBuffer, vertexArray, indexBuffer;
            unsigned int textureCount;
            unsigned int vertexShader, fragmentShader, shaderProgram;
    };
    
}