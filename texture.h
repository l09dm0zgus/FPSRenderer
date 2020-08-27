#ifndef TEXTURE_H
#define TEXTURE_H
#include <iostream>
#include <SOIL/SOIL.h>
#include "shader.h"

namespace PFE
{
    class Texture
    {
        public:
            void loadImageFile(std::string  file);
            glm::vec2 getTextureSize();
            void draw(int id);
            void create();
        protected:
            unsigned char *image;
            int imageHeight;
            int imageWidth;
            GLuint imageProgram;

     };
}


#endif // TEXTURE_H
