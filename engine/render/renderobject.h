#ifndef RENDEROBJECT_H
#define RENDEROBJECT_H
#include "engine/transform/transform.h"
#include "engine/render/shader/shader.h"
#include "engine/render/vertices/vertexbuffers.h"
#include "engine/render/vertices/IVertices.h"
#include "engine/camera/camera.h"
#include "engine/render/texture/texture.h"
namespace PFE
{
    class RenderObject
    {
        public:
            virtual~RenderObject(){}
            virtual void render()=0;
            virtual void destroy()=0;
            virtual void loadTextures()=0;
            virtual void addTexture(string textureFile) = 0;
            void setViewportProperties(glm::mat4 view,glm::vec2 viewportSize);
            void setShaderFile(string vertexShader, string fragmentShader);
            Transform getTransform();
            void setTransform(Transform &transform);
            
        protected:
            void updatePerspective();
            void drawTextures();
            glm::mat4 projectionMatrix;
            glm::mat4 viewMatrix;
            glm::vec2 viewportSize;
            vector<int> textureIds;
            vector<Texture*> textures;
            Transform transform;
            IVertices *vertices;
            ShaderProgram *shaderPrograms;
            VertexBuffers buffers;
    };
}


#endif // RENDEROBJECT_H
