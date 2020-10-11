#ifndef SPRITE_H
#define SPRITE_H
#include <iostream>
#include <iterator>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/gtc/matrix_transform.hpp>
#include "engine/render/renderobject.h"
#include "engine/render/vertices/spritevertices.h"
#include "engine/render/texture/tilesettexture.h"
#include "engine/render/animation/animator.h"
namespace PFE
{
    class Sprite:public RenderObject
    {
        public:
            //~Sprite() override{destroy();}
            void loadTextures() override;
            void render() override;
            void addTexture(string textureFile) override;
            void destroy() override;
        private:
            TilesetTexture *tile;

            Animator<Animation2D> animator;
    };
}


#endif // SPRITE_H
