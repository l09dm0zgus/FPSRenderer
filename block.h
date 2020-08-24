#ifndef BLOCK_H
#define BLOCK_H
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "renderobject.h"
#include "blockvertices.h"
#include "texture.h"
using namespace  std;
namespace PFE
{
    class Block:public RenderObject
    {
        public:
            void render(Camera &cam) override;
            void destroy() override;
            void loadTextures() override;
            void addTexture(string textureFile);
        private:
            void drawTextures();
            vector<int> textureIds;
            vector<Texture> textures;
     };

}

#endif // BLOCK_H
