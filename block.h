#ifndef BLOCK_H
#define BLOCK_H
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "renderobject.h"
#include "blockvertices.h"
using namespace  std;
namespace PFE
{
    class Block:public RenderObject
    {
        public:
            void render(Camera &cam) override;
            void destroy() override;
            void loadTextures() override;
            void addTexture(string textureFile) override;
     };

}

#endif // BLOCK_H
