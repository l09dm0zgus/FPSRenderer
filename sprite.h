#ifndef SPRITE_H
#define SPRITE_H
#include <iostream>
#include <iterator>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <SOIL/SOIL.h>
#include <glm/gtc/matrix_transform.hpp>
#include "renderobject.h"
#include "spritevertices.h"
#include "tilesheettexture.h"
namespace PFE
{
    class Sprite:public RenderObject
    {
        public:
            void loadTextures() override;
            void render(Camera &cam) override;
            void addTexture(string textureFile) override;
            void setTilePosition(float rows,float collums,float rowPos,float colPos);
            void destroy() override;
        private:
            float animationFrame = 1.0f;
            TilesheetTexture tile;
    };
}


#endif // SPRITE_H
