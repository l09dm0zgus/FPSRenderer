#ifndef TILESHEETTEXTURE_H
#define TILESHEETTEXTURE_H
#include "texture.h"
namespace PFE
{
    class TilesheetTexture :public Texture
    {
        public:
           void setShader(Shader *shader);
           void setTilePosition(float rows, float collums, float rowPos, float colPos);
        private:
           Shader *shader = 0;
    };
}


#endif // TILESHEETTEXTURE_H
