#ifndef BLOCK_H
#define BLOCK_H
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "engine/render/renderobject.h"
#include "engine/render/vertices/blockvertices.h"
using namespace  std;
namespace PFE
{
    class Cube:public RenderObject
    {
        public:
            //~Block()override{destroy();}
            void render() override;
            void destroy() override;
            void loadTextures() override;
            void addTexture(string textureFile) override;
     };

}

#endif // BLOCK_H
