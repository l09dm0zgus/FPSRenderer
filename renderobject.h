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
            virtual void render(Camera &cam)=0;
            virtual void destroy()=0;
            virtual void loadTextures()=0;
            virtual void addTexture(string textureFile) = 0;
            void setShaderFile(string vertexShader, string fragmentShader);
            Transform getTransform();
            void setPosition(glm::vec3 position);
            void setSize(glm::vec3 size);
            void setRotate(float angle,glm::vec3 axis);
            glm::vec3 getSize();
            glm::vec3 getPosition();
        protected:
            virtual void drawTextures();
            vector<int> textureIds;
            vector<Texture*> textures;
            Transform transform;
            IVertices *vertices;
            Shader *shaderPrograms;
            VertexBuffers buffers;
    };
}


#endif // RENDEROBJECT_H
