#include "application/game.h"

namespace melodramatic{

    class renderAPI{
        public:
            enum type{
                NONE = 0, OPENGL = 1, D3D = 2, VULKAN = 3
            };
            virtual void draw() = 0;
            virtual void setVertexBuffer(unsigned int count,std::vector<float> data) = 0;
            virtual void setIndexBuffer(unsigned int count, std::vector<unsigned int> data) =0 ;
            virtual void setShader() = 0;

    };

    class OPENGL_API : public renderAPI{
        public:
            static OPENGL_API* getInstance();
            OPENGL_API(){assert(!instance);};
            void setVertexBuffer(unsigned int count, std::vector<float>data) override;
            void draw() override;
            void setIndexBuffer(unsigned int count, std::vector<unsigned int> data) override ;
            void setShader() override;
        private:
            void init();
            static OPENGL_API* instance;
            GLFWwindow* m_window;
            unsigned int drawCount;
            unsigned int vertexBuffer, vertexArray, indexBuffer;
    };
    
}