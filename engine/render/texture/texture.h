#ifndef TEXTURE_H
#define TEXTURE_H
#include <iostream>
#include "libs/stb_image.h"
#include "engine/render/shader/shader.h"

namespace PFE
{
    class Texture
    {
        public:
            ~Texture(){image  = nullptr;}
            void loadImageFile(std::string  file);
            glm::vec2 getTextureSize();
            void draw(int id);
            void create();
        protected:
            unsigned char *image = nullptr;
            int imageHeight = 0;
            int imageWidth = 0;
            GLuint imageProgram = 0;

     };
}


#endif // TEXTURE_H
