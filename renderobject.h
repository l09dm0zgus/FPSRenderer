#ifndef RENDEROBJECT_H
#define RENDEROBJECT_H
#include "transform.h"
#include "shader.h"
#include "vertexbuffers.h"
#include "IVertices.h"
#include "camera.h"
#include "texture.h"
namespace PFE
{
    class RenderObject
    {
        public:
            //virtual~RenderObject() = 0;
            virtual void render()=0;
            virtual void destroy()=0;
            virtual void loadTextures()=0;
            virtual void addTexture(string textureFile) = 0;
            void setViewportProperties(glm::mat4 view,glm::vec2 viewportSize);
            void setShaderFile(string vertexShader, string fragmentShader);
            Transform getTransform();
            void setPosition(glm::vec3 position);
            void setSize(glm::vec3 size);
            void setRotate(float angle,glm::vec3 axis);
            glm::vec3 getSize();
            glm::vec3 getPosition();
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
            Shader *shaderPrograms;
            VertexBuffers buffers;
    };
}


#endif // RENDEROBJECT_H
