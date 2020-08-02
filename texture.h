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
            void draw(Shader *shader ,int id);
            void create();
        protected:
            unsigned char *image;
            int imageHeight;
            int imageWidth;
            GLuint imageProgram;

     };
}


#endif // TEXTURE_H
