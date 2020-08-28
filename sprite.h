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
#include "tilesettexture.h"
#include "animator.h"
namespace PFE
{
    class Sprite:public RenderObject
    {
        public:
            void loadTextures() override;
            void render(Camera &cam) override;
            void addTexture(string textureFile) override;
            void destroy() override;
        private:
            TilesetTexture tile;
            Animation2D anim;
            Animator<Animation2D> animator;
    };
}


#endif // SPRITE_H
